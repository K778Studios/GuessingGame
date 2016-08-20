#include <iostream>
#include <cstdlib>

using namespace std;

class GuessGame
{
	private:
		int earnings;
		int guess;
		int amountRaise;
		int randomInt;
	public:
		GuessGame();
		void process();
		bool hasEarnings();

};

GuessGame::GuessGame()
{
	earnings = 500;
	cout << "**************************************\n This is the guessing game, in which you\n guess 'higher' or 'lower'\n and an amount to raise it by\n**************************************" << endl;
}

void GuessGame::process()
  {
    cout << "You have this much earnings: " << earnings << endl;
    cout << "What do you guess is the random number from 1-10?" << endl;
    
    randomInt = rand() % 10 + 1;
    cin >> guess;
    
    cout << "How much would you like to raise?" << endl;
    cin >> amountRaise;

    while (amountRaise > earnings)
    {
      cout << "How much would you like to raise?" << endl;
      cin >> amountRaise;
    }
    
    if (guess == randomInt)
    {
      earnings += amountRaise;
      cout << "Correct guess" << endl;
    }
    else
    {
      earnings -= amountRaise;
      cout << "The correct guess was " << randomInt << endl;
    }
    
  }

bool GuessGame:: hasEarnings()
  {
    if (earnings > 0)
      return true;
    else
      return false;
  }




int main()
{
	GuessGame guess;
    
    while (guess.hasEarnings() == true)
    {
      guess.process();
    }
    
    if (guess.hasEarnings() == false)
	{
      cout << "Sorry you lost all of your earnings" << endl;
	}
	system("PAUSE");
	return 0;
}