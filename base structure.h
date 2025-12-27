struct MonAn {
    string id;
    string ten;
    double gia;
};

void themMonAn();
void hienThiMonAn();
void suaMonAn();
void xoaMonAn();

void loadMonAnFromFile();
void saveMonAnToFile();

bool tonTaiMonAnID(const string& id);

struct KhachHang {
    string id;
    string ten;
    string sdt;
};

void themKhachHang();
void hienThiKhachHang();
void suaKhachHang();
void xoaKhachHang();

void loadKhachHangFromFile();
void saveKhachHangToFile();

bool tonTaiKhachHangID(const string& id);
bool hopLeSDT(const string& sdt);
struct NhanVien {
    string id;
    string ten;
    string chucvu;
    double luong;
};

void themNhanVien();
void hienThiNhanVien();
void suaNhanVien();
void xoaNhanVien();

void loadNhanVienFromFile();
void saveNhanVienToFile();

bool tonTaiNhanVienID(const string& id);
bool hopLeLuong(double luong);
struct Combo {
    string id;
    string ten;
    double gia;
};

void themCombo();
void hienThiCombo();
void suaCombo();
void xoaCombo();

void loadComboFromFile();
void saveComboToFile();


bool tonTaiComboID(const string& id);
