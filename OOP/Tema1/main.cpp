#include <iostream>
#include "Stack.h"
#include <fstream>
using namespace std;

void DisplayMenu()
{
    cout << "1. INPUT from CONSOLE " << endl;
    cout << "2. INPUT from FILE" << endl;
}
void DisplayMenu1()
{
    cout << "0. EXIT " << endl;
    cout << "1. PUSH elements into the stack " << endl;
    cout << "2. POP element from stack " << endl;
    cout << "3. TOP of the stack " << endl;
    cout << "4. REVERSE stack " << endl;
    cout << "5. DIFFERENCE between 2 stack " << endl;

}
int main()
{
    ifstream f("file.in");
    Stack stack;
    int opt1;
    cout <<  "Choose your option for input:  " << endl << endl;
    DisplayMenu();
    cin >> opt1;
    switch(opt1){
        case 1 :

                 int opt2;
                 cout << endl << "Choose your option to operate on stack :  " << endl << endl;
                 DisplayMenu1();
                 cin >> opt2;
                 while(opt2){
                    switch(opt2)
                        {
                        case 0:
                            break;
                        case 1:
                            cout << "Press enter to stop reading" << endl;
                            cin >> stack;
                            cout << "Items in stack: " << endl;
                            cout << stack;
                            break;
                        case 2 :
                            stack.Pop();
                            cout << "Remaining items: " << stack;
                            break;
                        case 3 :
                           cout << stack.Top();
                            break;
                        case 4:
                            stack.Reverse();
                            cout << stack;
                            break;
                        case 5:
                            Stack stack1;
                            cout << "Introduce elements for the 2nd stack :" << endl;
                            cin >> stack1;
                            stack - stack1;
                            cout << "Remaining items in stack: " << endl;
                            cout << stack;
                            break;
                        }
                    cout << endl << "Choose your option to operate on stack :  " << endl << endl;
                    DisplayMenu1();
                    cin>>opt2;

                }

                break;

      case 2 :

                 cout<< endl << "Choose your option to operate on stack :  " << endl << endl;
                 DisplayMenu1();
                 cin>>opt2;
                 while(opt2){

                    switch(opt2)
                        {

                        case 0:
                            break;
                        case 1:
                            f >> stack;
                            cout << "Items in stack: "  << endl;
                            cout << stack;
                            break;
                        case 2 :
                            stack.Pop();
                            cout << "Remaining items: " << endl;
                            cout << stack;
                            break;
                        case 3 :
                            cout << stack.Top() << " ";
                            break;
                        case 4:
                            stack.Reverse();
                            cout << stack;
                            break;
                        case 5:
                            Stack stack1;
                            f >> stack1;
                            stack - stack1;
                            cout << "Remaining items in stack: " << endl;
                            cout << stack;
                            break;
                        }
                    cout << endl << "Choose your option to operate on stack :  " << endl << endl;
                    DisplayMenu1();
                    cin>>opt2;

                }
                f.close();
                break;
    }
    return 0;
}
