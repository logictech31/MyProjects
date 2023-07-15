#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NEW (avl_node*) malloc(1 * sizeof(avl_node))

typedef struct avl_node {
    int data;
    struct avl_node *left, *right;
}avl_node;
avl_node* root = NULL;

// In this type of rotation, the parent node goes to left of temp
// and the left of temp is assigned to right of parent node as it is its
// inorder successor
/*
    a
     \(R)                 ->                      c
      c                                          /  \
     / \(R)                                     a    d
    b   d                                        \
                                                  b
*/
avl_node* RR(avl_node* parent) {
    avl_node *temp;

    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;

    return temp;
}
// In this rotation, the parent node goes to the right of temp
// and the right of temp is assigned to left of parent node as it is its
// inorder predecessor
/*
        a
    (L)/
      b
  (L)/ \
    c   d
*/
avl_node* LL(avl_node* parent) {
    avl_node *temp;

    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;

    return temp;
}


avl_node* LR(avl_node* temp) {
    temp->left = RR(temp->left);
    return (LL(temp));
}

avl_node* RL(avl_node* temp) {
    temp->right = LL(temp->right);
    return (RR(temp));
}

int Max_int(int a, int b) {
    return (a > b) ? a: b;
}

int avl_height(avl_node* temp) {
    if(temp == NULL) {
        return 0;
    }
    return (1 + Max_int(avl_height(temp->left), avl_height(temp->right)));
}

avl_node* height_balance(avl_node *temp) {
    int left_height, right_height, balance_factor;

    if(temp == NULL) {
        return temp;
    }

    left_height = avl_height(temp->left);
    right_height = avl_height(temp->right);
    balance_factor = left_height - right_height;

    if(balance_factor > 1) {
        if(avl_height(temp->left->left) >= avl_height(temp->left->right)) {
            temp = LL(temp);
        } else {
            temp = LR(temp);
        }
    } else if(balance_factor < -1){
        if(avl_height(temp->right->left) >= avl_height(temp->right->right)) {
            temp = RL(temp);
        } else {
            temp = RR(temp);
        }
    }

    return temp;
}

avl_node* avl_add_node(avl_node* temp) {
    bool flag = false;
    avl_node* curr;

     if(root == NULL) {
        root = temp;
        return root;
     }

     curr = root;

    do {
        if(temp->data < curr->data) {
            if(curr->left == NULL) {
                curr->left = temp;
                flag = true;
            } else {
                curr = curr->left;
            }
        } else if(temp->data >= curr->data) {
            if(curr->right == NULL) {
                curr->right = temp;
                flag = true;
            } else {
                curr = curr->right;
            }
        }
    } while (flag == false);

    root = height_balance(root);
    
     return root;
}

int display_algo() {
    int choice;

    printf("\nPreorder: ");
    preorder_call();
    printf("\nInorder: ");
    inorder_call();

    printf("\n");
}

void preorder_call(void) {
    preorder(root);
}

void inorder_call(void) {
    inorder(root);
}

void preorder(avl_node* temp) {
    if(temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(avl_node* temp) {
    if(temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

int main() {
    int select_operation, display_type;
    char continue_main_loop, continue_node_addition, choice;
    avl_node* temp;

    do {
        printf("Which of the following operations do you want to perform?"
        "\n1. Add\t2. Display\t3. Height\nChoice: ");
        scanf("%d", &select_operation);
        switch (select_operation) {
        case 1:
            do {
                temp = NEW;
                temp->left = NULL;
                temp->right = NULL;
                printf("\nEnter data: ");
                scanf("%d", &(temp->data));
                root = avl_add_node(temp);
                printf("Do you want to continue adding nodes?(y/N):");
                scanf(" %c", &choice);
            } while (choice == 'y');
            
            break;

        case 2:
            display_algo();
            break;

        case 3:
            int h = avl_height(root);
            printf("%d", h);
            break;

        default:
            printf("\nIncorrect choice!");
            break;
        }

        printf("\nDo you want to continue? (y/N): ");
        scanf(" %c", &continue_main_loop);
    } while (continue_main_loop == 'Y' || continue_main_loop == 'y');
    
    return 0;
}