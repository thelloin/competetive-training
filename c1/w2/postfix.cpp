#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
   ifstream inFile("postfix.in");
   ofstream outFile("postfix.out");

   stack<int> s;

   string token;

   while (inFile >> token)
   {
      //cout << token << endl;
      if (token == "+")
      {
	 int n1 = s.top();
	 s.pop();
	 int n2 = s.top();
	 s.pop();
	 s.push(n1 + n2);
      } else if (token == "-")
      {
	 int n1 = s.top();
	 s.pop();
	 int n2 = s.top();
	 s.pop();
	 s.push(n2 - n1);
      } else if (token == "*")
      {
	 int n1 = s.top();
	 s.pop();
	 int n2 = s.top();
	 s.pop();
	 s.push(n1 * n2);
      } else
      {
	 // token is a int, cast and push to stack
	 int num = atoi( token.c_str() );
	 s.push(num);
      }
   }

   outFile << s.top();

   return 0;
}
