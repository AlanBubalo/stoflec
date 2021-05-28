#include <iostream>
#include <string>
using namespace std;

unsigned int numberOfPlayers, you, playerTurn = 1, currentNumber = 1, game = 1;
short rotation = 1;

string word(unsigned int currentNumber, short &rotation);
void turn(unsigned int &playerTurn, unsigned int &currentNumber, short &rotation);
void wordsUntilYourTurn(unsigned int &playerTurn, unsigned int &currentNumber, short &rotation);

int main()
{
    cout << "Number of players: ";
    cin >> numberOfPlayers;
    cout << "Which player are you: ";
    cin >> you;
    while (game)
    {
        cout << "\n";
        wordsUntilYourTurn(playerTurn, currentNumber, rotation);
        cout << "\nYou say: ------ ";
        turn(playerTurn, currentNumber, rotation);
        cout << " ------\nContinue? (1: yes, 0: no) ";
        cin >> game;
    }
    return 0;
}

string word(unsigned int currentNumber, short &rotation)
{
    if ((currentNumber % 10 == 7 || currentNumber % 7 == 0) && currentNumber % 5 == 0)
    {
        rotation = -rotation;
        return "Oriada Stoflec";
    }
    if (currentNumber % 10 == 7 || currentNumber % 7 == 0)
    {
        rotation = -rotation;
        return "Stoflec";
    }
    if (currentNumber % 5 == 0)
        return "Oriada";
    return to_string(currentNumber);
}

void turn(unsigned int &playerTurn, unsigned int &currentNumber, short &rotation)
{
    cout << word(currentNumber, rotation);
    playerTurn += rotation;
    playerTurn = (playerTurn == 0) ? numberOfPlayers : playerTurn;
    playerTurn = (playerTurn > numberOfPlayers) ? 1 : playerTurn;
    currentNumber++;
}

void wordsUntilYourTurn(unsigned int &playerTurn, unsigned int &currentNumber, short &rotation)
{
    while (playerTurn != you)
    {
        turn(playerTurn, currentNumber, rotation);
        cout << ", ";
    }
}