#include "header.hpp"
#include<cctype>
#include<locale>
#include<sstream>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void Restaurant::welcomeScreen(){
 cout << "\nWelcome to DiGiorno's Pizza!" << endl;
 cout << "Are you a customer (C) or an employee (E)? Or would you like to quite (Q)?" << endl;
 char menuSelection;
 while(toupper(menuSelection) != 'Q' && toupper(menuSelection) != 'E' && toupper(menuSelection) != 'C'){
   cin >> menuSelection;
   if(toupper(menuSelection) == 'E'){
     // login() = false;
     string id;
     string password;
     bool valid = false;
     while(valid == false){
       cout << "Please login..." << endl;
       cout << "Username: ";
       cin >> id;
       cout << "Password: ";
       cin >> password;
       cout << endl;
       valid = login(id, password);
     }
     // cout << "What would you like to do?" << endl;
     // cout << "\n  1. Change hours\n  2. View orders\n  3. Remove order\n  4. Add item to menu\n  5. Remove item from menu" << endl;
     // char toDo = '';
     // cin >> toDo;
     // if(toDo == '1'){
     //   updateHours();
   }
   else if(toupper(menuSelection) == 'C'){
     cout << "Welcome, valued customer!" << endl;
     // initiate customer function
   }
   else if(toupper(menuSelection) == 'Q'){
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
    for(int n=0; n<numDaysOpen; n++){
      restaurant_info >> week[n].day;
      restaurant_info >> week[n].open_hour;
      restaurant_info >> week[n].close_hour;
    }
  }
  else{
    cout << "Unable to open file... Please try again." << endl;
  }
}

bool Restaurant::login(std::string id, std::string password){
  bool status = false;
  if(employees->id == id && employees->password == password){
    cout << "Login successful..." << endl << endl;
    status = true;
    return status;
  }
  else{
    cout << "Login failed... Please try again." << endl << endl;
    return status;
  }
}

void Restaurant::create_employees(){
  ifstream employee1;
  employee1.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/employee.txt");
  int count = 0;
  if(employee1){
    while(employee1){
      string a;
      std::getline(employee1, a, '\n');
      // cout << a << endl;
      if(a != ""){
        count++;
        // cout << count << endl;
      }
    }
    employee1.close();
  }
  employees = new struct employee[count];
  string line = "";
  ifstream employee;
  std::stringstream linestream(line);
  employee.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/employee.txt");
  if(employee){
    // while(employee.good()){
    for(int n=0; n<count; n++){
      employee >> employees[count].id >> employees[count].first_name >> employees[count].last_name >> employees[count].password;
      // cout << employees[count].id << " " << employees[count].first_name << " " << employees[count].last_name << " " << employees[count].password << endl;
    }
    employee.close();
  }
  else{
    cout << "Error: Unable to open employee file..." << endl;
  }
}

// employee Restaurant::getEmployees(){
//   for(int n=0; n<3; n++){
//     cout << employees->id << endl;
//   }
// }

void Restaurant::view_hours(){
  for(int n=0; n<7; n++){
    cout << week[n].day << " " << week[n].open_hour << " " << week[n].close_hour << endl;
  }
}

// void view_menu(){
//   ifstream menu;
//   menu.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt")
//   if(menu){
//     while(menu){
//
//     }
//   }
// }

int main(){
  Restaurant Bytes;
  Bytes.load_data();
  // Bytes.view_hours();

  // test Login
  // employee ryandirezze =
  Bytes.create_employees();
  Bytes.welcomeScreen();
  // Bytes.login("3333", "Fringe");

  return 0;
}
