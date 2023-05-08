#include "danh_sach.cpp"

class DV{
    private:
        string tdv;
        long int gdv;
    public:
        DV(){}
        DV(string tdv, int gdv);
        ~DV(){}
        
        friend istream& operator>>(istream &is, DV* &a);

        friend ostream& operator<<(ostream &os, DV* a);

        void setTdv(string tdv);
        string getTdv();

        void setGdv(long int gdv);
        long int getGdv();
};


DV :: DV(string tdv, int gdv){
    this -> tdv = tdv;
    this -> gdv = gdv;
}

istream& operator>>(istream &is, DV* &a){
    cout << "Ten dich vu: "; getline(is, a -> tdv);
    cout << "Gia dich vu: "; is >> a -> gdv;
    is.ignore();
    return is;
}   

ostream& operator<<(ostream &os, DV* a){
    os << '|' << setw(25) << a -> tdv;
    os << '|' << setw(14) << a -> gdv << '|' << endl;
    return os;
} 

void DV :: setTdv(string tdv){
    this -> tdv = tdv;
}
string DV :: getTdv(){
    return tdv;
}

void DV :: setGdv(long int gdv){
    this -> gdv = gdv;
}
long int DV :: getGdv(){
    return gdv;
}

void ds_dvu(Ds* &ds_dv){
    int x, i = 0;
    hoi_dvu();
    cin >> x;
    cin.ignore();
    init(ds_dv);
    if (x == 0) ds_dv = NULL;
    else{
        DV *dv;
        do{
            dv = new DV;
            cout << "\n\tDich vu thu " << i + 1 << endl;
            cin >> dv;
            last_list(ds_dv, dv);
            i++;
            hoi_nhap();
            cin >> x;
        }while(x == 1);
    }
}