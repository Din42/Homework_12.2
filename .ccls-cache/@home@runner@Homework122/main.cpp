#include <iostream>
#include <time.h>


using namespace std;

int main()
{
int number, userNumber, level, lives;
srand(time(NULL));
cout << "\nИгра угадай число!\n\n";
cout << "Выберите уровень (1 или 2):\n";
cin >> level;

if (level == 1)
  {
    number = rand() % 10 + 1;
    lives = 5;
  }
else 
  {
    number = rand() % 100 + 1;
    lives = 25;
  }

cout << "У тебя есть " << lives << " жизней" << endl;

while (true)
  {
    cout << "Угадай число:\n";
    cin >> userNumber;

    if (userNumber == number)
      {
        cout << "Ты победил!" << endl;

        if (level == 1)
            cout << "Твой счет:\n" << lives * 5 << endl;
        else 
            cout << "Твой счет:\n" << lives * 10 << endl;

        break;
      }
    else
      {
        lives--;

        if (lives == 0)
          {
            cout << "Вы потерпели неудачу!" << endl;
            break;
          }
        else
          {
            cout << "Неправильный номер! Жизни: " << lives << endl;

            cout << "Хочешь подсказку? (y/n): ";
            char answer;
            cin >> answer;

            if (answer == 'y')
              {
                if (userNumber < number)
                    cout << "Число больше, чем ваше число" << endl;
                else 
                    cout << "Число меньше вашего числа" << endl;

                    lives--;
                    cout << "Жизни: " << lives << endl;
              }
          }
      }
  
  }

return 0;
}