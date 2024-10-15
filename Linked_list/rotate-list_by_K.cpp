#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        // Step 1: Calculate the length of the list
        ListNode* temp = head;
        int len = 1;
        while (temp->next != nullptr) {
            len++;
            temp = temp->next;
        }

        // Step 2: Form a circular linked list by connecting the last node to the head
        temp->next = head;

        // Step 3: Calculate the actual number of rotations needed (k % len)
        k = k % len;
        int remaining = len - k;

        // Step 4: Find the new tail node (the node just before the new head)
        temp = head;
        for (int i = 1; i < remaining; i++) {
            temp = temp->next;
        }

        // Step 5: Set the new head and break the cycle
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

// Function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example: create a list and rotate it
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    Solution solution;
    ListNode* rotatedHead = solution.rotateRight(head, k);

    cout << "Rotated list by " << k << " positions: ";
    printList(rotatedHead);

    return 0;
}
