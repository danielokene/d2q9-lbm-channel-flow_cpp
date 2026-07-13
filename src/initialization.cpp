#include "../include/initialization.h"
#include "../include/utilities.h"

namespace LBM
{
    void initializeDistributionFunction(
        std::vector<Cell>& f,
        const Parameters& params)
    {
        const int totalCells = params.nx * params.ny;

        f.resize(totalCells);

        for (int y = 0; y < params.ny; ++y)
        {
            for (int x = 0; x < params.nx; ++x)
            {
                const int n = index(x, y, params.nx);

                for (int k = 0; k < Q; ++k)
                {
                    f[n][k] = equilibrium(k, 1.0, 0.0, 0.0);
                }
            }
        }
    }
}