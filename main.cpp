#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//define a structure
struct Car {
	string id;
	Car* next;
};

void appendCar(Car*& head, Car*& tail, string id);
void printTrain(Car*& head);

int main() {
	Car* head = NULL, * tail = NULL;//create the null node first.
	int n;//length of the train
	cin >> n;
	string id;
	for (int i = 0; i < n; i++) {
		cin >> id;
		appendCar(head, tail, id);
	}
	printTrain(head);

	return 0;
}

void appendCar(Car*& head, Car*& tail, string id)
{
	Car* p = new Car;//new car node
	p->id = id;//the value of this new node
	p->next = NULL;//let the next node is null
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;//if the linked list is not empty, the next-pointer of the current tail node is set the the new node;
		tail = p;
	}
}

void printTrain(Car*& head) {
	Car* current = head;
	while (current != NULL) {
		if (current->next != NULL) {
			cout << current->id << ", ";
		}
		else {
			cout << current->id;
		}
		current = current->next;
	}
}
