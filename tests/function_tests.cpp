#include "test_basics.h"
#include "../src/genetics.h"

int main()
{
    test_expect(0, int(normalizer_function_sigmoid(-100000)), "NORMAL_SIGMOID");
    test_expect(1, int(normalizer_function_sigmoid_custom(PI)(100000)), "CUSTOM_SIGMOID");
    test_expect(0, int(normalizer_function_relu(-1)), "NORMAL_RELU");
    test_expect(-1, int(normalizer_function_relu_custom(-1)(-1)), "CUSTOM_RELU");
}