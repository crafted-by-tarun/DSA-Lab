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

    // Find middle using slow-fast pointer
    int findMiddle() {
        if(!head) return -1;

        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    SLL s;

    s.insertEnd(1);
    s.insertEnd(2);
    s.insertEnd(3);
    s.insertEnd(4);
    s.insertEnd(5);

    cout << "Middle element = " << s.findMiddle();
}
