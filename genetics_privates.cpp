#include "genetics.h"

bool Genes::InRange(int i1, int i2)
{
    return (i1 > 0 && i1 < _d1) && (i2 > 0 && i2 < _d2);
}