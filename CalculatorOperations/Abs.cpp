//
// Created by andrew on 08.11.2020.
//

#include "Abs.h"
#include "../Exceptions/RuntimeCalculatorException.h"

void Calculator::Abs::execute(const std::list<std::string> &executionArguments,
                              Calculator::ExecutionContext &executionCalculatorContext) {
    double x;
    try {
        x = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    executionCalculatorContext.pushCalculatorStack(std::abs(x));

}
