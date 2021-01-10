//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "ExecutionContext.h"

namespace Calculator {

    class CalculatorApplication {
    private:
        ExecutionContext executionCalculatorContext;

        const std::string STOP_CALCULATOR_COMMAND = "EXIT";
    public:
        void run(std::istream &inputStream);
    };

}