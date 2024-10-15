#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* findNode(ListNode* temp, int k) {
        k = k - 1;
        while (k > 0 && temp != NULL) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* newHead = NULL;

        while (temp != NULL) {
            ListNode* kthNode = findNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* reversedGroup = reverse(temp);

            if (prevNode == NULL) {
                newHead = reversedGroup;
            } else {
                prevNode->next = reversedGroup;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return newHead;
    }
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    int k = 3;
    ListNode* newHead = solution.reverseKGroup(head, k);

    cout << "Reversed List in Groups of " << k << ": ";
    printList(newHead);

    return 0;
}
