//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "ICalculatorOperation.h"

namespace Calculator {

    class IOperationsCreator {
    public:
        virtual ~IOperationsCreator() = default;

        [[nodiscard]] virtual Calculator::ICalculatorOperation *create() const = 0;
    };

}

