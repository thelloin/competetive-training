#include <fstream>
#include <stack>

using namespace std;

int main()
{
   stack< pair<int, int> > inStack;
   stack< pair<int, int> > outStack;
   int numOfCommands;

   ifstream inFile("queuemin.in");
   ofstream outFile("queuemin.out");
   if(inFile.is_open())
   {
      inFile >> numOfCommands;
   }

   char operation;
   for (int i{0}; i < numOfCommands; ++i)
   {
      inFile >> operation;
      if (operation == '?')
      {
	 if (inStack.empty())
	    outFile << outStack.top().second << '\n';
	 else if ( outStack.empty())
	    outFile << inStack.top().second << '\n';
	 else
	    outFile << min(inStack.top().second, outStack.top().second) << '\n';
      }
      else if (operation == '+')
      {
	 int newValue;
	 inFile >> newValue;
	 if (inStack.empty())
	    inStack.push(pair<int, int>(newValue, newValue));
	 else
	 {
	    inStack.push(pair<int, int>(newValue, min(newValue, 
						      inStack.top().second)));
	 }
      }
      else if (operation == '-')
      {
	 if (outStack.empty())
	 {
	    //int smallest = inStack.top().second;
	    pair<int, int> p(inStack.top().first, inStack.top().first);
	    outStack.push(p);
	    inStack.pop();
	    while (!inStack.empty())
	    {
	       pair<int, int> p(inStack.top().first, min(inStack.top().first,
							 outStack.top().second));
	       outStack.push(p);
	       inStack.pop();
	    }
	 }

	 outStack.pop();
      }
   }

   return 0;
}
