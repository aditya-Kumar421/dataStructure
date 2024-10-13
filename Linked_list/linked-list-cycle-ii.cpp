#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//Brute force method of storing node into hash map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* temp = head;
        map<ListNode*, int> mpp;
        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            } 
            mpp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};

//Optimal solution using tortoise and hare method:
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            } 
        }
        return nullptr;
    }
};
*/


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

    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
