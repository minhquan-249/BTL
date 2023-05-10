#include "khach_hang.cpp"

class NOR : public KH
{
public:
    NOR() {}
    ~NOR() {}

    friend istream &operator>>(istream &is, NOR *&a);
    friend ostream &operator<<(ostream &os, NOR *a);
};

istream &operator>>(istream &is, NOR *&a)
{
    is >> (KH *&)a;
    is.ignore();
    a->setSdt("NOR" + a->getSdt());
    return is;
}

ostream &operator<<(ostream &os, NOR *a)
{
    os << (KH *)a;
    cout<< setw(15) << '|' << endl;
    cout << '|' << setfill('=') << setw(134) << '|' << setfill(' ') << endl;
    return os;
}

void ds_nor(Ds *&ds_nor)
{
    int x, i = 0;
    KH *nr;
    Ds *sp, *dv;
    ifstream filein;
    du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1)
    {
        filein.open("khach_hang_nor.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++)
        {
            nr = new NOR;
            init(sp);
            init(dv);
            filein >> (NOR *&)nr;
            ds_sp_file(sp, nr);
            nr->setDs_sp(sp);
            ds_dv_file(dv, nr);
            nr->setDs_dv(dv);
            last_list(ds_nor, nr);
        }

    }
    else if (x == 2)
    {
        do
        {
            nr = new NOR;
            cout << "\n\tKhach hang NOR thu " << i + 1 << endl;
            cin >> (NOR *&)nr;
            ds_sanpham(sp);
            ds_dvu(dv);
            nr->setDs_sp(sp);
            nr->setDs_dv(dv);
            last_list(ds_nor, nr);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
    }
    else
        return;
}