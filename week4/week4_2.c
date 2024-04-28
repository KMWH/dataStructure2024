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

void print_ListNode(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main()
{
	ListNode* head = NULL;
	for (int i = 10; i <= 30; i += 10) {
		head = insert_first(head, i);
		print_ListNode(head);
	}
	printf("리스트에서 %d을 찾았습니다.", search_ListNode(head, 30)->data);

	return 0;
}