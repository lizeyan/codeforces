#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int a, b;
    cin >> a >> b;
    cout << int((log(double(b) / a)) / (log(1.5))) + 1 << endl;
    return 0;
}