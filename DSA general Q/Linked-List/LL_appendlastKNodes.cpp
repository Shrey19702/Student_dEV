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

int LLsize(Node* head){
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

Node* appendlastKNodes(Node* &h, int k){
    if(k == 0) return h;
    int l = LLsize(h);
    Node* ptr = h;
    Node* ptr2 = h;
    int count = 1;
    while(count != l - k){
        ptr = ptr->next;
        count++;
    }
    while(ptr2->next){
        ptr2 = ptr2->next;
    }

    // return newHead, make l-k to NULL
    Node* newHead = ptr->next;
    ptr->next = NULL;

    // join last to head
    ptr2->next = h;
    return newHead;
}

int main()
{
	struct Node* head;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 1;
	head->next = NULL;

    // code
    addElements(head, {2,3,4,5,6,7,8});
    printLL(head);
    // cout << LLsize(head) << endl;
    head = appendlastKNodes(head, 4);
    printLL(head);
	return 0;
}
