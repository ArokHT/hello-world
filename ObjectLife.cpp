
#include <iostream>
 
using namespace std;
 
class Test
{
public:
    int x_;
    void init(int x, int y,int z);
    void display()
    {
        cout<< x_ << endl;
    };
private:
    int y_;
protected:
    int z_;
};
 
void Test::init(int x, int y, int z)
{
    x_ = x;
    y_ = y;
    z_ = z;
}
int main()
{
    Test t;
    t.init(1,2,3);
    t.display();
    return 0;
}
