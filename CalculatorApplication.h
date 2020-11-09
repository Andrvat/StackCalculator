//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "ExecutionContext.h"

namespace Calculator {

    enum class DataEntryArguments {
        StandardConsoleInput = 1,
        FileInput = 2,
        IncorrectArguments
    };

    [[maybe_unused]] const std::string STOP_CALCULATOR_COMMAND = "EXIT";

    class CalculatorApplication {
    private:
        ExecutionContext executionCalculatorContext;
    public:
        void run(std::istream &inputStream);

        void launch(Calculator::DataEntryArguments dataEntryMod, const char *inputFileName);

    };

}