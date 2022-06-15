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
