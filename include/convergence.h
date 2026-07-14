#pragma once

#include <vector>

namespace LBM
{
    double computeResidual(
        const std::vector<double>& uxOld,
        const std::vector<double>& uxNew);
}