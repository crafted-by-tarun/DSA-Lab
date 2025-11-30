#include <bits/stdc++.h>
using namespace std;

class DLL {
public:
    struct Node {
        char data;
        Node* prev;
        Node* next;
        Node(char x) : data(x), prev(NULL), next(NULL) {}
    };
    Node* head = NULL;

    void insert(char ch) {
        Node* n = new Node(ch);
        if(!head) { head = n; return; }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    bool isPalindrome() {
        if(!head) return true;

        Node* left = head;
        Node* right = head;

        while(right->next) right = right->next;

        while(left != right && right->next != left) {
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DLL dll;

    string s = "level";
    for(char c : s) dll.insert(c);

    if(dll.isPalindrome())
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
}
