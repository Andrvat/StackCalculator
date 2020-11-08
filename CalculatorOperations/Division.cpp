//
// Created by andrew on 08.11.2020.
//

#include "Division.h"
#include "../Exceptions/CalculatorExecutesException.h"
#include "../Exceptions/RuntimeCalculatorException.h"

void Calculator::Division::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    double x, y;
    try {
        x = executionCalculatorContext.popCalculatorStack();
        y = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    if (y == 0) {
        executionCalculatorContext.pushCalculatorStack(x);
        executionCalculatorContext.pushCalculatorStack(y);
        throw Calculator::CalculatorExecutesException("Couldn't divide by zero!");
    }
    executionCalculatorContext.pushCalculatorStack(x / y);

}
