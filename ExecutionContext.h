//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <map>
#include <string>
#include <stack>

namespace Calculator {

    class ExecutionContext {
    private:

        std::map<std::string, double> calculatorVariables_;
        std::stack<double> calculatorStack_;

        const std::string EXECUTION_CONTEXT_INDICATOR = "EXECUTION CONTEXT:";
    public:

        void pushCalculatorStack(double num);

        [[nodiscard]] bool isCalculatorStackEmpty() const;

        double popCalculatorStack();

        [[nodiscard]] double topCalculatorStack() const;

        void addNewVariable(std::string &varName, double varValue);

        double getVariableByName(std::string &varName) const;

        [[nodiscard]] size_t getCalculatorStackSize() const;

    };


}