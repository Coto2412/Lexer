#ifndef LEXER
#define LEXER



enum token_type {
    number,
    suma,
    resta,
    var,
    var_opt,
    eq,
    lt,
    gt,
    lq,
    gq,
    end_of_file,
    error
};


typedef enum token_type token_t;

struct Token {
    token_t type;
    struct Token *next, *prev;
};

extern token_t *lexer(const char *file_name);


#endif
