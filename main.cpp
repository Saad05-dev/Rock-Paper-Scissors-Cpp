#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int wins,losses,draws = 0;

//Number of rounds the player wants to play
int numberOfRounds()
{
    int N;
    do
    {
        cout << "Enter number of rounds: ";
        cin >> N;
    } while ( N <= 0);
    return N;
}
//To keep track of player's and computer's choices
enum gameChoice
{
    Rock = 1,
    Paper = 2,
    Scissor = 3
};
// Converts a valid choice number (1–3) to its corresponding gameChoice.
gameChoice choiceConvert(int choice)
{
    if (choice == 1)
        return gameChoice::Rock;
    else if(choice == 2)
        return gameChoice::Paper;
    else
        return gameChoice::Scissor;
}
//Asks for player's choice
gameChoice playerChoice()
{
    string play = "";
    int N;
    bool isInvalid = false;
    do
    {
        if(isInvalid)
            cout << "\n>>Invalid choice! Please choose again.\n\n";

        cout << "Your choice: [1]:Rock, [2]:Paper, [3]:Scissor.\n";
        cin >> N;

        isInvalid = N <= 0 || N > 3;
    } while ( isInvalid );

    return choiceConvert(N);
}
// Generates a random number from 1 to 3 and converts it to a gameChoice.
gameChoice computerChoice()
{
    int choice = rand() % 3 + 1;
    
    return choiceConvert(choice);
}

//Win Condition
string winCondition(gameChoice player,gameChoice computer)
{
    int result = (static_cast<int>(player) - static_cast<int>(computer) + 3) % 3;

    if (result == 0)
    {
        draws++;
        return "No Winner";
    }
    else if (result == 1)
    {
        wins++;
        return "Player";
    }
    else
    {
        losses++;
        return "Computer";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    numberOfRounds();
    cout << playerChoice() << endl;
    cout << computerChoice() << endl;


    return 0;
}