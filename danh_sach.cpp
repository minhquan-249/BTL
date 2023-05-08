#pragma once
#include "tieu_de.cpp"

class Ds{
    private:
        void* data;
        Ds *next;
    public:
        Ds(){};
        ~Ds(){
            delete next;
        }

        void setData(void *data);
        void* getData();

        void setNext(Ds* next);
        Ds* getNext();
};
 
void Ds :: setData(void* data){
    this -> data = data;
}

void* Ds :: getData(){
    return data;
}

void Ds :: setNext(Ds* next){
    this -> next = next; 
}

Ds* Ds :: getNext(){
    return next;
}

void init(Ds* &ds){
    ds = new Ds;
    ds = NULL;
}

Ds* create(void* data){
    Ds *tg = new Ds;
    tg -> setData(data);
    tg -> setNext(NULL);
    return tg;
}

void first_list(Ds* &ds, void* data){
    Ds *tg = create(data);
    ds = tg;
}

void last_list(Ds* &ds, void* data){
    Ds *tg = create(data);
    
    if (ds == NULL) first_list(ds, data); 
    else{
        Ds *ds1 = ds;
        while(ds1 -> getNext() != NULL){
            ds1 = ds1 -> getNext();
        }
        ds1 -> setNext(tg);
    }
}

Ds* delete_ds(Ds*&ds, int k){
    Ds *tg = ds, *tg1;;

    k -= 1;
    if (k == -1) return tg;
    if (k == 0){
        tg = tg -> getNext();
        return tg;
    }

    for (int i = 0; i < k - 1; i++){
        tg = tg -> getNext();
    }
    tg -> setNext(tg -> getNext() -> getNext()); 
    return ds;
}
  
Ds* add_ds(Ds* &ds, void* data, int k){
    Ds *tg = create(data), *tg1 = ds;

    k -= 1;
    if (k == -1) return tg1;
    if (k == 0){
        tg -> setNext(ds);
        return tg;
    }

    for (int i = 0; i < k - 1; i++){
        tg1 = tg1 -> getNext();
    }
    tg -> setNext(tg1 -> getNext());
    tg1 -> setNext(tg);
    return tg1;
}