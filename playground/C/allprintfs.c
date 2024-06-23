#include <stdio.h>
#include <time.h>

int main(void) {
  char buffer[25];
  int time = 21;

  snprintf(buffer, sizeof(buffer), "Time right now is %d", time);

  printf("%s", buffer);

  return 0;
}
