#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int findPDayToAdd(const vector<int>& pVec, const vector<int>& tVec)
{
   int smallestDiffIndex{0};
   for(size_t i{1}; i < pVec.size(); ++i)
   {
      if ( (tVec[i] - pVec[i]) < (tVec[smallestDiffIndex] - pVec[smallestDiffIndex]))
	 smallestDiffIndex = i;
   }
   return smallestDiffIndex;
}

int findTDayToAdd(const vector<int>& pVec, const vector<int>& tVec)
{
   int smallestDiffIndex{0};
   for(size_t i{1}; i < pVec.size(); ++i)
   {
      if ( (pVec[i] - tVec[i]) < (pVec[smallestDiffIndex] - tVec[smallestDiffIndex]))
	 smallestDiffIndex = i;
   }
   return smallestDiffIndex;
}

int main()
{
   int n{}, res{};
   vector<int> pVec, tVec;
   bool addedTDay {false}, addedPDay {false};
   ifstream inFile("prepare.in");
   inFile >> n;
   pVec.resize(n);
   tVec.resize(n);

   for (int i{0}; i < n; ++i)
   {
      inFile >> pVec[i];
   }
   for (int i{0}; i < n; ++i)
   {
      inFile >> tVec[i];
   }
   for (int i{0}; i < n; ++i)
   {
      if (pVec[i] >= tVec[i])
      {
	 res += pVec[i];
	 addedPDay = true;
      } else
      {
	 res += tVec[i];
	 addedTDay = true;
      }
   }
   if (!addedPDay)
   {
      int index = findPDayToAdd(pVec, tVec);
      res -= tVec[index];
      res += pVec[index];
   } else if (!addedTDay)
   {
      int index = findTDayToAdd(pVec, tVec);
      res -= pVec[index];
      res += tVec[index];
   }

   ofstream outFile("prepare.out");
   outFile << res;
   //cout << "n: " << n << endl;
   //cout << "res: " << res << endl;
   return 0;
}
