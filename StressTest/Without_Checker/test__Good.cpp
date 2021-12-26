// Work hard, have fun, make history :)
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mag(v) (int)v.size()
#define all(v) begin(v), end(v)
const int inf = 4e18;
const int N = 2e5 + 10;  // verify

template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }

void testCase() {
    int n, m;
    cin >> n >> m;
    vector<set<pair<int, int>>> a(2);
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            a[r].insert({u, v});
        }
    }

    vector<int> p(n);
    iota(all(p), 0);

    auto chk = [&]() {
        bool pos = true;
        for (auto [u, v] : a[0]) {
            int uu = p[u], vv = p[v];
            if (uu > vv) swap(uu, vv);
            pos &= (a[1].count({uu, vv}));
        }

        return pos;
    };

    while (true) {
        if (chk()) { return void(cout << "Yes"); }
        if (!next_permutation(all(p))) break;
    }

    cout << "No";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    // cin >> t_c;
    while (t_c--) testCase();
}