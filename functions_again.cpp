#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int n;
vector<long long> arr;
long long solve(int begin) // Note that the input can be up to 10^9, so the sum is able to be larger than int
{
    if (begin >= arr.size())// Note that arr's minimum size is 1
        return 0;
    vector<long long> sum(n - 1);
    sum[begin] = arr[begin];
    bool negative = true;
    long long min = 0, max = 0;
    min = std::min(min, arr[begin]);
    max = std::max(max, arr[begin]);
    for (int i = begin + 1; i < n - 1; ++i)
    {
        sum[i] = sum[i - 1] + (negative? -arr[i]: arr[i]);
        min = std::min(min, sum[i]);
        max = std::max(max, sum[i]);
        negative = !negative;
    }
    // cout << "sum:";
    // for (int i = begin; i < n - 1; ++i)
    //     cout << sum[i] << " ";
    // cout << endl;
    return max - min;
}
int main ()
{
    cin >> n;
    int last, cur;
    cin >> last;
    for (int i = 1; i < n; ++i)
    {
        cin >> cur;
        arr.emplace_back(abs(cur - last));
        last = cur;
    }
    cout << std::max(solve(0), solve(1)) << endl;
    return 0;
}