#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* temp = head;
        while (temp != nullptr) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    Node* addOne(Node* head) {
        head = reverse(head);
        int carry = 1;
        Node* temp = head;

        while (temp != nullptr) {
            temp->data += carry;
            if (temp->data < 10) {
                carry = 0;
                break;
            } else {
                carry = 1;
                temp->data = 0;
            }
            temp = temp->next;
        }

        if (carry) {
            Node* newNode = new Node(1);
            head = reverse(head);
            newNode->next = head;
            return newNode;
        }

        head = reverse(head);
        return head;
    }
};

Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution solution;

    int arr[] = {1, 9, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, n);

    cout << "Original List: ";
    printLinkedList(head);

    head = solution.addOne(head);

    cout << "After adding one: ";
    printLinkedList(head);

    return 0;
}
