// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

class Card {
private:
    char rank;
    char suit;

public:
    Card();
    Card(char rank, char suit);
    void show();
    int compare(Card other);
};

#endif
