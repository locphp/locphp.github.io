// Bài toán xếp hậu
// Tìm cách xếp n quân hậu vào n hàng trên bàn cờ vua n*n sao cho không có 2 quân hậu nào ăn nhau.
// Gọi X = (X1, X2,..., Xn) là một nghiệm của bài toán. Khi đó nếu Xi = j thì có nghĩa ta xếp quân hậu hàng thứ i nằm trên cột j.

// Tư duy thuật toán

#include <bits/stdc++.h>

using namespace std;

int n, x[100];
char cot[100], d1[100], d2[100];
char a[100][100];
int cnt = 0;


void inkq(){
	memset(a, 'o', sizeof(a));
	for(int i = 1; i <= n; i++){
		a[i][x[i]] = 'x';
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int i){
	//Duyet cac kha nang ma x[i] co the nhan duoc
	for(int j = 1; j <= n; j++){
		//Chuan bi gan x[i] = j;
		if(cot[j] == 1 && d1[i-j+n] == 1 && d2[i+j-1] == 1){
			//Các đường chép xuôi được đánh chỉ số từ 1 đến 2n -1. 
			//ô (i,j) bị đường chéo xuôi i - j + n quản lý, bị đường chéo ngược i + j - 1 quản lý
			x[i] = j;
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
			if(i == n){
				inkq();
				++cnt;
			}
			else{
				Try(i + 1);
			}
			cot[j] = d1[i - j + n] = d2[i + j -1] = 1;
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i < 100; i++){
		cot[i] = d1[i] = d2[i] = 1;
	}
	Try(1);	
	cout <<"Co " << cnt << " cach xep " << n << " quan hau vao " << n << " hang tren ban co vua " << n << "*"<< n << "\n";
	return 0;
}