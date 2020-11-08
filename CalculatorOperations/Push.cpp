//
// Created by andrew on 08.11.2020.
//

#include "Push.h"
#include "../Exceptions/CalculatorExecutesException.h"

void Calculator::Push::execute(const std::list<std::string> &executionArguments,
                               Calculator::ExecutionContext &executionCalculatorContext) {
    if (executionArguments.size() != PUSH_OPERATION_ARGUMENTS_NUMBER) {
        throw Calculator::CalculatorExecutesException("PUSH: too few arguments");
    }

    double value;

    // Implementation depends on PUSH_OPERATION_ARGUMENTS_NUMBER
    std::string argsString = executionArguments.front();

    try {
        if (isArgumentDouble(argsString)) {
            value = std::stod(argsString);
        } else {
            value = executionCalculatorContext.getVariableByName(argsString);
        }
    } catch (Calculator::CalculatorExecutesException &exception) {
        throw Calculator::CalculatorExecutesException(exception.getErrorMessage());
    } catch (...) {
        throw Calculator::CalculatorExecutesException("PUSH: second argument must be number");
    }

    executionCalculatorContext.pushCalculatorStack(value);
}


bool Calculator::Push::isArgumentDouble(const std::string &argsString) {
    try {
        std::stod(argsString);
    } catch (...) {
        return false;
    }
    return true;
}
