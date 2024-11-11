#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        DLLNode* temp = head;
        DLLNode* pretemp = nullptr;
        
        while (temp != nullptr) {
            temp->prev = temp->next;
            temp->next = pretemp;
            pretemp = temp;
            temp = temp->prev;
        }
        head = pretemp;
        return head;
    }
};

void printList(DLLNode* head) {
    DLLNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

DLLNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    DLLNode* head = new DLLNode(arr[0]);
    DLLNode* curr = head;
    
    for (int i = 1; i < n; i++) {
        DLLNode* newNode = new DLLNode(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

int main() {
    Solution solution;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    DLLNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    head = solution.reverseDLL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
