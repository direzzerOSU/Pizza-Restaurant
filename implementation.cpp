#include "header.hpp"
#include<cctype>
#include<locale>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

// //###########################################################
// // function prototypes                                    //#
// void welcomeScreen();                                     //#
// restaurant::restaurant(std::ifstream& restFile);          //#
// void restaurant::setName(ifstream file);                  //#
// string restaurant::getName();                             //#
// string restaurant::getPhone();                            //#
// string restaurant::getAddress();                          //#
// int restaurant::getDaysOpen();                            //#
// std::map<char, string> restaurant::getHours();            //#
// employee::employee();                                     //#
// void employee::setRestaurant(restaurant x);               //#
// string employee::getRestaurantName();                     //#
// void employee::updateHours(std::map<char, string> hours); //#
// //###########################################################

void welcomeScreen(){
 cout << "\nWelcome to DiGiorno's Pizza!" << endl;
 cout << "Are you a customer (C) or an employee (E)? Or would you like to quite (Q)?" << endl;
 char menuSelection;
 while(toupper(menuSelection) != 'Q' && toupper(menuSelection) != 'E' && toupper(menuSelection) != 'C'){
   cin >> menuSelection;
   if(toupper(menuSelection) == 'E'){
     // cout << "What would you like to do?" << endl;
     // cout << "\n  1. Change hours\n  2. View orders\n  3. Remove order\n  4. Add item to menu\n  5. Remove item from menu" << endl;
     // char toDo = '';
     // cin >> toDo;
     // if(toDo == '1'){
     //   updateHours();
     // }
   }
   else if(toupper(menuSelection) == 'C'){
     // initiate customer function
   }
   else if(toupper(menuSelection) == 'Q'){
     // terminate program
     break;
   }
   else{
     cout << "Whoops! That is not a valid option... Please try again." << endl;
   }
 }
}

restaurant::restaurant(std::ifstream& restFile){
  if(restFile){
    getline(restFile, name);
    getline(restFile, phone);
    getline(restFile, address);
    restFile >> numDaysOpen;
    while(restFile.good()){
      char day;
      restFile >> day;
      string open = "";
      string close = "";
      restFile >> open;
      restFile >> close;
      if(open != "" && close != ""){
        storeHours[day] = open + "-" + close;
        // cout << "storeHours[" << day << "] = " << storeHours[day] << endl;
      }
    }
  }
  else{
    cout << "Unable to open file... Please try again." << endl;
  }
}

void restaurant::setName(ifstream file){
  if(file){
    getline(file, name);
  }
}

string restaurant::getName(){
  return name;
}

string restaurant::getPhone(){
  return phone;
}

string restaurant::getAddress(){
  return address;
}

int restaurant::getDaysOpen(){
  return numDaysOpen;
}

std::map<char, string> restaurant::getHours(){
  // std::map<char, std::string> *pointer = &storeHours;
  // pointer = &storeHours;
  // return pointer;
  return storeHours;
}

void restaurant::setHours(char a, string s){
  storeHours[a] = s;
}

employee::employee(){
  int id;
  std::string firstName = "";
  std::string lastName = "";
  std::string password = "";
  restaurant* restaurantName;
}

void employee::setRestaurant(restaurant x){
  restaurant* pointer;
  pointer = &x;
  restaurantName = pointer;
}

string employee::getRestaurantName(){
  return restaurantName->getName();
}

void employee::updateHours(std::map<char, string> hours){
  cout << endl << "Employee update to restaurant hours..." << endl;
  cout << "Current hours are as follows:" << endl << endl;

  cout << "Sunday    (S)    " << hours['S'] << endl;
  cout << "Monday    (M)    " << hours['M'] << endl;
  cout << "Tuesday   (T)    " << hours['T'] << endl;
  cout << "Wednesday (W)    " << hours['W'] << endl;
  cout << "Thursday  (H)    " << hours['R'] << endl;
  cout << "Friday    (F)    " << hours['F'] << endl;
  cout << "Saturday  (X)    " << hours['X'] << endl << endl;

  cout << "What day would you like to update restaurant hours?\n";
  cout << "Please enter the day's corresponding character..." << endl;
  char input;
  while(toupper(input) != 'S' && input != 'M' && input != 'T' && input != 'W' && input != 'R' && input != 'F' && input != 'X'){
    cin >> input;
  }
  cout << endl << "Please enter the new restaurant hours..." << endl;
  string inputHours;
  cin.ignore(256, '\n');  // ignore some chars until line feed is reached
  getline(cin, inputHours);
  // restaurantName->storeHours[input] = inputHours;
  restaurantName->setHours(input, inputHours);

  // cout << hours[input] << endl;
}

int main(){
 welcomeScreen();
 ifstream file;
 file.open("/Users/ryandirezze/Documents/OSU/CS_162_old2/Assignment_2/restaurant_info.txt");
 restaurant Bytes = restaurant(file);

 employee ryan = employee();
 ryan.setRestaurant(Bytes);
 // cout << ryan.getRestaurantName() << endl;
 ryan.updateHours(Bytes.getHours());
 auto a = Bytes.getHours();
 cout << a['S'] << endl;

 return 0;
}
