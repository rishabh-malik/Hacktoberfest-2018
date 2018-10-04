#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int num, temp1,temp2, rem, sum=0,dgt=0;
  cout << "Enter a positive  integer: ";
  cin >> num;

  temp1 = num;
  temp2 = num;

  while(temp1 != 0)
  {
      temp1/=10;
      dgt++;

  }

    while(temp2 != 0)
  {
      rem= temp2%10;
      sum+= pow(rem,dgt);
      temp2/=10;


  }

  if (sum==num)
    {cout << num << " is an Armstrong number.";}
  else
    cout << num << " is not an Armstrong number.";

  return 0;
}
