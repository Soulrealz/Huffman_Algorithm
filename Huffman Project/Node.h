#pragma once
#include "Pair.h"

struct Node
{
	Pair data;
	Node* leftNode;
	Node* rightNode;

	Node() : data(Pair()), leftNode(nullptr), rightNode(nullptr) {}
	Node(const char symbol) : data(Pair(symbol)), leftNode(nullptr), rightNode(nullptr) {}
	Node(const Pair& _data, Node* left, Node* right) : data(_data), leftNode(left), rightNode(right) {}
	Node(const Node& other) : data(other.data), leftNode(other.leftNode), rightNode(other.rightNode) {}

	bool operator>(const Node& rhs) const
	{
		return data.occuranceCount > rhs.data.occuranceCount;
	}
	bool operator<(const Node& rhs) const
	{
		return data.occuranceCount < rhs.data.occuranceCount;
	}
	friend std::ostream& operator<<(std::ostream& out, const Node& element)
	{
		out << element.data;
		return out;
	}
};
