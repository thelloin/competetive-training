#include <fstream>

using namespace std;

int main()
{
   ifstream inFile("stacks.in");
   ofstream outFile("stacks.out");

   int numberOfMugs;
   inFile >> numberOfMugs;

   int maxHeight{1};
   int freeSpaces{};
   int stacks{1};

   int current{};
   inFile >> current;
   for (int i{}; i < numberOfMugs - 1; ++i)
   {
      inFile >> current;
      if (current != 0)
      {
	 freeSpaces += maxHeight - 1;
	 stacks++;
      }
      else
      {
	 if (freeSpaces == 0)
	 {
	    maxHeight++;
	    freeSpaces += stacks - 1;
	 }
	 else
	 {
	    freeSpaces--;
	 }
      }
      //cout << "And the max height is: " << maxHeight << endl;
   }

   outFile << maxHeight;

   return 0;
}
