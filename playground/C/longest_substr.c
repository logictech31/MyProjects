#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALLOC_MEM (struct node *) malloc(1 * sizeof(struct node))
/*
    Code will be long, but I'm too tired to try and do it the British way
    I am using linked list to maintain the substring
    That's it.
    I had some better Ideas but I don't want to keep solving one problem for the entire day
*/

int list_len(void);
bool check_in_list_pop_list_if_found(char);
int pop_until_char_found(char);
int push(char);
int print_list(void);

struct node {
    char val;
    struct node *next;
};

static struct node *head;

int print_list(void) {
    struct node *ptr;

    ptr = head->next;

    while(ptr != NULL) {
        printf("%c", ptr->val);
        ptr = ptr->next;
    }


    return 0;
}

int list_len(void) {
    struct node *ptr;
    int len = 0;
    ptr = head->next;

    while(ptr != NULL) {
        ptr = ptr->next;
        len++;
    }

    return len;
}

/*
    Function will check if the character is there in the list or not
*/
bool check_in_list(char x) {
    struct node *ptr;

    ptr = head->next;
    if(ptr == NULL) {
        return false;
    }

    while(ptr != NULL) {
        if(ptr->val == x) {
            return true;
        }

        ptr = ptr->next;
    }
        
    return false;
}
/*
    Will pop from the list until finds the character
*/
int pop_until_char_found(char x) {
    struct node *ptr, *tmp;

    ptr = head->next;

    if(ptr == NULL) {
        return 1;
    }

    while(ptr->val != x) {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    tmp = ptr;
    ptr = ptr->next;
    free(tmp);
    head->next = ptr;
    push(x);

    return 0;
}

int push(char x) {
    struct node *ptr;

    // If the substring list is empty
    if(head->next == NULL) {
        ptr = ALLOC_MEM;
        if(ptr == NULL)
            return 1;
        ptr->val = x;
        head->next = ptr;
        return 0;
    }

    ptr = head->next;
    // If the substring list is not empty
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = ALLOC_MEM;
    ptr = ptr->next;
    if(ptr == NULL) {
        return 1;
    }

    ptr->next = NULL;
    ptr->val = x;

    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int iter = 0;

    head = (struct node *) malloc (1 * sizeof(struct node));
    head->val = 'H';
    head->next = NULL;
    
    while(s[iter] != '\0') {
        if(check_in_list(s[iter]) == false) {
            push(s[iter]);
        } else {
            pop_until_char_found(s[iter]);
        }
        iter++;
    }

    return list_len();
}

int main() {
    char *str;
    int len = 0, iter = 0, strlen;

    printf("Enter the length of the string you're going to enter: ");
    scanf("%d", &strlen);

    str = (char *) malloc(strlen * sizeof(char));

    printf("Enter a string to check its longest substring and the length: ");
    while(iter < strlen)
        scanf("%c", str+iter++);

    len = lengthOfLongestSubstring(str);

    printf("Length = %d\n", len);
    print_list();

    return 0;
}
