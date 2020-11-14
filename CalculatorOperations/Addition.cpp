//
// Created by andrew on 08.11.2020.
//

#include "Addition.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Addition, "+")

void Calculator::Addition::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    if (executionCalculatorContext.getCalculatorStackSize() < 2) {
        throw Calculator::RuntimeCalculatorException("EXECUTION CONTEXT: stack is underflow");
    }
    executionCalculatorContext.pushCalculatorStack(
            executionCalculatorContext.popCalculatorStack() + executionCalculatorContext.popCalculatorStack());

}
