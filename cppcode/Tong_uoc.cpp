#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int s = 0;
    
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
// một số nguyên >= 2 bất kỳ sẽ luôn có số ước ở nửa đầu căn bậc 2 của nó bằng số ước ở nửa sau căn bậc 2 của nó. Cụ thể, các ước sẽ phân bố thành 2 miền từ [2; sqrt(x)] và từ [sqrt(x); x].
        if (n % i == 0) {
            int j = n/i;
            if (i == j) {
                s = s + i;
            } else {
                s = s + i + j;
            }
        }
    }
    cout << (s - n);// trừ n do lúc ban đầu chạy vòng lặp for từ i =1 nên thực hiện s = s + i + j nên phải trừ lại n
    
    return 0;   
}
//code tối ưu
