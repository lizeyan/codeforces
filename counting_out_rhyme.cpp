#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int n, k;
    cin >> n >> k;
    vector<int> people(n);
    for (int i = 0; i < n; ++i)
        people[i] = i + 1;
    int step;
    unsigned int ptr = 0;
    for (int i = 0; i < k; ++i)
    {
        cin >> step;
        ptr = (ptr + step) % people.size();
        cout << people[ptr] << " ";
        people.erase(std::begin(people) + ptr);
        if (ptr >= people.size())
            ptr = 0;
    }
    cout << endl;
    return 0;
}
