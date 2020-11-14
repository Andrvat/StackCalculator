#include "CalculatorApplication.h"
#include "LaunchArgHandler.h"
#include "Exceptions/RuntimeCalculatorException.h"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    std::fstream inputFileStream;
    FileStreams::LaunchArgHandler argHandler{};
    argHandler.setArgumentsCount(argc);
    argHandler.setInputFileName(argv[1]);

    Calculator::CalculatorApplication calculator;
    try {
        calculator.run(argHandler.getIstreamByArguments(inputFileStream));
    } catch (Calculator::RuntimeCalculatorException &exception) {
        std::cout << exception.what() << std::endl;
    }

    inputFileStream.close();
    return EXIT_SUCCESS;
}