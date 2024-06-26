#include "DirectoryTree.h"
#include <algorithm>


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

json DirectoryTree::toJson(TreeNode* node) const
{
	json j;
	for (auto child : node->children)
	{
		j[child->value] = toJson(child);
	}
	return j;
}



