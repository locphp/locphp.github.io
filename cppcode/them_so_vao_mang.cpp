#include <iostream>
using namespace std;
// n là số phần tử của mảng, k là vị trí cần thêm,x là giá trị cần thêm
void input_array(int a[],int &n, int &x, int &k)
{
   cin >> n;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   cin >> x;
   cin >> k;
}

void output_array(int a[], int &n)
{
   for(int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
}

void add_num_array(int a[], int &n, int &x, int &k){
    if(k <= 0)
    {
        k = 0;
    }
    if(k >= n)
    {
        k = n;
    }
    for(int i = n; i > k; i--){
        a[i] = a[i-1];
    }
    a[k] = x;
    n++;
}

int main()
{
   int n,x,k;
   int a[100];
   input_array(a,n,x,k);
   add_num_array(a,n,x,k);
   output_array(a,n);
}