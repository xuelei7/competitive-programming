// https://atcoder.jp/contests/abc254/tasks/abc254_e

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    typedef long long ll;

    vector<vector<ll>> G(n+1);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<ll>> ans(n+1,vector<ll>(4));
    for (int i = 1; i <= n; i++) {
        set<ll> st;

        ll cnt = i;

        // dist = 0
        st.insert(i);
        ans[i][0] = i;

        for (int j = 1; j <= 3; j++) {
            set<ll> sst;
            for (auto node: st) {
                for (auto next_node: G[node]) {
                    if (st.find(next_node) == st.end() && sst.find(next_node) == sst.end()) {
                        sst.insert(next_node);
                        cnt += next_node;
                    }
                }
            }
            ans[i][j] = cnt;
            for (auto new_node: sst) {
                st.insert(new_node);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x,k;
        cin >> x >> k;
        cout << ans[x][k] << endl;
    }
    return 0;
}