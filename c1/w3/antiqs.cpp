#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
   ifstream inFile("antiqs.in");
   ofstream outFile("antiqs.out");

   int n;
   inFile >> n;

   vector<int> a(n);
   int index{0};
   int val = 1;
   while (index < n/2)
   {
      a[index] = val;
      index++;
      val += 2;
   }
   a[index++] = n;
   if (n%2 == 0 && n != 2)
   {
      int buf = a[index - 2];
      a[index - 2] = a[index - 1];
      a[index - 1] = buf;
   }
   val = 2;
   while (index < n)
   {
      a[index] = val;
      index++;
      val += 2;
   }

   for (size_t i = 0; i < a.size() - 1; ++i)
      outFile << a[i] << " ";
   outFile << a[a.size() - 1];
   
   return 0;
}
