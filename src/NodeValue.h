
#ifndef JSONCPP_NODEVALUE_H
#define JSONCPP_NODEVALUE_H

struct NodeValue
{
    using Value = std::variant<std::string, int, std::map<std::string, NodeValue>>;
    Value value;
};

#endif
