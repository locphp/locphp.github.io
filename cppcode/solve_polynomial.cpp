// Tính đa thức
// input:

// 7
// 2 15
// -1 10
// 0 8
// 1 5
// 6 2
// -8.5 1
// -10.52 0
// 2	
// Output:

// Da thuc vua nhap la: 2x^15-x^10+x^5+6x^2-8.5x-10.52
// Voi x=2, gia tri da thuc la: 64540.48

//.......................................Cách 1...................................................//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

struct DATHUC {
    int n;
    pair<double, int>* a;
};

DATHUC* Nhap() {
    DATHUC* B = new DATHUC;
    cin >> B->n;
    B->a = new pair<double, int>[B->n];
    for (int i = 0; i < B->n; i++)
        cin >> B->a[i].first >> B->a[i].second;
    return B;
}
void Xuat(DATHUC B)
{   double s=0;
    for (int i = 0; i < B.n; i++)
    {
        s=s+B.a[i].first;
        if(B.a[i].first==0)
            continue;
        if(B.a[i].second != 0)
        {
           if (i < B.n &&s!=B.a[i].first)
            cout << (B.a[i].first > 0 ? "+" : "");
           if(B.a[i].first!=1 && B.a[i].first!=-1)
            cout << B.a[i].first;
           if(B.a[i].first==-1)
             cout<<"-";
            if (B.a[i].second > 1)
             cout << "x^" << B.a[i].second;
            if (B.a[i].second == 1)
             cout<<"x";
        }
        if(B.a[i].second == 0)
        {
            if (i < B.n &&s!=B.a[i].first)
            cout << (B.a[i].first > 0 ? "+" : "");
            cout << B.a[i].first;

        }

    }
    if(s==0) cout<<0;
}

double TinhDaThuc(DATHUC B, double x) {
    double result = 0;
    for (int i = 0; i < B.n; i++)
        result += B.a[i].first * pow(x, B.a[i].second);
    return result;
}


int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}

//.......................................Cách 2...................................................//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct DATHUC {
    int n;
    double *heso;
    int *somu;
};

DATHUC* Nhap() {
    DATHUC* B = new DATHUC;
    cin >> B->n;
    B->heso = new double[B->n];
    B->somu = new int[B->n];
    for (int i = 0; i < B->n; i++)
        cin >> B->heso[i] >> B->somu[i];
    return B;
}

void Xuat(DATHUC B)
{   double s=0;
    for (int i = 0; i < B.n; i++)
    {
        s=s+B.heso[i];
        if(B.heso[i]==0)
            continue;
        if(B.somu[i] != 0)
        {
            if (i < B.n && s!=B.heso[i])
            cout << (B.heso[i] > 0 ? "+" : "");
            if(B.heso[i]!=1 && B.heso[i]!=-1)
            cout << B.heso[i];
            if(B.heso[i]==-1)
            cout<<"-";
            if (B.somu[i] > 1)
            cout << "x^" << B.somu[i];
            if (B.somu[i] == 1)
            cout<<"x";
        }
        if(B.somu[i] == 0)
        {
            if (i < B.n &&s!=B.heso[i])
            cout << (B.heso[i] > 0 ? "+" : "");
            cout << B.heso[i];
        }
    }
    if(s==0) cout<<0;
}

double TinhDaThuc(DATHUC B, double x) {
    double result = 0;
    for (int i = 0; i < B.n; i++)
        result += B.heso[i] * pow(x, B.somu[i]);
    return result;
}

int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
