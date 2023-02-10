//input:

// Nguyen Thi Lan
// 3
// 07520504
// Nguyen Thi Lan
// 31/07/1989
// M
// 10
// 9.5
// 10
// 07520045
// Nguyen Thi Lan
// 27/05/1989
// F
// 10
// 9
// 8
// 07521111
// Nguyen Anh Hong
// 07/12/1991
// F
// 7
// 9
// 8

//output:
//07521111	Nguyen Anh Hong	07/12/1991	F	7	9	8	8


#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(char hotenxoa[]){
	cin.getline(hotenxoa,100);
}
void Nhap(SinhVien (&A)[], int &n){
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> A[i].MASV;
		cin.ignore();
		cin.getline(A[i].HoTen,100);
		cin >> A[i].NgaySinh;
		cin >> A[i].GioiTinh;
		cin >> A[i].DiemToan;
		cin >> A[i].DiemLy;
		cin >> A[i].DiemHoa;
	}
}

void XoaTheoHoTen(SinhVien (&A)[], int &n, char (&hotenxoa)[]){
	for(int i = 0;i<n;i++)
	{
		if(strcmp(hotenxoa,A[i].HoTen)==0){
			int j = i;
			for(int i=j; i<n; i++){
				A[i] = A[i+1];
			}
			n--;
			i--;
		}
	}
}

void Xuat(SinhVien (&A)[], int &n){
	for(int i = 0;i<n;i++){
		A[i].DTB = (A[i].DiemToan + A[i].DiemHoa + A[i].DiemLy)/3;
		cout << A[i].MASV << "\t" << A[i].HoTen << '\t' << A[i].NgaySinh <<'\t'<< A[i].GioiTinh <<'\t'<< A[i].DiemToan<<'\t'<<A[i].DiemLy << '\t'<< A[i].DiemHoa<<"\t";
		printf("%.3g\n",A[i].DTB);
	}
}

int main() {
    SinhVien A[MAXN];
    char hoTenCanXoa[100];
    int n;
    Nhap(hoTenCanXoa);
    Nhap(A, n);
    XoaTheoHoTen(A, n, hoTenCanXoa);
    Xuat(A, n);
    return 0;
}

