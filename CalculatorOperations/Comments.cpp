//
// Created by andrew on 08.11.2020.
//

#include "Comments.h"
#include "../OperationCreator.h"

REGISTER_CREATOR(Calculator::Comments, "#")

void Calculator::Comments::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    // No actions
}
