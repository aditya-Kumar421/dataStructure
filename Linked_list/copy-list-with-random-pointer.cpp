#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;
        map<Node*, Node*> mpp;

        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Node value: " << temp->val;
        if (temp->random != nullptr)
            cout << ", Random points to: " << temp->random->val;
        else
            cout << ", Random points to: null";
        cout << endl;
        temp = temp->next;
    }
}

Node* createList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    head->random = third;
    second->random = head;
    third->random = second;

    return head;
}

int main() {
    Node* head = createList();

    cout << "Original List:" << endl;
    printList(head);

    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedList);

    return 0;
}
