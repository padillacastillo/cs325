// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#include "card.h"
#include <iostream>
using namespace std;

namespace {
    char RANK_ORDER[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int NUM_RANKS = 13;

    int rankIndex(char rank) {
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rank == RANK_ORDER[i]) return i;
        }
        return -1;
    }
}

Card::Card() {
    rank = ' ';
    suit = ' ';
}

Card::Card(char rank, char suit) {
    this->rank = rank;
    this->suit = suit;
}

void Card::show() {
    if (rank == 'T') {
        cout << "10" << suit;
    } else {
        cout << rank << suit;
    }
}

// Returns 1 if this card outranks other, -1 if it's lower, 0 if equal.
int Card::compare(Card other) {
    int thisRank = rankIndex(rank);
    int otherRank = rankIndex(other.rank);

    if (thisRank > otherRank) return 1;
    else if (thisRank < otherRank) return -1;
    else return 0;
}
