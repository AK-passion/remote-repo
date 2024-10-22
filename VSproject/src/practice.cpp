#include <iostream>
using namespace std;

class Rect
{
 public:
  int length;
  int height;

  int per()
   {return 2*(length+height);}

  int area()
   {return length*height;}

};

int main()
{
    Rect r;
    r.height=3;
    r.length=6;
    cout<<r.area()<<endl;
    return 0;
}