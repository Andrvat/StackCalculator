//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "IOperationsCreator.h"
#include "ICalculatorOperation.h"

namespace Calculator {

    template<class T>
    class OperationCreator : public Calculator::IOperationsCreator {
    public:
        [[nodiscard]] Calculator::ICalculatorOperation *create() const override {
            return new T();
        }
    };

}
