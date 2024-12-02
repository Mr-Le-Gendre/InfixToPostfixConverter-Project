#include "InfixToPostfixConverter.h"
#include <cctype> // For isalpha()
#include <iostream>

InfixToPostfixConverter::InfixToPostfixConverter() : postfixExpression("") {}

int InfixToPostfixConverter::precedence(char op) const {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void InfixToPostfixConverter::convert(const std::string& infixExpression) {
    std::stack<char> operators;
    postfixExpression.clear();

    for (char ch : infixExpression) {
        if (std::isalpha(ch)) {
            postfixExpression += ch; // Append operands directly to the result.
        }
        else if (ch == '(') {
            operators.push(ch); // Push '(' onto the stack.
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfixExpression += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Pop '('.
        }
        else if (ch == ' ') {
            continue; // Skip spaces.
        }
        else { // Operator case.
            while (!operators.empty() &&
                precedence(ch) <= precedence(operators.top())) {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Append remaining operators.
    while (!operators.empty()) {
        postfixExpression += operators.top();
        operators.pop();
    }
}

std::string InfixToPostfixConverter::getPostfixExpression() const {
    return postfixExpression;
}
