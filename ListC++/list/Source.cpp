#include <iostream>
#include <fstream>
#include "list.h"

int main()
{
	List list = List();
	list.push(5);
	list.push(3);
	list.push(1);

	list.print();

	int el = list.valueOflastElem();

}