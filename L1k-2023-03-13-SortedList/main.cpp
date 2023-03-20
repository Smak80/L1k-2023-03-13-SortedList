#include "sorted_list.h"
#include <iostream>
using namespace std;

void show_list(sorted_list list, bool reversed = false);

void main()
{
	setlocale(LC_ALL, "");
	int a[] = {1, 8, 5, 3, -1, -54, 24, 3, 12, 0, 3, 7, -9};
	sorted_list lst;
	for (int i = 0; i<13; i++)
	{
		add(lst, a[i]);
	}
	show_list(lst);
	show_list(lst, true);
	int val;
	auto result = get(lst, -1, val);
	char s_val[20];
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте -1: " << ((result) ? s_val : "-") << endl;
	result = get(lst, 0, val);
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте 0: " << ((result) ? s_val : "-") << endl;
	result = get(lst, 3, val);
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте 3: " << ((result) ? s_val : "-") << endl;
	result = get(lst, 10, val);
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте 10: " << ((result) ? s_val : "-") << endl;
	result = get(lst, 12, val);
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте 12: " << ((result) ? s_val : "-") << endl;
	result = get(lst, 100, val);
	_itoa_s(val, s_val, 10);
	cout << "Значение на месте 100: " << ((result) ? s_val : "-") << endl;
	remove_all(lst, 3);
	remove_all(lst, 24);
	remove_all(lst, -54);
	remove_all(lst, 1111);
	show_list(lst);
	clear(lst);
}

void show_list(sorted_list list, bool reversed)
{
	auto* curr = (reversed) ? list.last : list.first;
	while (curr)
	{
		cout << curr->x << " ";
		curr = (reversed) ? curr->prev : curr->next;
	}
	cout << endl;
}