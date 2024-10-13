#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1;
            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
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

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

ListNode* findIntersection(ListNode* headA, ListNode* headB, int intersectVal) {
    ListNode* intersection = nullptr;
    ListNode* currentA = headA;
    while (currentA != nullptr) {
        if (currentA->val == intersectVal) {
            intersection = currentA;
            break;
        }
        currentA = currentA->next;
    }

    if (intersection != nullptr) {
        ListNode* currentB = headB;
        while (currentB->next != nullptr) {
            currentB = currentB->next;
        }
        currentB->next = intersection;
    }
    return intersection;
}

int main() {
    Solution solution;

    int arrA[] = {4, 1};
    int arrB[] = {5, 6, 1};
    int commonArr[] = {8, 4, 5};
    
    ListNode* headA = createLinkedList(arrA, 2);
    ListNode* headB = createLinkedList(arrB, 3);
    ListNode* commonList = createLinkedList(commonArr, 3);

    ListNode* intersectionNode = findIntersection(headA, commonList, 8);
    findIntersection(headB, commonList, 8);

    cout << "List A: ";
    printLinkedList(headA);
    
    cout << "List B: ";
    printLinkedList(headB);

    ListNode* result = solution.getIntersectionNode(headA, headB);
    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
