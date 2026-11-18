#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class TaiLieuCuaThuVien
{
    public:
        string maTaiLieu;
        string tenTaiLieu;
        string tenNhaXuatBan;
        int namXuatBan;
    
    public:
        TaiLieuCuaThuVien(string maTaiLieu, string tenTaiLieu, string tenNhaXuatBan, int namXuatBan)
        {
            this->maTaiLieu = maTaiLieu;
            this->tenTaiLieu = tenTaiLieu;
            this->tenNhaXuatBan = tenNhaXuatBan;
            this->namXuatBan = namXuatBan;
        }

        TaiLieuCuaThuVien() : maTaiLieu(""), tenTaiLieu(""), tenNhaXuatBan(""), namXuatBan(0) {}

        void setMaTaiLieu(string maTaiLieu) { this->maTaiLieu = maTaiLieu; }
        void setTenTaiLieu(string tenTaiLieu) { this->tenTaiLieu = tenTaiLieu; }
        void setTenNhaXuatBan(string tenNhaXuatBan) { this->tenNhaXuatBan = tenNhaXuatBan; }
        void setNamXuatBan(int namXuatBan) { this->namXuatBan = namXuatBan; }

        string getMaTaiLieu() const { return maTaiLieu; }
        string getTenTaiLieu() const { return tenTaiLieu; }
        string getTenNhaXuatBan() const { return tenNhaXuatBan; }
        int getNamXuatBan() const { return namXuatBan; }

        virtual void hienThiThongTin() const = 0;    
};

class SachCuaThuVien : public TaiLieuCuaThuVien
{
    private:
        string tenTacGia;

    public:
        SachCuaThuVien(string maTaiLieu, string tenTaiLieu, string tenNhaXuatBan, int namXuatBan, string tenTacGia)
                      : TaiLieuCuaThuVien(maTaiLieu, tenTaiLieu, tenNhaXuatBan, namXuatBan)
        {
            this->tenTacGia = tenTacGia;
        }

        SachCuaThuVien() : TaiLieuCuaThuVien(), tenTacGia("") {}

        void setTenTacGia(string tenTacGia) { this->tenTacGia = tenTacGia; }

        string getTenTacGia() { return tenTacGia; }

        void hienThiThongTin() const override
        {
            cout << setw(12) << left << "[SACH]" << " | "
                 << setw(15) << left << getMaTaiLieu() << " | "
                 << setw(30) << left << getTenTaiLieu() << " | "
                 << setw(15) << left << getTenNhaXuatBan() << " | "
                 << setw(12) << left << getNamXuatBan() << " | "
                 << setw(15) << left << tenTacGia
                 << endl;
        }
};

class TapChiCuaThuVien : public TaiLieuCuaThuVien
{
    private:
        int soPhatHanh;

    public:
        TapChiCuaThuVien(string maTaiLieu, string tenTaiLieu, string tenNhaXuatBan, int namXuatBan, int soPhatHanh)
                        : TaiLieuCuaThuVien(maTaiLieu, tenTaiLieu, tenNhaXuatBan, namXuatBan)
        {
            this->soPhatHanh = soPhatHanh;
        }

        TapChiCuaThuVien() : TaiLieuCuaThuVien(), soPhatHanh(0) {}

        void setSoPhatHanh(int soPhatHanh) { this->soPhatHanh = soPhatHanh; }

        int getSoPhatHanh() { return soPhatHanh; }

        void hienThiThongTin() const override
        {
            cout << setw(12) << left << "[TAP CHI]" << " | "
                 << setw(15) << left << getMaTaiLieu() << " | "
                 << setw(30) << left << getTenTaiLieu() << " | "
                 << setw(15) << left << getTenNhaXuatBan() << " | "
                 << setw(12) << left << getNamXuatBan() << " | "
                 << setw(15) << left << soPhatHanh
                 << endl;
        }
};

class HeThongThuVien
{
    private:
        vector<TaiLieuCuaThuVien*> danhSachTaiLieu;

    public:
        void themTaiLieuMoi(TaiLieuCuaThuVien* taiLieu)
        {
            int soTaiLieuTrongThuVien = danhSachTaiLieu.size();
            for (int i = 0; i < soTaiLieuTrongThuVien; i++)
            {
                if (danhSachTaiLieu[i]->getMaTaiLieu() == taiLieu->getMaTaiLieu())
                {
                    cout << "Loi: Ma tai lieu da ton tai trong he thong. Khong the them." << endl;
                    return;
                }
            }
            danhSachTaiLieu.push_back(taiLieu);
        }

        void hienThiDanhSachTaiLieu() const
        {
            cout << setw(12) << left << "Loai" << " | "
                 << setw(15) << left << "Ma tai lieu" << " | "
                 << setw(30) << left << "Ten tai lieu" << " | "
                 << setw(15) << left << "Nha xuat ban" << " | "
                 << setw(12) << left << "Nam xuat ban" << " | "
                 << setw(15) << left << "Thong tin khac"
                 << endl;
            cout << string(113, '-') << endl;

            for (const auto& taiLieu : danhSachTaiLieu)
            {
                taiLieu->hienThiThongTin();
            }
            cout << endl;
        }

        pair<int, int> thongKeSoLuongTaiLieu() const
        {
            int soLuongSach = 0;
            int soLuongTapChi = 0;
            for (const auto& taiLieu : danhSachTaiLieu)
            {
                if (dynamic_cast<SachCuaThuVien*>(taiLieu))
                {
                    soLuongSach++;
                }
                else if (dynamic_cast<TapChiCuaThuVien*>(taiLieu))
                {
                    soLuongTapChi++;
                }
            }
            return make_pair(soLuongSach, soLuongTapChi);
        }

        void xoaTaiLieuTheoMa(string maTaiLieu)
        {
            for (auto documentInfo = danhSachTaiLieu.begin(); documentInfo != danhSachTaiLieu.end(); ++documentInfo)
            {
                if ((*documentInfo)->getMaTaiLieu() == maTaiLieu)
                {
                    danhSachTaiLieu.erase(documentInfo);
                    cout << "Da xoa tai lieu co ma: " << maTaiLieu << endl;
                    cout << endl;
                    return;
                }
            }
            cout << "Khong tim thay tai lieu co ma: " << maTaiLieu << endl;
            cout << endl;
        }

        void timKiemTaiLieuTheoTen(string tenTaiLieu) const
        {
            bool timThay = false;
            for (const auto& taiLieu : danhSachTaiLieu)
            {
                if (taiLieu->getTenTaiLieu() == tenTaiLieu)
                {
                    taiLieu->hienThiThongTin();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay)
            {
                cout << "Khong tim thay tai lieu co ten: " << tenTaiLieu << endl;
                cout << endl;
            }
        }

        void timKiemTaiLieuTheoNhaXuatBan(string tenNhaXuatBan) const
        {
            bool timThay = false;
            for (const auto& taiLieu : danhSachTaiLieu)
            {
                if (taiLieu->getTenNhaXuatBan() == tenNhaXuatBan)
                {
                    taiLieu->hienThiThongTin();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay)
            {
                cout << "Khong tim thay tai lieu cua nha xuat ban: " << tenNhaXuatBan << endl;
                cout << endl;
            }
        }

        void timKiemTaiLieuTheoNamXuatBan(int namXuatBan) const
        {
            bool timThay = false;
            for (const auto& taiLieu : danhSachTaiLieu)
            {
                if (taiLieu->getNamXuatBan() == namXuatBan)
                {
                    taiLieu->hienThiThongTin();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay)
            {
                cout << "Khong tim thay tai lieu duoc xuat ban vao nam: " << namXuatBan << endl;
                cout << endl;
            }
        }

        void timKiemTaiLieuTheoTuKhoa(string tuKhoa) const
        {
            bool timThay = false;
            for (const auto& taiLieu : danhSachTaiLieu)
            {
                if (taiLieu->getTenTaiLieu().find(tuKhoa) != string::npos ||
                    taiLieu->getTenNhaXuatBan().find(tuKhoa) != string::npos)
                {
                    taiLieu->hienThiThongTin();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay)
            {
                cout << "Khong tim thay tai lieu voi tu khoa: " << tuKhoa << endl;
                cout << endl;
            }
        }
};

int main()
{
    HeThongThuVien librarySystem;

    librarySystem.themTaiLieuMoi(new SachCuaThuVien("S001", "Lap trinh C++", "NXB ABC", 2020, "Nguyen Van A"));
    librarySystem.themTaiLieuMoi(new TapChiCuaThuVien("T001", "Tap chi CNTT", "NXB XYZ", 2021, 5));
    librarySystem.themTaiLieuMoi(new SachCuaThuVien("S002", "Giai thuat voi C++", "NXB DEF", 2019, "Tran Thi B"));
    librarySystem.themTaiLieuMoi(new TapChiCuaThuVien("T002", "Tap chi Khoa hoc", "NXB UVW", 2022, 10));
    librarySystem.themTaiLieuMoi(new SachCuaThuVien("S003", "Lap trinh Python", "NXB GHI", 2021, "Le Van C"));
    librarySystem.themTaiLieuMoi(new TapChiCuaThuVien("T003", "Tap chi Toan hoc", "NXB RST", 2020, 8));
    librarySystem.themTaiLieuMoi(new SachCuaThuVien("S004", "Lap trinh Java", "NXB JKL", 2022, "Pham Thi D"));
    librarySystem.themTaiLieuMoi(new TapChiCuaThuVien("T004", "Tap chi Kinh te", "NXB MNO", 2021, 12));

    int luaChon;
    do 
    {
        cout << "|==========================================================================|\n";
        cout << "|================== HE THONG QUAN LY THU VIEN TRUONG HOC ==================|\n";
        cout << "|==========================================================================|\n";
        cout << "Hay chon chuc nang ban muon su dung:\n";
        cout << "1. Hien thi danh sach tai lieu\n";
        cout << "2. Them tai lieu moi\n";
        cout << "3. Xoa tai lieu theo ma\n";
        cout << "4. Tim kiem tai lieu theo ten\n";
        cout << "5. Tim kiem tai lieu theo nha xuat ban\n";
        cout << "6. Tim kiem tai lieu theo nam xuat ban\n";
        cout << "7. Tim kiem tai lieu theo tu khoa\n";
        cout << "8. Thong ke so luong tai lieu\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "|==========================================================================|\n\n";
        cout << "Nhap lua chon cua ban: ";
        
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) 
        {
            case 0:
                cout << "Cam on ban da su dung chuong trinh. Tam biet!" << endl;
                return 0;
            case 1:
                librarySystem.hienThiDanhSachTaiLieu();
                break;
            case 2:
                int loaiTaiLieu;
                cout << "Chon loai tai lieu (1: Sach, 2: Tap chi): ";
                cin >> loaiTaiLieu;
                cin.ignore();
                if (loaiTaiLieu == 1) 
                {
                    string ma, ten, nhaXuatBan, tacGia;
                    int nam;
                    cout << "Nhap ma tai lieu: "; getline(cin, ma);
                    cout << "Nhap ten tai lieu: "; getline(cin, ten);
                    cout << "Nhap ten nha xuat ban: "; getline(cin, nhaXuatBan);
                    cout << "Nhap nam xuat ban: "; cin >> nam; cin.ignore();
                    cout << "Nhap ten tac gia: "; getline(cin, tacGia);
                    librarySystem.themTaiLieuMoi(new SachCuaThuVien(ma, ten, nhaXuatBan, nam, tacGia));
                } 
                else if (loaiTaiLieu == 2) 
                {
                    string ma, ten, nhaXuatBan;
                    int nam, soPhatHanh;
                    cout << "Nhap ma tai lieu: "; getline(cin, ma);
                    cout << "Nhap ten tai lieu: "; getline(cin, ten);
                    cout << "Nhap ten nha xuat ban: "; getline(cin, nhaXuatBan);
                    cout << "Nhap nam xuat ban: "; cin >> nam; cin.ignore();
                    cout << "Nhap so phat hanh: "; cin >> soPhatHanh; cin.ignore();
                    librarySystem.themTaiLieuMoi(new TapChiCuaThuVien(ma, ten, nhaXuatBan, nam, soPhatHanh));
                } 
                else 
                {
                    cout << "Lua chon khong hop le." << endl;
                }
                break;
            case 3:
                {
                    string ma;
                    cout << "Nhap ma tai lieu can xoa: ";
                    getline(cin, ma);
                    librarySystem.xoaTaiLieuTheoMa(ma);
                    break;
                }
            case 4:
                {
                    string ten;
                    cout << "Nhap ten tai lieu can tim kiem: ";
                    getline(cin, ten);
                    librarySystem.timKiemTaiLieuTheoTen(ten);
                    break;
                }
            case 5:
                {
                    string nhaXuatBan;
                    cout << "Nhap ten nha xuat ban can tim kiem: ";
                    getline(cin, nhaXuatBan);
                    librarySystem.timKiemTaiLieuTheoNhaXuatBan(nhaXuatBan);
                    break;
                }
            case 6:
                {
                    int nam;
                    cout << "Nhap nam xuat ban can tim kiem: ";
                    cin >> nam; cin.ignore();
                    librarySystem.timKiemTaiLieuTheoNamXuatBan(nam);
                    break;
                }
            case 7:
                {
                    string tuKhoa;
                    cout << "Nhap tu khoa can tim kiem: ";
                    getline(cin, tuKhoa);
                    librarySystem.timKiemTaiLieuTheoTuKhoa(tuKhoa);
                    break;
                }
            case 8:
                {
                    pair<int, int> soLuongSachVaTapChi = librarySystem.thongKeSoLuongTaiLieu();
                    cout << "So luong sach: " << soLuongSachVaTapChi.first << endl;
                    cout << "So luong tap chi: " << soLuongSachVaTapChi.second << endl;
                    break;
                }
            default:
                if (luaChon != 0) 
                {
                    cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                }
                break;
        }
    }
    while (luaChon != 0);
    return 0;
}