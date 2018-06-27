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
     cout << endl << "Whoops! That is not a valid option... Please try again." << endl << endl;
     cout << "Are you a customer (C) or an employee (E)? Or would you like to quite (Q)?" << endl;
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
  int count = 0;
  while(status == false){
    if(employees[count].id == "" && employees[count].password == ""){
      cout << "Login failed... Please try again." << endl << endl;
      return status;
    }
    else{
      if(employees[count].id == id && employees[count].password == password){
        cout << "Login successful..." << endl << endl;
        status = true;
        return status;
      }
      else{
        count++;
      }
    }
  }
  cout << "Error... Should not be here..." << endl;
  return status;
}

void Restaurant::create_employees(int num){
  employees = new employee[num];
  string line = "";
  ifstream employee;
  std::stringstream linestream(line);
  employee.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/employee.txt");
  if(employee){
    for(int n=0; n<num; n++){
      employee >> employees[n].id >> employees[n].first_name >> employees[n].last_name >> employees[n].password;
      // cout << employees[n].id << " " << employees[n].first_name << " " << employees[n].last_name << " " << employees[n].password << endl;
    }
    employee.close();
  }
  else{
    cout << "Error: Unable to open employee file..." << endl;
  }
}

void Restaurant::getEmployees(){
  for(int n=0; n<3; n++){
    cout << employees[n].id << " " << employees[n].first_name << " " << employees[n].last_name << " " << employees[n].password << endl;
  }
}

void Restaurant::view_hours(){
  for(int n=0; n<7; n++){
    cout << week[n].day << " " << week[n].open_hour << " " << week[n].close_hour << endl;
  }
}

int get_numEmployees(){
  ifstream employee1;
  employee1.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/employee.txt");
  int count = 0;
  if(employee1){
    while(employee1){
      string a;
      std::getline(employee1, a, '\n');
      if(a != ""){
        count++;
      }
    }
    employee1.close();
  }
  return count;
}

void Menu::menu_from_file(int num){   // NOTE: must use setters to access Pizzas private members
  pizzas = new Pizza[num];
  ifstream menu;
  menu.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt");
  if(menu){
    string line = "";
    int counter = 0;
    std::stringstream linestream(line);
    while(menu){
      getline(menu, line);
      linestream >> pizzas[counter].setName(); //>> pizzas[counter].small_cost >> pizzas[counter].medium_cost >> pizzas[counter].large_cost >> pizzas[counter].num_ingredients << endl;
      // for(int n=0; n<pizzas[counter].num_ingredients; n++){
      //   linestream >> pizzas[counter].ingredients[n];
      }
      counter++;
    }
  }
}

int Menu::numPizzas(){
  ifstream menu;
  menu.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt");
  if(menu){
    string line = "";
    counter = 0;
    while(menu){
      getline(menu, line);
      counter++;
    }
  }
  return counter;
}

int Menu::printMenu(){
  for(int n=0; n<numPizzas(); n++){
    cout << pizzas[counter].getName(); //<< " " << pizzas[counter].small_cost << " " << pizzas[counter].medium_cost << " " << pizzas[counter].large_cost << " " << pizzas[counter].num_ingredients;
    // for(int n=0; n<pizzas[counter].num_ingredients; n++){
    //   cout << pizzas[counter].ingredients[n] << " ";
    }
  }
}

void Pizza::setName(std::string x){
  name = x;
}

string Pizza::getName(){
  return name;
}

int main(){
  Restaurant Bytes;
  Bytes.load_data();
  // Bytes.view_hours();

  // test Login
  // employee ryandirezze =
  // Bytes.create_employees(get_numEmployees());
  // Bytes.getEmployees();
  // Bytes.welcomeScreen();
  // Bytes.login("3333", "Fringe");

  // test Menu / pizzas
  menu_from_file();
  printMenu();

  return 0;
}
