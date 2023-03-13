#include "sorted_list.h"

void add(sorted_list*& list, int value)
{
	list_elem* new_el = new list_elem;
	new_el->x = value;
	if (!list->first) list->first = list->last = new_el;
	else
	{
		if (value <= list->first->x)
		{
			new_el->next = list->first;
			list->first->prev = new_el;
			list->first = new_el;
		} else if (value >= list->last->x)
		{
			new_el->prev = list->last;
			list->last->next = new_el;
			list->last = new_el;
		} else
		{
			auto* curr = list->first;
			while (curr->next->x < value)
			{
				curr = curr->next;
			}
			curr->next->prev = new_el;
			new_el->next = curr->next;
			curr->next = new_el;
			new_el->prev = curr;
		}
	}
}
