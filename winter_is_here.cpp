/*
Winter is here at the North and the White Walkers are close. John Snow has an army consisting of n soldiers. While the rest of the world is fighting for the Iron Throne, he is going to get ready for the attack of the White Walkers.

He has created a method to know how strong his army is. Let the i-th soldier’s strength be ai. For some k he calls i1, i2, ..., ik a clan if i1 < i2 < i3 < ... < ik and gcd(ai1, ai2, ..., aik) > 1 . He calls the strength of that clan k·gcd(ai1, ai2, ..., aik). Then he defines the strength of his army by the sum of strengths of all possible clans.

Your task is to find the strength of his army. As the number may be very large, you have to print it modulo 1000000007 (109 + 7).

Greatest common divisor (gcd) of a sequence of integers is the maximum possible integer so that each element of the sequence is divisible by it.

Input
The first line contains integer n (1 ≤ n ≤ 200000) — the size of the army.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 1000000) — denoting the strengths of his soldiers.

Output
Print one integer — the strength of John Snow's army modulo 1000000007 (109 + 7).
*/

/*
Let f[i] denotes the sum of the number of each clan's members whose GCD is i, then \sigma_{i=2}_{MAX}{f[i] * i} is the answer. 
We calculate f[i] in descending order and let F[i] denotes the sum of the numbers of each combination's members of which i is a factor. And let cnt[i] denotes the numbers of soldiers of which i is a factor.
Then F[i] = 1 * C(cnt[i], 1) + 2 * C(cnt[i], 2) + ... + cnt[i] * C(cnt[i], cnt[i])
f[i] = F[i] - F[2 * i] - F[3 * i] - ... (because F[i] includes f[j] when j is a multiple of i)

After all, we should take the big quantity into consider. In each step, we save the answer's module of (1e9 + 7)
*/
#include <iostream>
#include <vector>
using namespace std;
constexpr long long P = 1000000007;
constexpr int MAX = 1000000;
#define MOD(x) (((x) % P + P) % P)
int main ()
{
    int n;
    vector<long long> f(MAX + 1, 0);
    vector<long long> cnt(MAX + 1, 0);
    vector<long long> power2(MAX + 1, 1);
    for (int i = 1; i <= MAX; ++i)
        power2[i] = ((power2[i - 1] * 2) % P + P) % P;
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        cnt[x] += 1;
        for (int j = 2; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                cnt[j] += 1;
                if (j * j != x)
                    cnt[x / j] += 1;
            }
        }
    }
    long long ans = 0;
    for (int i = MAX; i > 1; --i)
    {
        if (cnt[i] == 0)
            continue;
        f[i] = MOD(cnt[i] * power2[cnt[i] - 1]);
        for (int j = i + i; j <= MAX; j += i)
            f[i] = MOD(f[i] - f[j]);
        ans += MOD(f[i] * i);
        ans = MOD(ans);
    }
    cout << ans << endl;
    return 0;
}