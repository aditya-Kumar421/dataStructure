#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy_node = new ListNode(-1);
        ListNode* curr = dummy_node;
        int carry = 0;
        while(t1 != NULL || t2 != NULL){
            int sum = carry;
            if(t1) sum = sum+ t1->val;
            if(t2) sum = sum+ t2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = curr->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return dummy_node->next;
    }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


ListNode* createList(int arr[], int size) {
    ListNode* dummy_node = new ListNode(-1); 
    ListNode* curr = dummy_node;  
    
    for (int i = 0; i < size; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    
    return dummy_node->next;
}

int main() {
    int arr1[] = {9, 9, 9,9,9, 9}; 
    int arr2[] = {9, 9, 9}; 
    
    ListNode* l1 = createList(arr1, 6);
    ListNode* l2 = createList(arr2, 3);
    
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    cout << "Resultant List: ";
    printList(result);

    return 0;
}