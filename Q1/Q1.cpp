/*
    QUESTION-NO-01
*/

#define _CRT_SECURE_NO_WARNINGS // Ignore warnings related to Microsoft-specific functions

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define an enum to represent the four types of arithmetic operations
typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    DIV
} TypeTag;

// Define a struct for a node in the arithmetic expression tree
typedef struct Node {
    TypeTag type; // Type of arithmetic operation or value
    int value; // Value of the node if it's a leaf node, otherwise 0
    struct Node* left; // Pointer to the left child node
    struct Node* right; // Pointer to the right child node
} Node;

// A function to calculate the nth Fibonacci number recursively
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// A helper function to create a new node in the arithmetic expression tree
Node* makeFunc(TypeTag type, Node* left, Node* right)
{
    Node* node = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    node->type = type; // Set the type of the node
    node->left = left; // Set the left child node
    node->right = right; // Set the right child node
    node->value = 0; // Initialize value to 0 since the node is not a leaf node
    return node; // Return the new node
}

// A function to calculate the value of a node in the arithmetic expression tree
int calc(Node* n)
{
    if (n == NULL)
        return n->value; // If the node is NULL, return its value (which is 0)

    if (n->left == NULL && n->right == NULL) { // If the node is a leaf node
        n->value = n->value; // Set the value of the node to its existing value (which was set previously)
        return n->value; // Return the value of the node
    }

    // If the node is not a leaf node, recursively calculate the values of its left and right children
    if (n->left != NULL)
        calc(n->left);
    if (n->right != NULL)
        calc(n->right);

    // Calculate the value of the node based on its type and the values of its left and right children
    int left_val = (n->left != NULL) ? n->left->value : 0;
    int right_val = (n->right != NULL) ? n->right->value : 0;

    switch (n->type) {
    case ADD:
        n->value = left_val + right_val;
        return n->value;
        break;
    case SUB:
        n->value = right_val - left_val;
        return n->value;
        break;
    case MUL:
        n->value = left_val * right_val;
        return n->value;
        break;
    case DIV:
        n->value = left_val / right_val;
        return n->value;
        break;
    default:
        break;
    }
}

int main()
{
    Node* add = makeFunc(ADD, NULL, NULL); // fix arguments passed to makeFunc
    add->left = makeFunc(0, NULL, NULL); // initialize left and right nodes
    add->right = makeFunc(0, NULL, NULL);
    add->left->value = 10;
    add->right->value = 6;

    Node* mul = makeFunc(MUL, NULL, NULL); // fix arguments passed to makeFunc
    mul->left = makeFunc(0, NULL, NULL); // initialize left and right nodes
    mul->right = makeFunc(0, NULL, NULL);
    mul->left->value = 5;
    mul->right->value = 4;

    Node* sub = makeFunc(SUB, mul, add);
    Node* fibo = makeFunc(SUB, sub, NULL);

    int addRes = calc(add);
    int mulRes = calc(mul);
    int subRes = calc(sub);
    int fiboRes = calc(fibo);
    int fibon = fibonacci(fiboRes - 1);

    printf("%d\n", addRes);
    printf("%d\n", mulRes);
    printf("%d\n", subRes);
    printf("%d\n", fibon);

    return 0;
}
