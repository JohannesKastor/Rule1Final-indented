#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>



using namespace std;



int main() {

//Deklaration av variabler

int blc = 1000;    //Detta deklarerar startbeloppet och variabeln "balance".
int ins_blc = 100; //Detta står för "insufficient balance".
int trs_money;     //Detta står för "transfer money".
char playagain;    //Detta står för "Spela igen".
int bet;           //Jag anser att detta är självförklarande. 
int age;           //Detta är spelarens ålder.
int numb;          //Detta är vilket nummer spelaren väljer.
char color;        //Detta är vilken färg spelaren väljer.
int intcolor;      //Detta konverterar spelarens färg till antingen en 1 eller 0.

//Välkomnshälsning

cout << "Hi And welcome to.. \n";
cout << 
" ______    __   __  ___      _______         ____  \n"
"|    _ |  |  | |  ||   |    |       |       |    | \n"
"|   | ||  |  | |  ||   |    |    ___| ____   |   | \n"
"|   |_||_ |  |_|  ||   |    |   |___ |____|  |   | \n"
"|    __  ||       ||   |___ |    ___|        |   | \n"
"|   |  | ||       ||       ||   |___         |   | \n"
"|___|  |_||_______||_______||_______|        |___| \n";

//Ålderskontroll på spelaren

cout << "To start playing we have to make sure that you are 18 or above..\n";
cout << "Please enter your age:";
cin  >> age;
cout << endl;
if (age >= 18)

{

//Meddelande om psykiskhälsa kopplat till spelberoende 

  cout << "The proportion with some degree of gambling problems in the past year\n"
  "is around 4 percent in the Swedish population. \n"
  "130 000 people share a household with someone experiencing gambling problems.\n"
  "If you or someone close to you is struggling with addiction please call +46 208 191 00 \n";
  cout << endl;


  cout << "As a first time playing you are rewarded with 1000kr \n";
  cout << "Current balance:      ";
  cout << blc;    
  cout << "\n";        

}

else
 {

  return 0;
}

//En "do-loop" som loopar spelandet så länge spelaren anger [Y]
                                                                     
do 
{ 

  //Detta kollar om spelaren har mer än 100kr.


  if (blc >= ins_blc)
      {cout << "You have enough in your balance to play! \n";
      cout << endl;
    }

  //Spelaren har mindre än 100kr och måste sätta in ett belopp.

    else 
    {

        bool validtrs = false;

        while (!validtrs) {
          {
              std::cout << "How much money would you like to transfer? \n";
              cin >> trs_money; 
          }

  //Spelaren måste ange ett belopp som är mellan 0-3000 kr.

          if (trs_money >= 0 && trs_money <= 3000)
          {
            validtrs=true;
            blc = blc + trs_money;
            cout <<"You have transferred      "<<trs_money;
            cout<< endl;
          }
            else {
            cout <<"Invalid bet. Please enter a value between 0-3000.";

          }
        
      }
    }


    
      
  //En loop för att se till så att spelaren måste välja rätt summa

  bool validchoice = false;

  while (!validchoice) {
      std::cout << "Would you like to bet 100/300/500kr?";
      std::cin >> bet;
      
      if (bet == 100 && blc >= 100 || bet==300  && blc >= 300 || bet==500 && blc >= 500)
    {
        validchoice = true;
        std::cout << "You have betted:      " << bet <<std::endl;
        blc = blc - bet;
        cout <<"Current Balance:      ";
        cout << blc << endl;
        cout << endl;
    }
    
    else
    {

      std:: cout <<"Invalid bet. Please select again."<< std::endl;
    }

  }


  //en whileloop för att se till så att spelaren väljer en giltig siffra.


  bool validnumb = false;

  while (!validnumb) {
      cout << "Choose a number beetween 1-36?";
      cin >> numb;
      
      if (numb > 0 && numb < 36)

    {
        validnumb = true;
      
    }
    else
    {
        std:: cout <<"Invalid number. Please select again."<< std::endl;
      
    }
  }

  //en whileloop för att se till så att spelaren väljer en giltig färg

  bool validcolor = false;

  while (!validcolor) {
      std::cout << "Choose black or red (press [B] for black and [R] for red)";
      std::cout << endl;
      std::cin >> color;

      if (color == 'b' || color == 'B'|| color == 'r' || color == 'R'  )
    {
        validcolor = true;
    
    }
    
    else
    {
        std:: cout <<"Invalid choice. Please select again."<< std::endl;
        continue;
    }
  }

  //Detta konverterar Svart till "1" och Röd till "0".

  if (color == 'b' || 'B' )
  {
    intcolor = 1;
    cout << "Your final selection is " <<bet; cout <<":-  on  "; cout << "Black:    "<< numb;
    
  }
  else {
    intcolor = 0;
    cout << "Your final selection is " <<bet; cout <<":-  on  "; cout << "Red:    "<< numb;
    
  }

  /* Detta är en funktion för att det ska se ut som att randomatiseringsprocessen
  tar lite tid på sig, i själva verket så kommer randomatiseringen efter denna */ 

      std::cout <<endl;
      std::cout << "Loading super advanced algoritm";
      while (true)
      {   
          sleep(1);
          std::cout << "." << std::flush;
          sleep(1);
          std::cout << "." << std::flush;
          sleep(1);
          std::cout << "." << std::flush;
          sleep(1);
          std::cout << "\b\b\b   \b\b\b" << std::flush;
          break;
      }

  //Randomatisering av 1-37

  srand(time(0));
  int randomNumb = rand() % 36 + 1;
  cout << "\n";

  //Randomatisering av 0-1 (Svart/Röd)

  srand(time(0));
  int const randomColor = rand() % 2;

  //Detta visar spelaren resultatet av färg och nummer. 

  if (randomColor == 1)
  {
  cout << "Randomised results were Black:           " <<randomNumb;
  cout <<endl;
  cout <<endl;
  
  }

  else {
    cout << "Randomised results were Red:            " << randomNumb;
    cout <<endl;
    cout <<endl;
  }

    if (randomColor == intcolor && randomNumb == numb)
  {
    blc = blc + bet + (bet * 30);
      cout << "Holy Cow! Both your color and number was right..   ";
      cout << "You won:   ";
      cout <<  (bet + (bet * 30)) << endl;
      cout << "Current balance:  ";
      cout << blc << endl;
  }
else if (randomNumb == numb)
{
  blc = blc + bet + (bet * 10);
    cout << "Your number was right:  ";
    cout << "You won:   ";
    cout << (bet + (bet * 10)) << endl;
    cout << "Current balance:  ";
    cout << blc << endl;
  

}
else if (randomColor == intcolor)
  { blc = blc + bet + (bet * 2);
      cout << "Your color was right!!" << endl;
      cout << "You won:   ";
      cout <<  (bet + (bet * 2)) << endl;
      cout << "Current balance:  ";
      cout << blc << endl;
    
  }

else if(randomColor != intcolor && randomNumb != numb)
  {
    cout << "Sorry! you didn't win this round..";
    cout << endl;
  }

  //Detta gratulerar vinnaren om nummer var rätt.



  //Denna fråga är en del av "do-loopen" den frågar om spelaren vill spela igen.

  cout << "Would you like to play again? \n If Yes press [Y] or [N] for No.";

  cin >> playagain;


} 

while (playagain == 'y' || playagain == 'Y');


return 0;   }
    



