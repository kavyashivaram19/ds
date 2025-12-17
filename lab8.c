#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return create(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
struct node* find_min(struct node* ptr) {
    struct node* current = ptr;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct node* delete_node(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}
void inorder_tra(struct node* root) {
    if (root != NULL) {
        inorder_tra(root->left);
        printf("%d ", root->data);
        inorder_tra(root->right);
    }
}

void preorder_tra(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_tra(root->left);
        preorder_tra(root->right);
    }
}

void postorder_tra(struct node* root) {
    if (root != NULL) {
        postorder_tra(root->left);
        postorder_tra(root->right);
        printf("%d ", root->data);
    }
}
void display(struct node* root) {
    printf("Tree elements (In-order traversal): ");
    inorder_tra(root);
    printf("\n");
}

int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Construct/Insert element\n");
        printf("2. Traverse (In-order, Pre-order, Post-order)\n");
        printf("3. Display elements\n");
        printf("4. Delete an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("In-order traversal: ");
                inorder_tra(root);
                printf("\nPre-order traversal: ");
                preorder_tra(root);
                printf("\nPost-order traversal: ");
                postorder_tra(root);
                printf("\n");
                break;
            case 3:
                display(root);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                printf("Node deleted if present.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
