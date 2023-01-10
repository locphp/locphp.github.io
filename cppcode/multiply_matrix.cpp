#include <iostream>
using namespace std;

void input_matrix(float a[][100], float b[][100],int &m, int &n, int &p, int &q)
{
   cin >> m;
   cin >> n;
   for(int i = 0; i < m; i++)
   {
     for(int j=0;j<n;j++)
      {
         cin >> a[i][j];
      } 
   }
   cin >>p;
   cin >>q;
   for(int x = 0; x < p; x++)
   {
     for(int y=0;y<q;y++)
      {
         cin >> b[x][y];
      } 
   }
}

void multiply_matrix(float c[][100], float a[][100],float b[][100],int m, int n, int p, int q)
{
   for(int i = 0;i<m; i++)
   {
      for(int j=0;j<q;j++)
      {
         c[i][j]=0;
         for(int k=0;k<n;k++)
         {
            c[i][j]+=(a[i][k]*b[k][j]);
         }
         if(j!=q-1)
         {
            cout << c[i][j] <<" ";
         }
         else cout << c[i][j]<< endl;  
      }
   }
}

int main()
{
   int m,n,p,q;
   float a[100][100];
   float b[100][100];
   float c[100][100];
   input_matrix(a,b,m,n,p,q);
   multiply_matrix(c,a,b,m,n,p,q);
}