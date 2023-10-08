#include "necessary_headers.h"

// this function will count from 0 to 10
void* countToTen(void* param) {
    sleep(1);
    int i;
    for(i = 0; i <= 10; i++) {
        fprintf(stdout, "%d\n", i);
    }
}

// This function will count from 11 to 20
void* countFromTenToTwenty(void* param) {
    sleep(1);
    int i;

    for(i = 11; i <= 20; i++) {
        fprintf(stdout, "%d\n", i);
    }
}

int main(int argc, char const *argv[]) {
    static pthread_t thread_1, thread_2;

    fprintf(stdout, "Before thread!\n");
    pthread_create(&thread_1, NULL, &countToTen, NULL);
    pthread_create(&thread_1, NULL, &countFromTenToTwenty, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    fprintf(stdout, "After threading\n");

    return 0;
}
