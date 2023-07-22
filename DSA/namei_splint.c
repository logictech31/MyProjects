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

int string_compare(char *s1, char *s2) {
    int flag = 0;
    while (*s1 != '\0' && *s2 != '\0') {
        if(*s1 == *s2) {
            flag = 1;
        } else {
            flag = 0;
            break;
        }
        s1++;
        s2++;
    }

    return flag;
}

void namaei_logic(node *h1, node *h2) {
    node *t1, *t2;

    t1 = h1;
    t2 = h2;
    while (t1->next != NULL) {
        t1 = t1->next;
    }

    free(t2->prev);
    while (t2->next != NULL) {
        t2 = t2->next;
        if(string_compare(t2->path, "..")) {
            t1 = t1->prev;
            free(t1->next);
            t1->next = NULL;
        } else if(*(t2->path) == '.' && *(t2->path+sizeof(char)) == '\0') {
            continue;
        } else {
            t1->next = add_new_node(t2->path);
            t1->next->prev = t1;
            t1 = t1->next;
            t1->next = NULL;
        }
    }
    
}

int main() {
    node *head, *tmp, *head_2;
    char *base_path, *holder, *holder_c, *rel_path, *rel_path_c;

    holder = (char*) malloc(MAX * sizeof(char));
    holder_c = holder;
    base_path = (char*) malloc(MAX * sizeof(char));
    rel_path = (char*) malloc(MAX * sizeof(char));
    rel_path_c = rel_path;
    strcpy(rel_path, ".././hi/gorakhpur/");
    head = NEW;
    head_2 = NEW;
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
    memset(holder, '\0', MAX * sizeof(char));
    convert_to_ll(head_2, rel_path, holder);
    traverse(head);
    printf("\n\n");
    traverse(head_2);

    namaei_logic(head, head_2);
    traverse(head);

    return 0;
}