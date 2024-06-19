
#ifndef JSONPARSER_KEY_MAPPER_H
#define JSONPARSER_KEY_MAPPER_H

#include <map>
#include <string>
#include <vector>

#include "reader/Token.h"


class KeyMapper
{
public:
    KeyMapper() = default;

    void createKeyMapping(const std::vector<Token>&);

    size_t getSequence(const std::string& key);
    const std::string& getKey(size_t sequence);

    const std::map<std::string, size_t>& getkeyToSequence() const;
    const std::map<size_t, std::string>& getSequenceToKey() const;

private:
    std::map<std::string, size_t> keyToSequence;
    std::map<size_t, std::string> sequenceToKey;
};

#endif

