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

void MinHeap::heapify(std::size_t size, const std::size_t& index)
{
	std::size_t maxIndex = index;
	std::size_t left = 2 * index + 1;
	std::size_t right = 2 * index + 2;

	if ((left < size) && (heapVector[left] > heapVector[maxIndex]))
		maxIndex = left;

	if ((right < size) && (heapVector[right] > heapVector[maxIndex]))
		maxIndex = right;

	if (maxIndex != index)
	{
		swap(heapVector[maxIndex], heapVector[index]);
		heapify(size, maxIndex);
	}
}
void MinHeap::heapUp(const std::size_t& index)
{
	if (index == 0)
		return;

	std::size_t parentIndex = (index - 1) / 2;

	if (heapVector[parentIndex] > heapVector[index])
	{
		swap(heapVector[parentIndex], heapVector[index]);
		heapUp(parentIndex);
	}
}
void MinHeap::sort()
{
	std::size_t size = heapVector.size();
	int sz = size;
	if ((sz / 2) - 1 > 0)
	{
		for (std::size_t index = (size / 2) - 1; index > 0; --index)
		{
			heapify(size, index);
		}
	}

	if (sz - 1 > 0)
	{
		for (std::size_t index = size - 1; index > 0; --index)
		{
			swap(heapVector[0], heapVector[index]);
			heapify(index, 0);
		}
	}
}

void MinHeap::swap(Node& lhs, Node& rhs)
{
	Node tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}


