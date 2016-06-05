/*
{
    "name": "Merge two linked lists",
    "desc": "http://www.practice.geeksforgeeks.org/probfunc-page.php?pid=700073",
    "tags": "lists,",
    "tests": {
    }
}
*/
#include <iostream>

using namespace std;

typedef struct node {
    int val;
    struct node * next;
}node;


void add_val(node ** d_head, node ** d_tail, int val) {
    node * temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;

    if(*d_head == NULL)
        *d_head = temp;
    else
        (*d_tail)->next = temp;
    *d_tail = temp;

}

node* merge_lists(node ** d_head1, node ** d_head2) {
    node * head = NULL, *temp = NULL;
    while(*d_head1 != NULL && *d_head2 != NULL) {
        if((*d_head1)->val < (*d_head2)->val) {
            temp = *d_head1;
            *d_head1=temp->next;
            temp->next = head;
            head = temp;
        } else {
            temp = *d_head2;
            *d_head2 = temp->next;
            temp->next = head;
            head = temp;
        }
    }
    while( *d_head1 != NULL) {
        temp=*d_head1;
        *d_head1=temp->next;
        temp->next = head;
        head = temp;
    }
    while( *d_head2 != NULL) {
        temp=*d_head2;
        *d_head2=temp->next;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main() {
    int T, first, second, val;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> first >> second;
        node *head1 = NULL,
             *head2 = NULL,
             *tail1 = NULL,
             *tail2 = NULL;

        for (int j = 0; j < first; ++j) {
            cin >> val;
            add_val(&head1, &tail1, val);
        }
        for (int k = 0; k < second; ++k) {
            cin >> val;
            add_val(&head2, &tail2, val);
        }
        node * h1 = merge_lists(&head1, &head2);
        while(h1 != NULL) {
            cout << h1->val << " ";
            h1 = h1->next;
        }
        cout << endl;
    }

return 0;
}
