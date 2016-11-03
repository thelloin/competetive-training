#include <iostream>
#include <string>
#include <fstream>
#include <queue>

int main()
{
   using namespace std;
   int numOfCommands;

   ifstream inFile("queue.in");
   ofstream outFile("queue.out");
   if(inFile.is_open())
   {
      inFile >> numOfCommands;
   }

   char operation;
   queue<int> q;
   for (int i{0}; i < numOfCommands; ++i)
   {
      inFile >> operation;
      if (operation == '+')
      {
	 int newValue;
	 inFile >> newValue;
	 q.push(newValue);
      } else
      {	 
	 outFile << q.front() << '\n';
	 q.pop();
      }
   }

   return 0;
}
