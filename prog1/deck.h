// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck {
private:
    Card cards[52];
    int nextCardIndex;

public:
    Deck();
    Card deal();
    void show();
    void shuffle();
};

#endif
