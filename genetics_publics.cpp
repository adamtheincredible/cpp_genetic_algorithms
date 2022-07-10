#include "genetics.h"

long double Genes::Get(int i1, int i2)
{
    if (!InRange(i1, i2))
        return NULL;
    return gene_parts[i1][i2];
}

bool Genes::Set(int i1, int i2, long double val)
{
    if (!InRange(i1, i2) || val < _min_val || val > _max_val)
        return false;
    gene_parts[i1][i2] = val;
}

std::string Genes::ToJson(bool pretty)
{
    std::string res = "[";
    if (pretty)
        res += "\n";
    for (int i = 0; i < _d1; i++)
    {
        if (pretty)
            res += "\t";
        res += "[";
        for (int j = 0; j < _d2; j++)
        {
            res += std::to_string(gene_parts[i][j]);
            if (j != _d2-1)
                res += ", ";
        }
        res += "]";
        if (i != _d1-1)
            res += ", ";
        if (pretty)
            res += "\n";
    }
    res += "]";
    return res;
}

long double Genes::GetFitness(std::function<long double (long double**)> fitness_function, std::function<long double (long double)> normalizer_function)
{
    if (normalizer_function == NULL)
        normalizer_function = [](long double x){return x;};
    return normalizer_function(fitness_function(gene_parts));
}

int Genes::GetDimention1()
{
    return _d1;
}

int Genes::GetDimention2()
{
    return _d2;
}