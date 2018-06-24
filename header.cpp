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
};

class Menu{
private:
  int num_pizzas;
  Pizza* pizzas;

public:
  // need to include accessor and mutator functions for each private member
  // need to include constructors, copy constructors, assignment operator overload, and destructors where appropriate
  Menu search_pizza_by_cost(int upper_bound, std::string size);
  Menu search_pizza_by_ingredients_to_include(std::string* ingredients, int num_ingredients);
  void add_to_menu(Pizza pizza_to_add);
  void remove_from_menu(int index_of_pizza_on_menu);
};

class Restaurant{
private:
  Menu menu;
  employee* employees;
  hours* week;
  std::string name;
  std::string phone;
  std::string address;

public:
  // need to include accessor and mutator functions for each private member
  // need to include constructors, copy constructors, assignment operator overload, and destructors where appropriate
  void load_data(); // reads from files to correctly populate menu, employees, hours, etc.
  bool login(std::string id, std::string password);
  void view_menu();
  void view_hours();
  void view_address();
  void view_phone();
  void search_menu_by_price();
  void search_by_ingredients();
  void place_order(Pizza* selection);
  void change_hours();
  void add_to_menu();
  void remove_from_menu();
  void view_orders();
  void remove_orders();
};
