#include "cards.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  for (int i = 0;i<52;i++){
     card_t c1 = card_from_num(i);
     print_card(c1);
     printf(" %d", i);
     printf("\n");
     
  }

  printf(" \n");

  for (int i = 0; i<=0; i++){
    //    char str*  = ranking_to_string(i);
    // printf("%s\n", str);
  } 
  return 0;
}
