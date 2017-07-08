#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
template <class K, class C>
inline bool in (const K& k, const C& c)
{
    return c.find(k) != std::end(c);
}
int main ()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int k;
        cin >> k;
        unordered_set<int> group;
        int person;
        bool ok = false;
        while (k--)
        {
            cin >> person;
            if (!ok)
            {
                if (in(-person, group))
                    ok = true;
                group.insert(person);
            }
        }
        if (!ok)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}