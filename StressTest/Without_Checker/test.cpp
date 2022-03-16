// one often meets his destiny on the road he avoids to take --master oogway
#include "bits/stdc++.h"
using namespace std;

#ifdef PRABH
#include "debug.h"
#else
#define dbg(...)
#endif

#define int int64_t
#define ld long double
#define pb push_back
#define all(v) begin(v), end(v)
const int inf = 4e18;
const int N = 2e5 + 10;  // verify before using

void yes(bool caps = true) { cout << (caps ? "YES" : "Yes") << '\n'; }
void no(bool caps = true) { cout << (caps ? "NO" : "No") << '\n'; }

template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }

void testCase() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> can(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> can[i];
    }

    int ans = inf;
    for (int rep = 0; rep < 2; rep++) {
        vector<int> da(n, inf), db(n, inf);
        queue<pair<int, int>> q;
        da[a] = 0, db[b] = 0;
        q.push({a, b});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            dbg(x, y);
            if (can[x] ^ can[y] and can[x]) {
                ckmin(ans, da[x]);
            }

            if (da[l[x]] == inf) {
                da[l[x]] = da[x] + 1;
                ckmin(db[l[y]], db[y] + 1);
                q.push({l[x], l[y]});
            } else {
                int nx = l[x], ny = l[y];
                if (can[nx] and !can[ny]) {
                    ckmin(ans, da[x] + 1);
                }
            }

            if (da[r[x]] == inf) {
                da[r[x]] = da[x] + 1;
                ckmin(db[r[y]], db[y] + 1);
                q.push({r[x], r[y]});
            } else {
                int nx = r[x], ny = r[y];
                if (can[nx] and !can[ny]) {
                    ckmin(ans, da[x] + 1);
                }
            }
        }

        swap(a, b);
    }

    if (ans == inf)
        cout << "indistinguishable";
    else
        cout << ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    // cin >> t_c;
    for (int testNo = 1; testNo <= t_c; testNo++) {
        // cout << "Case #" << testNo << ": ";
        testCase();
    }
}