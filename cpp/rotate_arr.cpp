#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long value;
    map<long long, int, greater<long long>> frequencyTable;

    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        frequencyTable[value]++;
    }

    for (const auto &entry : frequencyTable) {
        cout << entry.first << " " << entry.second << "\n";
    }
    return 0;
}