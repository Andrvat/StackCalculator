//
// Created by andrew on 09.11.2020.
//

#include <fstream>
#include "gtest/gtest.h"
#include "CalculatorApplication.h"

enum class DataEntryArguments {
    StandardConsoleInput = 1,
    FileInput = 2,
    IncorrectArguments
};

namespace googleTests {
    class StackCalculatorFixture : public ::testing::Test {
    protected:

        void TearDown() override {
        }

        void SetUp() override {
        }

        DataEntryArguments dataEntryTestMod;
        std::ifstream inputTestFileStream;
        Calculator::CalculatorApplication testCalculator;

    public:
        // Fill functions
    };

}
