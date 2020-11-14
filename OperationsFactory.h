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

        std::map<std::string, Calculator::IOperationsCreator *> operationsCreatorsMap;

    public:

        OperationsFactory(const OperationsFactory &) = delete;

        OperationsFactory &operator=(const OperationsFactory &) = delete;

        static OperationsFactory &instance();

        void
        registerOperationCreator(const std::string &operationID, Calculator::IOperationsCreator *operationsCreator);

        Calculator::ICalculatorOperation *create(const std::string &operationID);
    };

}

