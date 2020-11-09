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

void Calculator::CalculatorApplication::run(std::istream &inputStream) {

    std::string currentInputLine;
    while(getline(inputStream, currentInputLine)) {
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
            Calculator::ICalculatorOperation *currentOperation = Calculator::OperationsFactory::instance().create(operationName);
            currentOperation->execute(argumentsList, this->executionCalculatorContext);
        } catch (const Calculator::CalculatorException &exception) {
            std::cout << exception.what() << std::endl;
        } catch (const Calculator::CalculatorExecutesException &exception) {
            std::cout << exception.what() << std::endl;
        } catch (const Calculator::RuntimeCalculatorException &exception) {
            std::cout << exception.what() << std::endl;
            return;
        }
    }


}
