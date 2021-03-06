#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

   /*
      Default constructor for the Card class.
      It could give repeated cards. This is OK.
      Most variations of Blackjack are played with
      several decks of cards at the same time.
   */
Card::Card() {
    int r = 1 + rand() % 4;
    switch (r) {
    case 1: Card::suit = OROS; break;
    case 2: Card::suit = COPAS; break;
    case 3: Card::suit = ESPADAS; break;
    case 4: Card::suit = BASTOS; break;
    default: break;
    }

    r = 1 + rand() % 10;
    switch (r) {
    case  1: Card::rank = AS; break;
    case  2: Card::rank = DOS; break;
    case  3: Card::rank = TRES; break;
    case  4: Card::rank = CUATRO; break;
    case  5: Card::rank = CINCO; break;
    case  6: Card::rank = SEIS; break;
    case  7: Card::rank = SIETE; break;
    case  8: Card::rank = SOTA; break;
    case  9: Card::rank = CABALLO; break;
    case 10: Card::rank = REY; break;
    default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
    string suitName;
    switch (Card::suit) {
    case OROS:
        suitName = "oros";
        break;
    case COPAS:
        suitName = "copas";
        break;
    case ESPADAS:
        suitName = "espadas";
        break;
    case BASTOS:
        suitName = "bastos";
        break;
    default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
    string rankName;
    switch (Card::rank) {
    case AS:
        rankName = "As";
        break;
    case DOS:
        rankName = "Dos";
        break;
    case TRES:
        rankName = "Tres";
        break;
    case CUATRO:
        rankName = "Cuatro";
        break;
    case CINCO:
        rankName = "Cinco";
        break;
    case SEIS:
        rankName = "Seis";
        break;
    case SIETE:
        rankName = "Siete";
        break;
    case SOTA:
        rankName = "Sota";
        break;
    case CABALLO:
        rankName = "Caballo";
        break;
    case REY:
        rankName = "Rey";
        break;
    default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string suitName;
    switch (Card::suit) {
    case OROS:
        suitName = "golds";
        break;
    case COPAS:
        suitName = "cups";
        break;
    case ESPADAS:
        suitName = "spades";
        break;
    case BASTOS:
        suitName = "clubs";
        break;
    default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string rankName;
    switch (Card::rank) {
    case AS:
        rankName = "Ace";
        break;
    case DOS:
        rankName = "Two";
        break;
    case TRES:
        rankName = "Three";
        break;
    case CUATRO:
        rankName = "Four";
        break;
    case CINCO:
        rankName = "Five";
        break;
    case SEIS:
        rankName = "Six";
        break;
    case SIETE:
        rankName = "Seven";
        break;
    case SOTA:
        rankName = "Page";
        break;
    case CABALLO:
        rankName = "Knight";
        break;
    case REY:
        rankName = "King";
        break;
    default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
   // Implemente the member functions of the Hand class here.
void Hand::addCard() {
    Card *newCard = new Card();
    cards.push_back(*newCard);
}

vector<Card> Hand::getCards() {
    return cards;
}

string Hand::showNewCard() {
    string newCard = "";

    string spanishRank = cards[cards.size()].get_spanish_rank();
    string spanishSuit = cards[cards.size()].get_spanish_suit();

    string englishRank = cards[cards.size()].get_english_rank();
    string englishSuit = cards[cards.size()].get_english_suit();

    newCard += "\n\t" + spanishRank + " de " + spanishSuit + "(" + englishRank + " of " + englishSuit + ")";

    return newCard;
}

void Hand::sumTotalValue() {
    double total = 0;
    int value;
    for (Card card : cards) {
        value = card.get_rank();
        switch (value)
        {
        case(10):
            value = 1; break;
        case(11):
            value = 1; break;
        case(12):
            value = 1; break;
        default:
            break;
        }

        total += value / 2.0;
    }

    totalValue = total;
}

double Hand::getTotalValue() {
    return totalValue;
}

   /* *************************************************
      Player class
      ************************************************* */
      // Implemente the member functions of the Player class here.
Player::Player(int m) {
    money = m;
    hand.addCard();
}

int Player::getMoney() {
    return money;
}

void Player::setMoney(int newBalance) {
    money = newBalance;
}

Hand Player::getHand() {
    return hand;
}

void Player::showHand() {
    for (Card card : hand.getCards()) {
        cout << "\n\t" << card.get_spanish_rank() << " de " << card.get_spanish_suit() << "\t";
        cout << "(" << card.get_english_rank() << " of " << card.get_english_suit() << ")" << endl;
    }
}