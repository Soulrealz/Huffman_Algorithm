#pragma once
#include <vector>

template <typename T>
class MinHeap
{
public:
	MinHeap() = default;
	MinHeap(const T* vect, const std::size_t& size);
	MinHeap(const std::vector<T>& other) : heapVector(other) { heapify(); }

	T top() const;
	void pop();
	void push(const T& element);
	std::size_t getSize() const { return heapVector.size(); }

	bool compare(T& lhs, T& rhs) { return lhs > rhs; }
private:
	std::vector<T> heapVector;

	void heapDown(const int& index);
	void heapUp(const int& index);
	void heapify();

	void swap(T& lhs, T& rhs);
};