#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define the key for thread-specific data
pthread_key_t key;

// Destructor function to free the memory allocated for TSD
void destructor(void* ptr) {
    free(ptr);
    printf("Memory freed for thread %ld\n", (long)pthread_self());
}

void* thread_function(void* arg) {
    // Allocate memory for thread-specific data
    int* tsd = (int*)malloc(sizeof(int));
    if (tsd == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }

    // Set the value of TSD for the current thread
    *tsd = (int)(long)arg;
    pthread_setspecific(key, tsd);

    // Retrieve and print the value of TSD for the current thread
    int* value = (int*)pthread_getspecific(key);
    printf("Thread %ld: TSD value = %d\n", (long)pthread_self(), *value);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create the key for thread-specific data
    pthread_key_create(&key, destructor);

    // Create two threads
    pthread_create(&thread1, NULL, thread_function, (void*)1);
    pthread_create(&thread2, NULL, thread_function, (void*)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Delete the key for thread-specific data
    pthread_key_delete(key);

    return 0;
}
