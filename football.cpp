#include <iostream>
using namespace std;
int main ()
{
    string input;
    cin >> input;
    int cnt = 0;
    bool dangerous = false;
    char last = 'x';
    for (const auto& chr: input)
    {
        if (chr != last)
        {
            cnt = 0;
            last = chr;
        }
        chr == '1'? ++cnt : --cnt;
        if (cnt == 7 || cnt == -7)
        {
            dangerous = true;
            break;
        }
    }
    cout << (dangerous? "YES":"NO") << endl;
    return 0;
}
