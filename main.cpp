// PROCESS STEPS
 // prompt for which user (customer v. employee) (cmd line prompt)
   // if employee, login successfully
     // can change
       // restaurant hours
       // add/remove items from the menu
       // view/remove orders
   // if customer
     // provide an option to search the menu by price or by ingredients or place an order
     // when placing an order, a customer may select off the entire menu or from the last result search they examined
 // both kinds of users may also log out at any time which will return them to the welcome prompt
 // from the welcome prompt, they can end the program or log in as another user

#include<iostream>
#include<string>
#include "implementation.cpp"

using std::cout;
using std::cin;
using std::endl;

int main(){
 welcomeScreen();
 ifstream file;
 file.open("/Users/ryandirezze/Documents/OSU/CS_162_old2/Assignment_2/restaurant_info.txt");
 restaurant Bytes = restaurant(file);

 employee ryan = employee();
 ryan.setRestaurant(Bytes);
 // cout << ryan.getRestaurantName() << endl;
 auto a = Bytes.getHours();
 ryan.updateHours(Bytes.getHours());
 cout << a['S'] << endl;

 return 0;
}
