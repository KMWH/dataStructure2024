#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode* link;
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

ListNode* reverse(ListNode* head) {
	if (head == NULL) return NULL;
	else {
		ListNode* p;
		ListNode* q;
		ListNode* r;
		p = head;
		q = NULL;
		while (p != NULL) {
			r = q;
			q = p;
			p = p->link;
			q->link = r;
		}
		return q;
	}
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	print_list(head);
	head = reverse(head);
	print_list(head);
	return 0;
}