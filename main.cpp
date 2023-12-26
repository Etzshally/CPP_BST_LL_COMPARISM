#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int key;
    string value;
    Node* left;
    Node* right;

    Node(int k, const string& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Linked List Node
struct ListNode {
    int key;
    string value;
    ListNode* next;

    ListNode(int k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Private recursive function to insert a node into the BST
    Node* insert(Node* node, int key, const string& value) {
        if (node == nullptr) {
            return new Node(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        }

        return node;
    }

public:
    BST() : root(nullptr) {}

    // Public function to insert a node into the BST
    void insert(int key, const string& value) {
        root = insert(root, key, value);
    }
};

// Linked List class
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the linked list
    void insert(int key, const string& value) {
        ListNode* newNode = new ListNode(key, value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

int main() {
    ifstream file("your_excel_sheet.csv"); // Change this to your Excel sheet file name

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    BST bst;
    LinkedList linkedList;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string key_str, value;
        getline(ss, key_str, ',');
        getline(ss, value, ',');

        int key = stoi(key_str);

        // Insert into BST
        bst.insert(key, value);

        // Insert into Linked List
        linkedList.insert(key, value);
    }

    // Close the file
    file.close();

    // Your data is now inserted into both BST and Linked List.

    return 0;
}
