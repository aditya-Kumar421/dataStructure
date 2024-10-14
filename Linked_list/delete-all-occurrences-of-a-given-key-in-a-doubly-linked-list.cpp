#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp != nullptr) {
            if(temp->data == x) {
                if(temp == *head_ref) *head_ref = temp->next; 
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;
                free(temp);
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
    }
};

Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createList(arr, n);
    cout << "Original list: ";
    printList(head);
    
    Solution obj;
    obj.deleteAllOccurOfX(&head, 2);
    
    cout << "Modified list after deleting all occurrences of 2: ";
    printList(head);
    
    return 0;
}
