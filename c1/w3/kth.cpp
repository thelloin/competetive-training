#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   ifstream inFile("kth.in");
   ofstream outFile("kth.out");

   int n, k1, k2, a, b, c;
   inFile >> n >> k1 >> k2;
   vector<int> data(n);
   inFile >> a >> b >> c >> data[0] >> data[1];
   //cout << a << " " << b << " " << b << " " << data[0] << " " << data[1] << endl;
   for (int i = 2; i < n; ++i)
   {
      data[i] = a * data[i - 2] + b * data[i - 1] + c;
   }

   /*for (int i = 0; i < n; ++i)
   {
      cout << data[i] << " ";
   }
   cout << endl;*/
   stable_sort(data.begin(), data.end());

   for (int i = k1-1; i < k2-1; i++)
   {
      outFile << data[i] << " ";
   }
   outFile << data[k2-1];
   /*for (int i = 0; i < n; ++i)
   {
      cout << data[i] << " ";
   }
   cout << endl;*/
   return 0;
}
