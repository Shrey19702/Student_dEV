#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

void printLL(struct Node* head){
	struct Node* p = head;
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int size(Node* head){
	if(head == NULL) return 0;

	int res = 1;
	Node* ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
		res++;
	}
	return res;
}

void addElements(struct Node* head, vector<int> v){
	for(auto element: v){
		struct Node* ptr;
		ptr = (struct Node*)malloc(sizeof(struct Node));
		head->next = ptr;
		ptr->data = element;
		head = ptr;
	}
    head->next = NULL;
}

Node* deleteAt(Node* &head, int k){
	if(head == NULL) return head;
	if(k == 0){
		 head = head->next;
		 return head;
	}

	Node* ptr = head;
	Node* ptr2 = ptr->next->next;
	int count = 0;
	while(count != k - 1){
		ptr = ptr->next;
		ptr2 = ptr->next->next;
		count++;
	}
	ptr->next = ptr2;
	return head;
}

void deleteThisNode(struct Node* n){
	struct Node* d = n->next;
	n->data = d->data;
	n->next = d->next;
	free(d);
}

Node* reverse(Node* &head){
	if(head == NULL || head->next == NULL) return head;

	Node* cur = head;
	Node* prev = NULL;
	Node* nex = head->next;

	while(cur){
		cur->next = prev;
		prev = cur;
		cur = nex;
		if(nex) nex = nex->next;
	}
	head = prev;
	return head;
}

Node* reverseByK(Node* head, int k){
    Node* cur = head;
    Node* prev = NULL;
    Node* nex = head->next;
    for(int i=1;i<=k;i++){
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(nex) nex = nex->next;
    }
    head->next = cur;
    head = prev;
    return head;
}

Node* reverseK(Node* &head, int k){
    // reversing for first k:
    Node* prev = NULL;
    Node* cur = head;
    Node* nex;
    for(int i=1;i<=k && cur;i++){
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    /* old head = last, prev = new head, nex = k + 1 node. */
    if(nex) head->next = reverseK(nex, k);
    return prev;
}

int main()
{
	Node* head = new Node();
	head->data = 1; head->next = NULL;
    addElements(head, {2,3,4,5,6});
    printLL(head);
    // head = reverseK(head, 2);
    head = reverseByK(head, 3);
    printLL(head);

	return 0;
}
