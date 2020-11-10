//#include "CalculatorApplication.h"
//#include "Exceptions/RuntimeCalculatorException.h"
//
//#include <iostream>
//
//int main(int argc, char *argv[]) {
//    Calculator::CalculatorApplication calculator;
//    auto dataEntry = static_cast<Calculator::DataEntryArguments>(argc);
//    try {
//        calculator.launch(dataEntry, argv[1]);
//    } catch (Calculator::RuntimeCalculatorException &exception) {
//        std::cout << exception.what() << std::endl;
//    }
//    return 0;
//}