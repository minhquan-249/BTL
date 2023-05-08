#include "dich_vu.cpp"

class SP{
    private:
        string name, id1;
        int price, amount;
    public:
        SP(){}
        SP(string name, string id1, int amount, int price);
        ~SP(){}
        
        friend istream& operator>>(istream &is, SP* &a);

        friend ostream& operator<<(ostream &os, SP* a);

        void setName(string name);
        string getName();

        void setID1(string id1);
        string getID1();

        void setPrice(int price);
        int getPrice();

        void setAmount(int amount);
        int getAmount();

        long int tong_tien();
};

SP :: SP(string name, string id1, int amount, int price){
    this -> name = name;
    this -> id1 = id1;
    this -> amount = amount;
    this -> price = price;
}

istream& operator>>(istream &is, SP* &a){
    cout << "Ten san pham: "; getline(is, a -> name);
    cout << "Ma san pham: "; getline(is, a -> id1);
    cout << "So luong: "; is >> a -> amount;
    cout << "Gia thanh: "; is >> a -> price;
    is.ignore();
    return is;
}

ostream& operator<<(ostream &os, SP* a){
    os << '|' << setw(25) << a -> name;
    os << '|' << setw(20) << a -> id1;
    os << '|' << setw(10) << a -> amount;
    os << '|' << setw(15) << a -> price;
    os << '|' << setw(10) << a -> tong_tien() << '|' << endl;
    return os;
}

void SP :: setName(string name){
    this -> name = name;
}
string SP :: getName(){
    return name;
}

void SP :: setID1(string id1){
    this -> id1 = id1;
}
string SP :: getID1(){
    return id1;
}

void SP :: setPrice(int price){
    this -> price = price;
}
int SP :: getPrice(){
    return price;
}

void SP :: setAmount(int amount){
    this -> amount = amount;
}
int SP :: getAmount(){
    return amount;
}

long int SP :: tong_tien(){
    return amount * price;
}

void ds_sanpham(Ds* &ds_sp){
    int x, i = 0;
    hoi_san_pham();
    cin >> x;
    cin.ignore();
    init(ds_sp);
    if (x == 0) ds_sp = NULL;
    else{
        SP *sp;
        do{
            sp = new SP;
            cout << "\n\tSan pham thu " << i + 1 << endl;
            cin >> sp;
            last_list(ds_sp, sp);
            i++;
            hoi_nhap();
            cin >> x;
        }while(x == 1);
    }
}



