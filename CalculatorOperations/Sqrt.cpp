//
// Created by andrew on 08.11.2020.
//

#include "Sqrt.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Sqrt, "SQRT")

#include <cmath>

void Calculator::Sqrt::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    executionCalculatorContext.pushCalculatorStack(sqrt(executionCalculatorContext.popCalculatorStack()));

}
