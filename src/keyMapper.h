
#ifndef JSONPARSER_KEY_MAPPER_H
#define JSONPARSER_KEY_MAPPER_H

#include <map>
#include <string>


class KeyMapper
{
public:
    KeyMapper() = default;

    void addKey(const std::string& key, size_t sequence);

    size_t getSequence(const std::string& key);
    const std::string& getKey(size_t sequence);

private:
    std::map<std::string, size_t> keyToSequence;
    std::map<size_t, std::string> sequenceToKey;
};

#endif

