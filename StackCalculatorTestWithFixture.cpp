//
// Created by andrew on 09.11.2020.
//

#include "gtest/gtest.h"
#include "CalculatorApplication.h"
#include "Exceptions/RuntimeCalculatorException.h"

#include <fstream>


namespace googleTests {

    static const char *TEST_INPUT_FILE_NAME = "input.txt";
    static const char *TEST_OUTPUT_FILE_NAME = "output.txt";

    class StackCalculatorFixture : public ::testing::Test {
    protected:

        void TearDown() override {
            std::cin.clear();

            std::cout.rdbuf(streamBufferCout);
            file.close();

        }

        void SetUp() override {
            dataEntryTestMod = Calculator::DataEntryArguments::StandardConsoleInput;
            file.open(TEST_OUTPUT_FILE_NAME, std::ios::out);
            streamBufferCout = std::cout.rdbuf();
            streamBufferFile = file.rdbuf();

            std::cout.rdbuf(streamBufferFile);
        }

        static std::string getCalculatorOutputString(std::ifstream &fileToRead) {
            fileToRead.open(TEST_OUTPUT_FILE_NAME);
            std::string fileLine;
            getline(fileToRead, fileLine);
            return fileLine;
        }

        std::streambuf *streamBufferCout;
        std::streambuf *streamBufferFile;
        std::fstream file;

        Calculator::DataEntryArguments dataEntryTestMod;
        Calculator::CalculatorApplication testCalculator;
    };

    TEST_F(StackCalculatorFixture, IncorrectArguments) {
        dataEntryTestMod = Calculator::DataEntryArguments::IncorrectArguments;
        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME),
                     Calculator::RuntimeCalculatorException);
    }

    TEST_F(StackCalculatorFixture, IncorrentInputFileName) {
        dataEntryTestMod = Calculator::DataEntryArguments::FileInput;
        const char *incorrectFileName = "abc.txt";
        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, incorrectFileName),
                     Calculator::RuntimeCalculatorException);
    }

    TEST_F(StackCalculatorFixture, StackUnderflow) {
        std::istringstream input("POP\n"
                                 "EXIT");
        std::cin.rdbuf(input.rdbuf());

        EXPECT_THROW(testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME),
                     Calculator::RuntimeCalculatorException);
    }

    TEST_F(StackCalculatorFixture, DivisionByZero) {
        std::istringstream input("PUSH 0\n"
                                 "PUSH 2\n"
                                 "/\n"
                                 "EXIT");
        std::cin.rdbuf(input.rdbuf());
        testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME);

        std::ifstream fileToRead;
        std::string calculatorOutputString = getCalculatorOutputString(fileToRead);
        const char * cStr = calculatorOutputString.c_str();
        EXPECT_STREQ(cStr, "Couldn't divide by zero!");

        fileToRead.close();
    }

    TEST_F(StackCalculatorFixture, UnknownCommand) {
        std::istringstream input("PUSH 0\n"
                                 "PUSH 2\n"
                                 "UNKNOWN\n"
                                 "EXIT");
        std::cin.rdbuf(input.rdbuf());
        testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME);

        std::ifstream fileToRead;
        std::string calculatorOutputString = getCalculatorOutputString(fileToRead);
        const char * cStr = calculatorOutputString.c_str();
        EXPECT_STREQ(cStr, "OPERATION FACTORY: unknown command");

        fileToRead.close();

    }

    TEST_F(StackCalculatorFixture, DefineOperation) {
        std::istringstream input("DEFINE A 5\n"
                                 "PUSH A\n"
                                 "PRINT\n"
                                 "EXIT");
        std::cin.rdbuf(input.rdbuf());
        testCalculator.launch(dataEntryTestMod, TEST_INPUT_FILE_NAME);

        std::ifstream fileToRead;
        std::string calculatorOutputString = getCalculatorOutputString(fileToRead);
        const char * cStr = calculatorOutputString.c_str();
        EXPECT_STREQ(cStr, "5");

        fileToRead.close();

    }

}
