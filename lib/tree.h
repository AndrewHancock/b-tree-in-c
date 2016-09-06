#include <stdlib.h>
#include "node.h"
#ifndef TREE_H_
#define TREE_H_


struct tree {
	struct node *root;
};

struct tree *create_tree() {
	struct tree *new_tree;
	new_tree = malloc(sizeof(struct tree));
	new_tree->root = NULL;
	return new_tree;
}

void add_element_to_tree(struct tree *tree, struct element *new_element, compare_keys compare_fun) {
	struct node *curr_node;
	if(tree->root == NULL) {
		tree->root = create_node(1, compare_fun, new_element);
	}
	else {
		curr_node = tree->root;

		while(curr_node->element_count == MAX_CHILD_NODES) {
			// Handle case where node is full
		}

		add_element_to_node(curr_node, compare_fun, new_element);
	}
}



#endif
