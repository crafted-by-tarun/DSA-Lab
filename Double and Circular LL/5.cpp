#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

bool isCircular(Node* head) {
    if(!head) return false;
    Node* t = head->next;

    while(t && t != head)
        t = t->next;

    return (t == head);
}

int main() {
    // Example 1: Circular list
    Node* head1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    head1->next = n2;
    n2->next = n3;
    n3->next = head1;  // circular

    cout << "List 1 is circular? " << (isCircular(head1) ? "Yes" : "No") << endl;

    // Example 2: Non-circular list
    Node* head2 = new Node(1);
    head2->next = new Node(2);

    cout << "List 2 is circular? " << (isCircular(head2) ? "Yes" : "No") << endl;
}
