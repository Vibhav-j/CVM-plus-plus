#include <iostream>
#include "token.h"
#include "lexer.h"

int main() {
    std::cout << "CVM++ v0.1 booting...\n\n";

    std::string source = "let x = 42 + 5;";
    std::cout << "Source: " << source << "\n\n";

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "Tokens:\n";
    for (auto& t : tokens) {
        std::cout << "  "
                  << tokenTypeToString(t.type)
                  << " -> '"
                  << t.lexeme
                  << "'\n";
    }

    return 0;
}