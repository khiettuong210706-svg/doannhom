#include "DonHang.h"

// --- CÁC HÀM XỬ LÝ ĐƠN HÀNG ---
string taoMaDonTuDong(const vector<DonHang>& dsDonHang) {
    if (dsDonHang.empty()) return "DH001";
    string maCuoi = dsDonHang.back().maDon; 
    string soThuTuStr = maCuoi.substr(2); 
    int soThuTu = stoi(soThuTuStr);
    soThuTu++;
    string maMoi = to_string(soThuTu);
    while (maMoi.length() < 3) maMoi = "0" + maMoi;
    return "DH" + maMoi;
}

void saveDonHang(const vector<DonHang>& dsDonHang) {
    ofstream outFile("donhang.txt");
    if (outFile.is_open()) {
        for (const auto& dh : dsDonHang) {
            outFile << dh.maDon << "|" << dh.maKhach << "|" 
                    << dh.ngayDat << "|" << dh.trangThai << "|" 
                    << (size_t)dh.tongTien << endl;
        }
        outFile.close();
        cout << "-> Đã lưu file donhang.txt!" << endl;
    }
}

void loadDonHang(vector<DonHang>& dsDonHang) {
    ifstream inFile("donhang.txt");
    if (!inFile.is_open()) return;
    dsDonHang.clear();
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        DonHang dh;
        string tongTienStr;
        getline(ss, dh.maDon, '|');
        getline(ss, dh.maKhach, '|');
        getline(ss, dh.ngayDat, '|');
        getline(ss, dh.trangThai, '|');
        getline(ss, tongTienStr, '|');
        if (!tongTienStr.empty()) dh.tongTien = stod(tongTienStr);
        dsDonHang.push_back(dh);
    }
    inFile.close();
}

void taoDonHangMoi(vector<DonHang>& dsDonHang, vector<ChiTietDonHang>& dsChiTiet) {
    DonHang dhMoi;
    dhMoi.maDon = taoMaDonTuDong(dsDonHang);
    cout << "\n--- TẠO ĐƠN HÀNG MỚI (" << dhMoi.maDon << ") ---" << endl;
    
    cout << "Nhập mã khách hàng: "; cin >> dhMoi.maKhach;
    cout << "Nhập ngày đặt (dd/mm/yyyy): "; cin >> dhMoi.ngayDat;
    dhMoi.trangThai = "Đã đặt";
    dhMoi.tongTien = 0;

    hienThiMenu(); // Gọi từ ChiTietDonHang.cpp

    char tiepTuc;
    do {
        ChiTietDonHang ct;
        ct.maDon = dhMoi.maDon;
        cout << "\nNhập MÃ muốn mua (VD: M01 hoặc CB01): "; cin >> ct.maMon;
        ct.donGia = layGiaMon(ct.maMon); 
        
        if (ct.donGia == 0) {
            cout << "-> Mã không tồn tại!" << endl;
            continue;
        }
        cout << "Nhập số lượng: "; cin >> ct.soLuong;
        
        dsChiTiet.push_back(ct);
        dhMoi.tongTien += (ct.soLuong * ct.donGia);
        cout << "-> Đã thêm: " << layTenMon(ct.maMon) << endl;

        cout << "Mua thêm? (y/n): "; cin >> tiepTuc;
    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    dsDonHang.push_back(dhMoi);
    cout << "\n-> TẠO ĐƠN THÀNH CÔNG! Tổng: " << (size_t)dhMoi.tongTien << " VND" << endl;
}

void capNhatTrangThai(vector<DonHang>& dsDonHang) {
    string maDonTim;
    cout << "\nNhập mã đơn hàng cần cập nhật: "; cin >> maDonTim;
    for (auto& dh : dsDonHang) {
        if (dh.maDon == maDonTim) {
            cout << "Trạng thái cũ: " << dh.trangThai << endl;
            cout << "1. Đang giao | 2. Hoàn thành: ";
            int chon; cin >> chon;
            if (chon == 1) dh.trangThai = "Đang giao";
            else if (chon == 2) dh.trangThai = "Hoàn thành";
            cout << "-> Đã cập nhật!" << endl;
            return;
        }
    }
    cout << "-> Không tìm thấy đơn!" << endl;
}

// --- HÀM MAIN (CHÍNH) ---
int main() {
    vector<DonHang> dsDonHang;
    vector<ChiTietDonHang> dsChiTiet;
    loadDonHang(dsDonHang);

    int choice;
    do {
        cout << "\n=== QUẢN LÝ ĐƠN HÀNG (BẢO NGUYỄN) ===" << endl;
        cout << "1. Tạo đơn hàng mới" << endl;
        cout << "2. Xem danh sách đơn hàng" << endl;
        cout << "3. Cập nhật trạng thái" << endl;
        cout << "4. Xem chi tiết đơn hàng" << endl;
        cout << "5. Lưu dữ liệu ra File" << endl;
        cout << "0. Thoát" << endl;
        cout << "Lựa chọn: "; cin >> choice;

        switch (choice) {
            case 1: taoDonHangMoi(dsDonHang, dsChiTiet); break;
            case 2:
                cout << left << setw(10) << "MÃ" << setw(15) << "KHÁCH" << setw(15) << "NGÀY" << setw(15) << "TT" << setw(15) << "TIỀN" << endl;
                for(const auto& dh : dsDonHang) 
                    cout << left << setw(10) << dh.maDon << setw(15) << dh.maKhach << setw(15) << dh.ngayDat << setw(15) << dh.trangThai << setw(15) << (size_t)dh.tongTien << endl;
                break;
            case 3: capNhatTrangThai(dsDonHang); break;
            case 4: {
                string md; cout << "Nhập mã đơn: "; cin >> md;
                xemChiTietDonHang(md, dsChiTiet);
                break;
            }
            case 5: saveDonHang(dsDonHang); saveChiTiet(dsChiTiet); break;
        }
    } while (choice != 0);

    return 0;
}