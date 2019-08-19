#include <iostream>
#include <unordered_map>

#define MAX 1000000007

using namespace std;

unordered_map<long long, long long> op;

long long solve(long long N) {
    auto search = op.find(N);
    if (search != op.end()) {
        return search->second;
    }
    if (N <= 0) {
        return 1;
    }
    if (N <= 2) j
        return N;
    }
    long long a = N / 2;
    long long sa = solve(a);
    long long sa2 = solve(a - 2);

    long long b = N - a;
    long long sb = solve(b);
    long long sb2 = solve(b - 2);

    long long total = sa * sb % MAX;
    long long tmp = sa2 * sb2 % MAX;
    total = (total + tmp) % MAX;
    op.emplace(N, total);
    return total;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long N;
        cin >> N;
        long long result = solve(N);
        cout << result << endl;
    }

    return 0;
}
