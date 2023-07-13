// Input: root = [4,2,5,1,3], target = 3.714286
// Output: Closest number = 4

#include<stdio.h>
#include<stdlib.h>
#include <float.h>
#include<math.h>

// struct a node
struct Node {
    int value;
    struct Node* left, * right;
};

// create a new BST node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// find the value in BST that is closest to the target
double findClosestValue(struct Node* root, double target, double closest) {
    if (root == NULL) {return closest;}
    if (fabs(closest - target) > fabs(root->value - target)) {closest = root->value;}
    if (target < root->value) {
        return findClosestValue(root->left, target, closest);
    } else if (target > root->value) {
        return findClosestValue(root->right, target, closest);
    } else {return closest;}
}


// free the memory
void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}


// main func
int main() {
    struct Node* root = NULL;
    int count, i, temp;
    double target;

    int *node = (int*)malloc(count*sizeof(int));

    // BST values
    printf("count number in root: ");
    scanf("%d", &count);

    printf("enter the values: \n");
    for (i = 0; i < count; i++) {
        scanf("%d", &temp);
        root = insert(root, temp);
        node[i] = temp;
    }
    printf("root = ");
    for (i = 0; i < count; i++) {
        printf("%d ", node[i]);
    }

    // target value
    printf("\ntarget = ");
    scanf("%lf", &target);

    // find the closest value and print the result
    int result = (int)findClosestValue(root, target, root->value);
    printf("Closest number = %d\n", result);

    // Free the memory
    freeBST(root);
    free(node);

    return 0;
}