#pragma once
#include "team.h"

struct list {
	team element;
	list* next;

	list(team new_team) {
		element = new_team;
		next = NULL;
	}
	
};

class List {
private:
	list* get_last() {
		list* temp_head = element;
		if (element == NULL)
		{
			return NULL;
		}

		while (temp_head->next != NULL)
		{
			temp_head = temp_head->next;
		}
		return temp_head;
	}

public:
	list* element;

	List() {
		
	}

	/*~List() {
		list* temp_next = element;
		while (element != NULL)
		{
			temp_next = element->next;
			if (element) {
				free(element);
			}
			element = temp_next;
		}
	}*/

	void push_item(team cur_team) {
		if (!element) {
		  element = new list(cur_team);
		}
		else {
			list* last_elem = get_last();
			list* obj = new list(cur_team);
			last_elem->next = obj;
		}
	}

	/*team LastAddedTeam() {
		list* temp_head = element;
		if (!temp_head) {
			return ;
		}
		while (temp_head->next != NULL) {
			temp_head = temp_head->next;
		}
		return temp_head->element;
	}*/

	list* find(string nameOfTeam) {
		list* temp_head = element;
		if (!temp_head) {
			return NULL;
		}

		while (temp_head != NULL && temp_head->element.name != nameOfTeam) {
			temp_head = temp_head->next;
		}
		return temp_head;
	}

};

//void foo() {
//	List l = List();
//	l.push(team());
//	l.push(team("sadf"));
//}

//list* get_last(list* head) {
//	if (head == NULL)
//	{
//		return NULL;
//	}
//
//	while (head->next != NULL)
//	{
//		head = head->next;
//	}
//	return head;
//}
//
//list* push_item(team element, list* head)
//{
//	if (head == NULL)
//	{
//		return new list(element);
//	}
//	list* last_elem = get_last(head);
//	list* obj = new list(element);
//	last_elem->next = obj;
//	return head;
//}

void free_list(list* head)
{
	list* temp_next = head->next;
	while (head != NULL)
	{
		temp_next = head->next;
		free(head);
		head = temp_next;
	}
}


void print_list(list* temp_head, FILE* fw, int win, int max_dif)
{
	if (temp_head == NULL)
	{
		fprintf(fw, "error\n");
	}
	while (temp_head != NULL)
	{
		if ((temp_head->element.score == win) && (temp_head->element.difference_of_goals == max_dif))
		{
			/*	print_name(fw, temp_head->code);*/
				/*cout << temp_head->element.name;*/
			int ia = 0;
			while (temp_head->element.name[ia])
			{
				fprintf(fw, "%c", temp_head->element.name[ia]);
				ia++;
			}
			fprintf(fw, " ");
			fprintf(fw, "%d ", temp_head->element.score);
			fprintf(fw, "%d\n", temp_head->element.difference_of_goals);
		}
		temp_head = temp_head->next;
	}
}

// rename
List change_list(List elem, team cur_team)
{
	list* element = NULL;element = elem.find(cur_team.name);
	if (element)
	{
		cout << cur_team.difference_of_goals << "\n";
		element->element.difference_of_goals += cur_team.difference_of_goals;
		element->element.score += cur_team.score;
	}
	else
	{
		elem.push_item(cur_team);
	}
	return elem;
}

