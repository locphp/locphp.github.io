#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sin_taylor(double x, double epsilon) {
  double sum = 0;
  double term = x;

  for (int n = 1; std::abs(term) > epsilon; n++) {
    sum += term;
    term = -term * x * x / ((2 * n) * (2 * n + 1));
  }

  return sum;
}

int main() {
  double x ;
  cin>>x;
  double epsilon = 0.00001;
  cout << fixed<< setprecision(4)<<sin_taylor(x, epsilon) << endl;
  return 0;
}