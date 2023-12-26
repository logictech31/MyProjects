#include <stdio.h>
#include <stdlib.h>

struct node {
    char indicator;
    int weight;
    struct node *next;
};

static struct node *arr;
// static void create_link(int);

int main() {
    int total_nodes = 0, iter = 0;
    char node_name = 0;

    printf("How many nodes exist in the graph?\nNodes: ");
    scanf("%d", &total_nodes);
    fflush(stdin);

    arr = (struct node *) malloc(sizeof(struct node) * total_nodes);
    if(arr == NULL) {
        return 1;
    }
    // This is where we ask node 'names' as in
    // node a, node b, node c
    while(total_nodes > 0 && iter < total_nodes) {
        (void)printf("Enter the node indicator: ");
        (void)scanf("%c", &node_name);
        (arr+iter++)->indicator = node_name;
    }

    return 0;
}