#include <iostream>
/*
A B tree of order m contains all the properties of an M way tree. In addition, it contains the following properties.

    Every node in a B-Tree contains at most m children.
    Every node in a B-Tree except the root node and the leaf node contain at least m/2 children.
    The root nodes must have at least 2 nodes.
    All leaf nodes must be at the same level.

*/
namespace tree {
    // Basic node structure of the b-tree
    class node {
    private:
        unsigned int data;
        struct node *left, *right;
    public:
        node();
        ~node();
    };

    node::node() {
        this->left = this->right = NULL;
    }

    node::~node() {
        this->left = this->right = NULL;
    }

    class btree {
        private:
        // The order of the btree tree
        const int M = 3;
        class node tree_node[3];
        static node *head;

        public:
            // Constructor
            btree();
            // Will be used for insertion
            void operator>>(unsigned int data);
            // Will be used for searching
            int operator<<(unsigned int search_key);
            // Will be used for traversing
            node *operator++();
            // Will be used to delete an entry in a node
            void delete_entry();
            // Destructor
            ~btree();
    };

    btree::btree() {
        head = &tree_node[0];
    }

    btree::~btree() {
        head = NULL;
    }
/*
Searching in B Trees is similar to that in Binary search tree. For example, if we search for an item 49 in the following B Tree. The process will something like following :

    1. Compare item 49 with root node 78. since 49 < 78 hence, move to its left sub-tree.
    2. Since, 40<49<56, traverse right sub-tree of 40.
    3. 49>45, move to right. Compare 49.
    4. match found, return.

*/
    int btree::operator<<(unsigned int search_key) {
        int found = -1;
        node *start = head;

        return found;
    }
/*
Insertions are done at the leaf node level. The following algorithm needs to be followed in order to insert an item into B Tree.

    1. Traverse the B Tree in order to find the appropriate leaf node at which the node can be inserted.
    2. If the leaf node contain less than m-1 keys then insert the element in the increasing order.
    3. Else, if the leaf node contains m-1 keys, then follow the following steps.
        - Insert the new element in the increasing order of elements.
        - Split the node into the two nodes at the median.
        - Push the median element upto its parent node.
        - If the parent node also contain m-1 number of keys, then split it too by following the same steps.


*/
    void btree::operator>>(unsigned int data) {
        
        return;
    }

/*
    I will be performing the traversal by using the post increment operator
    and return the address of the array of order M    
*/
}

int main(void) {
    tree::btree obj;
    unsigned int data_enter_iter = 0, data = 0;

    std::cout << "How many times do you want to enter data?\n";
    std::cin >> data_enter_iter;

    while(data_enter_iter--) {
        std::cin >> data;
        obj >> data;
    }

    return 0;
}