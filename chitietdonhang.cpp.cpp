#include "ChiTietDonHang.h"

// --- DỮ LIỆU MENU (94 Món + 100 Combo) ---
vector<MonAn> MENU_MON = {
    {"M01", "Phở bò", 20000}, {"M02", "Phở gà", 25000}, {"M03", "Bún bò Huế", 30000},
    {"M04", "Bún riêu", 35000}, {"M05", "Bún chả", 40000}, {"M06", "Cơm tấm", 45000},
    {"M07", "Cơm gà xối mỡ", 50000}, {"M08", "Cơm chiên hải sản", 55000}, {"M09", "Cơm sườn nướng", 60000},
    {"M10", "Hủ tiếu", 65000}, {"M11", "Mì Quảng", 70000}, {"M12", "Bánh canh", 75000},
    {"M13", "Bánh mì thịt", 80000}, {"M14", "Bánh mì xíu mại", 85000}, {"M15", "Bánh mì chả cá", 90000},
    {"M16", "Bánh cuốn", 95000}, {"M17", "Bánh xèo", 100000}, {"M18", "Bánh khọt", 105000},
    {"M19", "Bánh bèo", 110000}, {"M20", "Bánh bột lọc", 15000}, {"M21", "Gỏi cuốn", 20000},
    {"M22", "Nem rán", 25000}, {"M23", "Chả giò", 30000}, {"M24", "Cháo gà", 35000},
    {"M25", "Cháo lòng", 40000}, {"M26", "Cháo hải sản", 45000}, {"M27", "Lẩu thái", 50000},
    {"M28", "Lẩu hải sản", 55000}, {"M29", "Lẩu bò", 60000}, {"M30", "Lẩu gà lá é", 65000},
    {"M31", "Lẩu cá", 70000}, {"M32", "Bò kho", 75000}, {"M33", "Cà ri gà", 80000},
    {"M34", "Thịt kho trứng", 85000}, {"M35", "Cá kho tộ", 90000}, {"M36", "Gà nướng", 95000},
    {"M37", "Vịt quay", 100000}, {"M38", "Heo quay", 105000}, {"M39", "Sườn nướng", 110000},
    {"M40", "Bò lúc lắc", 15000}, {"M41", "Mực xào sa tế", 20000}, {"M42", "Tôm rang me", 25000},
    {"M43", "Cá chiên xù", 30000}, {"M44", "Trứng chiên", 35000}, {"M45", "Canh chua cá", 40000},
    {"M46", "Canh khổ qua", 45000}, {"M47", "Rau muống xào tỏi", 50000}, {"M48", "Đậu hũ sốt cà", 55000},
    {"M49", "Salad trộn", 60000}, {"M50", "Salad cá ngừ", 65000}, {"M51", "Pizza hải sản", 70000},
    {"M52", "Pizza bò", 75000}, {"M53", "Hamburger bò", 80000}, {"M54", "Hamburger gà", 85000},
    {"M55", "Khoai tây chiên", 90000}, {"M56", "Gà rán", 95000}, {"M57", "Cánh gà chiên nước mắm", 100000},
    {"M58", "Mì Ý sốt bò", 105000}, {"M59", "Mì Ý hải sản", 110000}, {"M60", "Sushi cá hồi", 15000},
    {"M61", "Sushi tổng hợp", 20000}, {"M62", "Sashimi cá hồi", 25000}, {"M63", "Cơm cuộn rong biển", 30000},
    {"M64", "Tokbokki", 35000}, {"M65", "Kimbap", 40000}, {"M66", "Mì ramen", 45000},
    {"M67", "Mì udon", 50000}, {"M68", "Mì lạnh Hàn Quốc", 55000}, {"M69", "Bánh pancake", 60000},
    {"M70", "Bánh waffle", 65000}, {"M71", "Bánh flan", 70000}, {"M72", "Bánh tiramisu", 75000},
    {"M73", "Bánh cheesecake", 80000}, {"M74", "Kem vani", 85000}, {"M75", "Kem socola", 90000},
    {"M76", "Kem dâu", 95000}, {"M77", "Trà sữa trân châu", 100000}, {"M78", "Trà đào", 105000},
    {"M79", "Trà chanh", 110000}, {"M80", "Cà phê đen", 15000}, {"M81", "Cà phê sữa", 20000},
    {"M82", "Cappuccino", 25000}, {"M83", "Latte", 30000}, {"M84", "Nước cam", 35000},
    {"M85", "Nước chanh", 40000}, {"M86", "Sinh tố bơ", 45000}, {"M87", "Sinh tố xoài", 50000},
    {"M88", "Sinh tố dâu", 55000}, {"M89", "Nước ép táo", 60000}, {"M90", "Nước ép cà rốt", 65000},
    {"M91", "Nước suối", 70000}, {"M92", "Nước ngọt có ga", 75000}, {"M93", "Sữa tươi", 80000},
    {"M94", "Sữa chua", 85000}
};

vector<MonAn> MENU_COMBO = {
    {"CB01", "Combo Ăn vặt 1", 80000}, {"CB02", "Combo Cơm gà 2", 160000},
    {"CB03", "Combo Cơm gà 3", 190000}, {"CB04", "Combo Trà sữa 4", 140000},
    {"CB05", "Combo Pizza 5", 170000}, {"CB06", "Combo Pizza 6", 150000},
    {"CB07", "Combo Bánh mì 7", 80000}, {"CB08", "Combo Chay 8", 80000},
    {"CB09", "Combo Cơm gà 9", 200000}, {"CB10", "Combo Trà sữa 10", 120000},
    {"CB11", "Combo Cơm gà 11", 50000}, {"CB12", "Combo Ăn vặt 12", 80000},
    {"CB13", "Combo Trà sữa 13", 150000}, {"CB14", "Combo Bánh mì 14", 90000},
    {"CB15", "Combo Ăn vặt 15", 90000}, {"CB16", "Combo Bánh mì 16", 70000},
    {"CB17", "Combo Cơm gà 17", 30000}, {"CB18", "Combo Ăn vặt 18", 190000},
    {"CB19", "Combo Burger 19", 170000}, {"CB20", "Combo Bánh mì 20", 100000},
    {"CB21", "Combo Gà rán 21", 150000}, {"CB22", "Combo Trà sữa 22", 50000},
    {"CB23", "Combo Pizza 23", 60000}, {"CB24", "Combo Trà sữa 24", 120000},
    {"CB25", "Combo Ăn vặt 25", 120000}, {"CB26", "Combo Bánh mì 26", 190000},
    {"CB27", "Combo Burger 27", 50000}, {"CB28", "Combo Bánh mì 28", 100000},
    {"CB29", "Combo Hải sản 29", 160000}, {"CB30", "Combo Mì Ý 30", 40000},
    {"CB31", "Combo Gà rán 31", 150000}, {"CB32", "Combo Hải sản 32", 170000},
    {"CB33", "Combo Bánh mì 33", 90000}, {"CB34", "Combo Pizza 34", 190000},
    {"CB35", "Combo Pizza 35", 60000}, {"CB36", "Combo Chay 36", 180000},
    {"CB37", "Combo Cơm gà 37", 60000}, {"CB38", "Combo Ăn vặt 38", 90000},
    {"CB39", "Combo Cơm gà 39", 80000}, {"CB40", "Combo Hải sản 40", 140000},
    {"CB41", "Combo Cơm gà 41", 120000}, {"CB42", "Combo Hải sản 42", 130000},
    {"CB43", "Combo Chay 43", 120000}, {"CB44", "Combo Mì Ý 44", 90000},
    {"CB45", "Combo Bánh mì 45", 110000}, {"CB46", "Combo Hải sản 46", 150000},
    {"CB47", "Combo Hải sản 47", 150000}, {"CB48", "Combo Mì Ý 48", 130000},
    {"CB49", "Combo Cơm gà 49", 80000}, {"CB50", "Combo Mì Ý 50", 30000},
    {"CB51", "Combo Ăn vặt 51", 110000}, {"CB52", "Combo Cơm gà 52", 40000},
    {"CB53", "Combo Mì Ý 53", 120000}, {"CB54", "Combo Hải sản 54", 150000},
    {"CB55", "Combo Trà sữa 55", 70000}, {"CB56", "Combo Cơm gà 56", 170000},
    {"CB57", "Combo Cơm gà 57", 100000}, {"CB58", "Combo Chay 58", 200000},
    {"CB59", "Combo Bánh mì 59", 40000}, {"CB60", "Combo Mì Ý 60", 130000},
    {"CB61", "Combo Burger 61", 40000}, {"CB62", "Combo Mì Ý 62", 60000},
    {"CB63", "Combo Bánh mì 63", 50000}, {"CB64", "Combo Hải sản 64", 170000},
    {"CB65", "Combo Cơm gà 65", 130000}, {"CB66", "Combo Gà rán 66", 110000},
    {"CB67", "Combo Bánh mì 67", 190000}, {"CB68", "Combo Burger 68", 170000},
    {"CB69", "Combo Gà rán 69", 40000}, {"CB70", "Combo Bánh mì 70", 140000},
    {"CB71", "Combo Pizza 71", 80000}, {"CB72", "Combo Pizza 72", 60000},
    {"CB73", "Combo Chay 73", 110000}, {"CB74", "Combo Trà sữa 74", 80000},
    {"CB75", "Combo Ăn vặt 75", 70000}, {"CB76", "Combo Burger 76", 180000},
    {"CB77", "Combo Pizza 77", 90000}, {"CB78", "Combo Ăn vặt 78", 80000},
    {"CB79", "Combo Burger 79", 70000}, {"CB80", "Combo Chay 80", 120000},
    {"CB81", "Combo Mì Ý 81", 180000}, {"CB82", "Combo Ăn vặt 82", 50000},
    {"CB83", "Combo Cơm gà 83", 50000}, {"CB84", "Combo Trà sữa 84", 140000},
    {"CB85", "Combo Bánh mì 85", 180000}, {"CB86", "Combo Mì Ý 86", 50000},
    {"CB87", "Combo Mì Ý 87", 140000}, {"CB88", "Combo Mì Ý 88", 70000},
    {"CB89", "Combo Burger 89", 130000}, {"CB90", "Combo Trà sữa 90", 30000},
    {"CB91", "Combo Cơm gà 91", 150000}, {"CB92", "Combo Chay 92", 110000},
    {"CB93", "Combo Cơm gà 93", 180000}, {"CB94", "Combo Pizza 94", 150000},
    {"CB95", "Combo Hải sản 95", 100000}, {"CB96", "Combo Ăn vặt 96", 70000},
    {"CB97", "Combo Mì Ý 97", 190000}, {"CB98", "Combo Ăn vặt 98", 110000},
    {"CB99", "Combo Chay 99", 130000}, {"CB100", "Combo Cơm gà 100", 160000}
};

string layTenMon(string id) {
    for (const auto& m : MENU_MON) if (m.id == id) return m.ten;
    for (const auto& m : MENU_COMBO) if (m.id == id) return m.ten;
    return "Không xác định";
}

double layGiaMon(string id) {
    for (const auto& m : MENU_MON) if (m.id == id) return m.gia;
    for (const auto& m : MENU_COMBO) if (m.id == id) return m.gia;
    return 0;
}

void inDanhSach(const vector<MonAn>& list) {
    for (size_t i = 0; i < list.size(); i += 2) {
        cout << left << setw(😎 << list[i].id << setw(30) << list[i].ten << setw(15) << (size_t)list[i].gia;
        if (i + 1 < list.size()) {
            cout << left << setw(😎 << list[i+1].id << setw(30) << list[i+1].ten << setw(15) << (size_t)list[i+1].gia;
        }
        cout << endl;
    }
}

void hienThiMenu() {
    cout << "\n================= THỰC ĐƠN NHÀ HÀNG =================" << endl;
    cout << left << setw(😎 << "MÃ" << setw(30) << "TÊN MÓN" << setw(15) << "GIÁ" 
         << setw(😎 << "MÃ" << setw(30) << "TÊN MÓN" << setw(15) << "GIÁ" << endl;
    cout << "-------------------- MÓN LẺ --------------------" << endl;
    inDanhSach(MENU_MON);
    cout << "\n-------------------- COMBO ---------------------" << endl;
    inDanhSach(MENU_COMBO);
    cout << "=====================================================" << endl;
}

void saveChiTiet(const vector<ChiTietDonHang>& dsChiTiet) {
    ofstream outFile("chitietdon.txt");
    if (outFile.is_open()) {
        for (const auto& ct : dsChiTiet) {
            outFile << ct.maDon << "|" << ct.maMon << "|" 
                    << ct.soLuong << "|" << (size_t)ct.donGia << endl;
        }
        outFile.close();
        cout << "-> Đã lưu file chitietdon.txt!" << endl;
    }
}

void xemChiTietDonHang(string maDonInput, const vector<ChiTietDonHang>& dsChiTiet) {
    cout << "\n--- CHI TIẾT ĐƠN: " << maDonInput << " ---" << endl;
    cout << left << setw(10) << "MÃ MÓN" << setw(30) << "TÊN MÓN" 
         << setw(10) << "SL" << setw(15) << "THÀNH TIỀN" << endl;
    double tong = 0;
    for (const auto& ct : dsChiTiet) {
        if (ct.maDon == maDonInput) {
            double tt = ct.soLuong * ct.donGia;
            tong += tt;
            cout << left << setw(10) << ct.maMon << setw(30) << layTenMon(ct.maMon) 
                 << setw(10) << ct.soLuong << setw(15) << (size_t)tt << endl;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "TỔNG CỘNG: " << (size_t)tong << " VND" << endl;
}
