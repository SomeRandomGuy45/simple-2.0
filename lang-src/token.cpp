#include "token.h"

int simple::gettoken() {
    static int last_char = ' ';

    // Skip whitespace
    while (isspace(last_char)) {
        last_char = getchar();
    }

    // Identifier or keyword
    if (isalpha(last_char)) {
        simple::IdentifierString = last_char;
        while (isalnum((last_char = getchar()))) {
            simple::IdentifierString += last_char;
        }

        if (simple::IdentifierString == "func") {
            return simple::token_func;
        }
        if (simple::IdentifierString == "def") {
            return simple::token_def;
        }
        return simple::tok_identifier;
    }

    // Number parsing
    if (isdigit(last_char) || last_char == '.') {
        std::string NumStr;
        do {
            NumStr += last_char;
            last_char = getchar();
        } while (isdigit(last_char) || last_char == '.');

        NumVal = strtod(NumStr.c_str(), nullptr);
        return simple::tok_number;
    }

    // Comment handling (single-line comments)
    if (last_char == '/') {
        int next_char = getchar();
        if (next_char == '/') {
            // Skip comment characters
            while (last_char != '\n' && last_char != EOF) {
                last_char = getchar();
            }
            return gettoken();
        } else {
            // If it's not a comment, return '/' and restore next_char
            ungetc(next_char, stdin);
            return '/';
        }
    }

    // End of file
    if (last_char == EOF) {
        return simple::token_eof;
    }

    // Otherwise, return the character as its ASCII value
    int thisChar = last_char;
    last_char = getchar();
    return thisChar;
}