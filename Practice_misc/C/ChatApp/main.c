#include "necessary_headers.h"

int main() {
    FILE *fr, *fw;
    pthread_t listen_thread, chat_thread;
    char *user_details, _choice_name = 'n';
    user_details = (char*) malloc(16 * sizeof(char));

    fr = fopen("user_details.txt", "r");
    if(fr != NULL) {
        fread(user_details, 16, 1, fr);

        // If the user details are not present in txt file \
        it will add them
        if(strncmp(user_details, "0", 1) == 0) {
            // opens user_details.txt in write mode
            fw = fopen("user_details.txt", "w");
            fflush(stdin);
            
            fprintf(stdout, "Enter your name: ");
            fscanf(stdin, "%s", user_details);
            fwrite(user_details, strlen(user_details), 1, fw);
        }


    } else {
        fprintf(stderr, "Abnormal exit!");
    }
    fclose(fr);
    fclose(fw);

    return 0;
}