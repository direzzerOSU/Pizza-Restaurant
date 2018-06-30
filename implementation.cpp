#include "header.h"
#include<cctype>
#include<locale>
#include<sstream>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

char string_to_char(string str);
string char_to_string(char a);

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
     cout << "What would you like to do? (Please enter the appropriate number)" << endl;
     cout << "\n  1. Change hours\n  2. View orders\n  3. Remove order\n  4. Add item to menu\n  5. Remove item from menu" << endl << endl;
     char toDo;
     cin >> toDo;
     if(toDo == '1'){
       // updateHours();
     }
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

void Restaurant::hours_from_file(){   // NOTE: needs to be modified to load (data): menu, employees, hours
  ifstream restaurant_info;
  restaurant_info.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/restaurant_info.txt");
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

// load_data() with menu, employees & hours
void Restaurant::load_data(){   // NOTE: needs to be modified to load (data): menu, employees, hours
  hours_from_file();
  employees_from_file(get_numEmployees());
  menu.menu_from_file();
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

void Restaurant::employees_from_file(int num){
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

int Restaurant::get_numEmployees(){
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
  // cout << endl << name << " " << small_cost << " " << medium_cost << " " << large_cost << " " << num_ingredients << " ";
  ingredients = new string[num_ingredients];
  for(int i=0; i<num_ingredients; i++){
    menuFile >> ingredients[i];
    // cout << ingredients[i] << " ";
  }
  // cout << endl << endl;
}

void Menu::menu_from_file(){
  num_pizzas = numPizzas();
  pizzas = new Pizza[num_pizzas];
  ifstream menuFile;
  menuFile.open("/Users/ryandirezze/Documents/GitHub/Pizza-Restaurant/menu.txt");
  if(menuFile){
    for(int n=0; n<num_pizzas; n++){
      pizzas[n].getPizza(menuFile, num_pizzas, pizzas);
    }
  }
  else{
    cout << "Uh oh! File was unable to open..." << endl;
  }
  // return pizzas;
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
  return counter;
}

void Restaurant::printMenu(){   // NOTE: incomplete?
  Menu a = getMenu();
  for(int n=0; n<menu.numPizzas(); n++){
    // cout << a.pizzas->name;
  }
}

void Pizza::setName(std::string x){
  name = x;
}

string Pizza::getName(){
  return name;
}

hours Restaurant::getHours(){
  return *week;
}

void Restaurant::view_hours(){
  for(int day=0; day<7; day++){
    cout << week[day].day << " " << week[day].open_hour << " " << week[day].close_hour << endl;
  }
}

void Restaurant::change_hours(){
  cout << endl << "What day would you like to update hours?" << endl << endl;
  cout << "Please enter the character that corresponds to the applicable day:" << endl;
  cout << "     Sunday    (" << week[0].day << ")" << endl;
  cout << "     Monday    (" << week[1].day << ")" << endl;
  cout << "     Tuesday   (" << week[2].day << ")" << endl;
  cout << "     Wednesday (" << week[3].day << ")" << endl;
  cout << "     Thursday  (" << week[4].day << ")" << endl;
  cout << "     Friday    (" << week[5].day << ")" << endl;
  cout << "     Saturday  (" << week[6].day << ")" << endl << endl;

  string day;
  char b;
  while(day != week[0].day && day != week[1].day && day != week[2].day && day != week[3].day && day != week[4].day && day != week[5].day && day != week[6].day){
    cin >> day;
    b = string_to_char(day);
    b = toupper(b);
    day = char_to_string(b);
    cout << endl;
  }

  for(int n=0; n<7; n++){
    if(day == week[n].day){
      cout << "Restaurant Open: ";
      cin >> week[n].open_hour;
      cout << endl << "Restaurant Close: ";
      cin >> week[n].close_hour;
    }
  }
}

char string_to_char(string str){
  char a[0];
  strcpy(a, str.c_str());
  return a[0];
}

string char_to_string(char a){
  std::stringstream ss;
  string b;
  ss << a;
  ss >> b;
  return b;
}

Menu Restaurant::getMenu(){
  return menu;
}

Pizza Menu::getPizzas(){
  return *pizzas;
}

Pizza Menu::getMenu(){   // NOTE: identical to the above function (getPizzas())
  return *pizzas;
}

int main(){
  Restaurant Bytes;
  Bytes.load_data();

  // string a = "R";
  // char b;
  // b = tolower(string_to_char(a));
  // cout << b << endl;
  // a = char_to_string(b);
  // cout << a << endl;

  // test getHours & view_hours
  // Bytes.getHours();
  // Bytes.view_hours();
  // Bytes.change_hours();
  // Bytes.view_hours();

  // test add_to_menu()
  Bytes.printMenu();
  getPizza();

  // test full application
  // Bytes.welcomeScreen();
  // Bytes.login("3333", "Fringe");

  return 0;
}
