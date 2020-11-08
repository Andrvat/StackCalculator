//
// Created by andrew on 08.11.2020.
//

#include "Subtraction.h"
#include "../Exceptions/RuntimeCalculatorException.h"

void Calculator::Subtraction::execute(const std::list<std::string> &executionArguments,
                                      Calculator::ExecutionContext &executionCalculatorContext) {
    double x, y;
    try {
        x = executionCalculatorContext.popCalculatorStack();
        y = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    executionCalculatorContext.pushCalculatorStack(x - y);
}
