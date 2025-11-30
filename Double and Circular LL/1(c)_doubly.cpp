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

    bool search(int key) {
        Node* t = head;
        while(t) {
            if(t->data == key)
                return true;
            t = t->next;
        }
        return false;
    }
};

int main() {
    DLL dll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);

    int key = 20;

    if(dll.search(key))
        cout << "Node " << key << " found\n";
    else
        cout << "Node " << key << " not found\n";
}
