// The only power I have is, I believe we can do better
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

template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }

void testCase() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int di : {-2, -1, 1, 2}) {
        for (int dj : {-2, -1, 1, 2}) {
            if (abs(di) != abs(dj)) {
                int aa = a + di, bb = b + dj;
                int dx = (aa - c), dy = (bb - d);
                if (dx * dx + dy * dy == 5) return void(cout << "Yes");
            }
        }
    }

    cout << "No";
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