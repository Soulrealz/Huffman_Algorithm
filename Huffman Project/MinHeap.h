#pragma once
#include <vector>
#include "Node.h"

class MinHeap
{
public:
	MinHeap() = default;
	MinHeap(const std::vector<Node>& other) : heapVector(other) { heapify(); }

	Node top() const;
	void pop();
	void push(const Node& element);

	std::size_t getSize() const { return heapVector.size(); }
	bool compare(Node& lhs, Node& rhs) { return lhs.data > rhs.data; }
	void print() const;

	Node& operator[](int index) { return heapVector[index]; }
private:
	std::vector<Node> heapVector;

	void heapDown(const std::size_t& index);
	void heapUp(const std::size_t& index);
	void heapify();

	void swap(Node& lhs, Node& rhs);
};