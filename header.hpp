// header with classes

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<fstream>
#include<map>

class restaurant{
private:
  std::string name = "";
  std::string phone = "";
  std::string address = "";
  int numDaysOpen;
  std::map<char, std::string> storeHours;
public:
  restaurant(std::ifstream&);
  void setName(std::ifstream);
  std::string getName();
  void setPhone(std::ifstream);
  std::string getPhone();
  void setAddress(std::ifstream);
  std::string getAddress();
  void setDaysOpen(std::ifstream);
  int getDaysOpen();
  void setHours(std::ifstream);
  std::map<char, std::string> getHours();
};

class employee{
private:
  int id;
  std::string firstName = "";
  std::string lastName = "";
  std::string password = "";
  restaurant* restaurantName;
public:
  employee();
  void setID(std::ifstream);
  int getID();
  void setFirst(std::ifstream);
  std::string getFirst();
  void setLast(std::ifstream);
  std::string getLast();
  void setPass(std::ifstream);
  std::string getPass();
  void setRestaurant(restaurant);
  std::string getRestaurantName();
  void updateHours(restaurant);
};
#endif
