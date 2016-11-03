#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
   using namespace std;
   int a, b;

   ifstream inFile("aplusb.in");
   if(inFile.is_open())
   {
      inFile >> a >> b;
   }

   ofstream outFile("aplusb.out");
   outFile << a + b;

   return 0;
}
