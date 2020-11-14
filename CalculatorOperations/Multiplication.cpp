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
    if (executionCalculatorContext.getCalculatorStackSize() < 2) {
        throw Calculator::RuntimeCalculatorException("EXECUTION CONTEXT: stack is underflow");
    }

    executionCalculatorContext.pushCalculatorStack(
            executionCalculatorContext.popCalculatorStack() * executionCalculatorContext.popCalculatorStack());
}
