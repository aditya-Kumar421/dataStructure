#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    int countNodesinLoop(Node *head) {
        if (head == nullptr || head->next == nullptr) return 0;

        map<Node*, int> mpp;
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (mpp.find(temp) != mpp.end()) {
                return position - mpp[temp];
            }
            mpp[temp] = position;
            temp = temp->next;
            position++;
        }
        return 0; 
    }
};

//Tortoise and hare algorithm based:
/*
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        if(head == nullptr || head->next == nullptr) return 0;
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                int cnt = 1;
                fast = fast->next;
                while(slow != fast){
                    cnt++;
                    fast = fast->next;
                }
                return cnt;
            }
        }
        return 0;
    }
};
*/

Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void createLoop(Node* head, int pos) {
    if (pos == -1) return;

    Node* loopStart = nullptr;
    Node* current = head;
    int index = 0;

    while (current->next != nullptr) {
        if (index == pos) loopStart = current;
        current = current->next;
        index++;
    }

    current->next = loopStart;
}

int main() {
    Solution solution;

    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createLinkedList(arr, 5);

    createLoop(head, 2); 

    int loopLength = solution.countNodesinLoop(head);
    if (loopLength > 0) {
        cout << "Loop detected with length: " << loopLength << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
