
#ifndef JSONCPP_DEFINES_H
#define JSONCPP_DEFINES_H


enum class TokenType
{
    CURLY_OPEN,
    CURLY_CLOSE,

    SQUARE_OPEN,
    SQUARE_CLOSE,

    COLON,
    COMMA,

    KEY,

    DATA_STR,
    DATA_BOOL,
    DATA_INT,
    DATA_DOUBLE,
};


enum class State
{
    OBJECT_PARSING,
    ARRAY_PARSING
};


enum class Result
{
    OK,

    API_EMPTY,
    API_NOT_KEY_IN_MAP,
    API_INCONSISTENT_DATA,
    API_INDEX_NEGATIVE,
    API_INDEX_OUT_OF_ARRAY,
    API_NODE_NOT_ARRAY,
    API_NODE_NOT_OBJECT,

    PREPARSER_STRING_ERROR,
    PREPARSER_UNKNOWN_SYMBOL,

    VALIDATOR_BRACKET_CURLY_ERROR,
    VALIDATOR_BRACKET_SQUARE_ERROR,

    VALIDATOR_IMPROPER_BEGINNING,
    VALIDATOR_IMPROPER_END,

    VALIDATOR_IMPROPER_TOKEN_AFTER_COMMA,
    VALIDATOR_IMPROPER_TOKEN_AFTER_COLON,
    VALIDATOR_IMPROPER_TOKEN_AFTER_CURLY_CLOSE,
    VALIDATOR_IMPROPER_TOKEN_AFTER_CURLY_OPEN,
    VALIDATOR_IMPROPER_TOKEN_AFTER_DATA_BOOL,
    VALIDATOR_IMPROPER_TOKEN_AFTER_DATA_DOUBLE,
    VALIDATOR_IMPROPER_TOKEN_AFTER_DATA_INT,
    VALIDATOR_IMPROPER_TOKEN_AFTER_SQUARE_CLOSE,
    VALIDATOR_IMPROPER_TOKEN_AFTER_SQUARE_OPEN,
    VALIDATOR_IMPROPER_TOKEN_AFTER_STRING,
};

#endif

