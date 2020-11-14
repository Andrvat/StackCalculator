//
// Created by andrew on 14.11.2020.
//

#include <fstream>
#include <iostream>
#include "LaunchArgHandler.h"
#include "Exceptions/FilesStreamExceptions.h"

void FileStreams::LaunchArgHandler::setArgumentsCount(unsigned int newArgumentsCount) {
    LaunchArgHandler::argumentsCount = newArgumentsCount;
}

void FileStreams::LaunchArgHandler::setInputFileName(char *newInputFileName) {
    LaunchArgHandler::inputFileName = newInputFileName;
}

std::istream &FileStreams::LaunchArgHandler::getIstreamByArguments(std::fstream &fileStream) const {
    auto dataEntryMod = static_cast<FileStreams::DataEntryArguments>(argumentsCount);
    switch (dataEntryMod) {
        case DataEntryArguments::StandardConsoleInput:
            return std::cin;
        case DataEntryArguments::FileInput:
            fileStream.open(inputFileName);
            if (!fileStream.is_open()) {
                throw Calculator::FileStreamExceptions(
                        "Couldn't open file by filename from console argument. Please, check it and try again...");
            }
            return fileStream;
        default:
            throw Calculator::FileStreamExceptions(
                    "Wrong number of console program arguments! Please, check it and try again...");
    }
}
