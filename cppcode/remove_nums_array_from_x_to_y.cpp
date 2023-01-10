#include <iostream>
using namespace std;

void input_array(int (&a)[], int &n, int &p, int&k)
{
   cin >>n;
   for(int i=0;i<n;i++)
   {
      cin >> a[i];
   }
   cin >>p;
   cin >> k;
}

void remove_nums_array(int a[], int &n, int p, int k)
{
   for(int i=p;i<n-k;i++)
   {
      a[i]=a[i+k];
   }
   n-=k;
   for(int i=0;i<n;i++)
   {
      cout << a[i] << " ";
   }
}  

int main()
{
   int n,p,k;
   int a[100];
   input_array(a,n,p,k);
   remove_nums_array(a,n,p,k);
   return 0;
}
