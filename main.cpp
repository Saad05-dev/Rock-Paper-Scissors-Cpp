#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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

enum gameChoice
{
    Rock = 1,
    Paper = 2,
    Scissor = 3
};

gameChoice choiceConvert(int choice)
{
    if (choice == 1)
        return gameChoice::Rock;
    else if(choice == 2)
        return gameChoice::Paper;
    else
        return gameChoice::Scissor;
}

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

gameChoice computerChoice()
{
    int choice = rand() % 3 + 1;
    
    return choiceConvert(choice);
}

int main()
{
    srand((unsigned)time(NULL));

    numberOfRounds();
    cout << playerChoice() << endl;
    cout << computerChoice() << endl;


    return 0;
}