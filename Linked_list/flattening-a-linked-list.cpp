#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
private:
    Node* convert(vector<int>& arr) {
        if (arr.size() == 0) return NULL;
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = temp->bottom;
        }
        return head;
    }

public:
    Node* flatten(Node* root) {
        vector<int> arr;
        Node* temp = root;
        while (temp != NULL) {
            Node* t2 = temp;
            while (t2 != NULL) {
                arr.push_back(t2->data);
                t2 = t2->bottom;
            }
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        root = convert(arr);
        return root;
    }
};

// Function to print the flattened list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Function to create a linked list with next and bottom pointers
Node* createMultiLevelList(vector<vector<int>>& data) {
    if (data.empty()) return NULL;

    Node* head = new Node(data[0][0]);
    Node* temp = head;

    // Create next-level nodes
    for (int i = 1; i < data.size(); i++) {
        Node* newNode = new Node(data[i][0]);
        temp->next = newNode;
        temp = newNode;
    }

    // Create bottom-level nodes
    temp = head;
    for (int i = 0; i < data.size(); i++) {
        Node* bottomTemp = temp;
        for (int j = 1; j < data[i].size(); j++) {
            Node* newNode = new Node(data[i][j]);
            bottomTemp->bottom = newNode;
            bottomTemp = bottomTemp->bottom;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<vector<int>> data = {
        {5, 7, 8, 30},
        {10, 20},
        {19, 22, 50},
        {28, 35, 40, 45}
    };

    Node* root = createMultiLevelList(data);

    cout << "Original Multi-level List: " << endl;
    Node* temp = root;
    while (temp != NULL) {
        printList(temp);
        temp = temp->next;
    }

    Solution solution;
    Node* flattenedList = solution.flatten(root);

    cout << "Flattened List: " << endl;
    printList(flattenedList);

    return 0;
}
