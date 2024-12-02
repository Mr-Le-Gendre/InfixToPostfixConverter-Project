#ifndef INFIXTOPOSTFIXCONVERTER_H
#define INFIXTOPOSTFIXCONVERTER_H

#include <string>
#include <stack>

class InfixToPostfixConverter {
private:
    std::string postfixExpression; // Stores the resulting postfix expression.

    // Assign precedence to operators.
    int precedence(char op) const;

public:
    // Converts infix to postfix.
    void convert(const std::string& infixExpression);

    // Returns the postfix expression.
    std::string getPostfixExpression() const;

    // Constructor
    InfixToPostfixConverter();
};

#endif // INFIXTOPOSTFIXCONVERTER_H
