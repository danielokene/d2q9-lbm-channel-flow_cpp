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

    // Initialise
    LBM::initializeDistributionFunction(f, params);

    // Time integration
    for (int step = 0; step < params.steps; ++step)
    {
        LBM::computeMacroscopic(f, rho, ux, uy, params);
        LBM::collide(f, fPostCollision, rho, ux, uy, params);
        LBM::stream(fPostCollision, fNext, params);

        std::swap(f, fNext);

        // writing results to file after every 200 iterations
        if (step % params.saveInterval == 0)
        {
            // computing macroscopic variables again to ensure saved data
            // matches the newly updated dstribution functions after streaming
            LBM::computeMacroscopic(f, rho, ux, uy, params);
            
            LBM::writeCSV(
                "../results/channel_" + std::to_string(step) + ".csv",
                rho,
                ux,
                uy,
                params);
        }

        if (step % params.outputInterval == 0)
        {
            std::cout << "Iteration " << step 
                << " / "
                << params.steps
                << '\n';
        }
    }
}
