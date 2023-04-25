#include <iostream>
using namespace std;

// node structure for binary search tree
struct Node {
    int data;
    Node *left, *right;
};

// function to create a new node with given data
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// function to insert a node in BST
Node* insertNode(Node* node, int data) {
    // if tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }
    // otherwise, recur down the tree
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    // return the (unchanged) node pointer
    return node;
}

// function to delete a node from BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    // if the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
        // if the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
        // if key is same as root's key, then this is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        // node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        // copy the inorder successor's content to this node
        root->data = temp->data;
        // delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// function to traverse the tree in inorder
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// main function
int main() {
    Node* root = NULL;
    int operation, operand;
    cin >> operation;
    while (operation != -1) {
        switch(operation) {
            case 1: // insert a node
                cin >> operand;
                root = insertNode(root, operand);
                break;
            case 2: // delete a node
                cin >> operand;
                root = deleteNode(root, operand);
                break;
            default:
                cout << "Invalid operator!\n";
                return 0;
        }
        cin >> operation;
    }
    // print the inorder traversal of the tree
    inorderTraversal(root);
    return 0;
}
//ddd
