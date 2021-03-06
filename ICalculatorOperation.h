//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <list>
#include <string>

#include "ExecutionContext.h"

namespace Calculator {

    class ICalculatorOperation {

    public:

        virtual void
        execute(const std::list<std::string> &executionArguments, ExecutionContext &executionCalculatorContext) = 0;

        virtual ~ICalculatorOperation() = default;
    };

}
