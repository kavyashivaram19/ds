#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
} *head = NULL;

int count() {
    struct node *temp;
    int i = 1;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    return(i);
}

struct node *create(int value) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf(" Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int value) {
    struct node *newnode;
    newnode = create(value);
    if(head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void delete_begin() {
    struct node *temp;
    if(head == NULL) {
        printf("deletion is not possible");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    struct node *temp1, *temp2;
    if(head == NULL) {
        printf("deletion is not possible");
    } else {
        temp1 = head;
        while(temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}

void delete_pos(int pos) {
    struct node *temp1, *temp2;
    int i, c = 1;
    i = count();
    if(pos == 1)
        delete_begin();
    else if(pos > i) {
        printf("Deletion is not posible");
        return;
    } else {
        temp1 = head;
        while(c <= pos-1 && temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
            c++;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}

void delete_spec_value(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node *temp1 = head;
    struct node *temp2 = NULL;
    // head node itself holds the key to be deleted
    if (temp1 != NULL && temp1->data == key) {
        head = temp1->next;
        free(temp1);
        printf("Element %d deleted.\n", key);
        return;
    }
    // Search for the key to be deleted, keep track of the previous node
    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    // If key not present in linked list
    if (temp1 == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    // Unlink the node from the linked list
    temp2->next = temp1->next;
    free(temp1);
    printf("Element %d deleted.\n", key);
}

void display() {
    struct node *temp;
    if(head == NULL) {
        printf("list is empty");
    } else {
        temp = head;
        while(temp->next != NULL) {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void main() {
    int ch, pos, value, key;
    do {
        printf("\n1.insert begin\n2. delete begin\n3. delete end\n4. delete position\n5.delete key\n6. display\n7.exit\n");
        printf("enter your choice:");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("enter the value:");
                scanf("%d", &value);
                insert_begin(value);
                break;
            case 2:
                delete_begin();
                break;
            case 3:
                delete_end();
                break;
            case 4:
                printf("enter position you want to delete: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 5:
                printf("enter key value of a node you want to delete: ");
                scanf("%d", &key);
                delete_spec_value(key);
                break;
            case 6:
                display();
                break;
            case 7:
                break;
            default:
                printf("\nyour choice is wrong!.. ");
        }
    } while(ch != 7);
}
