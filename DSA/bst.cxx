#include <iostream>
#include "bst.hxx"

Stack::Stack() {
    int i = 0;
    this->top = -1;

    while (i < MAX) {
        this->values[top++] = 0;
    }
}

int Stack::push(Trees::Node* value) {
    if (!(this->values[++this->top] = value)) {
        return 0;
    } else {
        std::cout << "Stack is full!\n";
    }
    return 1;
}

Trees::Node* Stack::pop(void) {
    this->values[this->top--] = 0;
    return 0;
}

namespace Trees{
    BST::BST() {
        this->root = NULL;
    }

    int BST::inorder_r_call(void) {
        if (this->root != NULL)
            inorder_r(this->root);
        else
            std::cout << "Cannot traverse an empty tree!";
            return 1;

        return 0;
    }

    void BST::inorder_r(Node *p) {
        if (p != NULL) {
            inorder_r(p->left);
            std::cout << p->value << " ";
            inorder_r(p->right);
        }
    }

    int BST::height(Node *ptr) {
        if (ptr != NULL){
            int left_h = height(ptr->left);
            int right_h = height(ptr->right);
            
            return ( ( ( left_h > right_h ) ? left_h : right_h ) + 1 );
        } else {
            return 0;
        }
    }

    int BST::inorder(void) {
        if (root == NULL) {
            std::cout << "Cannot traverse an empty tree!";
            return 1;
        } else {

        }
        Stack stk;
        Node *ptr = root;

        while (1) {
            stk.push(ptr->right);
        }

        return 0;
    }

    int BST::add_to_tree(int value) {
        if (this->root == NULL) {
            this->root = new Node;
            SET_CHILDREN_NULL(this->root);
            this->root->value = value;
            
            return 0;
        } else {

        }

        Node *ptr = root, *tmp;

        int height = this->height(this->root);
        int limit = SET_LIMIT(height);
        int i = 0;

        

        while(1) {
            if (ptr->value > value) {
                if (ptr->left != NULL) {
                    ptr = ptr->left;
                } else {
                    tmp = new Node;
                    tmp->value = value;
                    SET_CHILDREN_NULL(tmp);
                    ptr->left = tmp;
                    break;
                }
            } else if (ptr->value <= value) {
                if (ptr->right != NULL) {
                    ptr = ptr->right;
                } else {
                    tmp = new Node;
                    tmp->value = value;
                    SET_CHILDREN_NULL(tmp);
                    ptr->right = tmp;
                    break;
                }
            } else {
                // No condition can exist, this will be optimised out
            }
            
            /*
                Since height of the tree is log2(N)
                We will break this loop if it runs 2^n times.
                This is for security.
            */
            if (++i >= limit) {
                return 1;
            } else {

            }
        }

        return 0;
    }
}