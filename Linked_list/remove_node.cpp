#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    
    for (int i = 1; i < size; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    return head;
}

int main() {
    int arr[] = {4, 5, 1, 9};
    ListNode* head = createList(arr, 4);

    cout << "Original List: ";
    printList(head);

    ListNode* nodeToDelete = head->next; 

    Solution solution;
    solution.deleteNode(nodeToDelete);

    cout << "After Deleting Node with Value 5: ";
    printList(head); 
    return 0;
}