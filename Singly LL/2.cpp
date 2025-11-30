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

    // Count occurrences of a key
    int countOccurrences(int key) {
        int count = 0;
        Node* t = head;

        while(t) {
            if(t->data == key)
                count++;
            t = t->next;
        }

        return count;
    }

    // Delete all occurrences of key
    void deleteAll(int key) {
        while(head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* curr = head;
        Node* prev = NULL;

        while(curr) {
            if(curr->data == key) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
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

    // Example list
    s.insertEnd(1);
    s.insertEnd(2);
    s.insertEnd(1);
    s.insertEnd(3);
    s.insertEnd(1);
    s.insertEnd(1);

    int key = 1;

    int count = s.countOccurrences(key);
    cout << "Occurrences of " << key << " = " << count << endl;

    s.deleteAll(key);

    cout << "List after deletion: ";
    s.display();
}
