
#include <fstream>

#include <gtest/gtest.h>

#include "../src/jsonApi.h"
#include "config.h"
#include "utils.h"
#include <NodeValue.h>


TEST(ApiTest, InsertValue)
{
    Utils utils;
    std::string jsonString = utils.getJsonFromFile(TEST_DATA, "test_1.json");
    
    jsonApi api;
    bool result = api.parseJsonString(jsonString);
    ASSERT_TRUE(result);

    ObjectNode* root = api.getRoot();
    Node* node = &(root->at("person"));

    ObjectNode* nodePerson = std::get_if<ObjectNode>(&(node->value));
    nodePerson->insert(std::pair<std::string, int>("newValue", 23));

    std::string json = api.parseObjectToJsonString(root);
    std::string jsonExpected = utils.getJsonFromFile(std::string(TEST_DATA) + "api/", "test_1.json");
    ASSERT_EQ(json, jsonExpected);
}


TEST(ApiTest, InsertValue2)
{
    Utils utils;
    std::string jsonString = utils.getJsonFromFile(TEST_DATA, "test_2.json");

    jsonApi api;
    bool result = api.parseJsonString(jsonString);
    ASSERT_TRUE(result);

    InnerNodePtr node = api.getNode({ "shipTo", "name" });
    ASSERT_FALSE(std::holds_alternative<nullptr_t>(node));

    (std::get<ObjectNode*>(node))->insert(std::pair<std::string, bool>("boolValue", true));

    std::string json = api.parseObjectToJsonString(api.getRoot());
    std::string jsonExpected = utils.getJsonFromFile(std::string(TEST_DATA) + "api/", "test_2.json");
    ASSERT_EQ(json, jsonExpected);
}


TEST(ApiTest, ChangeValue)
{
    Utils utils;
    std::string jsonString = utils.getJsonFromFile(TEST_DATA, "test_3.json");

    jsonApi api;
    bool result = api.parseJsonString(jsonString);
    ASSERT_TRUE(result);

    Node newNode;
    newNode.value = "Spain";
    result = api.changeNodeValue({ "person", "country" }, newNode);
    ASSERT_TRUE(result);

    std::string json = api.parseObjectToJsonString(api.getRoot());
    std::string jsonExpected = utils.getJsonFromFile(std::string(TEST_DATA) + "api/", "test_3.json");
    ASSERT_EQ(json, jsonExpected);
}
