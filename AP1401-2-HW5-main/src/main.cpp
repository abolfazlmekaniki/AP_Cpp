#include "../include/graph.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
    if (false) // make false to run unit tests
    {
        // debug section
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << RUN_ALL_TESTS() << std::endl;
    }
    return 0;
}
