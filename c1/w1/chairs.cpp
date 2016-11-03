#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
   ifstream inFile("chairs.in");
   int a, b, c;
   inFile >> a >> b >> c;

   double res = ((double)a/2.0 + (double)b/2.0 + (double)c/2.0) / 3.0;

   ofstream outFile("chairs.out");
   outFile << fixed << setprecision(10) << res;
   return 0;
}
