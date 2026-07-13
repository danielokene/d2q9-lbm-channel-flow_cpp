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
                int newX = x + cx[k];
                const int newY = y + cy[k];

                // applying perodic boundary conditon for streaming distributon function
                if (newX < 0)
                    newX = params.nx - 1;

                if (newX >= params.nx)
                    newX = 0;

                
                const int destination = index(newX, newY, params.nx);

                // Push streaming implementation
                fNext[destination][k] = fPostCollision[current][k];
            }
        }
    }
}

}