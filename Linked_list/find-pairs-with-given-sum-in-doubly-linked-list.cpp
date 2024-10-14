#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* left = head;
        Node* right = head;
        while(right->next != nullptr) right = right->next;
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target){
                left = left->next;
            }
            else right = right->prev;
        }
        return ans;
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

void printPairs(const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    Node* head = createList(arr, n);
    Solution obj;
    
    vector<pair<int, int>> result = obj.findPairsWithGivenSum(head, target);
    cout << "Pairs with sum " << target << ": ";
    printPairs(result);
    
    return 0;
}
