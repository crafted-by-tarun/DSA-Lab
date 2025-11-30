#include <bits/stdc++.h>
using namespace std;

class SLL {
public:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(NULL) {}
    };

    Node* head = NULL;

    // Insert at end
    void insertEnd(int x) {
        Node* n = new Node(x);

        if(!head) {
            head = n;
            return;
        }

        Node* t = head;
        while(t->next) t = t->next;

        t->next = n;
    }

    void display() {
        Node* t = head;
        while(t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    SLL s;

    s.insertEnd(10);
    s.insertEnd(20);
    s.insertEnd(30);

    s.display();  // Output: 10 20 30
}
