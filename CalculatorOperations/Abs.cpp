//
// Created by andrew on 08.11.2020.
//

#include "Abs.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Abs, "ABS");

void Calculator::Abs::execute(const std::list<std::string> &executionArguments,
                              Calculator::ExecutionContext &executionCalculatorContext) {
    executionCalculatorContext.pushCalculatorStack(std::abs(executionCalculatorContext.popCalculatorStack()));

}
