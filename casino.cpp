#include <iostream>
#include <string> 
#include <cstdlib> //  to create random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance; 
    int bettingAmount;
    int guess;
    int dice; //  to stores the casino number
    char choice;
    srand(time(0)); 
    cout << "\n\t\t========WELCOME TO WORLD LARGEST CASINO HUB=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : Rs";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is RS. " << balance << "\n";
// function to get the betting balance
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : Rs.";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// function to ask the player to guess the number
        do
        {
            cout << "Guess any  number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1; // Trick of the casino
        if(dice == guess)
        {
            cout << "\n\nCONGRATS YOUR LUCK DUDE!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "OOPS, NOT THE ONE !! BETTER LUCK NEXT TIME !! You lost Rs. "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of Rs " << balance << "\n";
        if(balance == 0)
        {
            cout << "YOU HAVE NO MONEY TO PLAY !! REFIL IT  ";
            break;
        }
        cout << "\n\n-->WANT TO PLAY AGAIN ?? (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is Rs. " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======CASINO RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. WINNER EARN 10 TIMES OF THE BET MONEY\n";
    cout << "\t3. WRONG BET !! YOU LOOSE THE WHOLE MONEY THAT YOU HAVE PUT IN FOR BETTING\n\n";
}


