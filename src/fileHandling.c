#include <stdio.h>
#include <stdlib.h>

struct Data{
    char *content;
};

typedef struct Data *data;

int main() {
  FILE *file;
  file = fopen("src/example.txt", "r");

  if (file == NULL) {
    perror("Error opening the file");
  }

  data d = (data) malloc(sizeof(struct Data));

  if (d == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return 1;
  }

  // finding the size of the file
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  rewind(file);

  // creating enough space for the file size
  d->content = (char *)malloc(fileSize + 1); // +1 for null terminator

  if (d->content == NULL) {
      perror("Error allocating memory");
      free(d);
      fclose(file);
      return 1; // Return an error code
  }

  // read the content of the file into the struct
  fread(d->content, 1, fileSize, file);
  d->content[fileSize] = '\0'; // Null-terminate the string

  printf("File Content:\n%s\n", d->content);

  free(d->content);
  free(d);
  fclose(file);

  return 0;
}