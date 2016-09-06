#include <stdlib.h>

#ifndef ELEMENT_H_
#define ELEMENT_H_

typedef int (*compare_keys)(const void *, const void *);

struct element {
	void *key;
	void *value;
};

struct element * create_element(void *key, void *value){
	struct element *new_element;
	new_element = malloc(sizeof(struct element));
	new_element->key = key;
	new_element->value = value;
	return new_element;
}

int compare_elements(const struct element *left, const struct element *right, const compare_keys compare_fun){
	return compare_fun(left->key, right->key);
}

#endif
