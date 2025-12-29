#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct MonAn {
    string id;
    string ten;
    double gia;
};

struct ChiTietDonHang {
    string maDon;
    string maMon;
    int soLuong;
    double donGia;
};

struct DonHang {
    string maDon;
    string maKhach;
    string ngayDat;
    string trangThai;
    double tongTien;
};

#endif