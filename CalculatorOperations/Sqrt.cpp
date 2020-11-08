//
// Created by andrew on 08.11.2020.
//

#include "Sqrt.h"
#include "../Exceptions/RuntimeCalculatorException.h"

#include <cmath>

void Calculator::Sqrt::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    double x;
    try {
        x = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    executionCalculatorContext.pushCalculatorStack(sqrt(x));

}
