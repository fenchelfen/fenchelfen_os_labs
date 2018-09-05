#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node Node_t;

struct Node *LIST_ROOT = NULL;
unsigned int count = 0;

void print_list()
{
	Node_t *node;
	if ((node = LIST_ROOT) == NULL) return;
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/**
 * Creates a new node containing {@param data}
 * @return new_node A pointer to a new node, or NULL (if malloc fails)
 */
Node_t *create_node(int data)
{
	Node_t *new_node = (Node_t*) malloc(sizeof(Node_t));
	if (new_node == NULL) return NULL;
	new_node->data = data;
	new_node->next = NULL;
}

/**
 * Inserts a node containing {@param data}
 * {@return 0} if it works fine, or {@return 1} if adding a node twice 
 * @param list A linkedlist for insertion
 * @return Status code
 */
int insert_node(Node_t *node)
{
	Node_t *cur_node = LIST_ROOT;
	if (cur_node == NULL) LIST_ROOT = node;
	else {
		while (cur_node->next != NULL) {
			cur_node = cur_node->next;
			if (cur_node == cur_node->next)
				return 1;
		}
		cur_node->next = node;
	}
	++count;
	return 0;
}

/**
 * Searches for the first occurence of a node containing {@param data}
 * @return A pointer to a node, or NULL (if not found)
 */
Node_t *search(int data)
{
	Node_t *cur_node = LIST_ROOT;
	if (cur_node == NULL) return NULL;
	while (cur_node != NULL && cur_node->data != data)
		cur_node = cur_node->next;
	return cur_node;
}

/**
 * Removes a node
 * {@return 0} if everything works fine, {@return 1} if trouble 
 * @param list A linkedlist from which to remove
 * @return Status code
 */
int remove_node(Node_t *node)
{
	Node_t *cur_node = LIST_ROOT;
	if (node == LIST_ROOT) {
		node = node->next;
		free(node);
		return 0;
	}

	while (cur_node != NULL && cur_node->next != node)
		cur_node = cur_node->next;
	if (cur_node == NULL) return 1;

	cur_node->next = node->next;
	free(cur_node->next);
	--count;
	return 0;
}

int main()
{
	Node_t *newNode;
	newNode = create_node(3);
	insert_node(newNode);
	newNode = create_node(10);
	insert_node(newNode);
	newNode = create_node(2);
	insert_node(newNode);
	newNode = create_node(1);
	insert_node(newNode);
	print_list();

	remove_node(newNode);
	print_list();

	newNode = create_node(7);
	insert_node(newNode);
	print_list();

	return 0;
}
