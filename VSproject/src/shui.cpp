#include <iostream>
#include <cmath>
using namespace std;

int main()
{
for(int num=100;num<=999;num++)

 {int sum=0;
int temp = num;

int H=temp/100;
temp %=100;
int T=temp/10;
int O=temp %=10;

sum=std::pow(H,3)+std::pow(T,3)+std::pow(O,3);
if(sum==num)
{cout<<num<<endl;}
 }

}
