#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int wins = 0, losses = 0, draws = 0;
//To prevent player from typing chars or strings
int readInt()
{
    int x;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter a number: ";
    }
    return x;
}
//Number of rounds the player wants to play
int numberOfRounds()
{
    int N;
    do
    {
        cout << "Enter number of rounds: ";
        N = readInt();
        cout << "\n";
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
    switch (choice)
    {
    case 1:
        return gameChoice::Rock;
    case 2:
        return gameChoice::Paper;
    default:
        return gameChoice::Scissor;
    }
}
string choiceToString(gameChoice choice)
{
    switch (choice)
    {
    case gameChoice::Rock:
        return "Rock";
    case gameChoice::Paper:
        return "Paper";
    case gameChoice::Scissor:
        return "Scissor";
    default:
        return "Unknown";
    }
}
//Asks for player's choice
gameChoice playerChoice()
{
    int N;
    bool isInvalid = false;
    do
    {
        if(isInvalid)
            cout << "\n>>Invalid choice! Please choose again.\n\n";

        cout << "Your choice: [1]:Rock, [2]:Paper, [3]:Scissor.\n";
        N = readInt();

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
string winner()
{
    if (wins > losses)
        return "Player";
    else if(losses > wins)
        return "Computer";
    else
        return "Tie!";
}
//Simulate rounds
void rounds(int numRounds)
{
    for (int i = 1; i <= numRounds; i++)
    {
        cout << "Round[" << i << "] begins:\n";
        gameChoice player = playerChoice();
        gameChoice computer = computerChoice();

        cout << "\n_____________Round[" << i << "]_____________\n";
        cout << "Player's choice  : " << choiceToString(player) << "\n";
        cout << "Computer's choice: " << choiceToString(computer) << "\n";
        cout << "Round winner     : " << winCondition(player,computer) << "\n";
        cout << "\n__________________________________\n";
    }
    
}
//Display the total scores of wins and losses ad draws
void scores(int numRounds)
{
    cout << "\n\n";
    cout << "\t\t___________________________________________________________________________\n\n";
    cout << "\t\t                         +++ G a m e  O v e r\n\n";
    cout << "\t\t___________________________________________________________________________\n\n";
    cout << "\t\t_________________________[Game Results]____________________________________\n\n";
    cout << "\t\tGame rounds         : " << numRounds << "\n";
    cout << "\t\tPlayer won times    : " << wins << "\n";
    cout << "\t\tComputer won times  : " << losses << "\n";
    cout << "\t\tDraw times          : " << draws << "\n";
    cout << "\t\tFinal Winner        : " << winner() <<"\n";
    cout << "\t\t___________________________________________________________________________\n\n";
}
//Run an actual game of Rock, Paper, Scissor
void game()
{
    char again;
    do
    {
        wins = losses = draws = 0;   // reset scores

        int num = numberOfRounds();
        rounds(num);
        scores(num);

        cout << "\n\n\t\tDo you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    game();


    return 0;
}