// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
using namespace std;

namespace {
    int NUM_ROUNDS = 26;
}

int main() {
    string player1Name, player2Name;
    int player1Wins = 0, player2Wins = 0, ties = 0;

    Deck deck;

    cout << "Enter the name of the first player: ";
    getline(cin, player1Name);
    cout << "Enter the name of the second player: ";
    getline(cin, player2Name);

    cout << "\nOriginal Deck\n";
    deck.show();

    deck.shuffle();
    cout << "\nShuffled Deck\n";
    deck.show();

    for (int round = 1; round <= NUM_ROUNDS; round++) {
        cout << "\nGame " << round << "\n--------\n";
        Card player1Card = deck.deal();
        Card player2Card = deck.deal();

        cout << "        " << player1Name << "=>"; player1Card.show(); cout << endl;
        cout << "        " << player2Name << "=>"; player2Card.show(); cout << endl;

        int result = player1Card.compare(player2Card);
        if (result == 1) {
            cout << player1Name << "=> Winner\n";
            player1Wins++;
        } else if (result == -1) {
            cout << player2Name << "=> Winner\n";
            player2Wins++;
        } else {
            cout << "Tie game\n";
            ties++;
        }
    }

    cout << "\n------Final Stats-------\n";
    cout << "      " << player1Name << " vs. " << player2Name << endl;
    printf("Wins   %-12d %-12d\n", player1Wins, player2Wins);
    printf("Losses %-12d %-12d\n", player2Wins, player1Wins);
    printf("Ties   %-12d %-12d\n", ties, ties);

    return 0;
}
