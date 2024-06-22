#include "DirectoryTree.h"
#include <algorithm>

//TreeNode::TreeNode(const std::string& val) : value(val) {}
//
//DirectoryTree::DirectoryTree() {
//    root = std::make_shared<TreeNode>("root");
//    nodes["root"] = root;
//}
//
//void DirectoryTree::addChild(const std::string& parentValue, const std::string& childValue) {
//    if (nodes.find(parentValue) != nodes.end()) {
//        auto childNode = std::make_shared<TreeNode>(childValue);
//        nodes[parentValue]->children.push_back(childNode);
//        nodes[childValue] = childNode;
//    }
//}
//
//void DirectoryTree::deleteNode(const std::string& nodeValue) {
//    if (nodes.find(nodeValue) != nodes.end()) {
//        for (auto& pair : nodes) {
//            auto& parentNode = pair.second;
//            parentNode->children.erase(
//                std::remove_if(
//                    parentNode->children.begin(),
//                    parentNode->children.end(),
//                    [&nodeValue](const std::shared_ptr<TreeNode>& child) {
//                        return child->value == nodeValue;
//                    }
//                    ),
//                parentNode->children.end()
//                );
//        }
//        deleteSubTree(nodes[nodeValue]);
//        nodes.erase(nodeValue);
//    }
//}
//
//void DirectoryTree::clearTree() {
//    root->children.clear();
//    nodes.clear();
//    nodes["root"] = root;
//}
//
//void DirectoryTree::deleteSubTree(const std::shared_ptr<TreeNode>& node) {
//    for (const auto& child : node->children) {
//        deleteSubTree(child);
//        nodes.erase(child->value);
//    }
//}
//
//void DirectoryTree::dfsTraversal(const std::shared_ptr<TreeNode>& node) const {
//    if (node) {
//        std::cout << node->value << " ";
//        for (const auto& child : node->children) {
//            dfsTraversal(child);
//        }
//    }
//}
//
//void DirectoryTree::printDFSTraversal() const {
//    dfsTraversal(root);
//    std::cout << std::endl;
//}
//
//json DirectoryTree::toJson(const std::shared_ptr<TreeNode>& node) const {
//    json j;
//    for (const auto& child : node->children) {
//        j[child->value] = toJson(child);
//    }
//    return j;
//}
//
//json DirectoryTree::getTreeJson() const {
//    json j;
//    j[root->value] = toJson(root);
//    return j;
//}
//
//void DirectoryTree::fromJson(const json& j, const std::shared_ptr<TreeNode>& node) {
//    std::cout<<j.dump(4)<<std::endl;
//    for (auto it = j.begin(); it != j.end(); ++it) {
//        auto childNode = std::make_shared<TreeNode>(it.key());
//        node->children.push_back(childNode);
//        nodes[it.key()] = childNode;
//        fromJson(it.value(), childNode);
//    }
//}
//
//void DirectoryTree::buildTreeFromJson(const json& j) {
//    root = std::make_shared<TreeNode>("root");
//    nodes.clear();
//    nodes["root"] = root;
//    fromJson(j.at("root"), root);
//}

DirectoryTree::DirectoryTree()
{
	root = new TreeNode();
	root->value;
}

DirectoryTree::~DirectoryTree()
{
}

TreeNode* DirectoryTree::getRoot() const
{
	return root;
}

void DirectoryTree::addChild(const std::string& parentValue, const std::string& childValue)
{
	TreeNode* parentNode = findNode(root, parentValue);
	if (parentNode != nullptr)
	{
		TreeNode* childNode = new TreeNode();
		childNode->value = childValue;
		parentNode->children.push_back(childNode);
	}
}

TreeNode* DirectoryTree::findNode(TreeNode* node, const std::string& value)
{
	if (node->value == value)
	{
		return node;
	}
	else
	{
		for (auto child : node->children)
		{
			TreeNode* foundNode = findNode(child, value);
			if (foundNode != nullptr)
			{
				return foundNode;
			}
		}
	}
	return nullptr;
}

bool DirectoryTree::remveNode(TreeNode* node, const std::string& value)
{
	if (node->value == value)
	{
		delete node;
		return true;
	}
	else
	{
		for (auto child : node->children)
		{
			if (remveNode(child, value))
			{
				delete child;
				return true;
			}
		}
	}
	return false;
}

void DirectoryTree::printTraversal(TreeNode* node, int depth)
{
	std::string indent(depth * 4, ' '); 
	std::cout << indent << node->value << std::endl;
	for (auto child : node->children)
	{
		printTraversal(child, depth + 1);
	}
}



void DirectoryTree::fromJson(const json& j, TreeNode* node)
{

	for (auto it = j.begin(); it != j.end(); ++it)
	{
		TreeNode* childNode = new TreeNode();
		childNode->value = it.key();
		node->children.push_back(childNode);
		fromJson(it.value(), childNode);
	}


}

json DirectoryTree::toJson(TreeNode* node)
{
	json j;
	for (auto child : node->children)
	{
		j[child->value] = toJson(child);
	}
	return j;
}



