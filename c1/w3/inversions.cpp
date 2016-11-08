#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static long long int inversions{0};

void merge(vector<int>& array, int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   // Create temp arrays
   vector<int> L(n1), R(n2);

   // Copy vector segment to arrays L[] and R[]
   for (i = 0; i < n1; ++i)
      L[i] = array[l + i];
   for (i = 0; i < n2; ++i)
      R[i] = array[m + 1 + i];

   // Merge the temp arrays back into array[l..r]
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
      if (L[i] <= R[j])
      {
	 array[k] = L[i];
	 i++;
      }
      else
      {
	 array[k] = R[j];
	 j++;
	 inversions += n1 - i;
      }
      k++;
   }

   // Copy, if any, elements of L[]
   while (i < n1)
   {
      array[k] = L[i];
      i++;
      k++;
   }

   // Copy, if any, elements of L[]
   while (j < n2)
   {
      array[k] = R[j];
      j++;
      k++;
   }

}

void mergeSort(vector<int>& array, int l, int r)
{
   if (l == r)
   {
      return;
   }

   int middle = l + (r - l)/2;

   mergeSort(array, l, middle);
   mergeSort(array, middle + 1, r);

   merge(array, l, middle, r);
}

int main()
{
   ifstream inFile{ "inversions.in" };
   ofstream outFile{ "inversions.out" };

   int n;
   vector<int> array;
   inFile >> n;
   array.resize(n);
   for (int i{ 0 }; i < n; ++i)
   {
      inFile >> array[i];
      //cout << array[i] << endl;
   }

   mergeSort(array, 0, array.size()-1);

   outFile << inversions;
   return 0;
}
