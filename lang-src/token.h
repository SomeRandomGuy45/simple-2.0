#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdio>

#include "defines.h"

NAME_SPACESTART
    
enum token {
    // EOF token
    token_eof = -1,

    // keywords
    token_func = -2,
    token_def = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierString;
static double NumVal;

static int gettoken();

NAME_SPACEEND