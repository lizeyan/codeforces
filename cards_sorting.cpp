#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Card
{
    int number;
    Card *pre, *next;
};

int main ()
{
    int n;
    cin >> n;
    Card* head = new Card;
    cin >> head->number;
    vector<int> numbers;
    numbers.push_back(head->number);
    Card* tail = head;
    for (int i = 1; i < n; ++i)
    {
        Card* c = new Card;
        cin >> c->number;
        numbers.push_back(c->number);
        tail->next = c;
        c->pre = tail;
        tail = c;
    }
    sort(begin(numbers), end(numbers));
    tail->next = head;
    head->pre = tail;

    int cnt = 0;
    Card* p = head;
    int iter_cnt = 0;
    while (cnt != n)
    {
        ++iter_cnt;
        if (p->number == numbers[cnt])
        {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            ++cnt;
        }
        p = p->next;
    }
    cout << iter_cnt << endl;
    return 0;
}
