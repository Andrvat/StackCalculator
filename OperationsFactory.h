//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <map>
#include <string>

#include "IOperationsCreator.h"
#include "OperationCreator.h"
#include "Exceptions/RuntimeCalculatorException.h"
#include "Exceptions/CalculatorException.h"

namespace Calculator {

    class OperationsFactory {
    protected:
        std::map<std::string, Calculator::IOperationsCreator *> operationsMap_;

    public:

        template<class T>
        void registerOperationCreator(const std::string &operationID) {
            if (operationsMap_.find(operationID) == operationsMap_.end()) {
                operationsMap_[operationID] = new Calculator::OperationCreator<T>();
            } else {
                throw Calculator::RuntimeCalculatorException("OPERATION FACTORY: too much creators for given key");
            }
        }

        Calculator::ICalculatorOperation *create(const std::string &operationID) {
            auto it = operationsMap_.find(operationID);
            if (it != operationsMap_.end()) {
                return it->second->create();
            } else {
                throw Calculator::CalculatorException("OPERATION FACTORY: unknown command");
            }
        }
    };

}

