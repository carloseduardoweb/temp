//Contador de palavras em arquivo

#define MAX_FILENAME 80
#define MAX_WORD 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char filename[MAX_FILENAME];
  char word[MAX_WORD];
  FILE *file = NULL;
  char c = '\0';
  int  i = 0;
  int  count = 0;
  
  memset(filename, '\0', sizeof (filename));
  memset(word, '\0', sizeof (word));

  printf("Arquivo: ");
  scanf ("%s", filename);

  printf("Palavra: ");
  scanf ("%s", word);

  file = fopen(filename, "r");

  if (file == NULL)
  {
    printf("Erro ao abrir arquivo");
    return -1;
  }

  while ((c = fgetc(file)) != EOF)
  {
    if (c == word[i++])
    {
      if (i == strlen(word))
      {
        i = 0;
        count++;
      }
    }
    else
    {
      i = 0;
    }
  }

  fclose(file);
  file = NULL;

  printf("Contador = %d\n", count);

  return 0;
}
