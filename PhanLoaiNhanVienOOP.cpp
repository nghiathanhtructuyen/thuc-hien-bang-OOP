#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien
{
    private:
        string maNhanVien;
        
    protected:
        string hoTen;
        double luongNhanVienCoBan;

    public:
        NhanVien(string maNhanVien, string hoTen, double luongNhanVienCoBan)
        {
            this->maNhanVien = maNhanVien;
            this->hoTen = hoTen;
            this->luongNhanVienCoBan = luongNhanVienCoBan;
        }

        void setMaNhanVien(string maNhanVien)
        {
            this->maNhanVien = maNhanVien;
        }
        void setHoTen(string hoTen)
        {
            this->hoTen = hoTen;
        }
        void setLuongNhanVienCoBan(double luongNhanVienCoBan)
        {
            this->luongNhanVienCoBan = luongNhanVienCoBan;
        }

        string getMaNhanVien()
        {
            return maNhanVien;
        }
        string getHoTen()
        {
            return hoTen;
        }
        double getLuongNhanVienCoBan()
        {
            return luongNhanVienCoBan;
        }

        virtual double tinhLuong() const = 0;

        virtual void inThongTinNhanVien() const
        {
            cout << "Ma NV: " << maNhanVien << "; Ho ten: " << hoTen;
        }

        virtual ~NhanVien() {}
};

class NhanVienChinhThuc : public NhanVien
{
    private:
        double heSoLuong;

    public:
        NhanVienChinhThuc(string maNhanVien, string hoTen, double luongNhanVienCoBan, double heSoLuong) 
               : NhanVien(maNhanVien, hoTen, luongNhanVienCoBan)
        {
            this->heSoLuong = heSoLuong;
        }

        double tinhLuong() const override
        {
            return luongNhanVienCoBan * heSoLuong;
        }

        void inThongTinNhanVien() const override
        {
            NhanVien::inThongTinNhanVien();
            cout << "; Loai: Chinh thuc; Luong: " << tinhLuong() << endl;
        }
};

class NhanVienPartTime : public NhanVien
{
    private:
        double soGioLamViec;

    public:
        NhanVienPartTime(string maNhanVien, string hoTen, double luongNhanVienCoBan, double soGioLamViec) 
              : NhanVien(maNhanVien, hoTen, luongNhanVienCoBan)
        {
            this->soGioLamViec = soGioLamViec;
        }

        double tinhLuong() const override
        {
            return soGioLamViec * 50000;
        }

        void inThongTinNhanVien() const override
        {
            NhanVien::inThongTinNhanVien();
            cout << "; Loai: Part-time; Luong: " << tinhLuong() << endl;
        }
};

int main()
{
    vector<NhanVien*> danhSachNhanVienCT;
    vector<NhanVien*> danhSachNhanVienPT;

    NhanVien* nhanVien1 = new NhanVienChinhThuc("NV01", "Nguyen Van A", 5000000, 2.5);
    NhanVien* nhanVien2 = new NhanVienPartTime("NV02", "Tran Thi B", 0, 120);

    danhSachNhanVienCT.push_back(nhanVien1);
    danhSachNhanVienPT.push_back(nhanVien2);

    int soLuongNhanVienCT, soLuongNhanVienPT;
    cout << "Nhap lan luot so luong nhan vien chinh thuc va part-time: ";
    cin >> soLuongNhanVienCT >> soLuongNhanVienPT;

    cin.ignore();

    for (int i = 0; i < soLuongNhanVienCT; i++)
    {
        string maNV, hoTen;
        long long luongNVCoBan;
        double heSoLuongNV;

        getline(cin, maNV);
        getline(cin, hoTen);

        cin.ignore();

        cin >> luongNVCoBan;
        cin >> heSoLuongNV;

        NhanVien* nhanVienCT = new NhanVienChinhThuc(maNV, hoTen, luongNVCoBan, heSoLuongNV);
        danhSachNhanVienCT.push_back(nhanVienCT);
    }

    cin.ignore();

    for (int i = 0; i < soLuongNhanVienPT; i++)
    {
        string maNV, hoTen;
        long long luongNVCoBan;
        double soGioLamViecPT;

        getline(cin, maNV);
        getline(cin, hoTen);

        cin.ignore();

        cin >> luongNVCoBan;
        cin >> soGioLamViecPT;

        NhanVien* nhanVienPT = new NhanVienChinhThuc(maNV, hoTen, luongNVCoBan, soGioLamViecPT);
        danhSachNhanVienCT.push_back(nhanVienPT);
    }

    for (int i = 0; i < danhSachNhanVienCT.size(); i++)
    {
        danhSachNhanVienCT[i]->inThongTinNhanVien();
    }

    for (int i = 0; i < danhSachNhanVienPT.size(); i++)
    {
        danhSachNhanVienPT[i]->inThongTinNhanVien();
    }
    
    return 0;
}