//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <exception>
#include <string>

namespace Calculator {

    class CalculatorExecutesException : std::exception {
    private:
        std::string errorMessage_;
    public:
        explicit CalculatorExecutesException(const std::string &errorMessage) {
            errorMessage_ = errorMessage;
        };

        explicit CalculatorExecutesException(const char *errorMessage) {
            errorMessage_ = std::string(errorMessage);
        };

        [[nodiscard]] const char *what() const noexcept override {
            return errorMessage_.c_str();
        }
    };
}

