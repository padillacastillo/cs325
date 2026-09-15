#include <iostream> // lets us use input/output tools like cout and endl
#include <random>   // gives us random number tools (not used here, but included)
#include <cstdlib>  // gives us functions like rand() and EXIT codes
#include "deck.h"   // tells C++ about the Deck and card class definitions
using namespace std; // lets us write cout instead of std::cout

card::card() // this is the constructor for a single card object
{
    rank = 0;   // default rank is 0, which means "empty/no card"
    suit = 0;   // default suit is 0, which means "empty/no card"
    value = 0;  // default value is 0, same idea
}

Deck::Deck() // this is the constructor for a whole deck of cards
{
    int index = 0; // index keeps track of where we are inside the cards array

    for (int suitNumber = 1; suitNumber <= 4; ++suitNumber) // go through 4 suits: hearts, diamonds, clubs, spades
    {
        for (int rankNumber = 1; rankNumber <= 13; ++rankNumber) // go through ranks 1 to 13 (Ace to King)
        {
            cards[index].rank = rankNumber; // store this rank in the current card slot
            cards[index].suit = suitNumber; // store this suit in the current card slot
            cards[index].value = rankNumber; // for now, card value equals rank number
            ++index; // move to the next spot in the deck array
        }
    }
}

card Deck::deal() // this function gives the user one card from the deck
{
    for (int index = 0; index < 52; ++index) // check each slot in the deck
    {
        if (cards[index].rank != 0) // if this slot is not empty, it still has a card
        {
            card dealtCard = cards[index]; // copy the card we are about to deal
            cards[index] = card(); // replace that slot with an empty card object
            return dealtCard; // return the card to whoever called this function
        }
    }

    return card(); // if no cards are left, return an empty/default card
}

void Deck::show() // print every card still in the deck
{
    for (int index = 0; index < 52; ++index) // look at each slot in the deck
    {
        if (cards[index].rank != 0) // only print cards that are still there
        {
            cout << cards[index].rank << " " // print the rank number
                 << cards[index].suit << " " // print the suit number
                 << cards[index].value << endl; // print the value and move to next line
        }
    }
}

void Deck::shuffle() // mix up the cards in the deck
{
    for (int index = 51; index > 0; --index) // start from the last card and move backward
    {
        int otherIndex = rand() % (index + 1); // pick a random index from 0 to index
        card temporary = cards[index]; // save the current card in a temporary variable
        cards[index] = cards[otherIndex]; // swap current card with random card
        cards[otherIndex] = temporary; // put the saved card into the random slot
    }
}