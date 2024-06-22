#ifndef DIRECTORY_TREE_H
#define DIRECTORY_TREE_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include "json.hpp"

using json = nlohmann::json;


struct TreeNode {
    std::string value;
    std::vector<TreeNode* > children;
};



class DirectoryTree {
public:
    DirectoryTree();
    ~DirectoryTree();

    TreeNode* getRoot() const;

    void addChild(const std::string& parentValue, const std::string& childValue);
    TreeNode*  findNode(TreeNode* node, const std::string& value);
    bool remveNode(TreeNode* node, const std::string& value);
    void printTraversal(TreeNode* node ,int path = 0);
    void fromJson(const json& j, TreeNode* node);
    json toJson(TreeNode* node);

private:
    TreeNode* root;
};


#endif // DIRECTORY_TREE_H


