//
// Created by andrew on 08.11.2020.
//

#include "Pop.h"
#include "../Exceptions/RuntimeCalculatorException.h"

void Calculator::Pop::execute(const std::list<std::string> &executionArguments,
                              Calculator::ExecutionContext &executionCalculatorContext) {
    try {
        executionCalculatorContext.popCalculatorStack();
    } catch (Calculator::RuntimeCalculatorException &exception) {
        throw Calculator::RuntimeCalculatorException(exception.getErrorMessage());
    }
}
