#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[])
{
   using namespace std;
   long long int a, b;

   ifstream inFile("aplusbb.in");
   if(inFile.is_open())
   {
      inFile >> a >> b;
   }

   ofstream outFile("aplusbb.out");
   long long int res = a + b*b;
   outFile << fixed << res;

   return 0;
}
