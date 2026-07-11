#include "../include/collision.h"
#include "../include/utilities.h"

namespace LBM
{
    void computeMacroscopic(
        const std::vector<Cell>& f,
        std::vector<double>& rho,
        std::vector<double>& ux,
        std::vector<double>& uy,
        const Parameters& params)
    {
        const int totalCells = params.nx * params.ny; // calculating the total cells

        // assign the totalcells size to the density and velocity vectors
        rho.resize(totalCells);
        ux.resize(totalCells);
        uy.resize(totalCells);

        // iterating over all the lattice cells and storing density and velocity values
        for (int y = 0; y < params.ny; ++y)
        {
            for (int x = 0; x < params.nx; ++x)
            {
                const int n = index(x, y, params.nx);

                // temporary variables
                double density = 0.0;
                double velocityX = 0.0;
                double velocityY = 0.0;

                // iterating all directions 
                for (int k = 0; k < Q; ++k)
                {
                    density += f[n][k];
                    velocityX += f[n][k] * cx[k];
                    velocityY += f[n][k] * cy[k];
                }

                // dumps the new values to the permanent variables
                rho[n] = density;
                ux[n] = velocityX / density;
                uy[n] = velocityY / density;
            }
        }
    }

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
                        (f[n][k] - feq); // relax towards equillibrium and store result (implementing teh BGK method)
                }
            }
        }
    }
}