//
// Created by andrew on 08.11.2020.
//

#include "Multiplication.h"
#include "../Exceptions/CalculatorException.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Multiplication, "*")

void Calculator::Multiplication::execute(const std::list<std::string> &executionArguments,
                                         Calculator::ExecutionContext &executionCalculatorContext) {
    double x, y;
    try {
        x = executionCalculatorContext.popCalculatorStack();
        y = executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }

    executionCalculatorContext.pushCalculatorStack(x * y);
}
