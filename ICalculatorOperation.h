//
// Created by andrew on 08.11.2020.
//

#pragma once
#include <list>
#include <string>

#include "ExecutionContext.h"

namespace Calculator {

    class ICalculatorOperation {

    public:
        // Чисто-виртуальная функция. Оставляет определение классам-наследникам
        virtual void execute(const std::list<std::string> &executionArguments, ExecutionContext &executionCalculatorContext) = 0;

        // Обязательное требование к С++ интерфейсам
        virtual ~ICalculatorOperation() = default;
    };

}
