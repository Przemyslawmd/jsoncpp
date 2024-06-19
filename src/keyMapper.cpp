
#include "keyMapper.h"


void KeyMapper::createKeyMapping(const std::vector<Token>& tokens)
{
    size_t sequence = 0;
    for (const auto& token : tokens) {
        if (token.type == TokenType::KEY) {
            keyToSequence.emplace(std::make_pair(std::get<std::string>(token.data), sequence));
            sequenceToKey.emplace(std::make_pair(sequence, std::get<std::string>(token.data)));
            sequence++;
        }
    }
}


const std::map<std::string, size_t>& KeyMapper::getkeyToSequence() const
{
    return keyToSequence;
}


const std::map<size_t, std::string>& KeyMapper::getSequenceToKey() const
{
    return sequenceToKey;
}


size_t KeyMapper::getSequence(const std::string& key)
{
    return 0;
}


const std::string& KeyMapper::getKey(size_t sequence)
{
    return "";
}

