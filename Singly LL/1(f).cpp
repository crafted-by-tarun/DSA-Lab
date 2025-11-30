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

    void deleteNode(int key) {
        if(!head) return;

        // delete head
        if(head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while(curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if(!curr) {
            cout << "Node not found!\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
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
    SLL s;
    s.insertEnd(10);
    s.insertEnd(20);
    s.insertEnd(30);
    s.insertEnd(60);

    s.deleteNode(60);

    s.display(); // 10 20 30
}
