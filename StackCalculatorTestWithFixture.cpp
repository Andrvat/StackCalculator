//
// Created by andrew on 09.11.2020.
//

#include "gtest/gtest.h"
#include "CalculatorApplication.h"
#include "Exceptions/RuntimeCalculatorException.h"


namespace googleTests {

    static const char *TEST_INPUT_FILE_NAME = "input.txt";

    class StackCalculatorFixture : public ::testing::Test {
    protected:

        void TearDown() override {
        }

        void SetUp() override {
            dataEntryTestMod = Calculator::DataEntryArguments::StandardConsoleInput;
        }

        Calculator::DataEntryArguments dataEntryTestMod;
        Calculator::CalculatorApplication testCalculator;

    public:
        // Fill functions
    };

    TEST_F(StackCalculatorFixture, CheckIncorrectArguments) {
        dataEntryTestMod = Calculator::DataEntryArguments::IncorrectArguments;
        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME), Calculator::RuntimeCalculatorException);
    }

    TEST_F(StackCalculatorFixture, CheckIncorrentInputFileName) {
        dataEntryTestMod = Calculator::DataEntryArguments::FileInput;
        const char *incorrectFileName = "abc.txt";
        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, incorrectFileName), Calculator::RuntimeCalculatorException);
    }

    TEST_F(StackCalculatorFixture, StackUnderflow) {
        std::istringstream input("POP\n"
                                 "EXIT");
        std::cin.rdbuf(input.rdbuf());

        dataEntryTestMod = Calculator::DataEntryArguments::StandardConsoleInput;
        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME), Calculator::RuntimeCalculatorException);

    }

}
