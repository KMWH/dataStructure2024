#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = value;
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

ListNode* search_ListNode(ListNode* head, element value) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == value) {
			return p;
		}
	}
}

ListNode* concat_ListNode(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head2;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}

void print_ListNode(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	head1 = insert_first(head1, 30);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 10);
	print_ListNode(head1);

	head2 = insert_first(head2, 50);
	head2 = insert_first(head2, 40);
	print_ListNode(head2);

	head1 = concat_ListNode(head1, head2);
	print_ListNode(head1);

	return 0;
}