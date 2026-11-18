#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChuyenDiCoBan
{
    private:
        string maChuyenDi;
        string tenKhachHang;
        string quocTich;
        int khoangCach;
        int soLuongHanhKhach;

    public:
        ChuyenDiCoBan(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
        {
            this->maChuyenDi = maChuyenDi;
            this->tenKhachHang = tenKhachHang;
            this->quocTich = quocTich;
            this->khoangCach = khoangCach;
            this->soLuongHanhKhach = soLuongHanhKhach;
        }

        void setMaChuyenDi(string maChuyenDi) { this->maChuyenDi = maChuyenDi; }
        void setTenKhachHang(string tenKhachHang) { this->tenKhachHang = tenKhachHang; }
        void setQuocTich(string quocTich) { this->quocTich = quocTich; }
        void setKhoangCach(int khoangCach) 
        {
            if (khoangCach < 0) 
            {
                cout << "Loi: Khoang cach khong hop le. Vui long nhap lai." << endl;
                return;
            }
            this->khoangCach = khoangCach; 
        }
        void setSoLuongHanhKhach(int soLuongHanhKhach) 
        {
            if (soLuongHanhKhach < 0) 
            {
                cout << "Loi: So luong hanh khach khong hop le. Vui long nhap lai." << endl;
                return;
            }
            this->soLuongHanhKhach = soLuongHanhKhach; 
        }

        string getMaChuyenDi() const { return maChuyenDi; }
        string getTenKhachHang() const { return tenKhachHang; }
        string getQuocTich() const { return quocTich; }
        int getKhoangCach() const { return khoangCach; }
        int getSoLuongHanhKhach() const { return soLuongHanhKhach; }

        virtual double tinhCuocChuyenDi() const = 0;

        virtual void hienThiThongTinChuyenDi() const
        {
            cout << "Ma chuyen di: " << maChuyenDi << "\n"
                 << "Ten khach hang: " << tenKhachHang << "\n"
                 << "Quoc tich: " << quocTich << "\n"
                 << "Khoang cach: " << khoangCach << "\n"
                 << "So luong hanh khach: " << soLuongHanhKhach << "\n";
        }
};

class CuocPhiXeMay : public ChuyenDiCoBan
{
    private:
        double donGiaChoMotKm = 10000;
        double tongDonGia;

    public:
        CuocPhiXeMay(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
                   : ChuyenDiCoBan(maChuyenDi, tenKhachHang, quocTich, khoangCach, soLuongHanhKhach)
        {
            if (soLuongHanhKhach >= 2) 
            {
                cout << "Loi: So luong hanh khach khong hop le cho xe may. Vui long nhap lai." << endl;
                return;
            }
            this->tongDonGia = donGiaChoMotKm * khoangCach;
        }

        double tinhCuocChuyenDi() const override
        {
            return tongDonGia;
        }

        void hienThiThongTinChuyenDi() const override
        {
            ChuyenDiCoBan::hienThiThongTinChuyenDi();
            cout << "Tong cuoc phi: " << tongDonGia << endl;
            cout << "\n";
        }
};

class CuocPhiXeOto : public ChuyenDiCoBan
{
    private:
        double donGiaChoMotKm = 15000;
        int soLuongHanhKhach;
        double tongDonGia;

    public:
        CuocPhiXeOto(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
                   : ChuyenDiCoBan(maChuyenDi, tenKhachHang, quocTich, khoangCach, soLuongHanhKhach)
        {
            this->soLuongHanhKhach = soLuongHanhKhach;
            if (soLuongHanhKhach <= 4)
            {
                this->tongDonGia = donGiaChoMotKm * khoangCach;
            }
            if (soLuongHanhKhach > 4)
            {
                this->tongDonGia = donGiaChoMotKm * 1.2 * khoangCach;
            }
        }

        double tinhCuocChuyenDi() const override
        {
            return tongDonGia;
        }

        void hienThiThongTinChuyenDi() const override
        {
            ChuyenDiCoBan::hienThiThongTinChuyenDi();
            cout << "Tong cuoc phi: " << tongDonGia << endl;
            cout << "\n";
        }
};

int main()
{
    vector<ChuyenDiCoBan*> danhSachChuyenDi;

    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD01", "Nguyen Van A", "Viet Nam", 10, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD02", "Tran Thi B", "Viet Nam", 20, 5));
    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD03", "Le Van C", "Viet Nam", 15, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD04", "Pham Thi D", "Viet Nam", 30, 3));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD05", "Hoang Van E", "Viet Nam", 25, 6));
    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD06", "Nguyen Thi F", "Viet Nam", 5, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD07", "Tran Van G", "Viet Nam", 12, 4));

    cout << "Danh sach chuyen di va cuoc phi tuong ung:" << endl;
    for (const auto& chuyenDi : danhSachChuyenDi)
    {
        chuyenDi->hienThiThongTinChuyenDi();
    }

    return 0;
}