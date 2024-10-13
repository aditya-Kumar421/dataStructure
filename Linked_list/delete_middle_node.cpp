#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode; 
        
        return head;
    }
};

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr, 5);

    cout << "Original list: ";
    printList(head);

    head = solution.deleteMiddle(head);

    cout << "List after deleting middle node: ";
    printList(head);

    return 0;
}
