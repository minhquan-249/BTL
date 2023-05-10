#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void td_person()
{
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(13) << "Nam sinh";
    cout << '|' << setw(15) << "Ma";
    cout << '|' << setw(15) << "So dien thoai";
    cout << '|' << setw(10) << "Gioi tinh";
    cout << '|' << setw(20) << "Dia chi";
}

void td_khnor()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(119) << '|' << setfill(' ') << endl;
    td_person();
    cout << '|' << setw(13) << "Ngay mua" << setw(7)<<'|'<<endl;
    cout << '|' << setfill('=') << setw(119) << '|' << setfill(' ') << endl;
}

int main()
{
    td_khnor();
    return 0;
}

