#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4096
#define NEW (node*) malloc(1 * sizeof(node))
/* Doubly linked list structure is going to be used for the following
    program. Each and every mark of the path will be stored in the 
    doubly linked list */
typedef struct node {
    char path[MAX];
    struct node *next, *prev;
}node;

/*
    Will return the new node that is created from the data passed
*/
node* add_new_node(char *data) {
    node *tmp;
    tmp = NEW;
    int i = 0;

    tmp->next = NULL;
    strcpy(tmp->path, data);

    return tmp;
}

void traverse(node *head) {
    head = head->next;
    while (head != NULL) {
        fputs(head->path, stdout);
        fputs("/", stdout);
        head = head->next;
    }
    printf("\n");
}

void convert_to_ll(node* tmp, char *base_path, char *holder) {
    char *holder_c = holder;
    
    while(*base_path != '\0') {
        if(*base_path == '/') {
            base_path++;
            tmp->next = add_new_node(holder_c);
            tmp->next->prev = tmp;
            tmp = tmp->next;
            memset(holder, '\0', MAX * sizeof(char));
            holder = holder_c;
        } else {
            *holder = *base_path;
            holder++; base_path++;
        }
    }
}

int main() {
    node *head, *tmp;
    char *base_path, *holder, *holder_c, *rel_path, *rel_path_c;

    holder = (char*) malloc(MAX * sizeof(char));
    holder_c = holder;
    base_path = (char*) malloc(MAX * sizeof(char));
    rel_path = (char*) malloc(MAX * sizeof(char));
    rel_path_c = rel_path;
    strcpy(rel_path, ".././usr/data/");
    head = NEW;
    tmp = head;
    tmp->next = NULL;
    tmp->prev = NULL;
    strcpy(tmp->path, "/");
    printf("Enter base path: ");
    fgets(base_path, MAX, stdin);
    convert_to_ll(tmp, base_path, holder);
/*
    while(*base_path != '\0') {
        if(*base_path == '/') {
            base_path++;
            tmp->next = add_new_node(holder_c);
            tmp->next->prev = tmp;
            tmp = tmp->next;
            memset(holder, '\0', MAX * sizeof(char));
            holder = holder_c;
        } else {
            *holder = *base_path;
            holder++; base_path++;
        }
    }
*/
    traverse(head);

    return 0;
}