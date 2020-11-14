//
// Created by andrew on 08.11.2020.
//

#include "Pop.h"
#include "../Exceptions/RuntimeCalculatorException.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Pop, "POP")

void Calculator::Pop::execute(const std::list<std::string> &executionArguments,
                              Calculator::ExecutionContext &executionCalculatorContext) {
    executionCalculatorContext.popCalculatorStack();
}
