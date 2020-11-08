//
// Created by andrew on 08.11.2020.
//

#include "Define.h"
#include "../Exceptions/CalculatorExecutesException.h"

#include <string>

void Calculator::Define::execute(const std::list<std::string> &executionArguments,
                                   Calculator::ExecutionContext &executionCalculatorContext) {
    if (executionArguments.size() != DEFINE_OPERATION_ARGUMENTS_NUMBER) {
        throw Calculator::CalculatorExecutesException("DEFINE: too few arguments");
    }

    double value;
    std::string key;

    // Implementation depends on DEFINE_OPERATION_ARGUMENTS_NUMBER
    key = executionArguments.front();
    try {
        value = std::stod(executionArguments.back());
    } catch (...) {
        throw Calculator::CalculatorExecutesException("DEFINE: second argument must have double type");
    }

    executionCalculatorContext.addNewVariable(key, value);
}
