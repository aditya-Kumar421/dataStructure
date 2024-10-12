#include <iostream>
#include <stack>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL  || left == right) return head;
        stack<int> st;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode* temp = prev->next;
        for (int i = left; i <= right; i++) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = prev->next;
        while (!st.empty()) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return dummy->next;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.reverseBetween(head, 2, 4);

    cout << "Reversed between position 2 and 4: ";
    printList(result);

    return 0;
}