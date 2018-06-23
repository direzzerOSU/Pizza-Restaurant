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

using std::cout;
using std::cin;
using std::endl;

// prototypes
void welcomeScreen();

void welcomeScreen(){
 cout << "\nWelcome to DiGiorno's Pizza!" << endl;
 cout << "Are you a customer (C) or an employee (E)? Or would you like to quite (Q)?" << endl;
 char menuSelection;
 while(menuSelection != 'Q'){
   cin >> menuSelection;
   if(islower(menuSelection)){
     menuSelection = toupper(menuSelection);
   }

   if(menuSelection == 'E'){
     // initiate employee function
   }
   else if(menuSelection == 'C'){
     // initiate customer function
   }
   else if(menuSelection == 'Q'){
     // terminate program
     break;
   }
   else{
     cout << "Whoops! That is not a valid option... Please try again." << endl;
   }
 }
}

int main(){
 welcomeScreen();

 return 0;
}
