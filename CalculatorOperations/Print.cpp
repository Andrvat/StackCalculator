//
// Created by andrew on 08.11.2020.
//

#include "Print.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Print, "PRINT")

#include <iostream>

void Calculator::Print::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    std::cout << executionCalculatorContext.topCalculatorStack() << std::endl;

}
