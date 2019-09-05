#include <ctype.h>
#include <float.h>
#include <math.h>
#include <progbase.h>
#include <progbase/console.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int conReadLine(char str[], int maxBufLen) {
  fgets(str, maxBufLen, stdin);
  int bufLength = strlen(str);
  if (str[bufLength - 1] == '\n') {
    str[bufLength - 1] = '\0';
    bufLength -= 1;
  } else {
    for (char ch; (ch = getchar()) != '\n';) {
    }
  }
  return bufLength;
}
struct SLNode {
  float data;
  struct SLNode *next;
};
struct DynArray {
  int *array;
  int capacity;
  int length;
};
void waiting() {
  char key = 0;
  printf("\nPress ANY KEY to return to commands list or to continue TEST CASE");
  do {
    key = Console_getChar();
  } while (key == 0);
  Console_clear();
}

void error(int n) {
  Console_clear();
  puts("ERROR\n_______________\n");
  switch (n) {
  case 1:
    printf("  You must initialize ARRAY before using it");
    break;
  case 2:
    printf("Your input is WRONG or NOT NUMBER");
    break;
  case 3:
    printf("WRONG POSITION");
    break;
  case 4:
    printf("WRONG DOT POSITION");
    break;
  case 5:
    printf("TOO MUCH DOTS");
    break;
  }
  printf("\n_______________\n");
  waiting();
}
void dynarray_init(struct DynArray *pdarr) {
  Console_clear();
  printf("DYNARRAY INIT\n_______________\n");
  pdarr->capacity = 5;
  pdarr->length = 0;
  pdarr->array = malloc(pdarr->capacity * sizeof(int));
  if (pdarr->array == NULL) {
    int r = rand() % 99 + 1;
    printf("Cannot initialize ARRAY. Initializing with LENGTH = %i", r);
    pdarr->length = r;
    pdarr->array = malloc(pdarr->capacity * sizeof(int));
  }
  printf("\n  CAPACITY:  %i\n\n  LENGTH:  %i\n\n  ARRAY:  ", pdarr->capacity,
         pdarr->length);
  for (int i = 0; i < pdarr->length; i++) {
    printf("%i ", pdarr->array[i]);
  }
  printf("\n\n_______________\n");
  waiting();
}
void dynarray_deinit(struct DynArray *pdarr) {
  Console_clear();
  printf("DYNARRAY DEINIT\n_______________\n");
  pdarr->length = 0;
  pdarr->capacity = 0;
  free(pdarr->array);
  printf("\nARRAY has been DEINITialized\n\n_______________\n");
  waiting();
}
void dynarray_clear(struct DynArray *pdarr) {
  Console_clear();
  printf("DYNARRAY CLEAR\n_______________\n");
  pdarr->length = 0;
  printf("\n  Now LENGTH became 0\n_______________\n");
  waiting();
}
void dynarray_reserve(struct DynArray *pdarr, long int val) {
  Console_clear();
  printf("DYNARRAY RESERVE\n_______________\n");
  if (pdarr->capacity < val) {
    pdarr->capacity = val;
    int *NewArray = realloc(pdarr->array, pdarr->capacity * sizeof(int));
    pdarr->array = NewArray;
    printf("\n  New CAPACITY is %i", val);
  } else {
    printf("\n  New CAPACITY lower than PREVIOUS");
  }
  printf("\n_______________\n");
  waiting();
}
void dynarray_push_back(struct DynArray *pdarr, int val) {
  Console_clear();
  printf("DYNARRAY PUSH BACK\n_______________\n");
  if (pdarr->capacity <= pdarr->length + 1) {
    pdarr->capacity = pdarr->capacity + 1;
    int *NewArray = realloc(pdarr->array, pdarr->capacity * sizeof(int));
    pdarr->array = NewArray;
  }
  pdarr->array[pdarr->length] = val;
  pdarr->length++;
  printf("  VALUE %i has been added. Now LENGTH is %i", val, pdarr->length);
  printf("\n_______________\n");
  waiting();
}
void dynarray_erase(struct DynArray *pdarr, int index) {
  printf("DYNARRAY ERASE\n_______________\n");
  if (index >= pdarr->length || index < 0) {
    error(3);
    return;
  } else {
    for (int i = index; i < pdarr->length; i++) {
      pdarr->array[i] = pdarr->array[i + 1];
    }
    pdarr->length--;
    printf("  Element №%i has been erased", index);
  }
  printf("\n_______________\n");
  waiting();
}
void dynarray_print(struct DynArray *pdarr) {
  Console_clear();
  printf("DYNARRAY PRINT\n_______________\n");
  printf("\n  CAPACITY:  %i\n\n  LENGTH:  %i\n\n  ARRAY:  ", pdarr->capacity,
         pdarr->length);
  for (int i = 0; i < pdarr->length; i++) {
    printf("%i ", pdarr->array[i]);
  }
  printf("\n\n_______________\n");
  waiting();
}
void dynarray_test(struct DynArray *pdarr) {
  Console_clear();
  printf("DYNARRAY TEST\n_______________\n  TEST CASE is: \n  [1] "
         "dynarray_init\n  [2] dynarray_push_back 0-9 \n  [3] dynarray_print\n "
         " [4] dynarray_reserve 100\n  [4] dynarray_erase 9-0\n  [5] "
         "dynarray_print\n  [6] dynarray_clear\n  [7] "
         "dynarray_deinit\n_______________\nTap 1 to BEGIN or ENTER to abort "
         "operation");
  char key;
  do {
    key = Console_getChar();
    if (key == '\n') {
      Console_clear();
      return;
    }
  } while (key != '1');                                                                                                           
  dynarray_init(pdarr);
  for (int i = 0; i < 10; i++) {
    dynarray_push_back(pdarr, i);
  }
  dynarray_print(pdarr);
  dynarray_reserve(pdarr, 100);
  dynarray_print(pdarr);
  for (size_t i = 0; i < 10; i++) {
    dynarray_erase(pdarr, 9 - i);
  }
  dynarray_print(pdarr);
  dynarray_clear(pdarr);
  dynarray_deinit(pdarr);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}
void dynarray_main() {
  char **trash;
  Console_clear();
  char key;
  int z = 0, q;
  int isinit = 0;
  struct DynArray dynarr;
  do {
    if (z == 0) {
      printf("DYNARRAY MENU\n_______________\n\n  [1] INIT\n  [2] DEINIT\n  "
             "[3] CLEAR\n  [4] RESERVE\n  [5] PUSH_BACK\n  [6] ERASE\n  [7] "
             "PRINT\n_______________");
    } else if (z == 1) {
      printf("CURRENT CAPACITY: %i | LENGTH: %i | ARRAY: ", dynarr.capacity,
             dynarr.length);
      for (int i = 0; i < dynarr.length; i++) {
        printf("%i ", dynarr.array[i]);
      }
      printf(" |\n\nDYNARRAY MENU\n_______________\n\n  [1] INIT\n  [2] "
             "DEINIT\n  [3] CLEAR\n  [4] RESERVE\n  [5] PUSH_BACK\n  [6] "
             "ERASE\n  [7] PRINT\n\n_______________");
      z = 2;
    }
    key = Console_getChar();
    switch (key) {
    case '1':
      if (isinit == 1) {
        dynarr.length = 0;
        dynarr.capacity = 0;
        free(dynarr.array);
      }
      dynarray_init(&dynarr);
      isinit = 1;
      z = 1;
      break;
    case '2':
      if (z == 0) {
        error(1);
      } else {
        dynarray_deinit(&dynarr);
        isinit = 0;
        z = 0;
      }
      break;
    case '3':
      if (z == 0) {
        error(1);
      } else {
        dynarray_clear(&dynarr);
        z = 1;
      }
      break;
    case '4':
      q = 1;
      if (z == 0) {
        error(1);
      } else {
        Console_clear();
        char str[1000];
        printf("Enter capacity to RESERVE: ");
        int len = conReadLine(str, 1000);
        for (int i = 0; i < len; i++) {
          if (isdigit(str[i]) == 0) {
            error(2);
            z = 1;
            q = 0;
            break;
          }
        }
        if (q != 0) {
          dynarray_reserve(&dynarr, strtol(str, trash, 10));
        }

        z = 1;
      }
      break;
    case '5':
      if (z == 0) {
        error(1);
      } else {
        Console_clear();
        char str[1000];
        printf("Enter VALUE to add: ");
        int len = conReadLine(str, 1000);
        for (int i = 0; i < len; i++) {
          if (isdigit(str[i]) == 0) {
            error(2);
            z = 1;
            break;
          }
        }
        dynarray_push_back(&dynarr, strtol(str, trash, 10));
        z = 1;
        break;
      }
      break;
    case '6':
      if (z == 0) {
        error(1);
      } else {
        Console_clear();
        char str[1000];
        printf("Enter POSITION to ERASE: ");
        int len = conReadLine(str, 1000);
        for (int i = 0; i < len; i++) {
          if (isdigit(str[i]) == 0) {
            error(2);
            z = 1;
            break;
          }
        }
        dynarray_erase(&dynarr, strtol(str, trash, 10));
        z = 1;
        break;
      }
      break;
      z = 1;
      break;
    case '7':
      if (z == 0) {
        error(1);
      } else {
        dynarray_print(&dynarr);
        z = 1;
      }
      break;
    // case '8':
    //   dynarray_test(&dynarr);
    //   z = 0;
    //   break;
    }
  } while (key != '\n');
  if (isinit == 1) {
    dynarray_deinit(&dynarr);
  }
}
void slnode_clear(struct SLNode *head) {
  struct SLNode *node = head;
  while (node != NULL) {
    struct SLNode *next = node->next;
    free(node);
    node = next;
    next = NULL;
  }
}
struct SLNode *slnode_create(struct SLNode *head, float data) {
  struct SLNode *pnode = malloc(sizeof(struct SLNode));
  if (pnode == NULL) {
    printf("Memmory error\n");
    slnode_clear(head);
    exit(1);
  } else {
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
  }
}
struct SLNode *slnode_push_front(struct SLNode *head, float value) {
  struct SLNode *new_node = slnode_create(head, value);
  new_node->next = head;
  return new_node;
}
struct SLNode *slnode_push_back(struct SLNode *head, float value) {
  struct SLNode *new_node = slnode_create(head, value);
  if (head == NULL) {
    return new_node;
  } else {
    struct SLNode *node = head;
    while (node->next != NULL)
      node = node->next;
    node->next = new_node;
    return head;
  }
}
size_t slnode_size(struct SLNode *head) {
  size_t size = 0;
  struct SLNode *node = head;
  while (node != NULL) {
    size++;
    node = node->next;
  }
  return size;
}
size_t slnode_count_neg(struct SLNode *head) {
  size_t cnt = 0;
  struct SLNode *node = head;
  while (node != NULL) {
    if (node->data < 0)
      cnt++;
    node = node->next;
  }
  return cnt;
}
float slnode_min(struct SLNode *head) {
  struct SLNode *node = head;
  float min = node->data;
  if (node == NULL) {
    return NAN;
  }
  while (node != NULL) {
    if (node->data <= min) {
      min = node->data;
    }

    node = node->next;
  }
  return min;
}
void slnode_print(struct SLNode *head) {
  struct SLNode *node = head;
  printf("\n  NODE:  ");
  while (node != NULL) {
    printf("[%.3f] ", node->data);
    if (node->next != NULL) {
      printf("-> ");
    }
    node = node->next;
  }
}
void slnode_main() {
  char **trash;
  Console_clear();
  char key;
  int z = 0;
  struct SLNode *head = NULL;
  int isinit = 1;
  do {
    if (z != 1) {
      if (z == 2) {
        struct SLNode *node = head;
        printf("\n  NODE:  ");
        while (node != NULL) {
          printf("[%.3f] ", node->data);
          if (node->next != NULL) {
            printf("-> ");
          }
          node = node->next;
        }
      }
      printf(
          "\n\nSLNODE MENU\n_______________\n\n  [1] PUSH_FRONT\n  [2] "
          "PUSH_BACK\n  [3] SIZE\n  [4] CLEAR\n  [5] COUNT_NEG\n  [6] MIN\n  "
          "[7] PRINT\n_______________");
      z = 1;
    }
    key = Console_getChar();
    int dotc = 0;
    float a;
    switch (key) {
    case '\n':
      break;
    case '1':
      Console_clear();
      printf("Enter value to PUSH_FRONT: ");
      scanf("%f", &a);
      head = slnode_push_front(head, a);
      Console_clear();
      z = 2;
      break;
    case '2':
      Console_clear();
      printf("Enter value to PUSH_BACK: ");
      scanf("%f", &a);
      head = slnode_push_back(head, a);
      Console_clear();
      z = 2;
      break;
    case '3':
      Console_clear();
      printf("SLNODE SIZE\n_______________\n");
      printf("\n  SIZE: %zu", slnode_size(head));
      printf("\n_______________\n");
      waiting();
      z = 2;
      break;
    case '4':
      Console_clear();
      printf("SLNODE CLEAR\n_______________\n");
      slnode_clear(head);
      printf("\nNow SLNODE empty\n_______________\n");
      waiting();
      key = '\n';
      z = 2;
      break;
    case '5':
      Console_clear();
      printf("SLNODE COUNT_NEG\n_______________\n");
      printf("\n  NEGATIVE COUNT: %zu\n_______________\n",
             slnode_count_neg(head));
      waiting();
      z = 2;
      break;
    case '6':
      Console_clear();
      printf("SLNODE MIN\n_______________\n");
      if (slnode_size(head) == 0) {
        puts("\n  NAN\n_______________\n");
      } else {
        printf("\n  MINIMAL: %f\n_______________\n", slnode_min(head));
      }
      waiting();
      z = 2;
      break;
    case '7':
      Console_clear();
      printf("SLNODE PRINT\n_______________\n");
      slnode_print(head);
      printf("\n_______________\n");
      waiting();
      z = 2;
      break;
    }
  } while (key != '\n');
  if (isinit == 1)
  {
    free(head);
  }
  
}
void main(void) {
  srand(time(0));
  Console_clear();
  char key;
  int z = 1;
  do {
    if (z != 0) {
      Console_clear();
      puts("MAIN MENU\n_______________\n\n  [1] DYNARRAY MENU\n  [2] SLNODE "
           "MENU\n_______________\n");
      z = 0;
    }
    key = Console_getChar();
    switch (key) {
    case '1':
      dynarray_main();
      z = 1;
      break;
    case '2':
      slnode_main();
      z = 1;
      break;
    }
  } while (key != '\n');
  Console_clear();
}
