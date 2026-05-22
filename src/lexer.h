#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "token.h"

class Lexer {
    std::string source;
    int start   = 0;
    int current = 0;
    int line    = 1;
    std::vector<Token> tokens;

    // ── helpers ──────────────────────────
    bool isAtEnd() { 
        return current >= (int)source.size(); 
    }

    char advance() { 
        return source[current++]; 
    }

    char peek() {
        if (isAtEnd()) return '\0';
        return source[current];
    }

    bool match(char expected) {
        if (isAtEnd()) return false;
        if (source[current] != expected) return false;
        current++;
        return true;
    }

    void addToken(TokenType type) {
        std::string lexeme = source.substr(start, current - start);
        tokens.push_back({type, lexeme, line});
    }

    // ── scanners ─────────────────────────
    void number() {
        while (isdigit(peek())) advance();
        addToken(TokenType::NUMBER);
    }

    void identifier() {
        while (isalnum(peek()) || peek() == '_') advance();

        std::string text = source.substr(start, current - start);

        static std::unordered_map<std::string, TokenType> keywords = {
            {"let",   TokenType::LET},
            {"print", TokenType::PRINT},
            {"if",    TokenType::IF},
            {"while", TokenType::WHILE},
            {"input", TokenType::INPUT},
            {"true",  TokenType::TRUE},
            {"false", TokenType::FALSE},
        };

        TokenType type = TokenType::IDENTIFIER;
        if (keywords.count(text)) type = keywords[text];
        addToken(type);
    }

    void scanToken() {
        char c = advance();
        switch (c) {
            // single character tokens
            case '+': addToken(TokenType::PLUS);      break;
            case '-': addToken(TokenType::MINUS);     break;
            case '*': addToken(TokenType::STAR);      break;
            case '/': addToken(TokenType::SLASH);     break;
            case '(': addToken(TokenType::LPAREN);    break;
            case ')': addToken(TokenType::RPAREN);    break;
            case '{': addToken(TokenType::LBRACE);    break;
            case '}': addToken(TokenType::RBRACE);    break;
            case ';': addToken(TokenType::SEMICOLON); break;
            case '<': addToken(TokenType::LESS);      break;

            // = or ==
            case '=':
                if (match('=')) addToken(TokenType::EQUAL_EQUAL);
                else            addToken(TokenType::EQUAL);
                break;

            // whitespace
            case ' ':
            case '\r':
            case '\t':
                break;

            // newline
            case '\n':
                line++;
                break;

            // numbers
            default:
                if (isdigit(c))  { number();     break; }
                if (isalpha(c))  { identifier(); break; }

                // unknown character
                std::cout << "Unknown char '"
                          << c << "' at line "
                          << line << "\n";
                break;
        }
    }

public:
    Lexer(const std::string& source) : source(source) {}

    std::vector<Token> tokenize() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }
        tokens.push_back({TokenType::EOF_TOKEN, "", line});
        return tokens;
    }
};