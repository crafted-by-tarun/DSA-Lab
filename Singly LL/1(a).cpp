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

    // Insert at beginning
    void insertBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
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

    s.insertBeginning(30);
    s.insertBeginning(20);
    s.insertBeginning(10);

    s.display();  // Output: 10 20 30
}
