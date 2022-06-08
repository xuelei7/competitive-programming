// https://atcoder.jp/contests/abc254/tasks/abc254_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[31][31];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
            cout << a[i][j] << " \n"[j==i];
        }
    }
    return 0;
}
