// Name: Cris Padilla Castillo
// CECS 325-02

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <time.h>
using namespace std;


namespace {
    char RANK_ORDER[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int NUM_RANKS = 13;
}


struct Player {
    string name;
    int win;
    int lose;
    int tie;
};


class Card {
private:
    char rank;
    char suit;


public:
    Card(char rank, char suit);
    void display();
    int compare(Card other);
};


class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    Card deal();
    void display();
    void shuffle();
    bool isEmpty();
};


Card::Card(char rank, char suit) {
    this->rank = rank;
    this->suit = suit;
}


void Card::display() {
    if (rank == 'T') {
        cout << "10" << suit;
    } else {
        cout << rank << suit;
    }
}


int Card::compare(Card other) {
    int thisRank = -1;
    int otherRank = -1;
    for (int i = 0; i < NUM_RANKS; i++) {
        if (rank == RANK_ORDER[i]) thisRank = i;
        if (other.rank == RANK_ORDER[i]) otherRank = i;
    }

    if (thisRank > otherRank) return 1;
    else if (thisRank < otherRank) return -1;
    else return 0;
}


Deck::Deck() {
    char suits[] = {'C', 'S', 'D', 'H'};
    for (char suit : suits) {
        for (char rank : RANK_ORDER) {
            cards.push_back(Card(rank, suit));
        }
    }
}


Card Deck::deal() {
    if (isEmpty()) {
        throw runtime_error("Deck is empty");
    }
    Card top = cards.front();
    cards.erase(cards.begin());
    return top;
}


void Deck::display() {
    int size = cards.size();
    for (int i = 0; i < size; i++) {
        cards[i].display();
        cout << ( (i + 1) % NUM_RANKS == 0 || i == size - 1 ? "\n" : "," );
    }
}


void Deck::shuffle() {
    srand(time(0));
    int size = cards.size();
    for (int i = 0; i < size; i++) {
        int swapIndex = i + (rand() % (size - i));
        Card tmp = cards[i];
        cards[i] = cards[swapIndex];
        cards[swapIndex] = tmp;
    }
}


bool Deck::isEmpty() {
    return cards.empty();
}


int main() {
    Player player1 = {"", 0, 0, 0};
    Player player2 = {"", 0, 0, 0};
    int numGames;

    Deck deck;

    cout << "Enter the name of the first player: ";
    getline(cin, player1.name);
    cout << "Enter the name of the second player: ";
    getline(cin, player2.name);
    cout << "How many games will they play? ";
    cin >> numGames;

    cout << "\n Original Deck\n";
    deck.display();

    deck.shuffle();
    cout << "\n Shuffled Deck\n";
    deck.display();

    try {
        for (int game = 1; game <= numGames; game++) {
            Card player1Card = deck.deal();
            Card player2Card = deck.deal();

            cout << "\nGame " << game << "\n--------\n";
            cout << "        " << player1.name << "=>"; player1Card.display(); cout << endl;
            cout << "        " << player2.name << "=>"; player2Card.display(); cout << endl;

            int result = player1Card.compare(player2Card);
            if (result == 1) {
                cout << player1.name << "=> Winner\n";
                player1.win++;
                player2.lose++;
            } else if (result == -1) {
                cout << player2.name << "=> Winner\n";
                player2.win++;
                player1.lose++;
            } else {
                cout << "Tie game\n";
                player1.tie++;
                player2.tie++;
            }
        }
    } catch (runtime_error& e) {
        cout << "Error - " << e.what() << endl;
    }

    cout << "------Final Stats-------\n";
    cout << "       " << player1.name << " vs. " << player2.name << endl;
    printf("Wins   %-9d %d\n", player1.win, player2.win);
    printf("Losses %-9d %d\n", player1.lose, player2.lose);
    printf("Ties   %-9d %d\n", player1.tie, player2.tie);

    return 0;
}
