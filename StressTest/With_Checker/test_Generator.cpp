#include"/mnt/3E86036E860325CD/CP/Headers/generator.hpp"
using namespace std;
using namespace jngen;

int main() {
    setMod().printN().printM().add1();
    int TC = 2;
    cout << TC << '\n';
    for (int tc = 0; tc < TC; tc++) {
        int n = rnd.next(2, 5);
        int m = rnd.next(1, (n * (n - 1)) / 2);
        auto a = TArray<int>::random(m, 1, 1);
        Graph g = Graph::random(n, m);
        g.setEdgeWeights(a);
        cout << g << '\n';
    }
}