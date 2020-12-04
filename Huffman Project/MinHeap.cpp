#include "MinHeap.h"

template <typename T>
MinHeap<T>::MinHeap(const T* vect, const std::size_t& size)
{
	heapVector.reserve(size);
	for (std::size_t index = 0; index < size; ++index)
	{
		heapVector.emplace_back(vect[index]);
	}

	heapify();
}

template <typename T>
T MinHeap<T>::top() const
{
	if (heapVector.empty())
		throw std::out_of_range("MinHeap.h - top() - Empty heap, cannot access element.");

	return heapVector[0];
}

template <typename T>
void MinHeap<T>::pop()
{
	if (heapVector.empty())
		throw std::out_of_range("MinHeap.h - pop() - Empty heap, nothing to pop.");

	heapVector[0] = heapVector[heapVector.size() - 1];
	heapVector.pop_back();
	heapDown(0);
}

template <typename T>
void MinHeap<T>::push(const T& element)
{
	std::size_t size = heapVector.size();
	heapVector.emplace_back(element);
	heapUp(size);
}

template <typename T>
void MinHeap<T>::heapDown(const int& index)
{
	std::size_t size = heapVector.size();
	std::size_t leftChild = 2 * index + 1;
	std::size_t rightChild = 2 * index + 2;

	//when element is leaf
	if (leftChild >= size)
		return;

	int minIndex = index;
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
template <typename T>
void MinHeap<T>::heapUp(const int& index)
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

//Inspect .size() change
template <typename T>
void MinHeap<T>::heapify()
{
	for (int index = heapVector.size() - 1; index >= 0; --index)
	{
		heapDown(index);
	}
}

template <typename T>
void MinHeap<T>::swap(T& lhs, T& rhs)
{
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}


