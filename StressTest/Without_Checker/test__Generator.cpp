#include "/mnt/3E86036E860325CD/CP/Library/Headers/generator.hpp"
using namespace std;
using namespace jngen;

int main() {
    int TC = 1;
    cout << TC << '\n';
    setMod().add1();
    for (int tc = 0; tc < TC; tc++) {
        int n = rnd.next(1, 4);
        int m = rnd.next(0, n * (n - 1) / 2);
        cout << n << ' ' << m << '\n';
        for (int r = 0; r < 2; r++) {
            Graph g = Graph::random(n, m);
            cout << g << '\n';
        }
    }
}