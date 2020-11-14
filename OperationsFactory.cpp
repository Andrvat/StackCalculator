//
// Created by andrew on 08.11.2020.
//

#include "OperationsFactory.h"

Calculator::OperationsFactory &Calculator::OperationsFactory::instance() {
    static OperationsFactory factory;
    return factory;
}

void Calculator::OperationsFactory::registerOperationCreator(const std::string &operationID,
                                                             Calculator::IOperationsCreator *operationsCreator) {
    if (operationsCreatorsMap.find(operationID) == operationsCreatorsMap.end()) {
        operationsCreatorsMap[operationID] = operationsCreator;
    } else {
        throw Calculator::RuntimeCalculatorException("OPERATION FACTORY: too much creators for given key");
    }
}

Calculator::ICalculatorOperation *Calculator::OperationsFactory::create(const std::string &operationID) {
    auto it = operationsCreatorsMap.find(operationID);
    if (it != operationsCreatorsMap.end()) {
        return it->second->create();
    } else {
        throw Calculator::CalculatorException("OPERATION FACTORY: unknown command: " + operationID);
    }
}

