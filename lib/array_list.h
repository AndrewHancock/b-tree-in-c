#include "element.h"

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_


struct array_list {
	int capacity;
	int size;
	struct element **elements;
};

struct array_list *create_new_array_list_with_capacity(int initial_capacity) {
	struct array_list *new_list = malloc(sizeof(struct array_list));
	new_list->size = 0;
	new_list->capacity = initial_capacity;
	new_list->elements = malloc(sizeof(struct element *) * initial_capacity);

	return new_list;
}

/*
 * Invariant: new_capacity is greater than old capacity.
 */
void grow_capcity(struct array_list *list, int new_capacity) {
	struct element **elements;
	int i;
	elements = malloc(sizeof(struct element*) *new_capacity);

	for(i = 0; i < list->capacity; i++) {
		elements[i] = list->elements[i];
	}
	free(list->elements);
	list->elements = elements;
	list->capacity = new_capacity;
}

void ensure_capacity(struct array_list *list) {
	if(list->size + 1 > list->capacity) {
		grow_capcity(list, list->capacity + 1);
	}
}
void swap(struct element **elements, int a, int b) {
	struct element *tmp;
	tmp = elements[a];
	elements[a] = elements[b];
	elements[b] = tmp;
}

void insert_into_array_list_sorted(struct array_list *list, struct element *new_element, compare_keys compare_fun) {
	int i;
	if(list->size == 0) {
		*list->elements = new_element;
	}
	else {
		ensure_capacity(list);
		list->elements[list->size] = new_element;
		for (i = list->size -1;
				i >= 0
						&& compare_fun(list->elements[i]->key,
								list->elements[i + 1]->key) > 0; i--) {
			swap(list->elements, i, i + 1);
		}
	}
	list->size++;
}


#endif
