#pragma once
#include "san_pham.cpp"

class KH : public PS
{
private:
    NS nm;
    Ds *ds_sp;
    Ds *ds_dv;

public:
    KH() {}
    KH(NS nm, Ds *ds_sp, Ds *ds_dv);
    ~KH() {}

    friend istream &operator>>(istream &is, KH *&a);

    friend ostream &operator<<(ostream &os, KH *a);
    void setNm(NS nm);
    NS getNm();

    void setDs_sp(Ds *&ds_sp);
    Ds *getDs_sp();

    void setDs_dv(Ds *&ds_dv);
    Ds *getDs_dv();
};

KH ::KH(NS nm, Ds *ds_sp, Ds *ds_dv)
{
    this->nm = nm;
    this->ds_sp = ds_sp;
    this->ds_dv = ds_dv;
}

istream &operator>>(istream &is, KH *&a)
{
    is >> (PS *&)a;
    a->setID("KH" + a->getID());
    cout << "Ngay mua";
    is >> a->nm;

    return is;
}

ostream &operator<<(ostream &os, KH *a)
{
    os << (PS *)a;
    os << a->nm << setw(7) << '|';
    return os;
}

void KH ::setNm(NS nm)
{
    this->nm = nm;
}
NS KH ::getNm()
{
    return nm;
}
void KH ::setDs_sp(Ds *&ds_sp)
{
    this->ds_sp = ds_sp;
}
Ds *KH ::getDs_sp()
{
    return ds_sp;
}

void KH ::setDs_dv(Ds *&ds_dv)
{
    this->ds_dv = ds_dv;
}
Ds *KH ::getDs_dv()
{
    return ds_dv;
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

void ds_sp_file(Ds *&ds_sp, KH *kh)
{
    int x, y;
    string id;
    SP *sp1;
    ifstream filein2;

    filein2.open("san_pham.txt");
    filein2 >> x;
    filein2.ignore();
    for (int i = 0; i < x; i++)
    {
        getline(filein2, id);
        if (id == tach_id(kh->getID(), 1))
        {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++)
            {
                sp1 = new SP;
                filein2 >> (SP *&)sp1;
                last_list(ds_sp, sp1);
            }
        }
        else
        {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++)
            {
                sp1 = new SP;
                filein2 >> (SP *&)sp1;
                delete sp1;
            }
        }
    }
}

void ds_dv_file(Ds *&ds_dv, KH *kh)
{
    int x, y;
    string id;
    DV *dv1;
    ifstream filein2;

    filein2.open("dich_vu.txt");
    filein2 >> x;
    filein2.ignore();

    for (int i = 0; i < x; i++)
    {
        getline(filein2, id);
        if (id == tach_id(kh->getID(), 1))
        {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++)
            {
                dv1 = new DV;
                filein2 >> (DV *&)dv1;
                last_list(ds_dv, dv1);
            }
        }
        else
        {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++)
            {
                dv1 = new DV;
                filein2 >> (DV *&)dv1;
                delete dv1;
            }
        }
    }
}
