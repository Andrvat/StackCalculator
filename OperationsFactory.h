//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <map>
#include <string>

#include "IOperationsCreator.h"
#include "Exceptions/RuntimeCalculatorException.h"
#include "Exceptions/CalculatorException.h"

namespace Calculator {

    class OperationsFactory {
    private:

        OperationsFactory() = default;

    protected:

        std::map<std::string, Calculator::IOperationsCreator *> operationsCreatorsMap;

    public:

        OperationsFactory(const OperationsFactory &) = delete;

        static OperationsFactory &instance() {
            static OperationsFactory factory;
            return factory;
        }

        void registerOperationCreator(const std::string &operationID, Calculator::IOperationsCreator *operationsCreator) {
            if (operationsCreatorsMap.find(operationID) == operationsCreatorsMap.end()) {
                operationsCreatorsMap[operationID] = operationsCreator;
            } else {
                throw Calculator::RuntimeCalculatorException("OPERATION FACTORY: too much creators for given key");
            }
        }

        Calculator::ICalculatorOperation *create(const std::string &operationID) {
            auto it = operationsCreatorsMap.find(operationID);
            if (it != operationsCreatorsMap.end()) {
                return it->second->create();
            } else {
                throw Calculator::CalculatorException("OPERATION FACTORY: unknown command");
            }
        }
    };

}

