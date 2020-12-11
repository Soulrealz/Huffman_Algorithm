#include "MinHeap.h"

Node MinHeap::top() const
{
	if (heapVector.empty())
		throw std::out_of_range("MinHeap.h - top() - Empty heap, cannot access element.");

	return heapVector[0];
}

void MinHeap::pop()
{
	if (heapVector.empty())
		throw std::out_of_range("MinHeap.h - pop() - Empty heap, nothing to pop.");

	heapVector[0] = heapVector[heapVector.size() - 1];
	heapVector.pop_back();
	heapDown(0);
}
void MinHeap::push(const Node& element)
{
	std::size_t size = heapVector.size();
	heapVector.emplace_back(element);
	heapUp(size);
}

void MinHeap::print() const
{
	std::size_t size = heapVector.size();
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << heapVector[i];
	}
}

void MinHeap::heapDown(const std::size_t& index)
{
	std::size_t size = heapVector.size();
	std::size_t leftChild = 2 * index + 1;
	std::size_t rightChild = 2 * index + 2;

	//when element is leaf
	if (leftChild >= size)
		return;

	std::size_t minIndex = index;
	if (compare(heapVector[minIndex], heapVector[leftChild]))
		minIndex = leftChild;

	if ((rightChild < size) && compare(heapVector[minIndex], heapVector[rightChild]))
		minIndex = rightChild;

	if (minIndex != index)
	{
		swap(heapVector[minIndex], heapVector[index]);
		heapDown(minIndex);
	}
}
void MinHeap::heapUp(const std::size_t& index)
{
	if (index == 0)
		return;

	std::size_t parentIndex = (index - 1) / 2;

	if (compare(heapVector[parentIndex], heapVector[index]))
	{
		swap(heapVector[parentIndex], heapVector[index]);
		heapUp(parentIndex);
	}
}
void MinHeap::heapify()
{
	std::size_t size = heapVector.size();
	for (std::size_t index = size - 1; index >= 0; --index)
	{
		heapDown(index);
	}
}

void MinHeap::swap(Node& lhs, Node& rhs)
{
	Node tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}


