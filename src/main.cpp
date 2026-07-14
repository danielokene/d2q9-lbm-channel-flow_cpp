#include <iostream>
#include <vector>
#include <utility>      // std::swap

#include "../include/lattice.h"
#include "../include/parameters.h"
#include "../include/initialization.h"
#include "../include/bgk_collision.h"
#include "../include/macroscopic.h"
#include "../include/streaming.h"
#include "../include/output.h"
#include "../include/convergence.h"



int main()
{
    LBM::Parameters params;

    // Allocate memory
    std::vector<LBM::Cell> f;
    std::vector<LBM::Cell> fNext;
    std::vector<LBM::Cell> fPostCollision;

    std::vector<double> rho;
    std::vector<double> ux;
    std::vector<double> uy;
    std::vector<double> uxPrevious; // used for convergence check

    // Initialise
    LBM::initializeDistributionFunction(f, params);

    uxPrevious.resize(params.nx * params.ny, 0.0);

    // Time integration
    for (int step = 0; step <= params.steps; ++step)
    {
        LBM::computeMacroscopic(f, rho, ux, uy, params);
        LBM::collide(f, fPostCollision, rho, ux, uy, params);
        LBM::stream(fPostCollision, fNext, params);

        std::swap(f, fNext);

        // computing residual value and saving to file
        double residual = LBM::computeResidual(uxPrevious, ux);
        if (step % 100 == 0)
        {
            LBM::appendResidual("results/residual.csv", step, residual);
        }
        uxPrevious = ux;
        
        // checking for convergence
        if (residual < params.convergenceTolerance)
        {
            std::cout
                << "\nConverged after "
                << step
                << " iterations.\n";

            break;
        }

        // Solver output after every 1000 iterations
        if (step % params.outputInterval == 0)
        {
            std::cout
            << "Iteration "
            << step
            << " / "
            << params.steps
            << "   Residual = "
            << residual
            << '\n';
        }
    }
    // computing macroscopic variables again to ensure saved data
    // matches the newly updated dstribution functions after streaming
    LBM::computeMacroscopic(f, rho, ux, uy, params);

    // writing results to file after every 200 iterations
    LBM::writeCSV("results/channel_final.csv", rho, ux, uy, params);
}
