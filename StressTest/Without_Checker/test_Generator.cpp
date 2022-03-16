// The only power I have is, I believe we can do better
#include "/mnt/Drive1/CP/Algo_Library/includes/generator.h"
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
    int n = rnd.next(1, 10);
    int a = rnd.next(0, n - 1);
    int b = rnd.next(0, n - 1);
    cout << n << ' ' << a << ' ' << b << '\n';
    for (int i = 0; i < n; i++) {
        int l = rnd.next(0, n - 1);
        int r = rnd.next(0, n - 1);
        int c = rnd.next(0, 1);
        cout << l << ' ' << r << ' ' << c << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    // cout << t_c << '\n';
    for (int testNo = 1; testNo <= t_c; testNo++) {
        // cout << "Case #" << testNo << ": ";
        testCase();
    }
}