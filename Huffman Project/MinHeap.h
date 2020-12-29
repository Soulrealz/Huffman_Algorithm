#pragma once
#include <vector>
#include "Node.h"

class MinHeap
{
public:
	MinHeap() = default;
	MinHeap(const std::vector<Node>& other) : heapVector(other) { sort(); }

	Node top() const;
	void pop();
	void push(const Node& element);

	std::size_t getSize() const { return heapVector.size(); }
	void print() const;

	Node& operator[](int index) { return heapVector[index]; }
	void sort();
private:
	std::vector<Node> heapVector;

	void heapify(std::size_t size, const std::size_t& index);
	void heapUp(const std::size_t& index);

	void swap(Node& lhs, Node& rhs);
};