//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <exception>
#include <string>

namespace Calculator {

    class RuntimeCalculatorException : std::exception {
    private:
        std::string errorMessage_;
    public:
        explicit RuntimeCalculatorException(const std::string &errorMessage) {
            errorMessage_ = errorMessage;
        };

        [[nodiscard]] const char *what() const noexcept override {
            return errorMessage_.c_str();
        }

        [[nodiscard]] std::string getErrorMessage() const {
            return errorMessage_;
        }
    };

}
