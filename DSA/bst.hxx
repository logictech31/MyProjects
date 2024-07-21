#ifndef _BST_HXX_
#define _BST_HXX_
#include <math.h>
#define MAX 16
#define SET_CHILDREN_NULL(p) do {      \
    p->left = p->right = NULL;  \
    } while(0)                      \

#define SET_LIMIT(a) (pow((float)2, a));

class Stack {
private:
    Trees::Node* values[MAX];
    int top;
public:
    Stack();
    ~Stack();
    
    int push(Trees::Node* value);
    Trees::Node* pop(void);
};

namespace Trees {
    struct Node {
        int value;
        struct Node *left, *right;
    };

    class BST {
    private:
        Node *root;
        int height(Node *ptr);
    public:
        BST();
        int add_to_tree(int value);
        int delete_from_tree(int value);

        int preorder(void);
        int inorder(void);
        int postorder(void);

        int inorder_r_call(void);
        void inorder_r(Node *p);
    };
}
#endif