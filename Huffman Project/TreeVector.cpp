#include "TreeVector.h"

void TreeVector::pop()
{
	if (heapVector.empty())
		throw std::out_of_range("TreeVector.h - pop() - Empty vect, nothing to pop.");

	heapVector[0] = heapVector[heapVector.size() - 1];
	heapVector.pop_back();
}
void TreeVector::push(const Node& element)
{
	std::size_t size = heapVector.size();
	heapVector.emplace_back(element);
}

void TreeVector::print() const
{
	std::size_t size = heapVector.size();
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << heapVector[i];
	}
}

void TreeVector::sort()
{
	std::sort(heapVector.begin(), heapVector.end(), [](Node a, Node b) { return a.data.occuranceCount < b.data.occuranceCount; });
}


