#include "../include/macroscopic.h"
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
    const int totalCells = params.nx * params.ny;

    rho.resize(totalCells);
    ux.resize(totalCells);
    uy.resize(totalCells);

    for (int y = 0; y < params.ny; ++y)
    {
        for (int x = 0; x < params.nx; ++x)
        {
            const int n = index(x, y, params.nx);

            double density = 0.0;
            double velocityX = 0.0;
            double velocityY = 0.0;

            for (int k = 0; k < Q; ++k)
            {
                density  += f[n][k];
                velocityX += f[n][k] * cx[k];
                velocityY += f[n][k] * cy[k];
            }

            rho[n] = density;

            // Guo forcing velocity correction
            ux[n] = (velocityX + 0.5 * params.forceX) / density;
            uy[n] = velocityY / density;
        }
    }
}

}