#pragma once
#include <vector>
#include <algorithm>
#include "Node.h"

class TreeVector
{
public:
	TreeVector() = default;
	TreeVector(const std::vector<Node>& other) : heapVector(other) { sort(); }

	void pop();
	void push(const Node& element);

	std::size_t getSize() const { return heapVector.size(); }
	void print() const;

	Node& operator[](int index) { return heapVector[index]; }
	void sort();
private:
	std::vector<Node> heapVector;
};