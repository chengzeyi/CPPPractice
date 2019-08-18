#include <iostream>

using namespace std;

inline int getCurrSum(int n) {
    int currSum = 0;
    while (n != 0) {
        currSum += n % 10;
        n /= 10;
    }
    return currSum;
}

int main(int argc, char *argv[]) {
    int l, r;
    cin >> l >> r;
    string s;

    int totalSum = 0;
    for (int i = 1; i< l; ++i) {
        totalSum += getCurrSum(i);
    }
    int count = 0;
    for (int i = l; i <= r; ++i) {
        totalSum += getCurrSum(i);
        if (totalSum % 3 == 0) {
            count++;
        }
    }
    
    cout << count << endl;
    
	return 0;
}
