#include <iostream>
#include <vector>
#include <utility>      // std::swap

#include "../include/lattice.h"
#include "../include/parameters.h"
#include "../include/initialization.h"
#include "../include/bgk_collision.h"
#include "../include/macroscopic.h"
#include "../include/streaming.h"

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

        if (step % params.outputInterval == 0)
        {
            std::cout << "Iteration " << step 
                << " / "
                << params.steps
                << '\n';
        }
    }
}
