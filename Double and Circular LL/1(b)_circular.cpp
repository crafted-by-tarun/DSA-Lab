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

    void deleteNode(int key) {
        if(!head) return;

        Node* curr = head;
        Node* prev = NULL;

        // Case 1: head node delete
        if(curr->data == key) {

            // Only one node
            if(curr->next == head) {
                head = NULL;
                delete curr;
                return;
            }

            // Move to last node
            while(curr->next != head) curr = curr->next;

            // curr is last node
            curr->next = head->next;
            Node* temp = head;
            head = head->next;

            delete temp;
            return;
        }

        // Case 2: delete middle/last
        prev = head;
        curr = head->next;

        while(curr != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if(curr == head) {
            cout << "Node not found!\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
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

    c.insert(10);
    c.insert(20);
    c.insert(30);
    c.insert(40);

    c.deleteNode(30); // middle
    c.deleteNode(10); // head
    c.deleteNode(40); // last

    c.display();
}
