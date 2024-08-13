#include<iostream>
#include "Node.h"
using namespace std;
Node* Node::mergeSort(Node* arr1, Node* arr2) {
	if (!arr1)return arr2;
	if (!arr2) return arr1;
	
	Node* arr3 = nullptr;
	while (arr1 != nullptr && arr2 != nullptr) {
		if (arr1->value < arr2->value) {
			if (arr3 == nullptr) {
				arr3 = new Node(arr1->value);
			}
			else {
				Node* temp = new Node(arr1->value);
				arr3->next = temp;
				temp->previous = arr3;
				arr3 = temp;
			}
			arr1 = arr1->next;
		}
		else if (arr2->value < arr1->value) {
			if (arr3 == nullptr) {
				arr3 = new Node(arr2->value);
			}
			else {
				Node* temp = new Node(arr2->value);
				arr3->next = temp;
				temp->previous = arr3;
				arr3 = temp;
			}
			arr2 = arr2->next;
		}
	}

	//If There are Any Remaing Elements in any of Both List
	if (arr1 != nullptr) {
		while (arr1 != nullptr) {
			Node* temp = new Node(arr1->value);
			arr3->next = temp;
			temp->previous = arr3;
			arr3 = temp;
			arr1 = arr1->next;
		}
	}
	else if (arr2 != nullptr) {
		while (arr2 != nullptr) {
			Node* temp = new Node(arr2->value);
			arr3->next = temp;
			temp->previous = arr3;
			arr3 = temp;
			arr2 = arr2->next;
		}
	}
	return arr3;
}
Node* Node::sortArray(Node* arr) {
	Node* temp1 = arr;
	while (temp1 != nullptr) {
	Node* temp = temp1->next;
		while (temp != nullptr) {
			if (temp->value < temp1->value) {
				int tempStore = temp1->value;
				temp1->value = temp->value;
				temp->value = tempStore;
			}
			temp = temp->next;
		}
		temp1 = temp1->next;	
	}
	return arr;
}

double Node::findMedianSortedArrays(Node* arr1, Node* arr2) {
	Node* arr3 = mergeSort(arr1, arr2);
	//arr3 points to tail of the list
	Node* head = arr3;
	// finding Length and also reaching head position
	int l = 1;
	while (head->previous != nullptr) {
		l++;
		head = head->previous;
	}
	//head is now pointing at top

	if (arr3->value % 2 != 0) {
		// if n is odd means middle value is median
		int mid = 0;
		while (mid < l / 2) {
			head = head->next;
			mid++;
		}
		return head->value;
	}
	//else if n is even then we find average of middle and previous value and it will be median
	int mid = 0;
	while (mid < l / 2) {
		head = head->next;
		mid++;
	}
	double avg = ((head->value + head->previous->value) / 2.0);
	return avg;
}