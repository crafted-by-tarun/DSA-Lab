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
        if(!head) head = n;
        else {
            Node* t = head;
            while(t->next) t = t->next;
            t->next = n;
        }
    }

    int search(int key) {
        int pos = 1;
        Node* t = head;

        while(t) {
            if(t->data == key)
                return pos;
            pos++;
            t = t->next;
        }
        return -1;
    }
};

int main() {
    SLL s;
    s.insertEnd(10);
    s.insertEnd(20);
    s.insertEnd(30);

    int pos = s.search(20);
    if(pos == -1) cout << "Not found\n";
    else cout << "Found at position " << pos << endl;
}
