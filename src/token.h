#pragma once
#include <string>

enum class TokenType {
    // Literals
    NUMBER,
    IDENTIFIER,
    TRUE,
    FALSE,

    // Arithmetic
    PLUS,
    MINUS,
    STAR,
    SLASH,

    // Comparison
    EQUAL,
    EQUAL_EQUAL,
    LESS,

    // Delimiters
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    SEMICOLON,

    // Keywords
    LET,
    PRINT,
    IF,
    WHILE,
    INPUT,

    // Control
    EOF_TOKEN
};

struct Token {
    TokenType   type;
    std::string lexeme;
    int         line;
};

inline std::string tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::NUMBER:      return "NUMBER";
        case TokenType::IDENTIFIER:  return "IDENTIFIER";
        case TokenType::TRUE:        return "TRUE";
        case TokenType::FALSE:       return "FALSE";
        case TokenType::PLUS:        return "PLUS";
        case TokenType::MINUS:       return "MINUS";
        case TokenType::STAR:        return "STAR";
        case TokenType::SLASH:       return "SLASH";
        case TokenType::EQUAL:       return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::LESS:        return "LESS";
        case TokenType::LPAREN:      return "LPAREN";
        case TokenType::RPAREN:      return "RPAREN";
        case TokenType::LBRACE:      return "LBRACE";
        case TokenType::RBRACE:      return "RBRACE";
        case TokenType::SEMICOLON:   return "SEMICOLON";
        case TokenType::LET:         return "LET";
        case TokenType::PRINT:       return "PRINT";
        case TokenType::IF:          return "IF";
        case TokenType::WHILE:       return "WHILE";
        case TokenType::INPUT:       return "INPUT";
        case TokenType::EOF_TOKEN:   return "EOF";
        default:                     return "UNKNOWN";
    }
}