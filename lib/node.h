/*
 * node.h
 *
 *  Created on: Aug 29, 2016
 *      Author: andrew
 */

#include <stdarg.h>
#include "element.h"
#include "array_list.h"

#ifndef NODE_H_
#define NODE_H_

#define MAX_CHILD_NODES 4
#define MEDIAN_INDEX 2


struct node {
	int element_count;
	int child_count;
	struct array_list * element_list;
	struct array_list * child_nodes;
};

struct node * create_node(int count, compare_keys compare_fun, ...) {
	int i;
	va_list ap;
	struct node * new_node;
	va_start(ap, compare_fun);
	new_node = malloc(sizeof(struct node));
	new_node->element_list = create_new_array_list_with_capacity(MAX_CHILD_NODES - 1);
	new_node->child_count = 0;

	for(i = 0; i < count; i++) {
		insert_into_array_list_sorted(new_node->element_list, va_arg(ap, struct element *), compare_fun);
	}
	new_node->element_count = i;

	va_end(ap);
	return new_node;
}

/*
 * Precondition: node->element_count < MAX_NODES
 */
void add_element_to_node(struct node *node, compare_keys compare_fun, struct element *new_element) {
	if(node->element_list->size < MAX_CHILD_NODES -1) {
		insert_into_array_list_sorted(node->element_list, new_element, compare_fun);
	}
}

#endif
