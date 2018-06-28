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

void Pizza::getPizza(std::ifstream& menuFile, int numberPizzas, Pizza* pizzas){
  menuFile >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
  cout << name << " " << small_cost << " " << medium_cost << " " << large_cost << " " << num_ingredients << " ";
  ingredients = new string[num_ingredients];
  for(int i=0; i<num_ingredients; i++){
    menuFile >> ingredients[i];
    cout << ingredients[i] << " ";
  }
  cout << endl;
}

void Menu::menu_from_file(){
  pizzas = new Pizza[numPizzas()];
  ifstream menu;
  menu.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt");
  if(menu){
    for(int n=0; n<num_pizzas; n++){
      pizzas[n].getPizza(menu, num_pizzas, pizzas);
    }
  }
  else{
    cout << "Uh oh! File was unable to open..." << endl;
  }
}

int Menu::numPizzas(){
  ifstream menu;
  menu.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt");
  int counter = 0;
  if(menu){
    string line = "";
    while(menu){
      getline(menu, line);
      if(line != ""){
        counter++;
      }
    }
  }
  num_pizzas = counter;
  return counter;    // use this if returning an int value
}

void Menu::printMenu(){
  menu_from_file();
  for(int n=0; n<num_pizzas; n++){
    cout << pizzas[n].getName();//<< " " << pizzas[counter].small_cost << " " << pizzas[counter].medium_cost << " " << pizzas[counter].large_cost << " " << pizzas[counter].num_ingredients;
    // for(int n=0; n<pizzas[counter].num_ingredients; n++){
    //   cout << pizzas[counter].ingredients[n] << " ";
    // }
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
  Menu restaurantMenu;
  restaurantMenu.menu_from_file();
  // restaurantMenu.printMenu();

  return 0;
}
