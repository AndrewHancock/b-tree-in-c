#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/tree.h"
#include "lib/element.h"
#include"lib/array_list.h"

int cmp_str(const void *left, const void * right)
{
	return strcmp((char *)left, (char *)right);
}

int cmp_int(const void *left, const void *right) {
	return (*(int *)left - *(int *)right);
}



void print_node(struct node *node) {
	print_list(node->element_list);
}
void print_tree(struct tree *tree) {
	print_list(tree->root->element_list);
}

void print_list(struct array_list *list) {
	int i;
	printf("(") ;
	if(list->size > 0) {
		printf("%d: %s", *(int *)list->elements[0]->key, (char *)list->elements[0]->value);
		for(i = 1; i < list->size; i++) {
			printf(", %d: %s", *(int *)list->elements[i]->key, (char *)list->elements[i]->value);
		}

	}
	printf(")");
}

void test_list() {
	struct array_list *list;
	int *key;
	list = create_new_array_list_with_capacity(3);
	key = malloc(sizeof(int));
	*key = 3;
	insert_into_array_list_sorted(list, create_element(key, "George"), cmp_int);
	print_list(list);
	key = malloc(sizeof(int));
	*key = 1;
	insert_into_array_list_sorted(list, create_element(key, "Andrew"), cmp_int);
	key = malloc(sizeof(int));
	*key = 4;
	insert_into_array_list_sorted(list, create_element(key, "Harold"), cmp_int);
	key = malloc(sizeof(int));
	*key = 2;
	insert_into_array_list_sorted(list, create_element(key, "Baron"), cmp_int);
	key = malloc(sizeof(int));
	*key = 0;
	insert_into_array_list_sorted(list, create_element(key, "<noname>"), cmp_int);
	key = malloc(sizeof(int));
	*key = 5;
	insert_into_array_list_sorted(list, create_element(key, "Ingrid"), cmp_int);



	print_list(list);

}

void test_tree() {
	struct element *test_element;
	struct tree *test_tree;
	int *key;
	key = malloc(sizeof(int));
	*key = 5;
	test_element = create_element(key, "A guy named fred.");

	test_tree = create_tree();
	add_element_to_tree(test_tree, test_element, cmp_str);
	key = malloc(sizeof(int));
	*key = 6;
	test_element = create_element(key, "A guy named george.");
	add_element_to_tree(test_tree, test_element, cmp_str);

	print_tree(test_tree);
}

int main(int argc, const char * argv[])
{
	printf("\n=======================\n");
	printf("===List Tests       ===\n");
	printf("=======================\n");
	test_list();

	printf("\n=======================\n");
	printf("===Tree Tests       ===\n");
	printf("=======================\n");

	test_tree();
	return 0;
}

