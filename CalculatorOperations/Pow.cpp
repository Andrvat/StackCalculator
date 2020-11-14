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
    if (executionCalculatorContext.getCalculatorStackSize() < 2) {
        throw Calculator::RuntimeCalculatorException("EXECUTION CONTEXT: stack is underflow");
    }
    executionCalculatorContext.pushCalculatorStack(
            pow(executionCalculatorContext.popCalculatorStack(), executionCalculatorContext.popCalculatorStack()));

}
