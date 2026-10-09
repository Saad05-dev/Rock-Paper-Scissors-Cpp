#include <iostream>
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

int main()
{

    numberOfRounds();

    return 0;
}