#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x, y;

public:
    bidangDatar() {
        x = 0;
        y = 0;
    }

    virtual void input() {}
    virtual float Luas() { return 0; }
    virtual float Keliling() { return 0; }
    virtual void cekUkuran() { return; }

    void setX(int a) {
        this->x = a;
    }

    int getX() {
        return x;
    }

    void setY(int b) {
        this->y = b;
    }

    int getY() {
        return y;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        int r;
        cout << "Masukkan jejari lingkaran: ";
        cin >> r;
        setX(r);
    }

    float Luas() {
        return 3.14 * getX() * getX();
    }

    float Keliling() {
        return 2 * 3.14 * getX();
    }

    void cekUkuran() {
        if (Keliling() + Luas() > 40) {
            cout << "Ukuran lingkaran adalah besar" << endl;
        }
        else if (Keliling() + Luas() < 20) {
            cout << "Ukuran lingkaran adalah sedang" << endl;
        }
        else if (Keliling() + Luas() < 10) {
            cout << "Ukuran lingkaran adalah kecil" << endl;
        }
    }
};

class Persegipanjang : public bidangDatar {
public:
    void input() {
        int p, l;
        cout << "Masukkan panjang persegi panjang: ";
        cin >> p;
        setX(p);
        cout << "Masukkan lebar persegi panjang: ";
        cin >> l;
        setY(l);
    }

    float Luas() {
        return getX() * getY();
    }

    float Keliling() {
        return 2 * (getX() + getY());
    }

    void cekUkuran() {
        if (Keliling() + Luas() > 40) {
            cout << "Ukuran persegi panjang adalah besar" << endl;
        }
        else if (Keliling() + Luas() < 20) {
            cout << "Ukuran persegi panjang adalah sedang" << endl;
        }
        else if (Keliling() + Luas() < 10) {
            cout << "Ukuran persegi panjang adalah kecil" << endl;
        }
    }
};

int main() {
    char ch;

    do {
        bidangDatar* bd;
        Lingkaran lingkaran;
        Persegipanjang persegiPanjang;

        int bentuk;
        cout << "Pilih bentuk bidang datar:" << endl;
        cout << "1. Lingkaran" << endl;
        cout << "2. Persegi Panjang" << endl;
        cout << "Pilihan: ";
        cin >> bentuk;

        switch (bentuk) {
        case 1:
            bd = &lingkaran;
            cout << "Lingkaran dibuat" << endl;
            bd->input();
            cout << "Luas Lingkaran = " << bd->Luas() << endl;
            cout << "Keliling Lingkaran = " << bd->Keliling() << endl;
            bd->cekUkuran();
            break;
        case 2:
            bd = &persegiPanjang;
            cout << "Persegi Panjang dibuat" << endl;
            bd->input();
            cout << "Luas Persegi Panjang = " << bd->Luas() << endl;
            cout << "Keliling Persegi Panjang = " << bd->Keliling() << endl;
            bd->cekUkuran();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "Apakah anda ingin mengulang program? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}