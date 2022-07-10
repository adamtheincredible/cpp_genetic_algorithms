#pragma once
#include <string>
#include <functional>
#include "constant_numbers.h"

class Genes
{
    private:
        long double** gene_parts;
        int _d1, _d2;
        long double _min_val, _max_val;
        bool InRange(int i1, int i2);

    public:
        long double Get(int i1, int i2);
        int GetDimention1();
        int GetDimention2();
        long double GetFitness(std::function<long double (long double**)> fitness_function, std::function<long double (long double)> normalizer_function);
        bool Set(int i1, int i2, long double val);
        std::string ToJson(bool pretty);
        Genes(int d1, int s2, long double min_val, long double max_val);
        ~Genes();
};

long double normalizer_function_sigmoid(long double x);
long double normalizer_function_relu(long double x);
std::function<long double (long double)> normalizer_function_relu_custom(long double min);
std::function<long double (long double)> normalizer_function_sigmoid_custom(long double base);