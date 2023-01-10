#include <iostream>
using namespace std;

void input_matrix(float (&a)[][100],int &n, int &m)
{
   cin >> n ;
   cin >> m;
   for(int i = 0; i < n; i++)
   {
     for(int j=0;j<m;j++)
      {
         cin >> a[i][j];
      } 
   }    
}

void transpose_matrix(float b[][100], float a[][100], int n, int m)
{
   int k=m;
   int l=n;
   for(int i = 0; i < k; i++)
   {
      for(int j=0;j<l;j++)
      {
         b[i][j]=a[j][i];
         if(j!=l-1) 
         { 
            cout << b[i][j] << " ";
         }
         else cout << b[i][j]<< endl;
      }
   }
}

int main()
{
   int m,n;
   float a[100][100];
   float b[100][100];
   input_matrix(a,n,m);
   transpose_matrix(b,a,n,m);
}