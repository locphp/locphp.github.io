#include <iostream>
using namespace std;

int input()
{
	int n;
	cin >>n;
	return n;
}
void input(int &m)
{
	cin >> m;
}

int gcd_euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd_euclid(b, a % b);
}

int main() {
	int m, n;
	input(n);
	m=input();
	cout << gcd_euclid(m, n);
}
