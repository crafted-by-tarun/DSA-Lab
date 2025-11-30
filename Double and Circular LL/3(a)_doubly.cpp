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

    void insert(int x) {
        Node* n = new Node(x);
        if(!head) {
            head = n;
            return;
        }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    int countNodes() {
        int count = 0;
        Node* t = head;
        while(t) {
            count++;
            t = t->next;
        }
        return count;
    }
};

int main() {
    DLL dll;

    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    cout << "Number of nodes in DLL = " << dll.countNodes() << endl;
}
