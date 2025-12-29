#ifndef DONHANG_H
#define DONHANG_H

#include "Shared.h"
#include "ChiTietDonHang.h" // Để gọi hàm hienThiMenu()

// Khai báo hàm
string taoMaDonTuDong(const vector<DonHang>& dsDonHang);
void saveDonHang(const vector<DonHang>& dsDonHang);
void loadDonHang(vector<DonHang>& dsDonHang);
void taoDonHangMoi(vector<DonHang>& dsDonHang, vector<ChiTietDonHang>& dsChiTiet);
void capNhatTrangThai(vector<DonHang>& dsDonHang);

#endif