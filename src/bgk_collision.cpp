#include "../include/bgk_collision.h"
#include "../include/utilities.h"

namespace LBM
{
    void collide( const std::vector<Cell>& f,
        std::vector<Cell>& fPostCollision,
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params)
    {
        const int totalCells = params.nx * params.ny;
        fPostCollision.resize(totalCells); //resizing the fpost collision vector
        const double omega = 1.0 / params.tau; // inverse of relaxation time

        for (int y = 0; y < params.ny; ++y) //for every node
        {
            for (int x = 0; x < params.nx; ++x)
            {
                const int n = index(x, y, params.nx);

                for (int k = 0; k < Q; ++k) // for every direction
                {
                    const double feq =
                        equilibrium(k, rho[n], ux[n], uy[n]); // compute equillibrium

                    fPostCollision[n][k] =
                        f[n][k] - omega *
                        (f[n][k] - feq)
                        + 
                        forcingTerm(
                            k, omega, ux[n], uy[n], params.forceX
                        ); // relax towards equillibrium and store result (implementing the BGK-Guo Forcing method)
                }
            }
        }
    }
}