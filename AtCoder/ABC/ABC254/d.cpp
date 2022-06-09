// https://atcoder.jp/contests/abc254/tasks/abc254_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        v.push_back(i*i);
    }

    vector<int> vv(n+1);
    for (int i = 1; i <= n; i++) {
        vv[i] = i;
    }
    for (long long i = 2; i*i <= n; i++) {
        for (long long j = i*i; j <= n; j += i*i) {
            while (vv[j] % (i*i) == 0) {
                vv[j] /= i*i;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += upper_bound(v.begin(), v.end(), n / vv[i]) - v.begin();
    }

    cout << ans << endl;
    return 0;
}