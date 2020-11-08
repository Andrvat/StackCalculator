//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "../ICalculatorOperation.h"

namespace Calculator {

    static const unsigned int DEFINE_OPERATION_ARGUMENTS_NUMBER = 2;

    class Define : public ICalculatorOperation {
        void execute(const std::list<std::string> &executionArguments, ExecutionContext &executionCalculatorContext) override;
    };
}

