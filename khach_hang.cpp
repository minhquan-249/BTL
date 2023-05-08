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

    long int thanh_tien();
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
    os << a->nm << setw(7) << '|' << setw(15) << '|' << endl;
    cout << '|' << setfill('=') << setw(134) << '|' << setfill(' ') << endl;
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

bool tach_sdt(string a)
{
    string b = "";
    b = b + a[0] + a[1] + a[2];
    if (b == "VIP")
        return true;
    return false;
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

long int KH ::thanh_tien()
{
    Ds *tg = ds_sp;
    long int t1 = 0, t2 = 0;
    DV *dv;
    SP *sp;
    if (tg == NULL)
        t1 = 0;
    else
    {
        while (tg != NULL)
        {
            sp = (SP *)tg->getData();
            t1 += sp->tong_tien();
            tg = tg->getNext();
        }
    }

    tg = ds_dv;
    if (tg == NULL)
        t2 = 0;
    else
    {
        while (tg != NULL)
        {
            dv = (DV *)tg->getData();
            t2 += dv->getGdv();
            tg = tg->getNext();
        }
    }

    return t1 + t2;
}
