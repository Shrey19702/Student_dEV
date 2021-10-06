#include <bits/stdc++.h>
using namespace std;
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int dat, int position)
{
    SinglyLinkedListNode *t, *p;
    if (position == 0)
    {
        t = new SinglyLinkedListNode;
        t->data = dat;
        t->next = llist;
        llist = t;
        return llist;
    }
    else if (position > 0)
    {
        p = llist;
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
            if (p)
            {
                t = new SinglyLinkedListNode;
                t->data = dat;
                t->next = p->next;
                p->next = t;
            }
        }
         return llist;
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}