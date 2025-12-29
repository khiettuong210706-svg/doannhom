struct Date {
	int year{}, month{}, day{};
};

struct Time {
	Time() { hour = 0; minute = 0; second = 0; }
	int hour, minute, second;
};

enum WEEKDAY {
	MON, TUE, WED, THU, FRI, SAT
};

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
    string username;
    string password;
    string ten;
    string ngay_sinh;
    string chucvu;
	int luong;
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


