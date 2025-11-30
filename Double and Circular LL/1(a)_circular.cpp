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

    // Insert at first
    void insertFirst(int x) {
        Node* n = new Node(x);

        if(!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* t = head;
        while(t->next != head) t = t->next;

        n->next = head;
        t->next = n;
        head = n;
    }

    // Insert at last
    void insertLast(int x) {
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

    // Insert after a specific node
    void insertAfter(int key, int x) {
        if(!head) return;

        Node* t = head;
        do {
            if(t->data == key) {
                Node* n = new Node(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while(t != head);

        cout << "Key not found!\n";
    }

    // Insert before a specific node
    void insertBefore(int key, int x) {
        if(!head) return;

        // If key is head
        if(head->data == key) {
            insertFirst(x);
            return;
        }

        Node* t = head;
        Node* prev = NULL;

        do {
            prev = t;
            t = t->next;

            if(t->data == key) {
                Node* n = new Node(x);
                n->next = t;
                prev->next = n;
                return;
            }
        } while(t != head);

        cout << "Key not found!\n";
    }

    void display() {
        if(!head) return;
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while(t != head);
        cout << endl;
    }
};

int main() {
    CLL c;

    c.insertFirst(20);
    c.insertLast(40);
    c.insertAfter(20, 30);
    c.insertBefore(40, 35);

    c.display();
}
