#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert( ( c.value >= 2 ) && ( c.value <= VALUE_ACE ) );
  assert( ( c.suit >= SPADES ) && ( c.suit <= CLUBS ) );
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break;
  case STRAIGHT: return "STRAIGHT"; break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
  case TWO_PAIR: return "TWO_PAIR"; break;
  case PAIR: return "PAIR"; break;
  case NOTHING: return "NOTHING"; break;
  default: return 0; break;
  }
}

char value_letter(card_t c) {
  switch(c.value){
  case VALUE_ACE: return 'A'; break;
  case VALUE_KING: return 'K'; break;     
  case VALUE_QUEEN: return 'Q'; break;
  case VALUE_JACK: return 'J'; break;
  default: return ('0' + c.value%10); break;
  }
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES: return 's'; break;
  case HEARTS: return 'h'; break;
  case DIAMONDS: return 'd'; break;
  case CLUBS: return 'c'; break;
  default: return 0;  break;
  }
}

void print_card(card_t c) {
  printf( "%c", value_letter( c ) );
  printf( "%c", suit_letter( c ) );
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '0': value_let = '0' + 10; break;
  case 'J': value_let = '0' + VALUE_JACK; break;
  case 'Q': value_let = '0' + VALUE_QUEEN; break;
  case 'K': value_let = '0' + VALUE_KING; break;
  case 'A': value_let = '0' + VALUE_ACE; break;
  default: break;
  }
  
  temp.value = value_let - '0';
  
  switch(suit_let){
  case 's': suit_let = '0'; break;
  case 'h': suit_let = '1'; break;
  case 'd': suit_let = '2'; break;
  case 'c': suit_let = '3'; break;
  default: break;
  }
  
  temp.suit = suit_let - '0';
  
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = (c%13 + 2);
  temp.suit = c/13;
  return temp;
}
