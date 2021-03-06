//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "../ICalculatorOperation.h"

namespace Calculator {

    class Pow : public ICalculatorOperation {
        void execute(const std::list<std::string> &executionArguments, ExecutionContext &executionCalculatorContext) override;
    };
}

