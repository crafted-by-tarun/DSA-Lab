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
        while(t->next != head)
            t = t->next;

        t->next = n;
        n->next = head;
    }

    int countNodes() {
        if(!head) return 0;

        int count = 0;
        Node* t = head;

        do {
            count++;
            t = t->next;
        } while(t != head);

        return count;
    }
};

int main() {
    CLL cll;

    cll.insert(5);
    cll.insert(10);
    cll.insert(15);
    cll.insert(20);

    cout << "Number of nodes in CLL = " << cll.countNodes() << endl;
}
