#include "person.cpp"

void menu_chon()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(29) << "MENU" << setw(26) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(48) << "\t1. Nhap danh sach khach hang va nhan vien" << '|' << endl;
    cout << '|' << setw(48) << "\t2. Xuat danh sach khach hang da nhap" << '|' << endl;
    cout << '|' << setw(48) << "\t3. Xuat danh sach nhan vien da nhap" << '|' << endl;
    cout << '|' << setw(48) << "\t4. Xuat danh sach khach hang thuong " << '|' << endl;
    cout << '|' << setw(48) << "\t5. Xuat danh sach khach hang VIP" << '|' << endl;
    cout << '|' << setw(48) << "\t6. Xuat danh sach san pham cua moi khach hang" << '|' << endl;
    cout << '|' << setw(48) << "\t7. Xuat danh sach dich vu khach hang su dung" << '|' << endl;
    cout << '|' << setw(48) << "\t8. Xuat hoa don thanh toan" << '|' << endl;
    cout << '|' << setw(48) << "\t9. Them khach hang hoac nhan vien" << '|' << endl;
    cout << '|' << setw(48) << "\t10. Them san pham cua khach hang" << '|' << endl;
    cout << '|' << setw(48) << "\t11. Them dich vu cua khach hang" << '|' << endl;
    cout << '|' << setw(48) << "\t12. Xoa khach hang hoac sa thai nhan vien" << '|' << endl;
    cout << '|' << setw(48) << "\t13. Xoa san pham hoac dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t14. Sap xep danh sach nhan vien" << '|' << endl;
    cout << '|' << setw(48) << "\t15. Sap xep danh sach khach hang" << '|' << endl;
    cout << '|' << setw(48) << "\t16. Sua thong tin khach hang hoac nhan vien" << '|' << endl;
    cout << '|' << setw(48) << "\t17. Sua thong tin san pham va dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t18. Tim kiem nhan vien hoac khach hang" << '|' << endl;
    cout << '|' << setw(48) << "\t19. Tim kiem san pham hoac dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t0. Thoat" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(55) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void du_lieu()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(39) << "\t\tDU LIEU:" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Lay tu file cho san" << '|' << endl;
    cout << '|' << setw(46) << "\t2.Nhap tu ban phim" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_nv_kh()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1. Nhan vien" << '|' << endl;
    cout << '|' << setw(25) << "\t2. Khach hang" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void nhap_kh()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1.Khach hang thuong" << '|' << endl;
    cout << '|' << setw(25) << "\t2.Khach hang VIP" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_nhap()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(22) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(15) << "\t1.Nhap tiep" << '|' << endl;
    cout << '|' << setw(15) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(22) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_san_pham()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t\tKhach hang co mua them san pham khong ?" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Co, tien hanh nhap" << '|' << endl;
    cout << '|' << setw(46) << "\t0.Khong" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_dvu()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t\tKhach hang co dung them dich vu khong" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Co, tien hanh nhap" << '|' << endl;
    cout << '|' << setw(46) << "\t0.Khong" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_spdv()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1. San pham" << '|' << endl;
    cout << '|' << setw(25) << "\t2. Dich vu" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void td_person()
{
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(13) << "Nam sinh";
    cout << '|' << setw(15) << "Ma";
    cout << '|' << setw(15) << "So dien thoai";
    cout << '|' << setw(10) << "Gioi tinh";
    cout << '|' << setw(20) << "Dia chi";
}

void td_nv()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(140) << '|' << setfill(' ') << endl;
    td_person();
    cout << '|' << setw(25) << "Chuc vu";
    cout << '|' << setw(15) << "Luong co ban|" << endl;
    cout << '|' << setfill('=') << setw(140) << '|' << setfill(' ') << endl;
}

void td_kh()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(134) << '|' << setfill(' ') << endl;
    td_person();
    cout << '|' << setw(13) << "Ngay mua" << setw(7);
    cout << '|' << setw(10) << "Loai VIP" << setw(5) << '|' << endl;
    cout << '|' << setfill('=') << setw(134) << '|' << setfill(' ') << endl;
}

void td_sp()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(139) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma khach hang";
    cout << '|' << setw(13) << "Ngay mua";
    cout << '|' << setw(25) << "Ten san pham";
    cout << '|' << setw(20) << "Ma san pham";
    cout << '|' << setw(10) << "So luong";
    cout << '|' << setw(15) << "Gia thanh";
    cout << '|' << setw(14) << "Tong tien|" << endl;
    cout << '|' << setfill('=') << setw(139) << '|' << setfill(' ') << endl;
}

void td_dv()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(93) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma khach hang";
    cout << '|' << setw(13) << "Ngay mua";
    cout << '|' << setw(25) << "Ten dich vu";
    cout << '|' << setw(15) << "Gia dich vu" << '|' << endl;
    cout << '|' << setfill('=') << setw(93) << '|' << setfill(' ') << endl;
}

void line_page()
{
    cout << '|' << setw(20) << ' ';
    cout << '|' << setw(15) << ' ';
    cout << '|' << setw(13) << ' ';
}

void line_page_sp()
{
    cout << '|' << setw(25) << ' ';
    cout << '|' << setw(20) << ' ';
    cout << '|' << setw(10) << ' ';
    cout << '|' << setw(15) << ' ';
    cout << '|' << setw(14) << " |" << endl;
}

void line_page_dv()
{
    cout << '|' << setw(25) << ' ';
    cout << '|' << setw(16) << " |" << endl;
}

void td_hd()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(101) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma khach hang";
    cout << '|' << setw(15) << "So dien thoai";
    cout << '|' << setw(15) << "Tien san pham";
    cout << '|' << setw(15) << "Tien dich vu";
    cout << '|' << setw(16) << "Tong tien|" << endl;
    cout << '|' << setfill('=') << setw(101) << '|' << setfill(' ') << endl;
}

void hoi_qlps_qlsp()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1. Quan ly Nguoi" << '|' << endl;
    cout << '|' << setw(25) << "\t2. Quan ly san pham" << '|' << endl;
    cout << '|' << setfill('=') << setw(32) << right << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void menu_chon2()
{
    cout << endl;
    cout << '|' << setfill('=') << setw(29) << "MENU" << setw(26) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(48) << "\t1. Nhap danh sach san pham" << '|' << endl;
    cout << '|' << setw(48) << "\t2. Xuat danh sach san pham" << '|' << endl;
    cout << '|' << setw(48) << "\t3. Them san pham vao cua hang" << '|' << endl;
    cout << '|' << setw(48) << "\t4. Xoa san pham khoi cua hang" << '|' << endl;
    cout << '|' << setw(48) << "\t5. Tim kiem san pham " << '|' << endl;
    cout << '|' << setw(48) << "\t6. Sap xep san pham " << '|' << endl;
    cout << '|' << setw(48) << "\t7. Sua thong tin san pham" << '|' << endl;
    cout << '|' << setw(48) << "\t0. Thoat" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(55) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}