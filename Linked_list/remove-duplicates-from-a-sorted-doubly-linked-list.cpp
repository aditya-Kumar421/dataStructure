#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            Node* newNode = temp->next;
            while (newNode != nullptr && temp->data == newNode->data) {
                Node* duplicate = newNode;
                newNode = newNode->next;
                free(duplicate);
            }
            temp->next = newNode;
            if (newNode) newNode->prev = temp;
            temp = newNode;
        }
        return head;
    }
};

Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, n);
    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
