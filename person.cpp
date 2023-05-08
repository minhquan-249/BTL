#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class NS
{
private:
    int d, m, y;

public:
    NS() {}
    ~NS() {}

    friend istream &operator>>(istream &is, NS &a);
    friend ostream &operator<<(ostream &os, NS a);

    void setD(int d);
    int getD();

    void setM(int m);
    int getM();

    void setY(int y);
    int getY();
};

class PS
{
protected:
    string ht, dc, gt, sdt, id;
    NS ns;

public:
    PS() {}
    PS(string ht, string id, NS ns, string sdt, string gt, string dc);
    ~PS() {}

    friend istream &operator>>(istream &is, PS *&a);

    friend ostream &operator<<(ostream &os, PS *a);

    void setHt(string ht);
    string getHt();

    void setID(string id);
    string getID();

    void setSdt(string sdt);
    string getSdt();

    void setGt(string gt);
    string getGt();

    void setDc(string dc);
    string getDc();

    void setNs(NS ns);
    NS getNs();
};

// Tai dinh nghia toan tu cua class NS

istream &operator>>(istream &is, NS &a)
{
    cout << "Ngay: ";
    is >> a.d;
    cout << "Thang: ";
    is >> a.m;
    cout << "Nam: ";
    is >> a.y;
    return is;
}

ostream &operator<<(ostream &os, NS a)
{
    if (a.d < 10)
        os << '|' << setw(4) << '0' << a.d;
    else
        os << '|' << setw(5) << a.d;

    if (a.m < 10)
        os << "-0" << a.m;
    else
        os << '-' << a.m;

    os << '-' << setw(4) << a.y;
    return os;
}

// Dinh nghia ben ngoai class PS
PS::PS(string ht, string id, NS ns, string sdt, string gt, string dc)
{
    this->ht = ht;
    this->id = id;
    this->ns = ns;
    this->sdt = sdt;
    this->gt = gt;
    this->dc = dc;
}

istream &operator>>(istream &is, PS *&a)
{
    cout << "Ho ten: ";
    getline(is, a->ht);
    cout << "\n\tNgay sinh" << endl;
    is >> a->ns;
    is.ignore();
    cout << "Ma: ";
    getline(is, a->id);
    cout << "So dien thoai: ";
    getline(is, a->sdt);
    cout << "Gioi tinh: ";
    getline(is, a->gt);
    cout << "Dia chi: ";
    getline(is, a->dc);
    return is;
}

string tach_id(string a, int k)
{
    string b = "";
    while (a[a.length() - 1] != 'H' and a[a.length() - 1] != 'V')
    {
        b = a[a.length() - 1] + b;
        a.pop_back();
    }
    if (k == 1)
        return b;
    return a;
}

ostream &operator<<(ostream &os, PS *a)
{
    os << '|' << setw(20) << a->ht;
    os << a->ns;
    os << '|' << setw(15) << a->id;
    os << '|' << setw(15) << a->sdt;
    os << '|' << setw(10) << a->gt;
    os << '|' << setw(20) << a->dc;
    return os;
}

void PS ::setHt(string ht)
{
    this->ht = ht;
}
string PS ::getHt()
{
    return ht;
}

void PS::setID(string id)
{
    this->id = id;
}
string PS::getID()
{
    return id;
}
void PS ::setSdt(string sdt)
{
    this->sdt = sdt;
}
string PS ::getSdt()
{
    return sdt;
}

void PS ::setGt(string gt)
{
    this->gt = gt;
}
string PS ::getGt()
{
    return gt;
}

void PS ::setDc(string dc)
{
    this->dc = dc;
}
string PS ::getDc()
{
    return dc;
}

void PS ::setNs(NS ns)
{
    this->ns = ns;
}
NS PS ::getNs()
{
    return ns;
}
