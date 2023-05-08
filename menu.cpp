#include "khach_hang_vip.cpp"
#include "nhan_vien.cpp"
#include "khach_hang_nor.cpp"

bool check_id(PS *ps)
{
    if (tach_id(ps->getID(), 0) == "KH")
        return true;
    return false;
}

int dem_ptu(Ds *ds)
{
    int x = 0;
    while (ds != NULL)
    {
        x++;
        ds = ds->getNext();
    }
    return x;
}

PS *Find(Ds *&ds, string a, int &x)
{
    Ds *tg = ds;
    x = 0;
    PS *ps;
    KH *kh;
    NV *nv;
    while (tg != NULL)
    {
        x++;
        ps = (PS *)tg->getData();
        if (check_id(ps))
        {
            kh = (KH *)tg->getData();
            if (kh->getID() == a)
                return ps;
        }
        else
        {
            nv = (NV *)tg->getData();
            if (nv->getID() == a)
                return ps;
        }
        tg = tg->getNext();
    }
    return NULL;
}

string tach_ten(string a, int k)
{
    string b;
    while (a[a.length() - 1] != ' ' and a.length() > 0)
    {
        b = a[a.length() - 1] + b;
        a.pop_back();
    }
    if (k == 1)
        return b;
    return a;
}

bool ktra_ten(string a, string b)
{
    if (tach_ten(a, 1) == tach_ten(b, 1))
    {
        if (tach_ten(a, 0) > tach_ten(b, 0))
            return true;
        else
            return false;
    }
    if (tach_ten(a, 1) > tach_ten(b, 1))
        return true;
    return false;
}

void xuat(Ds *&ds, int x, int k)
{
    PS *ps;
    KH *kh;

    string sdt;
    while (ds != NULL)
    {
        ps = (PS *)ds->getData();
        if (check_id(ps) and k == 1)
        {
            kh = (KH *)ds->getData();
            sdt = kh->getSdt();
            if (tach_sdt(sdt) and x == 1)
                cout << kh;
            if (!tach_sdt(sdt) and x == 2)
                cout << kh;
            if (x == 0)
                cout << kh;
        }
        else if (!check_id(ps) and k == 0)
            cout << (NV *)ds->getData();
        if (k == 2)
        {
            cout << (PS *)ds->getData();
        }
        ds = ds->getNext();
    }
}

void xuat_spham(KH *kh)
{
    Ds *sp;
    bool x = true;
    cout << '|' << setw(20) << kh->getHt();
    cout << '|' << setw(15) <<kh->getSdt();
    cout << kh->getNm();
    x = true;

    sp = kh->getDs_sp();
    if (sp == NULL)
    {
        line_page_sp();
    }

    while (sp != NULL)
    {
        if (x)
        {
            cout << (SP *)sp->getData();
            x = false;
        }
        else
        {
            line_page();
            cout << '|' << setfill('=') << setw(88) << '|' << setfill(' ') << endl;
            line_page();
            cout << (SP *)sp->getData();
        }
        sp = sp->getNext();
    }
    cout << '|' << setfill('=') << setw(139) << '|' << setfill(' ') << endl;
}

void xuat_dv1(KH *kh)
{
    Ds *dv;
    bool x = true;
    cout << '|' << setw(20) << kh->getHt();
    cout << '|' << setw(15) << kh->getSdt();
    cout << kh->getNm();
    x = true;
    dv = kh->getDs_dv();
    if (dv == NULL)
        line_page_dv();
    while (dv != NULL)
    {
        if (x)
        {
            cout << (DV *)dv->getData();
            x = false;
        }
        else
        {
            line_page();
            cout << '|' << setfill('=') << setw(41) << '|' << setfill(' ') << endl;
            line_page();
            cout << (DV *)dv->getData();
        }
        dv = dv->getNext();
    }
    cout << '|' << setfill('=') << setw(93) << '|' << setfill(' ') << endl;
}

void xuat_sp(Ds *&ds)
{
    KH *kh;
    PS *ps;
    Ds *sp;
    bool x = true;
    while (ds != NULL)
    {
        ps = (PS *)ds->getData();
        if (check_id(ps))
        {
            kh = (KH *)ds->getData();
            xuat_spham(kh);
            sp = kh->getDs_sp();
        }
        ds = ds->getNext();
    }
}

void xuat_dv(Ds *&ds)
{
    KH *kh;
    PS *ps;
    Ds *dv;
    bool x = true;
    while (ds != NULL)
    {
        ps = (PS *)ds->getData();
        if (check_id(ps))
        {
            kh = (KH *)ds->getData();
            xuat_dv1(kh);
        }
        ds = ds->getNext();
    }
}

void xuat_hd(Ds *&ds)
{
    KH *kh;
    Ds *tg;
    DV *dv;
    SP *sp;
    string id;
    long int t1 = 0, t2 = 0;
    int x;
    cout << "\n\tMa khach hang: ";
    getline(cin, id);
    kh = (KH *)Find(ds,"KH" + id, x);
    if (kh == NULL)
    {
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
        return;
    }

    else
    {
        if (tach_sdt(kh->getSdt()))
        {
            tg = kh->getDs_sp();
            while (tg != NULL)
            {
                sp = (SP *)tg->getData();
                t1 += 0.5 * sp->tong_tien();
                tg = tg->getNext();
            }

            tg = kh->getDs_dv();
            while (tg != NULL)
            {
                dv = (DV *)tg->getData();
                t2 += 0.3 * dv->getGdv();
                tg = tg->getNext();
            }
        }
        else
        {
            tg = kh->getDs_sp();
            while (tg != NULL)
            {
                sp = (SP *)tg->getData();
                t1 += sp->tong_tien();
                tg = tg->getNext();
            }

            tg = kh->getDs_dv();
            while (tg != NULL)
            {
                dv = (DV *)tg->getData();
                t2 += dv->getGdv();
                tg = tg->getNext();
            }
        }
    }
    td_hd();
    cout << '|' << setw(20) << kh->getHt();
    cout << '|' << setw(15) << kh->getID();
    cout << '|' << setw(15) << kh->getSdt();
    cout << '|' << setw(15) << t1;
    cout << '|' << setw(15) << t2;
    cout << '|' << setw(14) << kh->thanh_tien() << '|' << endl;
    cout << '|' << setfill('=') << setw(101) << '|' << setfill(' ') << endl;
}

void nhap(Ds *&ds)
{
    int x;
    bool c[3] = {true, true, true};
    while (1)
    {
        hoi_nv_kh();
        cin >> x;
        cin.ignore();

        if (x == 0 or (!c[0] and !c[1] and !c[2]))
            break;
        else if (x == 1)
        {
            if (c[0])
            {
                ds_nv(ds);
                c[0] = false;
            }
            else
                cout << "\nDa nhap danh sach truoc do!!!" << endl;
        }
        else if (x == 2)
        {
            nhap_kh();
            cin >> x;
            cin.ignore();
            if (x == 0 or (!c[1] and !c[2]))
                break;

            else if (x == 1)
            {
                if (c[1])
                {
                    ds_nor(ds);
                    c[1] = false;
                }
                else
                    cout << "\nDa nhap danh sach truoc do!!!" << endl;
            }

            else if (x == 2)
            {
                if (c[2])
                {
                    ds_vip(ds);
                    c[2] = false;
                }
                else
                    cout << "\nDa nhap danh sach truoc do!!!" << endl;
            }
        }
    }
}

void add_if(Ds *&ds)
{
    PS *ps;
    Ds *sp, *dv;
    KH *kh;
    int k, x;
    hoi_nv_kh();
    cin >> x;

    do
    {
        if (dem_ptu(ds) > 1)
            cout << "\n\tThem thong tin vao vi tri (1 - " << dem_ptu(ds) << "): ";
        else
        {
            k = 2;
            break;
        }
        cin >> k;
    } while (k > dem_ptu(ds));

    cin.ignore();
    if (x == 1)
    {
        ps = new NV;
        cout << "\n\tThong tin nhan vien can nhap" << endl;
        cin >> (NV *&)ps;
    }

    else if (x == 2)
    {
        nhap_kh();
        cin >> x;
        cin.ignore();
        if (x == 1)
        {
            kh = new NOR;
            cout << "\n\tThong tin khach hang can them" << endl;
            cin >> (NOR *&)kh;
        }
        else if (x == 2)
        {
            kh = new VIP;
            cout << "\n\tThong tin khach hang VIP can them" << endl;
            cin >> (VIP *&)kh;
        }
        else
            return;

        ds_sanpham(sp);
        ds_dvu(dv);
        kh->setDs_sp(sp);
        kh->setDs_dv(dv);
        ps = (PS *)kh;
    }
    else
        return;
    if (ds == NULL)
    {
        last_list(ds, ps);
    }
    ds = add_ds(ds, ps, k);
}

void add_pro(Ds *&ds)
{
    string id;
    int x;
    SP *sp;
    Ds *ds_sp_them;
    KH *kh;
    bool c = true;

    cout << "\n\tMa khach hang: ";
    getline(cin, id);

    kh = (KH *)Find(ds,"KH" + id, x);
    if (kh == NULL)
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
    else
    {
        ds_sp_them = kh->getDs_sp();
        do
        {
            sp = new SP;
            cout << "\n\tSan pham can them" << endl;
            cin >> (SP *&)sp;
            last_list(ds_sp_them, sp);
            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
        kh->setDs_sp(ds_sp_them);
    }
}

void add_ser(Ds *&ds)
{
    string id;
    int x;
    KH *kh;
    Ds *ds_dv_them;
    DV *dv;

    cout << "\n\tMa khach hang: ";
    getline(cin, id);

    kh = (KH *)Find(ds,"KH"+ id, x);
    if (kh == NULL)
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
    else
    {
        ds_dv_them = kh->getDs_dv();
        do
        {
            dv = new DV;
            cout << "\n\tDich vu can them" << endl;
            cin >> (DV *&)dv;
            last_list(ds_dv_them, dv);
            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
        kh->setDs_dv(ds_dv_them);
    }
}

void delete_if(Ds *&ds)
{
    string b;
    int x;
    KH *kh;
    NV *nv;
    hoi_nv_kh();
    cin >> x;
    cin.ignore();

    if (x == 1)
    {
        do
        {
            cout << "\n\tMa so ID cua nhan vien: ";
            getline(cin, b);
            nv = (NV *)Find(ds, "NV" + b, x);

            if (nv == NULL)
                cout << "\n\tKhong ton tai ma so ID nay!!!" << endl;
            else
                ds = delete_ds(ds, x);

            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
    }

    else if (x == 2)
    {
        do
        {
            cout << "\n\tMa khach hang can xoa: ";
            getline(cin, b);
            kh = (KH *)Find(ds,"KH"+ b, x);

            if (kh == NULL)
                cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
            else
                ds = delete_ds(ds, x);

            hoi_nhap();
            cin >> x;
            cin.ignore();
        } while (x == 1);
    }
    else
        return;
}

void delete_pro_ser(Ds *&ds)
{
    string b;
    int x;
    Ds *dv, *sp;
    KH *kh;

    cout << "\n\tMa khach hang can xoa san pham hoac dich vu: ";
    getline(cin, b);
    kh = (KH *)Find(ds,"KH"+ b, x);

    if (kh == NULL)
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
    else
    {
        dv = kh->getDs_dv();
        sp = kh->getDs_sp();
        hoi_spdv();
        cin >> x;

        if (x == 1)
        {
            if (sp == NULL)
            {
                cout << "\n\tChua co san pham nao!!!" << endl;
                return;
            }

            do
            {
                do
                {
                    if (dem_ptu(sp) > 1)
                        cout << "\n\tVi tri san pham can xoa (1 - " << dem_ptu(sp) << "): ";
                    else
                    {
                        x = 1;
                        break;
                    }
                    cin >> x;
                } while (x > dem_ptu(sp));

                sp = delete_ds(sp, x);
                kh->setDs_sp(sp);
                hoi_nhap();
                cin >> x;
            } while (x == 1);
        }

        else if (x == 2)
        {
            if (dv == NULL)
            {
                cout << "\n\tChua co dich vu nao!!!" << endl;
                return;
            }

            do
            {
                do
                {
                    if (dem_ptu(dv) > 1)
                        cout << "\n\tVi tri san pham can xoa (1 - " << dem_ptu(dv) << " ): ";
                    else
                    {
                        x = 1;
                        break;
                    }
                    cin >> x;
                } while (x > dem_ptu(dv));

                dv = delete_ds(dv, x);
                kh->setDs_dv(dv);
                hoi_nhap();
                cin >> x;
            } while (x == 1);
        }
        else
            return;
    }
}

void arr_nv(Ds *&ds)
{
    Ds *ds_nv;
    NV *nv, *nv1;
    PS *ps;
    init(ds_nv);

    while (ds != NULL)
    { // luu ra 1 ds moi
        ps = (PS *)ds->getData();
        if (!check_id(ps))
        {
            nv = (NV *)ds->getData();
            last_list(ds_nv, nv);
        }
        ds = ds->getNext();
    }

    if (ds_nv == NULL)
    {
        cout << "\n\tKhong co nhan vien nao trong danh sach!!!" << endl;
        return;
    }

    for (Ds *i = ds_nv; i != NULL; i = i->getNext())
    {
        for (Ds *j = i->getNext(); j != NULL; j = j->getNext())
        {
            nv = (NV *)i->getData();
            nv1 = (NV *)j->getData();
            if (ktra_ten(nv->getHt(), nv1->getHt()))
            {
                i->setData(nv1);
                j->setData(nv);
            }
        }
    }

    td_nv();
    while (ds_nv != NULL)
    {
        cout << (NV *)ds_nv->getData();
        ds_nv = ds_nv->getNext();
    }
}

void arr_kh(Ds *&ds)
{
    Ds *ds_kh;
    KH *kh, *kh1;
    PS *ps;
    init(ds_kh);

    while (ds != NULL)
    {
        ps = (PS *)ds->getData();
        if (check_id(ps))
        {
            kh = (KH *)ds->getData();
            last_list(ds_kh, kh);
        }
        ds = ds->getNext();
    }

    if (ds_kh == NULL)
    {
        cout << "\n\tKhong co khach hang nao trong danh sach!!!" << endl;
        return;
    }

    for (Ds *i = ds_kh; i != NULL; i = i->getNext())
    {
        for (Ds *j = i->getNext(); j != NULL; j = j->getNext())
        {
            kh = (KH *)i->getData();
            kh1 = (KH *)j->getData();
            if (ktra_ten(kh->getHt(), kh1->getHt()))
            {
                i->setData(kh1);
                j->setData(kh);
            }
        }
    }

    td_kh();
    while (ds_kh != NULL)
    {
        cout << (KH *)ds_kh->getData();
        ds_kh = ds_kh->getNext();
    }
}

void change_if(Ds *&ds)
{
    PS *ps;
    Ds *sp, *dv, *ds1 = ds;
    KH *kh;
    int x, y = 0;
    string a;

    hoi_nv_kh();
    cin >> x;
    cin.ignore();

    if (x == 1)
    {
        cout << "\n\tMa so ID nhan vien can sua: ";
        getline(cin, a);
        ps = Find(ds1, "NV" + a, x);

        if (ps == NULL)
        {
            cout << "\n\tKhong ton tai nhan vien co ma so ID da nhap!!!" << endl;
            return;
        }

        ps = new NV;
        cout << "\n\tThong tin sua lai cua nhan vien" << endl;
        cin >> (NV *&)ps;
    }

    else if (x == 2)
    {
        cout << "\n\tMa khach hang can sua: ";
        getline(cin, a);
        ps = Find(ds1, a, x);

        if (ps == NULL)
        {
            cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
            return;
        }

        kh = (KH *)ds->getData();
        if (!tach_sdt(kh->getSdt()))
        {
            kh = new KH;
            cout << "\n\tThong tin sua lai cua khach hang" << endl;
            cin >> (KH *&)kh;
        }

        else
        {
            kh = new VIP;
            cout << "\n\tThong tin sua lai cua khach hang VIP" << endl;
            cin >> (VIP *&)kh;
        }

        ds_sanpham(sp);
        ds_dvu(dv);
        kh->setDs_sp(sp);
        kh->setDs_dv(dv);
        ps = (PS *)kh;
    }

    while (ds1 != NULL)
    {
        if (x - 1 == y)
        {
            ds1->setData(ps);
            break;
        }
        y++;
        ds1 = ds1->getNext();
    }
}

void sua_sp_dv(Ds *&ds)
{
    Ds *sp, *dv;
    KH *kh;
    SP *sp1;
    DV *dv1;
    string id;
    int x, y = 0;

    cout << "\n\tMa khach hang can sua san pham hoac dich vu: ";
    getline(cin, id);
    kh = (KH *)Find(ds, id, x);

    if (kh == NULL)
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
    else
    {
        dv = kh->getDs_dv();
        sp = kh->getDs_sp();
        kh->setDs_sp(sp);
        kh->setDs_dv(dv);

        hoi_spdv();
        cin >> x;

        if (x == 1)
        {
            if (sp == NULL)
            {
                cout << "\n\tChua co san pham nao!!!" << endl;
                return;
            }

            do
            {
                if (dem_ptu(sp) > 1)
                    cout << "\n\tVi tri san pham can sua (1 - " << dem_ptu(sp) << " ): ";
                else
                {
                    x = 1;
                    break;
                }
                cin >> x;

            } while (x > dem_ptu(sp));

            cin.ignore();
            cout << "\n\tThong tin san pham can sua" << endl;
            sp1 = new SP;
            cin >> (SP *&)sp1;

            while (sp != NULL)
            {
                if (x - 1 == y)
                {
                    sp->setData(sp1);
                    break;
                }
                y++;
                sp = sp->getNext();
            }
        }

        else if (x == 2)
        {
            if (dv == NULL)
            {
                cout << "\n\tChua co dich vu nao!!!" << endl;
                return;
            }

            do
            {
                if (dem_ptu(sp) > 1)
                    cout << "\n\tVi tri dich vu can sua (1 - " << dem_ptu(dv) << " ): ";
                else
                {
                    x = 1;
                    break;
                }
                cin >> x;
            } while (x > dem_ptu(dv));

            cin.ignore();
            cout << "\n\tThong tin dich vu can sua" << endl;
            dv1 = new DV;
            cin >> (DV *&)dv1;

            while (dv != NULL)
            {
                if (x - 1 == y)
                {
                    dv->setData(dv1);
                    break;
                }
                y++;
                dv = dv->getNext();
            }
        }
        else
            return;
    }
}

void find_if(Ds *&ds)
{
    string a;
    PS *ps;
    int x;

    hoi_nv_kh();
    cin >> x;
    cin.ignore();

    if (x == 1)
    {
        cout << "\n\tSo ID nhan vien can tim kiem: ";
        getline(cin, a);
        ps = Find(ds, "NV" + a, x);

        if (ps == NULL)
        {
            cout << "\n\tKhong ton tai nhan vien co so ID da nhap!!!" << endl;
            return;
        }

        td_nv();
        cout << (NV *)ps;
    }

    else if (x == 2)
    {
        cout << "\n\tMa khach hang can tim kiem: ";
        getline(cin, a);
        ps = Find(ds, a, x);

        if (ps == NULL)
        {
            cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
            return;
        }

        td_kh();
        cout << (KH *)ps;
    }
    else
        return;
}

void tim_sp_dv(Ds *&ds)
{
    string a;
    KH *kh;
    Ds *sp, *dv;
    int x;

    cout << "\n\tMa khach hang can tim kiem: ";
    getline(cin, a);
    kh = (KH *)Find(ds, a, x);

    if (kh == NULL)
    {
        cout << "\n\tKhong ton tai ma khach hang nay!!!" << endl;
        return;
    }

    sp = kh->getDs_sp();
    dv = kh->getDs_dv();
    hoi_spdv();
    cin >> x;

    if (x == 1)
    {
        if (sp == NULL)
        {
            cout << "\n\tChua co san pham nao!!!" << endl;
            return;
        }

        td_sp();
        xuat_spham(kh);
    }
    else if (x == 2)
    {
        if (dv == NULL)
        {
            cout << "\n\tChua co dich vu nao!!!" << endl;
            return;
        }

        td_dv();
        xuat_dv1(kh);
    }
    else
        return;
}

void menu()
{
    int x;
    Ds *ds;
    init(ds);
    bool c = true;
    hoi_qlps_qlsp();
    cin >> x;
    if (x == 1)
    {
    nhaplai:
        menu_chon();
        cin >> x;
        cin.ignore();
        Ds *tg = ds;

        switch (x)
        {
        case 1:
            if (x == 1)
            {
                if (c)
                {
                    nhap(ds);
                    c = false;
                }
                else
                    cout << "\nDa nhap danh sach truoc do!!!" << endl;
            }
            goto nhaplai;
        case 2:
            td_kh();
            xuat(tg, 0, 1);
            goto nhaplai;
        case 3:
            td_nv();
            xuat(tg, 0, 0);
            goto nhaplai;
        case 4:
            td_kh();
            xuat(tg, 2, 1);
            goto nhaplai;
        case 5:
            td_kh();
            xuat(tg, 1, 1);
            goto nhaplai;
        case 6:
            td_sp();
            xuat_sp(tg);
            goto nhaplai;
        case 7:
            td_dv();
            xuat_dv(tg);
            goto nhaplai;
        case 8:
            xuat_hd(tg);
            goto nhaplai;
        case 9:
            add_if(ds);
            goto nhaplai;
        case 10:
            add_pro(ds);
            goto nhaplai;
        case 11:
            add_ser(ds);
            goto nhaplai;
        case 12:
            delete_if(ds);
            goto nhaplai;
        case 13:
            delete_pro_ser(ds);
            goto nhaplai;
        case 14:
            arr_nv(tg);
            goto nhaplai;
        case 15:
            arr_kh(tg);
            goto nhaplai;
        case 16:
            change_if(ds);
            goto nhaplai;
        case 17:
            sua_sp_dv(ds);
            goto nhaplai;
        case 18:
            find_if(ds);
            goto nhaplai;
        case 19:
            tim_sp_dv(ds);
            goto nhaplai;
        case 0:
            break;
        }
    }
    else if (x == 2)
        cout << "bai bai";
}