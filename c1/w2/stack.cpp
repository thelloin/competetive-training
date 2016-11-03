#include <iostream>
#include <string>
#include <fstream>
#include <stack>

int main()
{
   using namespace std;
   int numOfCommands;

   ifstream inFile("stack.in");
   ofstream outFile("stack.out");
   if(inFile.is_open())
   {
      inFile >> numOfCommands;
   }

   char operation;
   stack<int> s;
   for (int i{0}; i < numOfCommands; ++i)
   {
      inFile >> operation;
      if (operation == '+')
      {
	 int newValue;
	 inFile >> newValue;
	 s.push(newValue);
      } else
      {	 
	 outFile << s.top() << '\n';
	 s.pop();
      }
   }


   
   outFile << "";

   return 0;
}
