#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int num_primes = 10005;
    bool primes[num_primes];
    for (int i = 2; i != num_primes; i++) {
        primes[i] = true;
    }

    for (int i = 2; i != int(sqrt(num_primes)); i++) {
        if (primes[i]) {
            for (int j = 2; i * j < num_primes; j++) {
                primes[i*j] = false;
            }
        }
    }
    int n, dem = 0;
    cin >> n;
        for (int i = 2; i <= n;i++) {
            if (primes[i] && primes[i-2]) {
                cout << i-2 << ", " << i << endl;
                dem++;
            }
    }
    cout << "Tong: "<< dem <<" cap so sinh doi < "<<n;

    return 0;
}
//*************************************************************************************************

#include <iostream>

using namespace std;
bool isprime(int n)
{
 int t = 0;
 for (int  i = 1; i <= n; i++)
 {
  if (n % i == 0)
   t++;
 }
 return t == 2;
}
int main()
{
 int n;
 int dem = 0;
 cin >> n;
 for (int i = 2; i <= n; i++)
 {
  if (isprime(i) && isprime(i + 2) && i+2 < n) {
   cout << i << ", " << i + 2 << endl; dem++;
  }
 }

 cout << "Tong: " << dem << " cap so sinh doi < " << n;
 return 0;
}
