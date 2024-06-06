
#ifndef JSONPARSER_ERROR_H
#define JSONPARSER_ERROR_H

#include <optional>
#include <string>

#include "../headers/defines.h"

class Error
{
public:
    Error() = default;

    void setInfo(ErrorCode, std::optional<std::string> info = std::nullopt);
    ErrorCode getErrorCode();
    std::string getErrorDetails();

private:
    std::optional<std::string> details;
    ErrorCode errorCode;
};

#endif


