#include <stdio.h>
#include <stdlib.h>

struct Data{
    char *content;
};

typedef struct Data *data;

int main() {
  FILE *file;
  file = fopen("example.txt", "r");

  if (file == NULL) {
    perror("Error opening the file");
  }

  data d = (d)malloc(sizeof(struct data));


}