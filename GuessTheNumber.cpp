#include <iostream>
#include <random>
using namespace std ;
int main() {

    string name ; 
    cout<<"________________________________GUESS NUMBER______________________________"<<endl  ; 

    cout<<" Enter your name "<<endl  ; 
    cin>>name ;

    cout<<" Hello "<<name<<" I thought a number between 0 - 100 . Can you please guess it for me "<<endl ; 

    int number; 
    int random_number = (rand()% 100) + 1;
    int attempts = 0; 
    
  while (true) {

    attempts++; 
    cout<<"\n Guess a number between 0 - 100  "<<endl  ;
    cin>>number;
    
    if (number<0 || number >100 ) {
      cout<<"\n Please enter a number between 0-100 "<<endl  ; 
      continue;
    }
     
    else if (number > random_number) {
      cout<<" \n Wrong guess . your guess is too high " <<endl ; 
      continue;
    }

    else if (number < random_number) {
      cout<<" \n Wrong guess . your guess is too  low  "<<endl  ; 
      continue;
    }

    else {
      cout << "\n Congratulations! You've guessed the number " << random_number << " correctly in " <<attempts << " attempts." << endl  ; 
      break ; 
    } 
  }     
    return 0;
}