#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node using typedef
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

// Function to search for a node in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Function to find the minimum value node
Node* minValueNode(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// **Simplified Delete Function**
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children -> Replace with inorder successor
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal (sorted order)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver code
int main() {
    Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    // Search for a key
    int key = 40;
    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);

    // Delete a node
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    return 0;
}
