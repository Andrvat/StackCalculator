//
// Created by andrew on 08.11.2020.
//

#include "ExecutionContext.h"
#include "Exceptions/CalculatorExecutesException.h"
#include "Exceptions/RuntimeCalculatorException.h"

void Calculator::ExecutionContext::pushCalculatorStack(double num) {
    calculatorStack_.push(num);
}

bool Calculator::ExecutionContext::isCalculatorStackEmpty() const {
    return calculatorStack_.empty();
}

double Calculator::ExecutionContext::popCalculatorStack() {
    double topValue = topCalculatorStack();
    calculatorStack_.pop();
    return topValue;
}

double Calculator::ExecutionContext::topCalculatorStack() const {
    if (isCalculatorStackEmpty()) {
        throw Calculator::RuntimeCalculatorException("EXECUTION CONTEXT: stack is underflow");
    }
    return calculatorStack_.top();
}

void Calculator::ExecutionContext::addNewVariable(std::string &varName, double varValue) {
    calculatorVariables_[varName] = varValue;
}

double Calculator::ExecutionContext::getVariableByName(std::string &varName) const {
    if (calculatorVariables_.find(varName) == calculatorVariables_.end()) {
        throw Calculator::CalculatorExecutesException("EXECUTION CONTEXT: unknown variable " + varName);
    }
    return calculatorVariables_.at(varName);
}