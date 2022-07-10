#include "genetics.h"
#include <cmath>

long double normalizer_function_sigmoid(long double x)
{
    return 1 / (1 + std::pow(E, -x));
}

long double normalizer_function_relu(long double x)
{
    if (x < 0)
        return 0;
    return x;
}

std::function<long double (long double)> normalizer_function_relu_custom(long double min)
{
    return std::function<long double (long double)>(
        [&](long double x)
        {
            if (x < min)
                return (long double)0;
            return x;
        }
    );
}

std::function<long double (long double)> normalizer_function_sigmoid_custom(long double base)
{
    return std::function<long double (long double)>(
        [&](long double x)
        {
            return 1 / (1 + std::pow(base, -x));
        }
    );
}

