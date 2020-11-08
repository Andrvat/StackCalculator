//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "../ICalculatorOperation.h"

namespace Calculator {

    static const unsigned int PUSH_OPERATION_ARGUMENTS_NUMBER = 1;

    class Push : public ICalculatorOperation {
        void execute(const std::list<std::string> &executionArguments,
                     ExecutionContext &executionCalculatorContext) override;

        static bool isArgumentDouble(const std::string &argsString);
    };
}

