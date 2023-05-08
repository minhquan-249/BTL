#include <iostream>
#include <string>

using namespace std;

void tach_id(string a, int k)
{
    string b = "";
    while ((a[a.length() - 1] != 'H' )|| (a[a.length() - 1] != 'V'))
    {
        b = a[a.length() - 1] + b;
        a.pop_back();
    }
    if (k == 1)
        cout<< b;
    cout<< a;
}

int main()
{
    string x="KH0001";
    tach_id(x,1);
}

