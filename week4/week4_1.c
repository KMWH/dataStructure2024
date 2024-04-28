// 202112304 김원호

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct {
	element data;
	ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, value);
	//node->data = value;
	node->link = head;
	head = node;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* remove_first(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* removed;
	removed = head;
	head = head->link;
	free(removed);
	return head;
}

ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s->", p->data);
	}
	printf("NULL\n");
}

int main()
{
	ListNode* head = NULL;
	head = insert_first(head, (char*)"APPLE");
	print_list(head);
	head = insert_first(head, (char*)"KIWI");
	print_list(head);
	head = insert_first(head, (char*)"BANANA");
	print_list(head);
	return 0;
}
