#include "../include/streaming.h"

#include "../include/utilities.h"

namespace LBM
{

void stream(
    const std::vector<Cell>& fPostCollision,
    std::vector<Cell>& fNext,
    const Parameters& params)
{
    const int totalCells = params.nx * params.ny;

    // using assign so as to resize and reset after every iteration
    fNext.assign(totalCells, Cell{});

    for (int y = 0; y < params.ny; ++y)
    {
        for (int x = 0; x < params.nx; ++x)
        {
            const int current = index(x, y, params.nx);

            for (int k = 0; k < Q; ++k)
            {
                const int newX = x + cx[k];
                const int newY = y + cy[k];

                // Skip destinations outside the domain.
                // Boundary conditions will handle these later.
                if (newX < 0 || newX >= params.nx ||
                    newY < 0 || newY >= params.ny)
                {
                    continue;
                }

                const int destination = index(newX, newY, params.nx);

                // Push streaming implementation
                fNext[destination][k] = fPostCollision[current][k];
            }
        }
    }
}

}