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

    void insertEnd(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
    }

    // Insert after a given value
    void insertAfter(int key, int x) {
        Node* t = head;
        while(t && t->data != key) t = t->next;

        if(!t) {
            cout << "Key not found!\n";
            return;
        }

        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
    }

    // Insert before a given value
    void insertBefore(int key, int x) {
        if(!head) return;

        // If key is head
        if(head->data == key) {
            Node* n = new Node(x);
            n->next = head;
            head = n;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while(curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if(!curr) {
            cout << "Key not found!\n";
            return;
        }

        Node* n = new Node(x);
        n->next = curr;
        prev->next = n;
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
    s.insertEnd(40);

    s.insertAfter(20, 30);   // 20 → 30 → 40
    s.insertBefore(40, 35);  // 30 → 35 → 40

    s.display();
}
