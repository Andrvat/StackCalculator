#include <fstream>
#include <iostream>

#include "CalculatorApplication.h"

enum class DataEntryArguments {
    StandardConsoleInput = 1,
    FileInput = 2,
    IncorrectArguments
};

int main(int argc, char *argv[]) {
    Calculator::CalculatorApplication calculator;
    auto dataEntry = static_cast<DataEntryArguments>(argc);
    std::ifstream fileStream;
    switch (dataEntry) {
        case DataEntryArguments::StandardConsoleInput:
            calculator.run(std::cin);
            break;
        case DataEntryArguments::FileInput:
            fileStream.open(argv[1]);
            if (!fileStream.is_open()) {
                std::cout << "Couldn't open file by filename from console argument. Please, check it and try again..." << std::endl;
                break;
            }
            calculator.run(fileStream);
            break;
        case DataEntryArguments::IncorrectArguments:
            std::cout << "Wrong number of console program arguments! Please, check it and try again..." << std::endl;
            break;
    }
    return 0;
}
