// Sample generator to generate an array of length n
#include "bits/stdc++.h"
using namespace std;

void testCase() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // returns a number between [a,b]
    auto rnd = [&](int a, int b) { return a + (rng() % (b - a)); };

    int n = rnd(1, 10);
    for (int i = 0; i < n; i++) {
        int x = rnd(0, 26);
        cout << char('A' + x);
    }

    cout << '\n';
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