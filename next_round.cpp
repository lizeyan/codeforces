#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int n, k, _tmp;
    cin >> n >> k;
    vector<int> scores;
    for (int i = 0; i < k; ++i)
    {
        cin >> _tmp;
        scores.push_back(_tmp);
    }
    if (scores[k - 1] > 0)
    {
        for (int i = k; i < n; ++i)
        {
            cin >> _tmp;
            if (_tmp != scores[k - 1])
            {
                cout << i << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }
    else
    {
        for (int i = k - 1; i >= 0; --i)
        {
            if (scores[i] > 0)
            {
                cout << i + 1<< endl;
                return 0;
            }
        }
        cout << 0 << endl;
        return 0;
    }
}