#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class TuVung
{
    private:
        string tuVungTiengAnh;
        string nghiaTuTiengViet;

    public:
        TuVung(string tuVungTiengAnh, string nghiaTuTiengViet) 
        {
            this->tuVungTiengAnh = tuVungTiengAnh;
            this->nghiaTuTiengViet = nghiaTuTiengViet;
        }

        void setTuVungTiengAnh(string tuVungTiengAnh)
        {
            this->tuVungTiengAnh = tuVungTiengAnh;
        }
        void setNghiaTuTiengViet(string nghiaTuTiengViet)
        {
            this->nghiaTuTiengViet = nghiaTuTiengViet;
        }

        string getTuVungTiengAnh() const
        {
            return tuVungTiengAnh;
        }
        string getNghiaTuTiengViet() const
        {
            return nghiaTuTiengViet;
        }

        void inThongTinTuVung()
        {
            cout << left << setw(20) << tuVungTiengAnh << " | " << nghiaTuTiengViet << endl;
        }
};

class TuDienAnhViet
{
    private:
        vector<TuVung> danhSachTuVung;
        int timViTriTu(const string& tuCanTim) const
        {
            for (int i = 0; i < danhSachTuVung.size(); i++)
            {
                if (danhSachTuVung[i].getTuVungTiengAnh() == tuCanTim)
                {
                    return i;
                }
            }
            return -1;
        }

    public:
        void themTuVungMoi(const string& tuVungEng, const string& nghiaTuVie)
        {
            if (timViTriTu(tuVungEng) != -1)
            {
                cout << "Tu " << tuVungEng << " da ton tai trong tu dien";
                return;
            }
            danhSachTuVung.push_back(TuVung(tuVungEng, nghiaTuVie));
            cout << "Da nhap tu " << tuVungEng << " thanh cong";
        }

        void suaTuDaCo(const string& tuEngCu, const string& nghiaVieMoi)
        {
            if (timViTriTu(tuEngCu) != -1)
            {
                danhSachTuVung[timViTriTu(tuEngCu)].setNghiaTuTiengViet(nghiaVieMoi);
                cout << "Da cap nhat tu " << tuEngCu << " thanh cong" << endl;
            }
            else
            {
                cout << "Khong ton tai tu can cap nhat";
            }
        }

        void xoaTuVungCu(const string& tuEngCu)
        {
            if (timViTriTu(tuEngCu) != -1)
            {
                danhSachTuVung.erase(danhSachTuVung.begin() + timViTriTu(tuEngCu));
                cout << "Tu " << tuEngCu << " da duoc xoa khoi tu dien" << endl;
            }
            else
            {
                cout << "Khong ton tai tu " << tuEngCu << " trong tu dien de xoa" << endl;
            }
        }

        void hienDanhSachTu()
        {
            if (danhSachTuVung.empty()) 
            {
                cout << "Tu dien hien dang trong.\n";
                return;
            }
            else
            {
                cout << string(40, '-') << endl;
                cout << left << setw(20) << "Tieng Anh" << "| Tieng Viet\n";
                cout << string(40, '-') << endl;
                for (int i = 0; i < danhSachTuVung.size(); i++)
                {
                    danhSachTuVung[i].inThongTinTuVung();
                }
                cout << string(40, '-') << endl;
            }
        }

        void traTuCanTim(const string& tuEngCanTim) const
        {
            if (timViTriTu(tuEngCanTim) != -1)
            {
                cout << "Nghia cua tu " << tuEngCanTim << " co nghia la: " 
                     << danhSachTuVung[timViTriTu(tuEngCanTim)].getNghiaTuTiengViet() << endl;
            }
            else 
            {
                cout << "Khong tim thay tu can tim" << endl;
            }
        }
};

int main()
{
    TuDienAnhViet tuVungCanThem;
    
    tuVungCanThem.themTuVungMoi("game", "tro choi dien tu");
    tuVungCanThem.themTuVungMoi("travel", "chuyen du lich, di chuyen");
    tuVungCanThem.themTuVungMoi("robot", "nguoi may tu dong");
    tuVungCanThem.themTuVungMoi("application", "ung dung");
    tuVungCanThem.themTuVungMoi("movie", "bo phim");
    tuVungCanThem.themTuVungMoi("motherboard", "bo mach chu");

    int luaChon;
    do 
    {
        cout << string(30, '-') << endl;
        cout << "=== TU DIEN ANH - VIET ===" << endl;
        cout << string(30, '-') << endl;
        cout << "1. Xem danh sach tu" << endl;
        cout << "2. Tra tu" << endl;
        cout << "3. Them tu moi" << endl;
        cout << "4. Sua nghia cua tu" << endl;
        cout << "5. Xoa tu" << endl;
        cout << "0. Thoat" << endl;
        cout << string(30, '-') << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        string tuVungTiengAnh, nghiaTuTiengViet;
        switch (luaChon) 
        {
            case 1:
                tuVungCanThem.hienDanhSachTu();
                break;
            case 2:
                cout << "Nhap tu tieng Anh can tra: ";
                getline(cin, tuVungTiengAnh);
                tuVungCanThem.traTuCanTim(tuVungTiengAnh);
                break;
            case 3:
                cout << "Nhap tu tieng Anh: ";
                getline(cin, tuVungTiengAnh);
                cout << "Nhap nghia tieng Viet: ";
                getline(cin, nghiaTuTiengViet);
                tuVungCanThem.themTuVungMoi(tuVungTiengAnh, nghiaTuTiengViet);
                break;
            case 4:
                cout << "Nhap tu tieng Anh can sua: ";
                getline(cin, tuVungTiengAnh);
                cout << "Nhap nghia moi: ";
                getline(cin, nghiaTuTiengViet);
                tuVungCanThem.suaTuDaCo(tuVungTiengAnh, nghiaTuTiengViet);
                break;
            case 5:
                cout << "Nhap tu tieng Anh can xoa: ";
                getline(cin, tuVungTiengAnh);
                tuVungCanThem.xoaTuVungCu(tuVungTiengAnh);
                break;
            case 0:
                cout << "Dang thoat chuong trinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
        cout << endl;
    } 
    while (luaChon != 0);

    return 0;
}
