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
                    int sourceX = x - cx[k];
                    int sourceY = y - cy[k];

                    // applying perodic boundary conditon for streaming distributon function
                    if (sourceX < 0)
                        sourceX = params.nx - 1;

                    if (sourceX >= params.nx)
                        sourceX = 0;

                    // top/bottom bounce-back boundary condition
                    if (sourceY < 0 || sourceY >= params.ny)
                    {
                        fNext[current][k] = fPostCollision[current][opposite[k]];
                        continue;
                    }
                    
                    // Pull streaming implementation
                    const int source = index(sourceX, sourceY, params.nx);
                    fNext[current][k] = fPostCollision[source][k];
                }
            }
        }
    }
}