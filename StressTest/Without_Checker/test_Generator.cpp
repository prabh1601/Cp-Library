// Come on mate, keep going, we ain't that weak
#include "bits/stdc++.h"
using namespace std;

#ifdef PRABH
#include "debug.h"
#else
#define dbg(...)
#endif

#define int int64_t
#define pb push_back
#define all(v) begin(v), end(v)
using ld = long double;
const int inf = 4e18;
const int N = 2e5 + 10;  // verify before using

void yes(bool caps = true) { cout << (caps ? "YES" : "Yes") << '\n'; }
void no(bool caps = true) { cout << (caps ? "NO" : "No") << '\n'; }

template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }

void testCase() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto rnd = [&](int a, int b) { return a + (rng() % (b - a)); };
    int N = 1e5;
    int n = rnd(1, N);
    int m = rnd(n, N);
    cout << n << ' ' << m << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 10;
    cout << t_c << '\n';
    for (int testNo = 1; testNo <= t_c; testNo++) {
        // cout << "Case #" << testNo << ": ";
        testCase();
    }
}