#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 4096
#define NEW (node*) malloc(1 * sizeof(node))

typedef struct node {
    char path[MAX];
    struct node *next, *prev;
}node;

void add_node(node* head, char *data) {
    node *temp;
    int i = 0;

    temp = NEW;
    temp->next = NULL;
    while(*data != '\0') {
        temp->path[i] = *data;
        data++; i++;
    }

    while(head->next != NULL) {
        head = head->next;
    }

    head->next = temp;
    temp->prev = head;
}

void traverse(node* head) {
    while(head != NULL) {
        printf("%s", head->path);
        printf("/");
        head = head->next;
    }
}

int main() {
    node *head;
    bool flag = true;
    int i = 0, j = 0;
    char base_path[MAX], holder[MAX], relative_path[MAX], output_path[MAX]; 
    
    head = NEW;
    head->path[0] = "/";
    head->prev = NULL;
    head->next = NULL;
    printf("Enter the base path: ");
    scanf("%s", &base_path);
    while(base_path[i] != '\0') {
        if(base_path[i] == '/') {
            holder[i+1] = '\0';
            add_node(head, &holder);
            j = 0;
            memset(holder, " ", MAX * sizeof(char));
        } else {
            holder[j] = base_path[i];
        }
        i ++;
        j ++;
    }
    traverse(head);
    printf("\nGive the relative path: ");
    scanf(" %s", &relative_path);
    printf("%s", relative_path);
    printf("\n");
    free(head);

    return 0;
}