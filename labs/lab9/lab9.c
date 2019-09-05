#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase.h>

struct DynArray {
  size_t capacity;
  int * array;
  size_t length;
};

struct StrDynArray {
  size_t capacity;
  char ** array;
  size_t length;
};

void dynarray_init(struct DynArray *pdarr) {
  const size_t size = 30;
  if (pdarr->array == NULL) {
    pdarr->array = malloc(size * sizeof(int));
    pdarr->capacity = size;
    pdarr->length = 0;
  }
}

void strdynarray_init(struct StrDynArray *pdarr) {
  const size_t in_capacity = 16;
  if (pdarr->array == NULL) {
    pdarr->array = malloc(16 * sizeof(char *));
    pdarr->capacity = in_capacity;
    pdarr->length = 0;
  }
}

void dynarray_realloc(struct DynArray *pdarr) {
  pdarr->capacity *= 2;
  int *new_array = realloc(pdarr->array, pdarr->capacity * sizeof(int));
  pdarr->array = new_array;
}

void strdynarray_realloc(struct StrDynArray *p) {
  p->capacity *= 2;
  char **tmp = realloc(p->array, p->capacity * sizeof(char *));
  if (tmp == NULL) {
    free(p->array);
    fprintf(stderr, "Reallocation error\n");
    exit(1);
  } else {
    p->array = tmp;
  }
}

void dyn_int_init(FILE *fin, struct DynArray *p) {
  p->capacity = 16;
  p->length = 0;
  p->array = malloc(p->capacity * sizeof(int));
  if (p->array == NULL) {
    printf("Creating new list is impossible\n");
    fclose(fin);
    exit(1);
  }
}

void strdynarray_deinit(struct StrDynArray *p) {
  free(p->array);
  p->capacity = 0;
  p->length = 0;
}

void dynarray_deinit(struct DynArray *p) {
  free(p->array);
  p->capacity = 0;
  p->length = 0;
}

void dynarray_push_back(struct DynArray *pdarr, int new_val) {
  if (pdarr->length == pdarr->capacity) {
    dynarray_realloc(pdarr);
  }
  pdarr->array[pdarr->length] = new_val;
  pdarr->length += 1;
}

void strdynarray_push_back(struct StrDynArray *p, char *str) {
  if (p->length == p->capacity) {
    strdynarray_realloc(p);
  }
  p->array[p->length] = str;
  p->length += 1;
}

void dynarray_print(struct DynArray *pdarr) {
  printf("Capacity: %zu\nLength: %zu\nElements: ", pdarr->capacity,
         pdarr->length);
  for (int i = 0; i < pdarr->length; i++) {
    printf("%i ", pdarr->array[i]);
  }
  puts("");
}



void numbers_main(FILE *fin, FILE *fout) {
  struct DynArray numbers;
  numbers.array = NULL;
  dynarray_init(&numbers);
  int minus = 0, plus = 0, all = 0;
  while (!feof(fin)) {
    if (numbers.length == numbers.capacity) {
      dynarray_realloc(&numbers);
    }
    fscanf(fin, "%i", &numbers.array[numbers.length]);
    all+=numbers.array[numbers.length];
    if (numbers.array[numbers.length]<0)
    {
      minus+=numbers.array[numbers.length];
    } else {
      plus+=numbers.array[numbers.length];
    }
    numbers.length++;
  }
  dynarray_print(&numbers);
  fprintf(fout, "%i %i %i", plus, minus, all);
  // fclose(fout);
  dynarray_deinit(&numbers);
}

int lengthMid(struct StrDynArray *p) {
  int sum = 0;
  for (size_t i = 0; i < p->length; i++) {
    sum += strlen(p->array[i]) - 1;
  }
  return sum / p->length;
}

char *readTextLine(FILE *fin) {
  char buffer[10];
  buffer[0] = '\0';
  int length = 10;
  char *pstr = malloc(length * sizeof(char));
  pstr[0] = '\0';

  if (feof(fin) != 0) {
    free(pstr);
    return NULL;
  }

  while (1) {
    fgets(buffer, 10, fin);
    strcat(pstr, buffer);
    if (strchr(buffer, '\n') != NULL || feof(fin) != 0) {
      break;
    }
    length += 10;
    char *temp = realloc(pstr, length * sizeof(char));
    if (temp == 0) {
      exit(1);

    } else {
      pstr = temp;
    }
  }

  return pstr;
}

int text_main(FILE *fin, FILE *fout) {
  struct StrDynArray text = {0};
  strdynarray_init(&text);
  struct DynArray length = {0};
  dynarray_init(&length);
  while (1) {
    char *line = readTextLine(fin);
    if (line == NULL)
      break;
    strdynarray_push_back(&text, line);
  }
  if (text.length != 0) {
    int mid = lengthMid(&text);
    for (size_t i = 0; i < text.length; i++) {
      printf("> %s", text.array[i]);
      if (strlen(text.array[i]) > mid) {
        fprintf(fout, "%s", text.array[i]);
      }
    }
    puts("");
    strdynarray_deinit(&text);
  } else {
    fprintf(fout, "%f", NAN);
    printf("No text");
  }
}

int main(int argc, char *argv[argc]) {
  if (argc != 3) {
    fprintf(stderr, "Wrong args\n");
    return 1;
  }
  char * f1 = argv[1];
  char * f2 = argv[2];
  FILE * fin = fopen(f1, "r");
  FILE * fout = fopen(f2, "w");
  if (!fin) {
    fprintf(stderr, "ERROR OF OPEN INPUT\n");
    return 1;
  }
  char comm[8];
  fgets(comm, 8, fin);
  if (strncmp(comm, "numbers\0", 8) == 0) {
    numbers_main(fin, fout);
  } else if (strncmp(comm, "text\0", 4) == 0) {
    text_main(fin, fout);
  } else {
    fprintf(stderr, "Wrong task in file '%s'\n", f1);
    fclose(fin);
    return EXIT_FAILURE;
  }

  if (fclose(fin) == EOF || fclose(fout) == EOF) {
    fprintf(stderr, "ERROR OF CLOSE\n");
    return 1;
  }
  return 0;
}