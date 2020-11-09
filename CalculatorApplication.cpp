//
// Created by andrew on 08.11.2020.
//

#include "CalculatorApplication.h"
#include "Exceptions/CalculatorException.h"
#include "Exceptions/RuntimeCalculatorException.h"
#include "Exceptions/CalculatorExecutesException.h"
#include "OperationsFactory.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void Calculator::CalculatorApplication::run(std::istream &inputStream) {

    std::string currentInputLine;
    while (getline(inputStream, currentInputLine)) {
        std::stringstream parserByStringStream(currentInputLine);

        std::string operationName;
        parserByStringStream >> operationName;

        if (operationName == STOP_CALCULATOR_COMMAND) {
            break;
        }

        std::list<std::string> argumentsList;
        std::string currentArgument;
        while (!parserByStringStream.eof()) {
            parserByStringStream >> currentArgument;
            argumentsList.push_back(currentArgument);
        }

        try {
            Calculator::ICalculatorOperation *currentOperation = Calculator::OperationsFactory::instance().create(
                    operationName);
            currentOperation->execute(argumentsList, this->executionCalculatorContext);
        } catch (const Calculator::CalculatorException &exception) {
            std::cout << exception.what() << std::endl;
        } catch (const Calculator::CalculatorExecutesException &exception) {
            std::cout << exception.what() << std::endl;
        } catch (const Calculator::RuntimeCalculatorException &exception) {
            throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
        }
    }


}

void Calculator::CalculatorApplication::launch(Calculator::DataEntryArguments dataEntryMod, const char *inputFileName) {
    std::ifstream fileStream;
    switch (dataEntryMod) {
        case DataEntryArguments::StandardConsoleInput:
            try {
                this->run(std::cin);
            } catch (Calculator::RuntimeCalculatorException &exception) {
                throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
            }
            break;
        case DataEntryArguments::FileInput:
            fileStream.open(inputFileName);
            if (!fileStream.is_open()) {
                throw Calculator::RuntimeCalculatorException(
                        "Couldn't open file by filename from console argument. Please, check it and try again...");
            }
            try {
                this->run(fileStream);
            } catch (Calculator::RuntimeCalculatorException &exception) {
                throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
            }
            break;
        case DataEntryArguments::IncorrectArguments:
            throw Calculator::RuntimeCalculatorException(
                    "Wrong number of console program arguments! Please, check it and try again...");
    }

}
