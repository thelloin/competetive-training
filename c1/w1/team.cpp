#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
   ifstream inFile("team.in");
   vector<int> coder, mathematician, tester;

   for (int i{0}; i < 3; ++i)
   {
      int codeSkill{}, mathSkill{}, testSkill{};
      inFile >> codeSkill >> mathSkill >> testSkill;
      coder.push_back(codeSkill);
      mathematician.push_back(mathSkill);
      tester.push_back(testSkill);
   }
   int numberOfTests{0};
   double res{0.0};
   for (int i{0}; i < 3; ++i)
   {
      for (int j{0}; j < 3; ++j)
      {
	 if (j == i)
	    continue;
	 for (int k{0}; k < 3; ++k)
	 {
	    if (k == i || k == j)
	       continue;
	    ++numberOfTests;
	    double currentScore = sqrt( (double)(coder[i] * coder[i]) + 
					(double)(mathematician[j] * mathematician[j]) +
					(double)(tester[k] * tester[k]) );
	    if (currentScore > res)
	       res = currentScore;
	 }
      }
   }

   ofstream outFile("team.out");
   outFile << fixed << setprecision(10) << res;
   //cout << "numberOfTests: " << numberOfTests << endl;
   //cout << "res: " << fixed << setprecision(10)<< res << endl;
   return 0;
}
