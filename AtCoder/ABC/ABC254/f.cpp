#include <bits/stdc++.h>
using namespace std;

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html

#include <vector>

template <typename Monoid>
struct SegTree {
    using F = function<Monoid(Monoid, Monoid)>;

    vector<Monoid> data;
    int size;

    const F f; // Monoid をマージする二項演算
    const Monoid M1; // Monoid の単位元

    SegTree(int sz, const F f, const Monoid& M1) : f(f), M1(M1) {
        size = 1;
        while (size < sz) size <<= 1;
        data.assign(2 * size, M1);
    }

    void set(int pos, const Monoid& x) {
        data[pos+size] = x;
    }

    void build() {
        for (int i = size - 1; i > 0; i--) {
            data[i] = f(data[2*i], data[2*i+1]);
        }
    }

    void update(int pos, const Monoid& val) {
        pos += size;
        data[pos] = val;
        while (pos >>= 1) {
            data[pos] = f(data[2*pos], data[2*pos+1]);
        }
    }

    Monoid query(int from, int to) {
        Monoid ret = M1;

        for (from += size, to += size; from < to; from >>= 1, to >>= 1) {
            if (from&1) ret = f(ret, data[from++]);
            if (to&1) ret = f(ret, data[--to]);
        }

        return ret;
    }

    Monoid operator[](const int& pos) const {
        return data[pos+size];
    }
};

int main() {
    int n,q;
    cin >> n >> q;
    
    typedef long long ll;
    
    // calculate function
    auto f = [](ll a, ll b) {
        return __gcd(a, b);
    };

    // build the tree
    vector<ll> va(n), vb(n);
    SegTree<ll> seg_a(n, f, 0), seg_b(n, f, 0);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
        if (i != 0)
            seg_a.set(i, va[i] - va[i-1]);
    }
    for (int i = 0; i < n; i++) {
        cin >> vb[i];
        if (i != 0)
            seg_b.set(i, vb[i] - vb[i-1]);
    }
    seg_a.build();
    seg_b.build();
    
    // queries
    for (int i = 0; i < q; i++) {
        int a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        a1--; b1--;
        cout << abs(__gcd(va[a1]+vb[b1], 
                    __gcd(seg_a.query(a1+1,a2),seg_b.query(b1+1,b2))))
            << endl;
    }
    return 0;
}