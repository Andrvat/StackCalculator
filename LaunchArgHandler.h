//
// Created by andrew on 14.11.2020.
//

#pragma once

#include <istream>

namespace FileStreams {

    enum class DataEntryArguments {
        StandardConsoleInput = 1,
        FileInput = 2,
    };

    class LaunchArgHandler {
        unsigned int argumentsCount;
        char *inputFileName;
    public:
        void setArgumentsCount(unsigned int newArgumentsCount);

        void setInputFileName(char *newInputFileName);

        [[nodiscard]] std::istream &getIstreamByArguments(std::fstream &fileStream) const;
    };

}

