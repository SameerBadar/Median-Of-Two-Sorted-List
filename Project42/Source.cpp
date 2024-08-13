#include<iostream>
#include"Node.h"
using namespace std;
Node* insertValues(Node*);
void display(Node*);
int main() {
	Node* arr1 = nullptr;
	Node* arr2 = nullptr;
	cout << "Enter List 1 Elements " << endl;
	arr1 = insertValues(arr1);
	cout << endl;
	cout << "Enter List 2 Elements " << endl;
	arr2 = insertValues(arr2);
arr1 = arr1->sortArray(arr1);
arr2 = arr2->sortArray(arr2);
cout << endl;
double median = arr1->findMedianSortedArrays(arr1, arr2);
cout << "Median Of Both Array Is : " << median << endl;
cout << endl;
	return 0;
}
Node* insertValues(Node* head) {
	int value = 0;
	while (value != -1) {
		cout << "Enter Value or Press -1 To Exit " << endl;
		cin >> value;
		if(value!=-1){
			if (head == nullptr) {
				head = new Node(value);
			}
			else {
			Node* temp = new Node(value);
			temp->next = head;
			head->previous = temp;
			head = temp;
			}
		}
	}
	return head;
}
void display(Node* head) {
	if (head!= nullptr) {
		cout << head->value << endl;
		display(head->next);
	}
	return;
}