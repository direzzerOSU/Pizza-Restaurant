#include "header.hpp"
#include<cctype>
#include<locale>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

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

void Restaurant::load_data(){
  ifstream restaurant_info;
  restaurant_info.open("/Users/ryandirezze/Documents/OSU/CS_162_old2/Assignment_2/restaurant_info.txt");
  if(restaurant_info){
    getline(restaurant_info, name);
    getline(restaurant_info, phone);
    getline(restaurant_info, address);
    int numDaysOpen = 0;
    restaurant_info >> numDaysOpen;
    week = new hours[numDaysOpen];
    // while(restaurant_info.good()){
    for(int n=0; n<numDaysOpen; n++){
      restaurant_info >> week[n].day;
      restaurant_info >> week[n].open_hour;
      restaurant_info >> week[n].close_hour;
      // if(week->open_hour != "" && week->close_hour != ""){
      //   week[week->day] = week->open_hour + "-" + week->close_hour;
        // cout << "storeHours[" << day << "] = " << storeHours[day] << endl;
      // }
    }
  }
  else{
    cout << "Unable to open file... Please try again." << endl;
  }
}

bool login(std::string id, std::string password)

void Restaurant::view_hours(){
  for(int n=0; n<7; n++){
    cout << week[n].day << " " << week[n].open_hour << " " << week[n].close_hour << endl;
  }
}

int main(){
  Restaurant Bytes;
  Bytes.load_data();
  Bytes.view_hours();

  return 0;
}
