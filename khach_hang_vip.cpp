#include "khach_hang.cpp"

class VIP : public KH
{
private:
    string vip;

public:
    VIP() {}
    VIP(string vip);
    ~VIP() {}

    friend istream &operator>>(istream &is, VIP *&a);
    friend ostream &operator<<(ostream &os, VIP *a);

    void setVIP(string vip);
    string getVIP();
};

VIP ::VIP(string vip)
{
    this->vip = vip;
}

istream &operator>>(istream &is, VIP *&a)
{
    is >> (KH *&)a;
    is.ignore();
    a->setSdt("VIP" + a->getSdt());
    cout << "Loai VIP: ";
    getline(is, a->vip);
    return is;
}

ostream &operator<<(ostream &os, VIP *a)
{
    os << (KH *)a;
    os <<setw(6)<< a->vip << setw(9)<< '|' << endl;
    os << '|' << setfill('=') << setw(134) << '|' << setfill(' ') << endl;
    return os;
}

void VIP ::setVIP(string vip)
{
    this->vip = vip;
}
string VIP ::getVIP()
{
    return vip;
}

void ds_vip(Ds *&ds_vip)
{
    int x, i = 0;
    KH *vp;
    Ds *sp, *dv;
    ifstream filein;
    du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1)
    {
        filein.open("khach_hang_vip.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++)
        {
            vp = new VIP;
            init(sp);
            init(dv);
            filein >> (VIP *&)vp;
            ds_sp_file(sp, vp);
            vp->setDs_sp(sp);
            ds_dv_file(dv, vp);
            vp->setDs_dv(dv);
            last_list(ds_vip, vp);
        }
    }
    else if (x == 2)
    {
        do
        {
            vp = new VIP;
            cout << "\n\tKhach hang VIP thu " << i + 1 << endl;
            cin >> (VIP *&)vp;
            ds_sanpham(sp);
            ds_dvu(dv);
            vp->setDs_sp(sp);
            vp->setDs_dv(dv);
            last_list(ds_vip, vp);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
    }
    else
        return;
}