#pragma once

#include <vector>

#include "lattice.h"
#include "parameters.h"

namespace LBM
{
    void stream(
        const std::vector<Cell>& fPostCollision,
        std::vector<Cell>& fNext,
        const Parameters& params);
}