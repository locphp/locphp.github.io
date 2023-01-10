// Viết chương trình nhập vào số nguyên x sao cho 1 ≤ x ≤ 30. Nếu x không thỏa điều kiện, chương trình xuất ra màn hình thông báo “So <x> khong nam trong khoang [1,30].”. Nếu x nằm trong khoảng [1,30], chương trình xuất ra màn hình số Fibonacci thứ x.

// Input

// Một số nguyên x

// Output

// Thông báo “So <x> khong nam trong khoang [1,30].” nếu x không hợp lệ

// Ngược lại, xuất ra màn hình số Fibonacci thứ x
#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
    int x;
    cin >> x;
    if (x < 1 || x>30)
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    else
    {
        cout << Fibo(x) << endl;
    }
    return 0;
}

int Fibo(int x)
{
    int f1=0 , f2=1, f=1;

    if (x==0 || x==1)
        return x;

    for (int i=2 ; i < x; i++) {
        f1=f2;
        f2=f;
        f= f1 + f2;
    }
    return f;
}

//Đây là cách khác làm theo đệ quy
int fibonacci(int n)
{
    if (n == 1 || n ==2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}