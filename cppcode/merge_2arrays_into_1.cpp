#include <iostream>
using namespace std;

void input_array(int a[], int b[], int &m,int &n)
{
   cin >>m;
   for(int i=0;i<m;i++)
   {
      cin >> a[i];
   }
   cin >>n;
   for(int j=0;j<n;j++)
   {
      cin >> b[j];
   }
}

void arrange(int a[], int n)
{
   int temp;
   for(int i=0;i<n-1;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         if(a[i]>a[j])
         {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
   }
}

void merge_2_into_1(int a[], int b[], int c[], int &m, int &n)
{
   int i,j,k=0;
   for(i = 0; i < m; i++)
   {
     c[k] = a[i];
     k++;
   }
   k = m;
   for(j = 0; j < n; j++)
   {
     c[k] = b[j];
     k++;
   }
   arrange(c,k);
   for(i = 0; i < k; i++)
   {
      cout << c[i]<< " ";
   } 
}

int main()
{
   int m,n;
   int a[100],b[100],c[200];
   input_array(a,b,m,n);
   merge_2_into_1(a,b,c,m,n);
   return 0;
}