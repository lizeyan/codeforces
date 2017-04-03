#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;
int main ()
{
    string input;
    getline(cin, input);
    // index from 1 to n
    auto n = input.size();
    //cnt[i][j] means how many char is left in the first i char with the remainder of j
    vector<vector<int>> cnt(n + 1, vector<int>(3, 0));
    //ptr[i][j] means  the last char's index
    vector<vector<int>> pre(n + 1, vector<int>(3, 0));
    //state[i][j] means the state the string. 0:nothing 1:only zero 2:normal
    vector<vector<int>> state(n + 1, vector<int>(3, 0));
    auto index = 1;
    for (auto c: input)
    {
        int number = c - '0';
        int remain = number % 3;
        for (int j = 0; j < 3; ++j)
        {
            //inherit
            cnt[index][j] = cnt[index - 1][j];
            pre[index][j] = pre[index - 1][j];
            state[index][j] = state[index - 1][j];
            //update
            int from = (j - number + 12) % 3; //+12 to avoid negative number
            int i = index - 1;
            if (cnt[i][from] > 0 && cnt[i][from] + 1 > cnt[index][j])
            {
                if (number != 0 || state[i][from] != 1)
                {
                    cnt[index][j] = cnt[i][from] + 1;
                    pre[index][j] = index;
                    if (number != 0)
                        state[index][j] = 2;
                    else if (state[i][from] == 0)
                        state[index][j] = 1;
                }
            }
        }
        if (cnt[index][remain] == 0)
        {
            cnt[index][remain] = 1;
            pre[index][remain] = index;
            if (number == 0)
                state[index][remain] = 1;
            else
                state[index][remain] = 2;
        }
        ++index;
    }
    if (cnt[n][0] == 0)
        cout << -1 << endl;
    else
    {
        vector<int> rst;
        auto ptr = n;
        auto last_remain = 0;
        while (ptr > 0)
        {
            int p = pre[ptr][last_remain];
            rst.push_back(p - 1);
            last_remain = (last_remain - int(input[p - 1] - '0') + 12) % 3;
            ptr = pre[p - 1][last_remain];
        }
        //remove leading zeros
        while (rst.size())
        {
            if (input[rst.back()] != '0')
                break;
            rst.pop_back();
        }
        if (!rst.size())
            cout << 0 << endl;
        else
        {
            while(rst.size())
            {
                cout << input[rst.back()];
                rst.pop_back();
            }
            cout << endl;
        }
    }
    return 0;
}