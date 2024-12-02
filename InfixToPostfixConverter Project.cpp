// InfixToPostfixConverter Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "InfixToPostfixConverter.h"

int main() {
    std::ifstream inputFile("InfixData.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    InfixToPostfixConverter converter;
    std::string infixExpression;

    while (std::getline(inputFile, infixExpression)) {
        converter.convert(infixExpression);
        std::cout << "Infix Expression: " << infixExpression << std::endl;
        std::cout << "Postfix Expression: " << converter.getPostfixExpression() << std::endl << std::endl;
    }

    inputFile.close();
    return 0;
}
