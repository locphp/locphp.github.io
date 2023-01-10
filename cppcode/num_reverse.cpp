#include <iostream>
#include <cmath>
using namespace std;

int num_reverse(int n)
{
    int sum = 0;
    int temp = 0;
    while(n > 0)
    {
        temp = n % 10;
        sum = sum*10 + temp;
        n = n/10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << num_reverse(n);
}
// tính tổng chữ số của số
// int TongChuSo(int n)
// {

//     int sum = 0;
//     int temp;
//     while(n > 0)
//     {
//     temp = n % 10;
//     sum += temp;
//     n = n/10;
//     }
//     return sum;
// }

//...................................................................................
// dùng đệ quy
// #include <iostream>

// using namespace std;

// int input(int &n)
// {
//     cin >> n;
//     return n;
// }
// int sum(int n, int &s)
// {
//     int temp;
//     if(n)
//     {
//         temp = n % 10;
//         s += temp;
//         sum(n/10,s);
//     }
//     else return s; 
//     return s;
// }

// int main() {
//     int n, s=0;
//     input(n);
//     sum(n, s);
//     cout << s;

// }