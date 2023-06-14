#include <iostream>
using namespace std;
struct Element {
	int number;
	Element* next;

	Element(int number) {
		this->number = number;
		this->next = NULL;
	}
};

class List {
	Element* head = NULL;
	
	Element* get_last() {
		Element* temp_head = head;
		if (!temp_head) {
			return NULL;
		}
		while (temp_head->next != NULL) {
			temp_head = temp_head->next;
		}
		return temp_head;
	}

	Element* find(int number) {
		Element* temp_head = head;
		if (!temp_head) {
			return NULL;
		}

		while (temp_head != NULL && temp_head->number != number) {
			temp_head = temp_head->next;
		}
		return temp_head;
	}

public:

	List() {
	}

	~List() {
		Element* temp_head = head;
		while (temp_head) {
			temp_head = head->next;
			free(head);
			head = temp_head;
		}
	}

	void push(int number) {
		if (!head) {
			head = new Element(number);
		}
		else {
			Element* last_elem = get_last();
			Element* obj = new Element(number);
			last_elem->next = obj;
		}
	}

	void print() {
		Element* temp_head = head;
		while (temp_head) {
			cout << temp_head->number << " ";
			temp_head = temp_head->next;
		}
		cout << "\n";
	}

	int valueOflastElem() {
		Element* temp_head = head;
		if (!temp_head) {
			return -1;
		}
		while (temp_head->next != NULL) {
			temp_head = temp_head->next;
		}
		return temp_head->number;
	}
};

