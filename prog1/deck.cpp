// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

namespace {
    int DECK_SIZE = 52;
    int RANKS_PER_SUIT = 13;
}

Deck::Deck() {
    char suits[] = {'C', 'S', 'D', 'H'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int i = 0;
    for (char suit : suits) {
        for (char rank : ranks) {
            cards[i++] = Card(rank, suit);
        }
    }
    nextCardIndex = 0;
}

void Deck::show() {
    for (int i = 0; i < DECK_SIZE; i++) {
        cards[i].show();
        cout << ( (i + 1) % RANKS_PER_SUIT == 0 ? "\n" : ", " );
    }
}

void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; i++) {
        int swapIndex = i + (rand() % (DECK_SIZE - i));
        Card tmp = cards[i];
        cards[i] = cards[swapIndex];
        cards[swapIndex] = tmp;
    }
    nextCardIndex = 0;
}

Card Deck::deal() {
    return cards[nextCardIndex++];
}
