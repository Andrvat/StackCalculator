//
// Created by andrew on 08.11.2020.
//

#include "Division.h"
#include "../Exceptions/CalculatorExecutesException.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Division, "/")

void Calculator::Division::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    if (executionCalculatorContext.getCalculatorStackSize() < 2) {
        throw Calculator::RuntimeCalculatorException("EXECUTION CONTEXT: stack is underflow");
    }
    double x, y;
    x = executionCalculatorContext.popCalculatorStack();
    y = executionCalculatorContext.popCalculatorStack();

    if (y == 0) {
        executionCalculatorContext.pushCalculatorStack(y);
        executionCalculatorContext.pushCalculatorStack(x);
        throw Calculator::CalculatorExecutesException("Couldn't divide by zero!");
    }
    executionCalculatorContext.pushCalculatorStack(x / y);

}
