#include <bits/stdc++.h>
using namespace std;

class CLL {
public:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(NULL) {}
    };

    Node* head = NULL;

    void insert(int x) {
        Node* n = new Node(x);
        if(!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* t = head;
        while(t->next != head) t = t->next;

        t->next = n;
        n->next = head;
    }

    void displayWithHeadTwice() {
        if(!head) return;

        Node* t = head;

        // Print entire circular list
        do {
            cout << t->data << " ";
            t = t->next;
        } while(t != head);

        // Print head again
        cout << head->data << endl;
    }
};

int main() {
    CLL cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    cll.displayWithHeadTwice();
}
