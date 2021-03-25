#include <iostream>
#include <sstream> 

using namespace std;

void hanoi(int n, string a, string b, string c)
{
  if (n == 1)
    cout << "move " << n <<" from "<< a << " to " << b << endl;
  else
  {
    hanoi(n - 1, a, c, b);
    cout << "move " << n <<" from "<< a << " to " << b << endl;
    hanoi(n - 1, c, b, a);      
  }
}

int main (int argc, char** argv) {
    if(argc<2){
      return 1;
    }
    string input = argv[1];
    stringstream s(input);
    int a;
    s >> a;
    hanoi(a,"T1","T2","T3");
    return 0;    
}