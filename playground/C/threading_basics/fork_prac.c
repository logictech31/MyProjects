#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
static int global_var = 10;

int main (void) {
  pid_t pID = fork();
  int loc_variable = 11;
  if (pID < 0)
    return EXIT_FAILURE;

  if (pID == 0) {
    printf ("\nCHILD: Global = %i; Local = %i", ++global_var, ++loc_variable);
  } else {
    printf ("\nPARENT: Global = %i; Local = %i", global_var, loc_variable);
  }

  return EXIT_SUCCESS;
}
