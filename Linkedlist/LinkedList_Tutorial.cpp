#include <bits/stdc++.h>
using namespace std;

// Inspiration from : HackerRank boilerplate code + Problems

class SinglyLinkListNode
{
public:
    int data;
    SinglyLinkListNode *next;
    SinglyLinkListNode(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class SinglyLinkList
{
public:
    // SinglyLinkListNode *node = new SinglyLinkListNode()
    SinglyLinkListNode *head, *tail;
    SinglyLinkList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    SinglyLinkListNode *insertNodeAtHead(SinglyLinkListNode *head, int data)
    {
        SinglyLinkListNode *node = new SinglyLinkListNode(data);
        if (head == NULL)
            head = node;
        else
        {
            node->next = head;
            head = node;
        }
        return head;
    }
    SinglyLinkListNode *insertNodeAtTail(SinglyLinkListNode *head, int data)
    {
        SinglyLinkListNode *node = new SinglyLinkListNode(data);
        if (head == NULL)
            head = node;
        else
        {
            SinglyLinkListNode *temp;
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = node;
        }
        return head;
    }
    void printLinkedList(SinglyLinkListNode *head)
    {
        if (head == NULL)
            return;
        SinglyLinkListNode *temp;
        temp = head;
        while (temp->next != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << "->NULL";
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        SinglyLinkList *llist = new SinglyLinkList();
        int llist_count;
        cin >> llist_count;
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < llist_count; i++)
        {
            int llist_item;
            cin >> llist_item;
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            SinglyLinkListNode *llist_head = llist->insertNodeAtHead(llist->head, llist_item);
            llist->head = llist_head;
            // llist->insertNodeAtTail(llist->head, llist_item); /*I don't why this doesn't work*/
        }
        llist->printLinkedList(llist->head);
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}
