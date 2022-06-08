// https://atcoder.jp/contests/abc254/tasks/abc254_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int a[1<<20];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        vector<int> v;
        for (int j = i; j < n; j += k) {
            v.push_back(a[j]);
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++) {
            a[j*k + i] = v[j];
        }
    }

    bool ok = 1;
    for (int i = 0; i < n-1; i++) {
        if (a[i+1] < a[i]) ok = 0;
    }

    cout << (ok? "Yes": "No") << endl;
    return 0;
}
