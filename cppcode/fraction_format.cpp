/*Dãy các số nguyên trong đó: (Giả sử luôn thỏa điều kiện nhập n).

Dòng đầu tiên là số n: đây là số lượng phân số trong mảng.
n dòng tiếp theo, mỗi dòng chứa 02 số nguyên lần lượt là tử số và mẫu số của một phân số trong mảng.
OUTPUT
Ứng với mỗi phân số trong mảng, xuất ra:

Nếu mẫu số của phân số không thỏa điều kiện xác định, xuất ra "Khong thoa yeu cau bai toan".
Ngược lại xuất kết quả phân số kết quả ở dạng sau: a/b.
Phân số kết quả phải là phân số tối giản, mẫu số không được là số âm, nếu phân số là một số nguyên thì xuất số nguyên đó.

EXAMPLE
Input   Output
9
8   2
9   -2
-1  -2
7   0
9   1
10  15
0   -2
0   3
10  10
4
-9/2
1/2
Khong thoa yeu cau bai toan
9
2/3
0
0
1
*/

#include <iostream>
using namespace std;
#define MAXN 300
struct PhanSo
{
	int tuso;
	int mauso;
};

void Nhap(PhanSo a[], int &n)
{
	cin >> n;
	for(int i = 0; i < n;i++)
	{
		cin >> a[i].tuso;
		cin >> a[i].mauso;
	}
}
int UCLN(int a, int b){
	int x = abs(a);
	int y = abs(b);
	while(x!=y){
		if(x>y){
			x-=y;
		}
		else{y-=x;}
	}
	return x;
}

void Xuat(PhanSo a[], int &n){
	int tu,mau;
	
	for(int i = 0;i<n;i++){
		if(a[i].mauso ==0){
			cout << "Khong thoa yeu cau bai toan"<< endl;
		}
		else if(a[i].tuso == 0){
			cout << 0<< endl;
		}
		else{
			if(abs(a[i].tuso) % (abs(a[i].mauso)) == 0){
				tu = a[i].tuso;
				mau = a[i].mauso;
				cout << tu/mau<< endl;
			}
			else{
			int uoc = UCLN(a[i].tuso,a[i].mauso);
			if(a[i].tuso > 0 && a[i].mauso < 0){
				tu = -1*(a[i].tuso)/uoc;
				mau = -1*(a[i].mauso)/uoc;
				cout <<tu<< "/"<<mau<< endl;
			}
			else if(a[i].tuso < 0 && a[i].mauso < 0){
				tu = abs((a[i].tuso)/uoc);
				mau = abs((a[i].mauso)/uoc);

				cout << tu <<"/"<< mau<< endl;
			}
			else{
				tu = (a[i].tuso)/uoc;
				mau = (a[i].mauso)/uoc;
				cout << tu << "/"<< mau<< endl;
			}
		}
		}
		
	}
}

int main(){
	PhanSo a[MAXN];
	int n;
	Nhap(a, n);
	Xuat(a, n);
	return 0;
}
