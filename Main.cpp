#include <iostream>

#include "Utils.h"
#include "AllSolutions.h"

int main()
{
    #define FOR_PROBLEM(x)                                                                                            \
        std::cout << "Running problem " << problem_##x::number << " \"" << problem_##x::name << "\"..." << std::endl; \
        problem_##x::try_solve();

    ENUMERATE_PROBLEMS;
}
