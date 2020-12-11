#pragma once
#include "Pair.h"

struct Node
{
	Node* leftNode;
	Node* rightNode;
	Pair data;

	Node() : data(Pair()), leftNode(nullptr), rightNode(nullptr) {}
	Node(const Pair& _data, Node* left, Node* right) : data(_data), leftNode(left), rightNode(right) {}
	
	friend std::ostream& operator<<(std::ostream& out, const Node& element)
	{
		out << element.data;
		return out;
	}
};
