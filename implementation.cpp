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
        cout << "storeHours[" << day << "] = " << storeHours[day] << endl;
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

int main(){
  ifstream file;
  file.open("/Users/ryandirezze/Documents/OSU/CS_162_old2/Assignment_2/restaurant_info.txt");
  restaurant a = restaurant(file);
  // a.setName(file);
  cout << a.getName() << endl;
  cout << a.getPhone() << endl;
  cout << a.getAddress() << endl;
  cout << a.getDaysOpen() << endl;
  // cout << a.getHours() << endl;
  std::map<char, string> b = a.getHours();
  cout << "b['S'] = " << b['S'] << endl;
  cout << b['M'] << endl;
  cout << b['T'] << endl;
  cout << b['W'] << endl;
  cout << b['R'] << endl;
  cout << b['F'] << endl;
  cout << b['X'] << endl;

  return 0;
}
