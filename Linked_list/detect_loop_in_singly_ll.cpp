#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        return false;
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

void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    
    ListNode* cycleStart = nullptr;
    ListNode* current = head;
    int index = 0;
    
    while (current->next != nullptr) {
        if (index == pos) cycleStart = current;
        current = current->next;
        index++;
    }
    
    current->next = cycleStart;
}

int main() {
    Solution solution;
    
    int arr[] = {3, 2, 0, -4};
    ListNode* head = createLinkedList(arr, 4);
    
    createCycle(head, 1);
    
    if (solution.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
