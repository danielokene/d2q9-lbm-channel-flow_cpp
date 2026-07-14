#include "../include/convergence.h"

#include <cmath>
#include <algorithm>

namespace LBM
{
    double computeResidual(
        const std::vector<double>& uxOld,
        const std::vector<double>& uxNew)
    {
        double residual = 0.0;

        for (std::size_t i = 0; i < uxOld.size(); ++i)
        {
            residual = std::max(
                residual,
                std::abs(uxNew[i] - uxOld[i]));
        }

        return residual;
    }
}