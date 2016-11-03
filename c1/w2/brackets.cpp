#include <fstream>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
   ifstream inFile("brackets.in");
   ofstream outFile("brackets.out");
   stack<char> s;

   string line{};
   while (getline(inFile, line))
   {
      while (!s.empty())
	 s.pop();
      cout << "We are here" << endl;
      for (size_t i{0}; i < line.size(); ++i)
      {
	 if (line[i] == '[' || line[i] == '(')
	    s.push(line[i]);
	 else 
	 {
	    if (!s.empty() && line[i] == ')' && s.top() == '(')
	       s.pop();
	    else if (!s.empty() && line[i] == ']' && s.top() == '[')
	       s.pop();
	    else s.push(line[i]);
	 }
      }
      if (s.empty())
      {
	 outFile << "YES\n";
      } else
      {
	 outFile << "NO\n";
      }
   }
   return 0;
}
