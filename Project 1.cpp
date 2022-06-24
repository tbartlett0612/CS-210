#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


void displayClocks(int& hours, int& minutes, int& seconds, char& colon, string& ampm, int& hour12){
  //Sets hour and AM/PM for 12 hour clock
    if(hours == 0){
      hour12 = 12;
      ampm = "A M";
    }
    if(hours > 0){
      hour12 = hours;
    }
    if(hours >= 12){
      ampm ="P M";
    }
    if(hours > 12){
      hour12 = hours - 12;
    }
    
    
  //Displays 12 and 24 hour clocks next to eachother
  cout << "**************************\t" << "**************************" << endl;
  cout << "*     12-hour clock      *\t" << "*     24-hour clock      *" << endl;
  cout << "*     ";
  cout << setfill('0') << setw(2);
  cout << hour12;
  cout << colon;
  cout << setfill('0') << setw(2);
  cout << minutes;
  cout << colon;
  cout << setfill('0') << setw(2);
  cout << seconds;
  cout << " " << ampm;
  cout << "       *\t*       ";
  cout << setfill('0') << setw(2);
  cout << hours;
  cout << colon;
  cout << setfill('0') << setw(2);
  cout << minutes;
  cout << colon;
  cout << setfill('0') << setw(2);
  cout << seconds << "         *" << endl;
  cout << "**************************\t" << "**************************" << endl;
}

void displayMenu(){
  //Displays Menu choices
  cout << "\t\t**************************" << endl;
	cout << "\t\t*  1-Add One Hour        *" << endl;
	cout << "\t\t*  2-Add One Minute      *" << endl;
	cout << "\t\t*  3-Add One Second      *" << endl;
	cout << "\t\t*  4-Exit Program        *" << endl;
	cout << "\t\t**************************" << endl;
}

void addHour(int& hours){
  //adds 1 hour when called from menu choice
  hours += 1;
  //loops back to 0 when hours hits 24
  if(hours > 23){
    hours = 0;
  }
}

void addMinute(int& minutes, int& hours){
  //adds 1 minute when function is called
  minutes += 1;
  //loops back to 0 when minutes hit 60, then adds 1 hour.
  if(minutes > 59){
    minutes = 0;
    addHour(hours);
  }
}

void addSecond(int& seconds, int& minutes, int& hours){
  //adds 1 second when function is called
  seconds += 1;
  //Loops back to 0 when seconds hit 60, then adds 1 mnute.
  if(seconds > 59){
    seconds = 0;
    addMinute(minutes, hours);
  }
}

int main() 
{
  
  int hour12 = 0;
  int hours = 11;
  int minutes = 59;
  int seconds = 5;
  char colon = ':';
  string ampm = "A M";
  int userChoice;
  string userString;
  bool exitProgram = false;
  
  //While loop to run clocks and menu. Takes user input to add hour, minute, or second. Also allows user to exit program.
  while(!exitProgram){
    displayClocks(hours, minutes, seconds, colon, ampm, hour12);//Calls function to display the clocks.
    displayMenu();//Calls the function to display the menu
    
    try{
      getline(cin, userString); //takes in user choice as a string
      for (int i = 0; i < userString.length(); i++){
        if (isdigit(userString[i]) == false){
          throw 505;
        }
        else{
          userChoice = stoi(userString);
        }
      }
    }
    catch(int myNum){
      cout << "Your selection is not a valid selection." << endl;
      userChoice = 0;
    }
    
    
    switch(userChoice){
      case 1:
        //call addHour function
        addHour(hours);
        break;
        
      case 2:
        //call addMinute function
        addMinute(minutes, hours);
        break;
        
      case 3:
        //call addSecond function
        addSecond(seconds, minutes, hours);
        break;
        
      case 4:
        //exits program
        cout << "Goodbye!" <<endl;
        exitProgram = true;
        break;
        
      default:
        //if userChoice is anything other than 1, 2, 3, or 4, prints out statement and loops back through while loop.
        cout << "Please choose 1, 2, 3, or 4." << endl;
        break;
    }
    
  }
    return 0;
}