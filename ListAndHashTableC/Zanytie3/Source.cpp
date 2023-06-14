#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#define SIZE 100;
using namespace std;
struct list
{
	int number;
	string name;
	list* next;
};

list* init_list(int number, string name)
{
	list* head = new list;//(list*)malloc(sizeof(list));
	head->number = number;
	head->name = name;
	head->next = NULL;
	return head;
}


list* get_last(list* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	while (head->next != NULL)
	{
		head = head->next;
	}
	return head;
}

void push_item(int number, string name, list* head)
{
	list* last_elem = get_last(head);
	if (last_elem != NULL)
	{
		list* element = (list*)malloc(sizeof(list));
		element->number = number;
		element->name = name;
		element->next = NULL;

		last_elem->next = element;
	}
}

list* remove_item(list* head, list* pointer)
{
	list* temp_pointer;
	list* temp;
	int zam = 0;
	if (pointer == head)
		zam = 1;
	while ((head->next != pointer) && (head != pointer))
	{
		head = head->next;
	}
	if (head->next == pointer)
	{
		temp = head->next;
		temp_pointer = temp->next;
		head->next = temp_pointer;
	}
	else
	{
		temp = head;
		temp_pointer = temp->next;
	}
	if (zam == 1)
		return temp_pointer;
	free(temp);
}

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

list* find(string Key, list* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	return head;
}

struct HashTable {
	list* mass[100];

	long hashFunc(string Key, int q, int p) {
		long index = 0;
		long d = 1;
		for (int i = 0; i < Key.length(); ++i)
		{
			index = (long)((index + (Key[i] - 'a' + 1) * d));
			d *= p;
		}
		return index % q;
	}

	int Insert(string Key, int Value, int q, int p) {
		int index = hashFunc(Key, q, p);
		if (mass[index] == NULL)
		{
			mass[index] = init_list(Value, Key);
			return 2;
		}
		else
		{
			int temp = index;
			index++;
			while (index != temp)
			{
				if (index == q)
				{
					index = 0;
				}
				if ((mass[index] == NULL) || (mass[index]->name == "rip"))
				{
					mass[index] = init_list(Value, Key);
					return 1;
				}
				index++;
			}
			return 0;
		}
	}
	int Delete(string Key, int q, int p) {
		int index = hashFunc(Key, q, p);
		list* head = mass[index];
		list* elem = find(Key, head);
		if (elem == NULL)
			return 0;
		if ((elem != NULL) && (elem->name == Key))
		{
			head->name = "rip";
			return 2;
		}
		else
		{
			int temp = index;
			index++;
			while (index != temp)
			{
				if (index == q)
				{
					index = 0;
				}
				list* elem2 = find(Key, mass[index]);
				if ((elem2 != NULL) && (elem2->name == Key))
				{
					mass[index]->name = "rip";
					return 1;
				}
				index++;
			}
			return -1;
		}
	}

	int Find(string Key, int q, int p) {
		int index = hashFunc(Key, q, p);
		list* head = mass[index];
		list* elem = find(Key, head);
		if (elem == NULL)
			return 0;
		if ((elem != NULL) && (elem->name == Key))
			return 2;
		else
		{
			int temp = index;
			index++;
			while (index != temp)
			{
				if (index == q)
				{
					index = 0;
				}
				list* elem2 = find(Key, mass[index]);
				if ((elem2 != NULL) && (elem2->name == Key))
					return 1;
				if (elem2 == NULL)
				{
					return -1;
				}
				index++;
			}
			return -1;
		}
	}
	int Find_hash(string Key, int q, int p) {
		int index = hashFunc(Key, q, p);
		list* head = mass[index];
		list* elem = find(Key, head);
		if (elem == NULL)
			return 0;
		if ((elem != NULL) && (elem->name == Key))
			return index;
		else
		{
			int temp = index;
			index++;
			while (index != temp)
			{
				if (index == q)
				{
					index = 0;
				}
				list* elem2 = find(Key, mass[index]);
				if ((elem2 != NULL) && (elem2->name == Key))
					return index;
				if ((elem2 == NULL) || ((elem2->name == "rip") && (Find(Key, q, p) != 1)))
				{
					return index;
				}
				index++;
			}
			return -1001;
		}
	}
	int Find_val(string Key, int q, int p)
	{

		int index = hashFunc(Key, q, p);
		list* head = mass[index];
		list* elem = find(Key, head);
		if (elem == NULL)
			return 0;
		if ((elem != NULL) && (elem->name == Key))
			return elem->number;
		else
		{
			int temp = index;
			index++;
			while (index != temp)
			{
				if (index == q)
				{
					index = 0;
				}
				list* elem2 = find(Key, mass[index]);
				if ((elem2 != NULL) && (elem2->name == Key))
					return elem->number;
				index++;
			}
			return -1001;
		}
	}

};

int main()
{
	HashTable ht = HashTable();
	int p = 5, q = 8;
	int n;
	int code = 0;
	int value;
	char str[100] = { 0 };
	char copy[100] = { 0 };
	char temp[100][100] = { 0 };
	scanf("%d", &q);
	scanf("%d", &p);
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		fgets(str, 100, stdin);
		for (int j = 0; j < strlen(str); ++j)
		{
			temp[i][j] = str[j];
		}
	}
	int ia = 4;
	int ja = 0;
	for (int i = 0; i < n; ++i)
	{
		if (temp[i][0] == 'P')
			code = 1;
		else if (temp[i][0] == 'G')
			code = 2;
		else if (temp[i][0] == 'D')
			code = 3;
		ia = 4;
		ja = 0;
		while ((temp[i][ia] != ' ') && (temp[i][ia] != '\0') && (temp[i][ia] != '\n') && (temp[i][ia] != '\r'))
		{
			copy[ja] = temp[i][ia];
			ja++;
			ia++;
		}
		int len = strlen(copy);
		string Key = string(copy);
		ia++;
		ja = 0;
		for (int ib = 0; ib < len; ib++)
		{
			copy[ib] = '\0';
		}
		while ((temp[i][ia] >= '0') && (temp[i][ia] <= '9'))
		{
			if (temp[i][ia] == ' ')
			{
				ia++;
			}
			else
			{
				copy[ja] = temp[i][ia];
				ia++;
				ja++;
			}
		}
		value = atoi(copy);
		int len2 = strlen(copy);
		for (int ib = 0; ib < len2; ib++)
		{
			copy[ib] = '\0';
		}
		int k = 1;
		if (code == 1)
		{
			int temp_hash = ht.hashFunc(Key, q, p);
			int result = ht.Insert(Key, value, q, p);
			int zam_hash = ht.Find_hash(Key, q, p);
			int temp_number = value;
			if (result == 2)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=PUT result=inserted value=" << temp_number << "\n";
			}
			else if (result == 1)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=PUT result=collision linear_probing=" << zam_hash << " value=" << temp_number << "\n";
			}
			else if (result == 0)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=PUT result=overflow\n";
			}
		}
		else if (code == 2)
		{
			int temp_hash = ht.hashFunc(Key, q, p);
			int result = ht.Find(Key, q, p);
			int zam_hash;
			int temp_number;
			if (result != 0)
			{
				zam_hash = ht.Find_hash(Key, q, p);
				if (result != -1)
					temp_number = ht.mass[zam_hash]->number;
			}
			if (result == 2)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=GET result=found value=" << temp_number << "\n";
			}
			else if (result == 1)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=GET result=collision linear_probing=" << zam_hash << " value=" << temp_number << "\n";
			}
			else if (result == -1)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=GET result=collision linear_probing=" << zam_hash << " value=no_key\n";
			}
			else if (result == 0)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=GET result=no_key\n";
			}
		}
		else if (code == 3)
		{
			int temp_hash = ht.hashFunc(Key, q, p);
			int result = ht.Delete(Key, q, p);
			int zam_hash;
			if (result != 0)
			{
				zam_hash = ht.Find_hash(Key, q, p);
			}
			if (result == 2)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=DEL result=removed\n";
			}
			else if (result == 1)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=DEL result=collision linear_probing=" << zam_hash << " value=removed\n";
			}
			else if (result == -1)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=DEL result=collision linear_probing=" << zam_hash << " value=no_key\n";
			}
			else if (result == 0)
			{
				cout << "key=" << Key << " hash=" << temp_hash << " operation=DEL result=no_key\n";
			}
		}
	}
	return 0;
}
