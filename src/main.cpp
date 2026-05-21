#include <iostream>
#include "token.h"

int main() {
    std::cout << "CVM++ v0.1 booting...\n";

    Token t;
    t.type   = TokenType::NUMBER;
    t.lexeme = "42";
    t.line   = 1;

    std::cout << "Token: "
              << tokenTypeToString(t.type)
              << " → '"
              << t.lexeme
              << "' (line "
              << t.line
              << ")\n";

    return 0;
}