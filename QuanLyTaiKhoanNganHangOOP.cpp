#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TaiKhoanNganHang
{
    private:
        string soTaiKhoan;
        string tenChuTaiKhoan;

    protected:
        long long soDuTaiKhoan;

    public:
        TaiKhoanNganHang(string soTaiKhoan, string tenChuTaiKhoan, long long soDuTaiKhoan)
        {
            this->soTaiKhoan = soTaiKhoan;
            this->tenChuTaiKhoan = tenChuTaiKhoan;
            this->soDuTaiKhoan = soDuTaiKhoan;
        }

        void setSoTaiKhoan(string soTaiKhoan)
        {
            this->soTaiKhoan = soTaiKhoan;
        }
        void setTenChuTaiKhoan(string tenChuTaiKhoan)
        {
            this->tenChuTaiKhoan = tenChuTaiKhoan;
        }
        void setSoDuTaiKhoan(long long soDuTaiKhoan)
        {
            this->soDuTaiKhoan = soDuTaiKhoan;
        }

        string getSoTaiKhoan() const
        {
            return soTaiKhoan;
        }
        string getTenChuTaiKhoan() const
        {
            return tenChuTaiKhoan;
        }
        long long getSoDuTaiKhoan()
        {
            return soDuTaiKhoan;
        }

        virtual void rutTien(long long soTien) = 0;

        virtual void inThongTinTaiKhoanNganHang() const
        {
            cout << "So tai khoan: " << soTaiKhoan 
                 << " | Ho ten chu tai khoan: " << tenChuTaiKhoan
                 << " | So du: " << soDuTaiKhoan; 
        }

        virtual ~TaiKhoanNganHang() {}
};

class TaiKhoanTietKiem : public TaiKhoanNganHang
{
    private:
        double laiSuatHangNam;

    public:
        TaiKhoanTietKiem(string soTaiKhoan, string tenChuTaiKhoan, long long soDuTaiKhoan, double laiSuatHangNam) 
                        : TaiKhoanNganHang(soTaiKhoan, tenChuTaiKhoan, soDuTaiKhoan)
        {
            this->laiSuatHangNam = laiSuatHangNam;
        }

        long long tinhLaiSuatNam() const
        {
            return soDuTaiKhoan * laiSuatHangNam;
        }

        void rutTien(long long soTien) override
        {
            if (soTien > 0 && soTien <= soDuTaiKhoan)
            {
                soDuTaiKhoan -= soTien;
                cout << "Thanh cong rut " << soTien << " VND tu tai khoan tiet kiem.\n";
            }
            else
            {
                cout << "That bai vi so du khong du hoac so tien rut khong hop le!\n";
            }
        }

        void inThongTinTaiKhoanNganHang() const override
        {
            TaiKhoanNganHang::inThongTinTaiKhoanNganHang();
            cout << " | Lai suat hang nam: " << laiSuatHangNam 
                 << " | Tien lai du kien: " << tinhLaiSuatNam() << endl;
        }
};

class TaiKhoanThanhToan : public TaiKhoanNganHang
{
    private:
        long long hanMucThauChi;

    public:
        TaiKhoanThanhToan(string soTaiKhoan, string tenChuTaiKhoan, long long soDuTaiKhoan, long long hanMucThauChi) 
                         : TaiKhoanNganHang(soTaiKhoan, tenChuTaiKhoan, soDuTaiKhoan)
        {
            this->hanMucThauChi = hanMucThauChi;
        }

        void setHanMucThauChi(long long hanMucThauChi)
        {
            this->hanMucThauChi = hanMucThauChi;
        }

        long long getHanMucThauChi()
        {
            return hanMucThauChi;
        }

        void rutTien(long long soTien) override
        {
            if (soTien > 0 && soTien <= soDuTaiKhoan)
            {
                soDuTaiKhoan -= soTien;
                cout << "Thanh cong rut " << soTien << " VND tu tai khoan tiet kiem.\n";
            }
            else
            {
                cout << "That bai vi so du khong du hoac so tien rut khong hop le!\n";
            }
        }

        void inThongTinTaiKhoanNganHang() const override
        {
            TaiKhoanNganHang::inThongTinTaiKhoanNganHang();
            cout << " | Han muc thau chi: " << hanMucThauChi << endl;
        }
};

int main()
{
    vector<TaiKhoanNganHang*> danhSachTaiKhoanTietKiem;
    vector<TaiKhoanNganHang*> danhSachTaiKhoanThanhToan;

    TaiKhoanNganHang* taiKhoan1 = new TaiKhoanTietKiem("TK01", "Nguyen Van A", 10000000, 0.25);
    TaiKhoanNganHang* taiKhoan2 = new TaiKhoanThanhToan("TK02", "Tran Thi B", 5000000, 2000000);

    danhSachTaiKhoanTietKiem.push_back(taiKhoan1);
    danhSachTaiKhoanThanhToan.push_back(taiKhoan2);

    int soLuongTaiKhoanTK, soLuongTaiKhoanTT;
    cout << "Nhap lan luot so luong tai khoan tiet kiem va thanh toan: ";
    cin >> soLuongTaiKhoanTK >> soLuongTaiKhoanTT;

    cin.ignore();

    for (int i = 0; i < soLuongTaiKhoanTK; i++)
    {
        string soTK, tenChuTK;
        long long soDuTK;
        double laiSuatHangNam;

        getline(cin, soTK);
        getline(cin, tenChuTK);
        
        cin.ignore();

        cin >> soDuTK;
        cin >> laiSuatHangNam;

        TaiKhoanNganHang* tkTietKiem = new TaiKhoanTietKiem(soTK, tenChuTK, soDuTK, laiSuatHangNam);
        danhSachTaiKhoanTietKiem.push_back(tkTietKiem);
    }

    cin.ignore();

    for (int i = 0; i < soLuongTaiKhoanTT; i++)
    {
        string soTK, tenChuTK;
        long long soDuTK, hanMucThauChi;

        getline(cin, soTK);
        getline(cin, tenChuTK);

        cin.ignore();

        cin >> soDuTK;
        cin >> hanMucThauChi;

        TaiKhoanNganHang* tkThanhToan = new TaiKhoanThanhToan(soTK, tenChuTK, soDuTK, hanMucThauChi);
        danhSachTaiKhoanThanhToan.push_back(tkThanhToan);
    }

    cout << "---- Thong tin ban dau truoc giao dich ----\n";
    for (int i = 0; i < danhSachTaiKhoanTietKiem.size(); i++)
    {
        danhSachTaiKhoanTietKiem[i]->inThongTinTaiKhoanNganHang();
    }
    for (int i = 0; i < danhSachTaiKhoanThanhToan.size(); i++)
    {
        danhSachTaiKhoanThanhToan[i]->inThongTinTaiKhoanNganHang();
    }

    cout << "\n---- Giao dien rut tien ----\n";
    taiKhoan1->rutTien(9000000);
    taiKhoan2->rutTien(4000000);

    cout << "\n---- Thong tin tai khoan sau khi giao dich ----\n";
    for (int i = 0; i < danhSachTaiKhoanTietKiem.size(); i++)
    {
        danhSachTaiKhoanTietKiem[i]->inThongTinTaiKhoanNganHang();
    }
    for (int i = 0; i < danhSachTaiKhoanThanhToan.size(); i++)
    {
        danhSachTaiKhoanThanhToan[i]->inThongTinTaiKhoanNganHang();
    }

    delete taiKhoan1;
    delete taiKhoan2;

    return 0;
}