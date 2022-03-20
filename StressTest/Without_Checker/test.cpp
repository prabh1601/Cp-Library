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

    auto solve = [&](int x) {
        string s = to_string(x);
        int n = s.size();
        int tot = 0;
        for (int sum = 1; sum <= 9 * n; sum++) {
            vector dp(n + 1, vector(2, vector(sum + 1, vector(sum + 1, int(-1)))));
            auto rec = [&](auto& self, int pos, bool tight, int rem, int mod) -> int {
                if (pos == n) {
                    return (!rem and !mod);
                }
                int& ans = dp[pos][tight][rem][mod];
                if (ans != -1) return ans;
                ans = 0;

                int lim = (tight ? s[pos] - '0' : 9);
                for (int i = 0; i <= lim; i++) {
                    if (i <= rem) {
                        ans += self(self, pos + 1, tight and (i == lim), rem - i, (mod * i) % sum);
                    }
                }
                return ans;
            };

            int got = rec(rec, 0, 1, sum, 1);
            tot += got;
        }
        return tot;
    };

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

    a--;
    int ans = 0;
    if ((b % 10) == 0)
        ans += solve(b - 1) + chk(b);
    else
        ans += solve(b);

    if (a and (a % 10) == 0)
        ans -= (solve(a - 1) + chk(a));
    else
        ans -= solve(a);

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