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

    // Insert at beginning
    void insertFirst(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    // Insert at end
    void insertLast(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    // Insert after specific value
    void insertAfter(int key, int x) {
        Node* t = head;
        while(t && t->data != key) t = t->next;
        if(!t) { cout << "Key not found!\n"; return; }

        Node* n = new Node(x);
        n->next = t->next;
        n->prev = t;

        if(t->next) t->next->prev = n;
        t->next = n;
    }

    // Insert before specific value
    void insertBefore(int key, int x) {
        if(!head) return;

        // If key is at head
        if(head->data == key) {
            insertFirst(x);
            return;
        }

        Node* t = head;
        while(t && t->data != key) t = t->next;
        if(!t) { cout << "Key not found!\n"; return; }

        Node* n = new Node(x);
        n->next = t;
        n->prev = t->prev;

        t->prev->next = n;
        t->prev = n;
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

    dll.insertFirst(20);
    dll.insertLast(40);
    dll.insertAfter(20, 30);
    dll.insertBefore(40, 35);

    dll.display();
}
