#include "genetics.h"

Genes::Genes(int d1, int d2, long double min_val, long double max_val)
{
    _min_val = min_val;
    _max_val = max_val;
    _d1 = d1;
    _d2 = d2;
    gene_parts = new long double*[d1];
    for (int i = 0; i < d1; i++)
    {
        gene_parts[i] = new long double[d2];
        for (int j = 0; j < d2; j++)
            gene_parts[i][j] = 0;
    }
}

Genes::~Genes()
{
    for (int i = 0; i < _d1; i++)
        delete[] gene_parts[i];
    delete[] gene_parts;
}