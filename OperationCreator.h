//
// Created by andrew on 08.11.2020.
//

#pragma once

#include "IOperationsCreator.h"
#include "ICalculatorOperation.h"
#include "OperationsFactory.h"

#define REGISTER_CREATOR(T, NAME) static Calculator::OperationCreator<T> creator(NAME);

namespace Calculator {

    template<class T>
    class OperationCreator : public Calculator::IOperationsCreator {
    public:
        [[nodiscard]] Calculator::ICalculatorOperation *create() const override {
            return new T();
        }

        explicit OperationCreator(const std::string &operationName) {
            OperationsFactory::instance().registerOperationCreator(operationName, this);
        }
    };

}
