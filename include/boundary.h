#pragma once

#include <vector>

#include "lattice.h"
#include "parameters.h"

namespace LBM
{
    void applyBounceBack(
        std::vector<Cell>& f,
        const Parameters& params);
}