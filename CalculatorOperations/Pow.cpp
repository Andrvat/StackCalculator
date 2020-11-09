//
// Created by andrew on 08.11.2020.
//

#include "Pow.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Pow, "^")

#include <cmath>

void Calculator::Pow::execute(const std::list<std::string> &executionArguments,
                              Calculator::ExecutionContext &executionCalculatorContext) {
    double x, y;
    try {
        x = executionCalculatorContext.popCalculatorStack();
        y = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    executionCalculatorContext.pushCalculatorStack(pow(x, y));

}
