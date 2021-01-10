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
    if (isValueByIdExistInOperationsCreatorsMap(operationID)) {
        throw Calculator::RuntimeCalculatorException(OPERATIONS_FACTORY_INDICATOR + " " + "too much creators for given key");
    } else {
        operationsCreatorsMap[operationID] = operationsCreator;
    }
}

Calculator::ICalculatorOperation *Calculator::OperationsFactory::create(const std::string &operationID) {
    if (isValueByIdExistInOperationsCreatorsMap(operationID)) {
        return operationsCreatorsMap.find(operationID)->second->create();
    } else {
        throw Calculator::CalculatorException(OPERATIONS_FACTORY_INDICATOR + " " + "unknown command:" + " " + operationID);
    }
}

bool Calculator::OperationsFactory::isValueByIdExistInOperationsCreatorsMap(const std::string &operationID) const {
    return operationsCreatorsMap.find(operationID) != operationsCreatorsMap.end();
}

