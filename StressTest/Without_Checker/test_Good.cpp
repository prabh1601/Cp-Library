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
    int a, b;
    cin >> a >> b;
    auto chk = [&](int x) {
        int t = x;
        int s = 0;
        while (t) {
            s += (t % 10);
            t /= 10;
        }

        t = x;
        int p = 1;
        while (t) {
            int c = (t % 10);
            t /= 10;
            p = (p * c) % s;
        }

        return (p == 0);
    };

    int ans = 0;
    for (int i = a; i <= b; i++) ans += chk(i);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    cin >> t_c;
    for (int testNo = 1; testNo <= t_c; testNo++) {
        cout << "Case #" << testNo << ": ";
        testCase();
    }
}