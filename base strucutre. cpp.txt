vector<MonAn> dsMonAn;

bool tonTaiMonAnID(const string& id) {
    for (auto &m : dsMonAn)
        if (m.id == id) return true;
    return false;
}

void loadMonAnFromFile() {
    dsMonAn.clear();
    ifstream fin("MonAn.txt");
    MonAn m;
    while (fin >> m.id) {
        fin.ignore();
        getline(fin, m.ten);
        fin >> m.gia;
        dsMonAn.push_back(m);
    }
    fin.close();
}

void saveMonAnToFile() {
    ofstream fout("MonAn.txt");
    for (auto &m : dsMonAn) {
        fout << m.id << '\n' << m.ten << '\n' << m.gia << '\n';
    }
    fout.close();
}

void themMonAn() {
    MonAn m;
    cout << "ID: "; cin >> m.id;
    if (tonTaiMonAnID(m.id)) {
        cout << "ID da ton tai!\n";
        return;
    }
    cin.ignore();
    cout << "Ten: "; getline(cin, m.ten);
    cout << "Gia: "; cin >> m.gia;
    dsMonAn.push_back(m);
    saveMonAnToFile();
}

void hienThiMonAn() {
    for (auto &m : dsMonAn)
        cout << m.id << " | " << m.ten << " | " << m.gia << endl;
}

void suaMonAn() {
    string id;
    cout << "Nhap ID can sua: "; cin >> id;
    for (auto &m : dsMonAn) {
        if (m.id == id) {
            cin.ignore();
            cout << "Ten moi: "; getline(cin, m.ten);
            cout << "Gia moi: "; cin >> m.gia;
            saveMonAnToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void xoaMonAn() {
    string id;
    cout << "Nhap ID can xoa: "; cin >> id;
    for (int i = 0; i < dsMonAn.size(); i++) {
        if (dsMonAn[i].id == id) {
            dsMonAn.erase(dsMonAn.begin() + i);
            saveMonAnToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}
vector<KhachHang> dsKH;

bool tonTaiKhachHangID(const string& id) {
    for (auto &k : dsKH)
        if (k.id == id) return true;
    return false;
}

bool hopLeSDT(const string& sdt) {
    if (sdt.length() != 10) return false;
    for (char c : sdt)
        if (!isdigit(c)) return false;
    return true;
}

void loadKhachHangFromFile() {
    dsKH.clear();
    ifstream fin("KhachHang.txt");
    KhachHang k;
    while (fin >> k.id) {
        fin.ignore();
        getline(fin, k.ten);
        fin >> k.sdt;
        dsKH.push_back(k);
    }
    fin.close();
}

void saveKhachHangToFile() {
    ofstream fout("KhachHang.txt");
    for (auto &k : dsKH) {
        fout << k.id << '\n' << k.ten << '\n' << k.sdt << '\n';
    }
    fout.close();
}

void themKhachHang() {
    KhachHang k;
    cout << "ID: "; cin >> k.id;
    if (tonTaiKhachHangID(k.id)) {
        cout << "ID da ton tai!\n";
        return;
    }
    cin.ignore();
    cout << "Ten: "; getline(cin, k.ten);
    do {
        cout << "SDT (10 so): "; cin >> k.sdt;
        if (!hopLeSDT(k.sdt)) cout << "SDT khong hop le!\n";
    } while (!hopLeSDT(k.sdt));

    dsKH.push_back(k);
    saveKhachHangToFile();
}

void hienThiKhachHang() {
    for (auto &k : dsKH)
        cout << k.id << " | " << k.ten << " | " << k.sdt << endl;
}

void suaKhachHang() {
    string id;
    cout << "Nhap ID: "; cin >> id;
    for (auto &k : dsKH) {
        if (k.id == id) {
            cin.ignore();
            cout << "Ten moi: "; getline(cin, k.ten);
            do {
                cout << "SDT moi: "; cin >> k.sdt;
            } while (!hopLeSDT(k.sdt));
            saveKhachHangToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void xoaKhachHang() {
    string id;
    cout << "Nhap ID: "; cin >> id;
    for (int i = 0; i < dsKH.size(); i++) {
        if (dsKH[i].id == id) {
            dsKH.erase(dsKH.begin() + i);
            saveKhachHangToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}
vector<NhanVien> dsNV;

bool tonTaiNhanVienID(const string& id) {
    for (auto &n : dsNV)
        if (n.id == id) return true;
    return false;
}

bool hopLeLuong(double luong) {
    return luong >= 1000000; // ví dụ: >= 1 triệu
}

void loadNhanVienFromFile() {
    dsNV.clear();
    ifstream fin("NhanVien.txt");
    NhanVien n;
    while (fin >> n.id) {
        fin.ignore();
        getline(fin, n.ten);
        fin >> n.luong;
        dsNV.push_back(n);
    }
    fin.close();
}

void saveNhanVienToFile() {
    ofstream fout("NhanVien.txt");
    for (auto &n : dsNV) {
        fout << n.id << '\n' << n.ten << '\n' << n.luong << '\n';
    }
    fout.close();
}

void themNhanVien() {
    NhanVien n;
    cout << "ID: "; cin >> n.id;
    if (tonTaiNhanVienID(n.id)) {
        cout << "ID da ton tai!\n";
        return;
    }
    cin.ignore();
    cout << "Ten: "; getline(cin, n.ten);
    do {
        cout << "Luong: "; cin >> n.luong;
        if (!hopLeLuong(n.luong)) cout << "Luong khong hop le!\n";
    } while (!hopLeLuong(n.luong));

    dsNV.push_back(n);
    saveNhanVienToFile();
}

void hienThiNhanVien() {
    for (auto &n : dsNV)
        cout << n.id << " | " << n.ten << " | " << n.luong << endl;
}

void suaNhanVien() {
    string id;
    cout << "Nhap ID: "; cin >> id;
    for (auto &n : dsNV) {
        if (n.id == id) {
            cin.ignore();
            cout << "Ten moi: "; getline(cin, n.ten);
            do {
                cout << "Luong moi: "; cin >> n.luong;
            } while (!hopLeLuong(n.luong));
            saveNhanVienToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void xoaNhanVien() {
    string id;
    cout << "Nhap ID: "; cin >> id;
    for (int i = 0; i < dsNV.size(); i++) {
        if (dsNV[i].id == id) {
            dsNV.erase(dsNV.begin() + i);
            saveNhanVienToFile();
            return;
        }
    }
    cout << "Khong tim thay!\n";
}
vector<Combo> dsCombo;

bool tonTaiComboID(const string& id) {
    for (auto &c : dsCombo)
        if (c.id == id) return true;
    return false;
}

void loadComboFromFile() {
    dsCombo.clear();
    ifstream fin("Combo.txt");
    Combo c;
    while (fin >> c.id) {
        fin.ignore();
        getline(fin, c.ten);
        fin >> c.gia;
        dsCombo.push_back(c);
    }
    fin.close();
}

void saveComboToFile() {
    ofstream fout("Combo.txt");
    for (auto &c : dsCombo) {
        fout << c.id << '\n'
             << c.ten << '\n'
             << c.gia << '\n';
    }
    fout.close();
}

void themCombo() {
    Combo c;
    cout << "ID: ";
    cin >> c.id;
    if (tonTaiComboID(c.id)) {
        cout << "ID da ton tai!\n";
        return;
    }
    cin.ignore();
    cout << "Ten: ";
    getline(cin, c.ten);
    cout << "Gia: ";
    cin >> c.gia;

    dsCombo.push_back(c);
    saveComboToFile();
}

void hienThiCombo() {
    cout << "\nDanh sach combo:\n";
    for (auto &c : dsCombo) {
        cout << c.id << " | " << c.ten << " | " << c.gia << endl;
    }
}

void suaCombo() {
    string id;
    cout << "Nhap ID combo can sua: ";
    cin >> id;
    for (auto &c : dsCombo) {
        if (c.id == id) {
            cin.ignore();
            cout << "Ten moi: ";
            getline(cin, c.ten);
            cout << "Gia moi: ";
            cin >> c.gia;
            saveComboToFile();
            return;
        }
    }
    cout << "Khong tim thay combo!\n";
}

void xoaCombo() {
    string id;
    cout << "Nhap ID combo can xoa: ";
    cin >> id;
    for (int i = 0; i < (int)dsCombo.size(); i++) {
        if (dsCombo[i].id == id) {
            dsCombo.erase(dsCombo.begin() + i);
            saveComboToFile();
            return;
        }
    }
    cout << "Khong tim thay combo!\n";
}