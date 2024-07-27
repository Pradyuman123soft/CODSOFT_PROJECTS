#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(nullptr));
    int Randomnumber = rand() % 100 + 1;
    // cout << "The Random number is : " << Randomnumber;
    int GuessNumber = 0;

        cout << "Welcome To The Number Guessing Game....!" << endl;
        cout << "Let see That You can Guess My Number Between 1 to 100...!" << endl;
    while (GuessNumber != Randomnumber)
    {
        cout << "Enter Your Guess Number: " << endl;
        cin >> GuessNumber;
        if (GuessNumber < Randomnumber)
        {
            cout << "Guess Number Is to less" << endl;
        }
        else if (GuessNumber > Randomnumber)
        {
            cout << "Guess Number Is To High" << endl;
        }
        else
        {
            cout<<"Congratulations Your Guess is Correct...!";
        }
        
    }

    return 0;
}