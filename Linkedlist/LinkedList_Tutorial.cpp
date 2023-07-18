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
    SinglyLinkListNode *insertNodeAtPosition(SinglyLinkListNode *head, int data, int pos)
    {
        SinglyLinkListNode *node = new SinglyLinkListNode(data);
        if (head == NULL)
            return node;
        if (!pos)
        {
            node->next = head;
            return node;
        }
        SinglyLinkListNode *temp;
        temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        node->next = temp->next;
        temp->next = node;
        return head;
    }
    SinglyLinkListNode *deleteNode(SinglyLinkListNode *head, int pos)
    {
        SinglyLinkListNode *temp;
        temp = head;
        if (!temp || !temp->next)
            return NULL;
        if (!pos)
            return temp->next;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
    SinglyLinkListNode *reverse(SinglyLinkListNode *head)
    {
        SinglyLinkListNode *prev, *curr, *next;
        prev = NULL;
        curr = next = head;
        while (next)
        {
            curr = next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
    bool compare_lists(SinglyLinkListNode *head1, SinglyLinkListNode *head2)
    {
        SinglyLinkListNode *temp1, *temp2;
        temp1 = head1;
        temp2 = head2;
        while (temp1 && temp2)
        {
            if (temp1->data == temp2->data)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
                return false;
        }
        return !(temp1 || temp2);
    }
    void reversePrint_estack(SinglyLinkListNode *head)
    {
        SinglyLinkListNode *temp;
        temp = head;
        if (temp == NULL)
            return;
        stack<int> st;
        while (temp)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        while (!st.empty())
        {
            cout << st.top() << '\n';
            st.pop();
        }
    }
    void rev(SinglyLinkListNode *head)
    {
        if (head == NULL)
            return;
        rev(head->next);
        cout << head->data << '\n';
    }
    void reversePrint_istack(SinglyLinkListNode *head)
    {
        SinglyLinkListNode *temp;
        temp = head;
        rev(temp);
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

    /*
    #Input format
    --------
    t
    n
    l_1
    l_2
    ...
    l_n
    x y
    --------
    */
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
            SinglyLinkListNode *llist_head = llist->insertNodeAtTail(llist->head, llist_item);
            llist->head = llist_head;
            // llist->insertNodeAtTail(llist->head, llist_item); /*I don't why this doesn't work*/
        }
        int data, pos;
        cin >> data >> pos;
        SinglyLinkListNode *llist_head = llist->insertNodeAtPosition(llist->head, data, pos);
        llist->head = llist_head;
        int delpos;
        cin >> delpos;
        SinglyLinkListNode *llist_head1 = llist->deleteNode(llist->head, delpos);
        llist->head = llist_head1;
        llist->printLinkedList(llist->head);
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}
