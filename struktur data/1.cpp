#include <iomanip> // Library ini digunakan untuk mengatur tampilan output, seperti mengatur lebar dan presisi angka, mengatur penulisan bilangan dengan format desimal atau heksadesimal, dan lainnya. Fungsionalitas ini sering digunakan dalam manipulasi tampilan output pada program C++.
#include <vector> // Library ini menyediakan implementasi dari struktur data dinamis yang disebut vector. Vector merupakan kumpulan elemen yang dikelompokkan secara berurutan dan dapat secara dinamis ditambah atau dikurangi ukurannya. Library ini menyediakan fungsi-fungsi untuk memanipulasi vector, seperti menambah atau menghapus elemen, mengakses elemen berdasarkan indeks, dan melakukan operasi lainnya.
#include <iostream> //Library ini menyediakan input dan output standar dalam C++. Melalui library ini, kita dapat melakukan operasi seperti membaca input dari keyboard dan menampilkan output ke layar. Fungsi-fungsi dasar seperti cin dan cout terdapat dalam library ini.
#include <algorithm> // Library ini menyediakan berbagai fungsi algoritma yang umum digunakan dalam pemrograman, seperti pengurutan, pencarian, permutasi, dan manipulasi range. Fungsi-fungsi ini membantu dalam memanipulasi dan memproses data dengan lebih efisien dan mudah.

using namespace std;

struct PesRental { // Struktur PesRental digunakan untuk merepresentasikan informasi pesanan rental dalam program. Setiap objek dari struktur ini akan menyimpan detail spesifik tentang satu pesanan rental.
    string nama; // nama (tipe data string): Menyimpan nama pesanan rental.
    int durasi; // durasi (tipe data int): Menyimpan durasi pemesanan rental.
    int jumlahPes; // jumlahPes (tipe data int): Menyimpan jumlah pesanan rental.
    double harga;  // harga (tipe data double): Menyimpan harga total pesanan rental.
    PesRental* next;  // Pointer ke node berikutnya dalam linked list // Struktur PesRental digunakan untuk merepresentasikan informasi pesanan rental dalam program. Setiap objek dari struktur ini akan menyimpan detail spesifik tentang satu pesanan rental.
};

double hitungTotalHarga(const PesRental& pes) { //  Fungsi ini bertujuan untuk menghitung total harga pesanan berdasarkan informasi yang terdapat pada objek pes dari tipe data PesRental. Fungsi ini menggunakan atribut-atribut harga, jumlahPes, dan durasi dari objek pes untuk melakukan perhitungan. 
    return pes.harga * pes.jumlahPes * pes.durasi; 
}

void tampilkanPesanan(const PesRental& pes) { // Fungsi ini digunakan untuk menampilkan rincian pesanan yang terdapat pada objek pes dari tipe data PesRental. Fungsi ini menggunakan objek cout dari C++ untuk mencetak informasi pesanan ke output.
    cout << "========== Rincian Pesanan ==========" << endl;
    cout << "Nama Pemesan: " << pes.nama << endl;
    cout << "Durasi Rental: " << pes.durasi << " jam" << endl;
    cout << "Jumlah PlayStation: " << pes.jumlahPes << endl;
    cout << "Harga per PlayStation per jam: Rp. " << pes.harga << "000" << endl;
    cout << "Total Harga: Rp. " << hitungTotalHarga(pes) << "000" << endl;
    cout << "======================================" << endl;
}

bool comparePesanan(const PesRental& pes1, const PesRental& pes2) { //Fungsi ini merupakan fungsi perbandingan untuk objek-objek PesRental. Fungsi ini mengambil dua parameter dengan tipe data const PesRental& yang disebut pes1 dan pes2. Fungsi ini membandingkan atribut nama dari objek pes1 dan pes2. Jika nama objek pes1 lebih kecil dari nama objek pes2, fungsi ini mengembalikan nilai true. Fungsi ini berguna ketika kita ingin melakukan pengurutan objek PesRental berdasarkan atribut nama.
    return pes1.nama < pes2.nama;
}

int cariPesanan(const vector<PesRental>& pesanan, const string& namaPemesan) { // Fungsi ini menerima dua parameter. Parameter pertama adalah vektor (vector) dengan tipe data const vector<PesRental>& yang disebut pesanan. Parameter kedua adalah sebuah string (string) dengan tipe data const string& yang disebut namaPemesan. Fungsi ini bertujuan untuk mencari objek PesRental dalam vektor pesanan berdasarkan atribut namaPemesan. Fungsi ini melakukan iterasi melalui setiap elemen vektor pesanan menggunakan loop for. Jika nilai nama pada objek pesanan[i] sama dengan namaPemesan, fungsi ini akan mengembalikan indeks i. Jika tidak ditemukan objek dengan nama yang sesuai, fungsi ini mengembalikan nilai -1. Fungsi ini berguna ketika kita ingin mencari informasi tentang pesanan berdasarkan nama pemesan dalam vektor pesanan.
    for (int i = 0; i < pesanan.size(); i++) {
        if (pesanan[i].nama == namaPemesan) {
            return i;
        }
    }
    return -1;
}

void tampilkanMenuPes() { // Fungsi ini bertujuan untuk menampilkan menu pilihan terkait dengan penyewaan konsol game PS (PlayStation) beserta harga sewanya.
    cout << "Menu PES:" << endl;
    cout << "1. PS 2 - Harga: Rp.5000/jam" << endl;
    cout << "2. PS 3 - Harga: Rp.6000/jam" << endl;
    cout << "3. PS 4 - Harga: Rp.10000/jam" << endl;
    cout << "4. PS 5 - Harga: Rp.15000/jam" << endl;
    cout << "5. Kembali ke menu utama" << endl;
}
// tarif dan didi
double getPesHarga(int pilihanPes) { // Fungsi ini memiliki fungsi untuk mengembalikan harga sesuai dengan pilihan pesanan yang diberikan. Fungsi ini menggunakan pernyataan switch untuk memeriksa nilai pilihanPes dan mengembalikan harga yang sesuai dengan setiap pilihan yang mungkin.
    switch (pilihanPes) {
        case 1:
            return 5.0;
        case 2:
            return 6.0;
        case 3:
            return 7.0;
        case 4:
            return 8.0;
        default:
            return 0.0;
    }
}

void hapusPesanan(PesRental*& head, PesRental*& tail, const string& namaPemesan) {
    if (head == NULL) {
        return;
    } // Fungsi ini memiliki fungsi untuk menghapus pesanan dengan nama pemesan tertentu dari daftar pesanan.

    // Hapus pesanan dari awal linked list jika nama pemesan cocok
    while (head != NULL && head->nama == namaPemesan) {
        PesRental* temp = head;
        head = head->next;
        delete temp;
    }

    // Hapus pesanan dari tengah atau akhir linked list jika nama pemesan cocok
    PesRental* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->nama == namaPemesan) {
            PesRental* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    // Perbarui ekor linked list jika pesanan terakhir dihapus
    if (head != NULL && head->next == NULL) {
        tail = head;
    }
}

int main() {
    PesRental* head = NULL;  // Pointer ke kepala linked list
    PesRental* tail = NULL;  // Pointer ke ekor linked list

    cout << "Selamat datang di layanan pemesanan rental PlayStation!" << endl;

    int opsi;// Variabel opsi bertipe data int digunakan untuk menyimpan pilihan opsi yang dimasukkan oleh pengguna.
    do { // Dalam blok do-while, program akan terus menampilkan menu opsi dan mengambil input dari pengguna sampai pengguna memilih opsi untuk keluar (opsi 6).
        cout << endl;
        cout << "Pilih salah satu opsi:" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Tampilkan Semua Pesanan" << endl;
        cout << "3. Urutkan Pesanan" << endl;
        cout << "4. Cari Pesanan" << endl;
        cout << "5. Hapus Pesanan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Opsi: ";
        cin >> opsi;
        cin.ignore();// Setelah menerima input opsi, pernyataan cin.ignore() digunakan untuk mengabaikan karakter newline yang tertinggal di buffer masukan setelah memasukkan angka.
        system("cls"); // Pernyataan system("cls") digunakan untuk membersihkan layar konsol, sehingga tampilan menu selanjutnya akan ditampilkan di bagian atas layar.
//habib dan rizki
        switch (opsi) { // Fungsi dari bagian ini adalah untuk memungkinkan pengguna memasukkan rincian pesanan dan memilih jenis pes yang diinginkan. Jika pengguna memilih keluar (opsi 5), maka objek pesanan yang dialokasikan secara dinamis akan dihapus sebelum keluar dari menu pesanan.
            case 1: {
                PesRental* pes = new PesRental;

                cout << "Silakan masukkan rincian pesanan Anda." << endl;

                cout << "Nama Pemesan: ";
                getline(cin, pes->nama);

                cout << "Durasi Rental (dalam jam): ";
                cin >> pes->durasi;

                int pilihanPes;
                do {
                    tampilkanMenuPes();
                    cout << "Pilihan Pes: ";
                    cin >> pilihanPes;
                    system("cls");
                } while (pilihanPes < 1 || pilihanPes > 5);

                if (pilihanPes == 5) {
                    delete pes;
                    break;
                }

                pes->jumlahPes = 1;
                pes->harga = getPesHarga(pilihanPes);

                pes->next = NULL;

                if (head == NULL) {
                    // Linked list kosong
                    head = pes;
                    tail = pes;
                } else {
                    // Sambungkan pesanan baru ke ekor linked list
                    tail->next = pes;
                    tail = pes;
                }

                break;
            }
            case 2: {
                if (head == NULL) {
                    cout << "Belum ada pesanan yang tersimpan." << endl;
                } else {
                    PesRental* temp = head;
                    cout << "Daftar Pesanan:" << endl;
                    while (temp != NULL) {
                        tampilkanPesanan(*temp);
                        temp = temp->next;
                    }
                }
                break;
            }
            case 3: {
                if (head == NULL) {
                    cout << "Belum ada pesanan yang tersimpan." << endl;
                } else {
                    vector<PesRental> temp;
                    PesRental* current = head;
                    while (current != NULL) {
                        temp.push_back(*current);
                        current = current->next;
                    }
                    sort(temp.begin(), temp.end(), comparePesanan);

                    // Hapus semua node dalam linked list
                    while (head != NULL) {
                        PesRental* temp = head;
                        head = head->next;
                        delete temp;
                    }

                    // Buat linked list baru dengan urutan yang diurutkan
                    for (vector<PesRental>::const_iterator iter = temp.begin(); iter != temp.end(); ++iter) {
                        const PesRental& pes = *iter;
                        PesRental* newNode = new PesRental;
                        *newNode = pes;
                        newNode->next = NULL;

                        if (head == NULL) {
                            head = newNode;
                            tail = newNode;
                        } else {
                            tail->next = newNode;
                            tail = newNode;
                        }
                    }

                    cout << "Pesanan berhasil diurutkan berdasarkan nama pemesan." << endl;
                }
                break;
            }
            case 4: {
                if (head == NULL) {
                    cout << "Belum ada pesanan yang tersimpan." << endl;
                } else {
                    string namaPemesan;
                    cout << "Masukkan nama pemesan yang ingin dicari: ";
                    getline(cin, namaPemesan);

                    PesRental* current = head;
                    bool found = false;
                    while (current != NULL) {
                        if (current->nama == namaPemesan) {
                            tampilkanPesanan(*current);
                            found = true;
                        }
                        current = current->next;
                    }

                    if (!found) {
                        cout << "Pesanan dengan nama pemesan tersebut tidak ditemukan." << endl;
                    }
                }
                break;
            }
            case 5: {
                if (head == NULL) {
                    cout << "Belum ada pesanan yang tersimpan." << endl;
                } else {
                    string namaPemesan;
                    cout << "Masukkan nama pemesan yang ingin dihapus: ";
                    getline(cin, namaPemesan);

                    hapusPesanan(head, tail, namaPemesan);

                    cout << "Pesanan berhasil dihapus." << endl;
                }
                break;
            }
            case 6: {
                // Hapus semua node dalam linked list sebelum keluar
                while (head != NULL) {
                    PesRental* temp = head;
                    head = head->next;
                    delete temp;
                }
                cout << "Terima kasih telah menggunakan layanan pemesanan rental PlayStation!" << endl;
                break;
            }
            default:
                cout << "Opsi yang Anda pilih tidak valid. Silakan coba lagi." << endl;
        }
    } while (opsi != 6);
//rifki dan indah
    return 0;
}