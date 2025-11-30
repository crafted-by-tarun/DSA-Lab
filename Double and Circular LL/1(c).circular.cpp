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

    bool search(int key) {
        if(!head) return false;

        Node* t = head;

        do {
            if(t->data == key)
                return true;

            t = t->next;

        } while(t != head);

        return false;
    }
};

int main() {
    CLL cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    int key = 25;

    if(cll.search(key))
        cout << "Node " << key << " found\n";
    else
        cout << "Node " << key << " not found\n";
}
