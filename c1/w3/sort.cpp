#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream outFile{ "sort.out" };

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

   // Write end indices and values to ofstream outFile
   outFile << l+1 << " " << r+1 << " " << array[l] << " " << array[r] << endl;
}

void mergeSort(vector<int>& array, int l, int r)
{
   if (l == r)
   {
      outFile << r+1 << " " << r+1 << " " << array[r] << " " << array[r] << endl;
      return;
   }

   int middle = l + (r - l)/2;

   mergeSort(array, l, middle);
   mergeSort(array, middle + 1, r);

   merge(array, l, middle, r);
}

int main()
{
   ifstream inFile{ "sort.in" };

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

   for (size_t i{0}; i < array.size()-1; ++i)
      outFile << array[i] << " ";
   outFile << array[array.size() - 1];
   return 0;
}
