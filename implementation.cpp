#include "header.hpp"
#include<cctype>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

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
  return storeHours;
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

int main(){
  ifstream file;
  file.open("/Users/ryandirezze/Documents/OSU/CS_162_old2/Assignment_2/restaurant_info.txt");
  restaurant Bytes = restaurant(file);
  // Bytes.setName(file);
  cout << Bytes.getName() << endl;
  cout << Bytes.getPhone() << endl;
  cout << Bytes.getAddress() << endl;
  cout << Bytes.getDaysOpen() << endl;

  employee ryan = employee();
  // ryan.updateHours(Bytes);
  ryan.setRestaurant(Bytes);
  cout << ryan.getRestaurantName() << endl;

  return 0;
}
