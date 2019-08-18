#include <iostream>

using namespace std;

// 递归函数解决汉诺塔问题。
void hanoi(int n, char a, char b, char c)
{
    // 递归终止的条件，当仅有一个盘子的时候，将盘子从a移到c即可。
    if (n == 1)
    {
        cout << a << "->" << c << ' ';
    }
    // 否则，首先将除最底层以外的盘子从a移到b，
    // 再将a移到c，最后，再将剩余的盘子从b移到c。
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << "->" << c << ' ';
        hanoi(n - 1, b, a, c);
    }
}

// 一个wrapper。
void hanoi(int n)
{
    hanoi(n, 'a', 'b', 'c');
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Disk number: 6" << endl;
    hanoi(6);
    cout << endl;
    cout << "Disk number: 8" << endl;
    hanoi(8);
    return 0;
}
