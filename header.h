// header with classes

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<fstream>
#include<map>

struct employee{
  std::string id;
  std::string first_name;
  std::string last_name;
  std::string password;
};

struct hours{
  std::string day;
  std::string open_hour;
  std::string close_hour;
};

class Pizza{
private:
  std::string name;
  int small_cost;
  int medium_cost;
  int large_cost;
  int num_ingredients;
  std::string* ingredients;

public:
  // need to include accessor and mutator functions for each private member
  // need to include constructors, copy constructors, assignment operator overload, and destructors where appropriate
  // Pizza getPizza();
  void setName(std::string);
  std::string getName();
  void getPizza(std::ifstream&, int, Pizza*);
  void setSmallCost();
  void setMediumCost();
  void setLargeCost();
  void setNumIngredients();
  void setIngredients();
};

class Menu{
private:
  int num_pizzas;
  Pizza* pizzas;

public:
  // need to include accessor and mutator functions for each private member
  // need to include constructors, copy constructors, assignment operator overload, and destructors where appropriate
  Pizza getMenu();
  Pizza getPizza();
  int numPizzas();
  void menu_from_file();
  Menu search_pizza_by_cost(int upper_bound, std::string size);
  Menu search_pizza_by_ingredients_to_include(std::string* ingredients, int num_ingredients);
  void add_to_menu(Pizza pizza_to_add);
  void remove_from_menu(int index_of_pizza_on_menu);
};

class Restaurant{
private:
  Menu menu;  // should this be a pointer?
  // Menu* menu;  // this would be my choice is used; non-pointer was used in the assignment instructions
  employee* employees;
  hours* week;
  std::string name;
  std::string phone;
  std::string address;

public:
  // need to include accessor and mutator functions for each private member
  // need to include constructors, copy constructors, assignment operator overload, and destructors where appropriate

  // welcome screen (starting screen)
  void welcomeScreen();

  // loads all required data from files
  void load_data(); // reads from files to correctly populate menu, employees, hours, etc.
  void employees_from_file(int num);
  void hours_from_file();
  int get_numEmployees();

  // employee login
  bool login(std::string id, std::string password);
  void getEmployees();

  // employee: make changes
  void change_hours();
  hours getHours();   // non-standard
  void add_to_menu();
  void remove_from_menu();
  void view_orders();
  void remove_orders();
  void printMenu();
  Menu getMenu();

  void view_menu();
  void view_hours();
  void view_address();
  void view_phone();
  void search_menu_by_price();
  void search_by_ingredients();
  void place_order(Pizza* selection);
};
#endif
