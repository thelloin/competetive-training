#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

int main()
{
   int w{}, h{};
   ifstream inFile("template.in");
   inFile >> w >> h;

   string temp;
   getline(inFile, temp);

   map<char, pair<int, int>> charMap;

   for (int i{h}; i > 0; --i)
   {
      string line;
      getline(inFile, line);
      for (int j{0}; j < w; ++j)
      {
	 charMap.insert( make_pair(line[j], pair<int, int>(i, j + 1)) );
      }
   }

   /*cout << "a: " << charMap['a'].first << " : " << charMap['a'].second << endl;
   cout << "b: " << charMap['b'].first << " : " << charMap['b'].second << endl;
   cout << "c: " << charMap['c'].first << " : " << charMap['c'].second << endl;
   cout << "k: " << charMap['k'].first << " : " << charMap['k'].second << endl;
   cout << "g: " << charMap['g'].first << " : " << charMap['g'].second << endl;
   cout << "y: " << charMap['y'].first << " : " << charMap['y'].second << endl;
   cout << " : " << charMap[' '].first << " : " << charMap[' '].second << endl;
   cout << "f: " << charMap['f'].first << " : " << charMap['f'].second << endl;
   cout << "u: " << charMap['u'].first << " : " << charMap['u'].second << endl;
   cout << charMap['f'].first << " : " << charMap['f'].second << endl;*/
   pair<string, int> bestLanguage;
   bestLanguage.second = 1000000;
   bool readLanguageSyntax = false;
   string languageName = "Empty";
   bool firstLine = true;
   string line;
   int totalScore{10000000};
   char lastChar;
   while (getline(inFile, line))
   {
      //cout << "This is a line: " << line << endl;
      if (line != "" && line != " " && readLanguageSyntax == false)
      {
	 //cout << "New languare should be now." << endl;
	 readLanguageSyntax = true;
	 firstLine = true;
	 languageName = line;
	 totalScore = 0;
      }  else if ( line == "" || line == " ")
      {
	 readLanguageSyntax = false;
	 //cout << "This is the total score: " << totalScore << endl;
	 if ( totalScore < bestLanguage.second )
	 {
	    bestLanguage.first = languageName;
	    bestLanguage.second = totalScore;
	    totalScore = 1000000;
	    languageName = "This is a reset.";
	    //cout << "DO THIS EXECUTE???" << endl;
	 }
      } else if (readLanguageSyntax)
      {
	 if (firstLine)
	    firstLine = false;
	 else
	 {
	    totalScore += max( abs(charMap[line[0]].first - charMap[lastChar].first ),
			       abs(charMap[line[0]].second -  charMap[lastChar].second));
	 }
	 for (size_t i {1}; i < line.size(); ++i)
	 {
	    //cout << "checking score for: " << line[i-1] << " and " << line[i] << ", " << 
	    // max( abs(charMap[line[i]].first - charMap[line[i-1]].first ),
	    //	    abs(charMap[line[i]].second -  charMap[line[i-1]].second)) << endl;
	    totalScore += max( abs(charMap[line[i]].first - charMap[line[i-1]].first ),
			       abs(charMap[line[i]].second -  charMap[line[i-1]].second));
	 }
	 lastChar = line[line.size() - 1];
      }
      
   }

   //cout << "This is the total score after while-loop: " << totalScore << endl;
   if ( totalScore < bestLanguage.second )
   {
      bestLanguage.first = languageName;
      bestLanguage.second = totalScore;
      totalScore = -1;
      languageName = "This is a reset.";
      //cout << "*************************** IN THE LAST IF ******" << endl;
   }
   //cout << "This is the best language to choose:\n" << bestLanguage.first << '\n' << bestLanguage.second << endl;

   ofstream outFile("template.out");
   outFile << bestLanguage.first << endl << bestLanguage.second;

   return 0;
}
