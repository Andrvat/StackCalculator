//
// Created by andrew on 14.11.2020.
//

#pragma once

//
// Created by andrew on 08.11.2020.
//

#pragma once

#include <exception>
#include <string>

namespace Calculator {

    class FileStreamExceptions : std::exception {
    private:
        std::string errorMessage_;
    public:
        explicit FileStreamExceptions(const std::string &errorMessage) {
            errorMessage_ = errorMessage;
        };

        [[nodiscard]] const char *what() const noexcept override {
            return errorMessage_.c_str();
        }
    };

}
