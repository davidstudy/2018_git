#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    int a, b, res;
    bool flag = false;
    while (cin >> a >> b)
    {
        flag = a % 2;//
        int tmp = (1 + a) / 2;
        if (flag)//
        {
            if (b >= tmp) res = b - 1;
            else res = b + 1;
        }
        else//
        {
            if (b > tmp) res = b - 1;
            else res = b + 1;
        }
        if (res < 1) res = 1;
        else if (res >= a) res = a;
        cout << res << endl;
    }
    return 0;
}
