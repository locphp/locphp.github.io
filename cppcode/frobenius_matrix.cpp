// Nhập ma trận vuông A (n x n). Kiểm tra A có phải là ma trận Frobenius hay không.

// Ma trận Frobenius được định nghĩa là ma trận vuông thoả các tính chất sau:

// Tất cả các phần tử trên đường chéo chính bằng 1.
// Có tối đa một cột mà các phần tử dưới đường chéo chính có thể nhận giá trị bất kì.
// Ngoài ra, tất cả các phần tử khác có giá trị bằng 0.
// INPUT

// 2 số nguyên là số dòng, số cột của ma trận A.
// Giá trị các phần tử của ma trận A là số thực.
// OUTPUT

// "Yes", nếu A là ma trận Frobenius.
// "No", nếu A không là ma trận Frobenius.

#include <iostream>
using namespace std;

void input_array(float a[][100], int &m, int &n)
{
    cin>>m;
    cin >> n;
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> a[i][j];
        }
    }
}

bool check_frobenius(float a[][100], int n)
{
    int num=0;
    int x;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if((i<j && a[i][j]!=0) || (i==j && a[i][j]!=1)) return false;
            if(i>j && a[i][j]!=0)
            {
                if(num==0)
                {
                    x=j;
                    num++;
                }
                if(j!=x) return false;
            }
        }
    }
    return true;
}


int main()
{
    int m,n;
    float a[100][100];
    input_array(a,m,n);
    if(check_frobenius(a,n))
    {
        cout << "Yes";
    }
    else cout << "No";
}