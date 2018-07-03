#include "HelloWorld.h"
#include<iostream>
using namespace std;
class HelloWorld
{
  public:
    void hello()
    {
      cout << "Hello World" << endl;
    }
}
int main() {
  HelloWorld hw;
  hw.hello();
  return 0;
}
