#include <iostream>
using namespace std;

void input_array(int a[],int &n)
{
   cin >> n;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
}

int find_max(int a[], int &n)
{
   int maxx = a[0];
   for(int i=1;i<n;i++)
   {
      if(a[i]>maxx)
      {
         maxx = a[i];
      }
   }
   return maxx;
}
int find_second_max( int a[], int &n)
{
   int maxx = find_max(a,n);
   int max2;
   for(int i=0;i<n;i++)
   {
      if(a[i]!= maxx)
      {
         max2 =a[i];
         break;
      }
   }
   for(int j=0;j<n;j++)
   {
      if(a[j]>max2 && a[j] != maxx)
      {
         max2=a[j];     
      }
   }
   return max2;
}

int main()
{
   int n;
   int a[100];
   input_array(a,n);
   int maxx = find_max(a,n);
   int max2 = find_second_max(a,n);
   if(maxx!=max2)
   {
      cout << max2;
   }
   else cout<< 0;
}