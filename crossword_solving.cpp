#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main ()
{
    int _;
    cin >> _ >> _;

    string str, pattern;
    cin >> pattern;
    cin >> str;
    vector<size_t> replace_positions(pattern.size() + 1, 0), tmp_replace_positions;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (i + pattern.size() > str.size())
            break;
        tmp_replace_positions.clear();
        for (size_t j = 0; j < pattern.size(); ++j)
        {
            if (pattern[j] != str[i + j])
                tmp_replace_positions.push_back(j);
        }
        if (tmp_replace_positions.size() < replace_positions.size())
            replace_positions = std::move(tmp_replace_positions);
    }
    cout << replace_positions.size() << endl;
    for (auto pos: replace_positions)
        cout << pos + 1 << " ";
    cout << endl;
    return 0;
}
