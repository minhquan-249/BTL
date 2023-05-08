#include "danh_sach.cpp"

class NV : public PS
{
private:
    string cv;
    long int lcb;

public:
    NV() {}
    NV(string cv, long int lcb);
    ~NV() {}

    friend istream &operator>>(istream &is, NV *a);

    friend ostream &operator<<(ostream &os, NV *a);

    void setCv(string cv);
    string getCv();

    void setLcb(long int lcb);
    long int getLcb();
};

NV ::NV(string cv, long int lcb)
{
    this->cv = cv;
    this->lcb = lcb;
}

istream &operator>>(istream &is, NV *a)
{
    is >> (PS *&)a;
    a->setID("NV" + a->getID());
    cout << "Chuc vu: ";
    getline(is, a->cv);
    cout << "Luong co ban: ";
    is >> a->lcb;
    is.ignore();
    return is;
}

ostream &operator<<(ostream &os, NV *a)
{
    os << (PS *)a;
    os << '|' << setw(25) << a->cv;
    os << '|' << setw(10) << a->lcb <<setw(5)<< '|' << endl;
    os << '|' << setfill('=') << setw(140) << '|' << setfill(' ') << endl;
    return os;
}

void NV ::setCv(string cv)
{
    this->cv = cv;
}
string NV ::getCv()
{
    return cv;
}

void NV ::setLcb(long int lcb)
{
    this->lcb = lcb;
}
long int NV ::getLcb()
{
    return lcb;
}

void ds_nv(Ds *&ds_nv)
{
    int x, i = 0;
    NV *nv;
    ifstream filein;
    du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1)
    {
        filein.open("nhan_vien.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++)
        {
            nv = new NV;
            filein >> (NV *&)nv;
            last_list(ds_nv, nv);
        }
    }
    else if (x == 2)
    {
        do
        {
            nv = new NV;
            cout << "\n\tNhan vien thu " << i + 1 << endl;
            cin >> (NV *&)nv;
            last_list(ds_nv, nv);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
    }
    else
        return;
}