
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n,int y);

bool is_prime(int n)
{
   if(n<2) return false;
   for(int i=2;i<=sqrt(n);i++)
   {
      if(n%i==0)return false;
   }
   return true;
}

void NhapmangSNT(int a[], int &n)
{
   cin >>n;
   int i=0, j=2, dem=0;
   while(dem<n)
   {
      if(is_prime(j))
      {
         a[i]=j;
         j++;
         i++;
         dem++;
      }
      else j++;
   }  
}

int SoPhanTuChuaY(int a[], int n,int y)
{
   int num=0;
   for(int i=0;i<n;i++)
   {
      do
      {
         if(a[i]%10==y)
         {  num++;
            break;
         }
         else a[i]/=10;
      }
      while(a[i]>0);
   }
   return num;
}

int main()
{
   int a[MAX], n, y;
   cin >>y;
   NhapmangSNT(a,n);
   cout << SoPhanTuChuaY(a, n, y) << endl;;
   return 0;
}