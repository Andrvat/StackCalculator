//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "ExecutionContext.h"

namespace Calculator {

    [[maybe_unused]] const std::string STOP_CALCULATOR_COMMAND = "EXIT";

    class CalculatorApplication {
    private:
        ExecutionContext executionCalculatorContext;
    public:
        void run(std::istream &inputStream);

    };

}