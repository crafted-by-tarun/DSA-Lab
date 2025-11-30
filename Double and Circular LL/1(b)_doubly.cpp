#include <bits/stdc++.h>
using namespace std;

class DLL {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int x) : data(x), prev(NULL), next(NULL) {}
    };

    Node* head = NULL;

    void insertLast(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }

        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void deleteNode(int key) {
        if(!head) return;

        Node* t = head;

        // Case 1: delete head node
        if(t->data == key) {
            head = t->next;
            if(head) head->prev = NULL;
            delete t;
            return;
        }

        // Search for node
        while(t && t->data != key) t = t->next;

        if(!t) {
            cout << "Node not found!\n";
            return;
        }

        // Case 2: middle or last node
        if(t->prev) t->prev->next = t->next;
        if(t->next) t->next->prev = t->prev;

        delete t;
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
    DLL dll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);
    dll.insertLast(40);

    dll.deleteNode(30); // delete middle
    dll.deleteNode(10); // delete head
    dll.deleteNode(40); // delete last

    dll.display();
}
