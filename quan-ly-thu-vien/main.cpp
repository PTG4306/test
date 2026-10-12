#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

// Chuan hoa chuoi, loai bo khoang trang o dau va cuoi.
string xoaKhoangTrang(const string& s) {
    const size_t dau = s.find_first_not_of(" \t\r\n");
    if (dau == string::npos) return "";
    const size_t cuoi = s.find_last_not_of(" \t\r\n");
    return s.substr(dau, cuoi - dau + 1);
}

string nhapChuoi(const string& thongBao) {
    string giaTri;
    do {
        cout << thongBao;
        if (!getline(cin, giaTri)) return "";
        giaTri = xoaKhoangTrang(giaTri);
        if (giaTri.empty()) cout << "Khong duoc de trong. Vui long nhap lai!\n";
    } while (giaTri.empty());
    return giaTri;
}

// Doc nguyen mot dong de xu ly ca truong hop nhap chu thay vi so.
int nhapSoNguyen(const string& thongBao, int nhoNhat, int lonNhat = INT_MAX) {
    while (true) {
        string dong;
        cout << thongBao;
        if (!getline(cin, dong)) return nhoNhat;
        istringstream iss(dong);
        long long giaTri;
        char kyTuThua;
        if ((iss >> giaTri) && !(iss >> kyTuThua) &&
            giaTri >= nhoNhat && giaTri <= lonNhat) {
            return static_cast<int>(giaTri);
        }
        cout << "Du lieu khong hop le! Nhap so tu " << nhoNhat
             << " den " << lonNhat << ".\n";
    }
}

string chuanHoaMa(string ma) {
    for (size_t i = 0; i < ma.size(); ++i) {
        ma[i] = static_cast<char>(toupper(static_cast<unsigned char>(ma[i])));
    }
    return ma;
}

bool namNhuan(int nam) {
    return nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0);
}

int soNgayTrongThang(int thang, int nam) {
    const int soNgay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && namNhuan(nam)) return 29;
    return soNgay[thang];
}

struct Ngay {
    int ngay, thang, nam;
};

Ngay nhapNgay() {
    Ngay ngayPhatHanh;
    ngayPhatHanh.nam = nhapSoNguyen("Nam phat hanh: ", 1, 9999);
    ngayPhatHanh.thang = nhapSoNguyen("Thang phat hanh (1-12): ", 1, 12);
    ngayPhatHanh.ngay = nhapSoNguyen("Ngay phat hanh: ", 1,
        soNgayTrongThang(ngayPhatHanh.thang, ngayPhatHanh.nam));
    return ngayPhatHanh;
}

// LOP CO SO
class TaiLieu {
private:
    string maTaiLieu;
    string nhaXuatBan;
    int soBanPhatHanh;

public:
    TaiLieu(const string& ma, const string& nxb, int soBan)
        : maTaiLieu(ma), nhaXuatBan(nxb), soBanPhatHanh(soBan) {}

    virtual ~TaiLieu() {}

    string getMaTaiLieu() const { return maTaiLieu; }
    virtual int getLoai() const = 0; // 1: Sach, 2: Tap chi, 3: Bao.
    virtual void hienThi() const = 0;

protected:
    void hienThiChung() const {
        cout << "  Ma tai lieu      : " << maTaiLieu << '\n';
        cout << "  Nha xuat ban     : " << nhaXuatBan << '\n';
        cout << "  So ban phat hanh : " << soBanPhatHanh << '\n';
    }
};

class Sach : public TaiLieu {
private:
    string tenTacGia;
    int soTrang;

public:
    Sach(const string& ma, const string& nxb, int soBan,
         const string& tacGia, int trang)
        : TaiLieu(ma, nxb, soBan), tenTacGia(tacGia), soTrang(trang) {}

    int getLoai() const override { return 1; }
    void hienThi() const override {
        cout << "[SACH]\n";
        hienThiChung();
        cout << "  Ten tac gia      : " << tenTacGia << '\n';
        cout << "  So trang         : " << soTrang << '\n';
    }
};

class TapChi : public TaiLieu {
private:
    int soPhatHanh;
    int thangPhatHanh;

public:
    TapChi(const string& ma, const string& nxb, int soBan,
           int soPhatHanh, int thang)
        : TaiLieu(ma, nxb, soBan), soPhatHanh(soPhatHanh),
          thangPhatHanh(thang) {}

    int getLoai() const override { return 2; }
    void hienThi() const override {
        cout << "[TAP CHI]\n";
        hienThiChung();
        cout << "  So phat hanh     : " << soPhatHanh << '\n';
        cout << "  Thang phat hanh  : " << thangPhatHanh << '\n';
    }
};

class Bao : public TaiLieu {
private:
    Ngay ngayPhatHanh;

public:
    Bao(const string& ma, const string& nxb, int soBan, Ngay ngay)
        : TaiLieu(ma, nxb, soBan), ngayPhatHanh(ngay) {}

    int getLoai() const override { return 3; }
    void hienThi() const override {
        cout << "[BAO]\n";
        hienThiChung();
        cout << "  Ngay phat hanh   : " << ngayPhatHanh.ngay << '/'
             << ngayPhatHanh.thang << '/' << ngayPhatHanh.nam << '\n';
    }
};

// Quan ly tap trung cac tai lieu; unique_ptr tu giai phong bo nho.
class QuanLyThuVien {
private:
    vector<unique_ptr<TaiLieu> > danhSach;

    bool daTonTaiMa(const string& ma) const {
        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (danhSach[i]->getMaTaiLieu() == ma) return true;
        }
        return false;
    }

public:
    void themTaiLieu() {
        cout << "\n--- THEM TAI LIEU ---\n";
        cout << "1. Sach\n2. Tap chi\n3. Bao\n";
        int loai = nhapSoNguyen("Chon loai (1-3): ", 1, 3);

        string ma;
        do {
            ma = chuanHoaMa(nhapChuoi("Ma tai lieu: "));
            if (daTonTaiMa(ma)) {
                cout << "Ma tai lieu da ton tai. Vui long chon ma khac!\n";
            }
        } while (daTonTaiMa(ma));

        string nxb = nhapChuoi("Ten nha xuat ban: ");
        int soBan = nhapSoNguyen("So ban phat hanh: ", 1);

        if (loai == 1) {
            string tacGia = nhapChuoi("Ten tac gia: ");
            int soTrang = nhapSoNguyen("So trang: ", 1);
            danhSach.push_back(unique_ptr<TaiLieu>(
                new Sach(ma, nxb, soBan, tacGia, soTrang)));
        } else if (loai == 2) {
            int soPhatHanh = nhapSoNguyen("So phat hanh: ", 1);
            int thang = nhapSoNguyen("Thang phat hanh (1-12): ", 1, 12);
            danhSach.push_back(unique_ptr<TaiLieu>(
                new TapChi(ma, nxb, soBan, soPhatHanh, thang)));
        } else {
            Ngay ngay = nhapNgay();
            danhSach.push_back(unique_ptr<TaiLieu>(
                new Bao(ma, nxb, soBan, ngay)));
        }
        cout << "Them tai lieu thanh cong!\n";
    }

    void xoaTheoMa() {
        cout << "\n--- XOA TAI LIEU ---\n";
        string ma = chuanHoaMa(nhapChuoi("Nhap ma can xoa: "));
        for (vector<unique_ptr<TaiLieu> >::iterator it = danhSach.begin();
             it != danhSach.end(); ++it) {
            if ((*it)->getMaTaiLieu() == ma) {
                danhSach.erase(it);
                cout << "Da xoa tai lieu co ma " << ma << ".\n";
                return;
            }
        }
        cout << "Khong tim thay tai lieu co ma " << ma << ".\n";
    }

    void hienThiTatCa() const {
        cout << "\n--- DANH SACH TAI LIEU ---\n";
        if (danhSach.empty()) {
            cout << "Thu vien chua co tai lieu nao.\n";
            return;
        }
        for (size_t i = 0; i < danhSach.size(); ++i) {
            cout << "\nTai lieu thu " << (i + 1) << ":\n";
            danhSach[i]->hienThi();
        }
        cout << "\nTong so tai lieu: " << danhSach.size() << '\n';
    }

    void timTheoLoai() const {
        cout << "\n--- TIM KIEM THEO LOAI ---\n";
        cout << "1. Sach\n2. Tap chi\n3. Bao\n";
        int loai = nhapSoNguyen("Chon loai (1-3): ", 1, 3);
        int dem = 0;
        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (danhSach[i]->getLoai() == loai) {
                ++dem;
                cout << "\nKet qua " << dem << ":\n";
                danhSach[i]->hienThi();
            }
        }
        if (dem == 0) cout << "Khong co tai lieu thuoc loai nay.\n";
        else cout << "\nTim thay " << dem << " tai lieu.\n";
    }

    void chay() {
        while (true) {
            cout << "\n========== QUAN LY THU VIEN ==========\n"
                 << "1. Them moi tai lieu\n"
                 << "2. Xoa tai lieu theo ma\n"
                 << "3. Hien thi tat ca tai lieu\n"
                 << "4. Tim kiem tai lieu theo loai\n"
                 << "0. Thoat chuong trinh\n"
                 << "=======================================\n";
            int chon = nhapSoNguyen("Lua chon cua ban: ", 0, 4);
            switch (chon) {
                case 1: themTaiLieu(); break;
                case 2: xoaTheoMa(); break;
                case 3: hienThiTatCa(); break;
                case 4: timTheoLoai(); break;
                case 0:
                    cout << "Tam biet!\n";
                    return;
            }
        }
    }
};

int main() {
    QuanLyThuVien quanLy;
    quanLy.chay();
    return 0;
}
