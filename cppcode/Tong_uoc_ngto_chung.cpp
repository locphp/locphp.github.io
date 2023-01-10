#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n){
	int dem=0;
	for(int j = 2; j <= sqrt(n); j++)
	{
		if(n % j == 0)
		{
			dem++;
		}
	}
	if(dem != 0 || n < 2)return false;
	else return true;
}

int common_prime_divisor(int M, int N){
	int s=0;
	if ( M % 2 == 0 && N % 2 == 0 )
	{
		s +=2;
	}
	for (int i = 3;i <= min(N,M); i= i+2)
	{
		if(M % i == 0 && N % i == 0)
		{
			if (is_prime(i))
			{ s += i; }
		}
	}
	if(s == 0) return -1;
	else return s;
	}

int main() {
	int N, M ;
	cin >> N >> M;
	cout << common_prime_divisor(M,N);
	return 0;
}