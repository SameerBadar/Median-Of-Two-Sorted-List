#pragma once
struct Node
{
	Node() { value = 0; next = nullptr; previous = nullptr; }
	Node(const int _value) { value = _value; next = nullptr; previous = nullptr; }
	Node* mergeSort(Node*, Node*);
	Node* sortArray(Node*);
	double findMedianSortedArrays(Node*, Node*);
	int value = 0;
	Node* next = nullptr;
	Node* previous = nullptr;
};

