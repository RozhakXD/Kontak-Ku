#include <iostream>
#include <string>
using namespace std;

// DEKLARASI FUNGSI GLOBAL //
void TambahkanStack(string nama, string nomor, string kategori);
void TambahkanQueue(string nama, string nomor, string kategori);

// DEKLARASI GLOBAL STACK //
const int stackMaksimal = 100;
string arrayFull_Name[stackMaksimal];
string arrayNomor[stackMaksimal];
string arrayKategori[stackMaksimal];
int top = 0;

// DEKLARASI GLOBAL QUEUE //
const int queueMaksimal = 100;
string queueFull_Name[queueMaksimal];
string queueNomor[queueMaksimal];
string queueKategori[queueMaksimal];
int front = 0;
int back = 0;

// LINKED LIST //
class Linked {
    public: string full_name;
    public: string nomor;
    public: string kategori;
    Linked * prev;
    Linked * next;
};

class LinkedList {
    public: Linked * head;
    Linked * tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void Tambahkan(string nama, string nomor, string kategori, Linked * next_ptr = nullptr) {
        Linked * newNode = new Linked;
        newNode -> full_name = nama;
        newNode -> nomor = nomor;
        newNode -> kategori = kategori;
        newNode -> prev = nullptr;
        newNode -> next = nullptr;
        if (next_ptr == nullptr) {
            if (head != nullptr) {
                tail -> next = newNode;
            } else {
                head = newNode;
            }
            tail = newNode;
        } else {
            newNode -> next = next_ptr -> next;
            next_ptr -> next -> prev = newNode;
            next_ptr -> next = newNode;
            newNode -> prev = next_ptr;
        }
    }

    void Pencarian_Dengan_Nama(string nama) {
        bool found = false;
        if (head == nullptr) {
            cout << "\nPenyimpanan Linked List Kosong!\n" << endl;
        } else {
            Linked * tampilkan = head;
            cout << endl;
            while (tampilkan != nullptr) {
                if (tampilkan -> full_name == nama) {
                    cout << "Full Name: " << tampilkan -> full_name << endl;
                    cout << "Nomor    : " << tampilkan -> nomor << endl;
                    cout << "Kategori : " << tampilkan -> kategori << "\n" << endl;
                    found = true;
                }
                tampilkan = tampilkan -> next;
            }
            if (!found) {
                cout << "Kontak Dengan Nama " << nama << " Tidak Ditemukan!\n" << endl;
            }
        }
    }

    void Pengurutan() { // BINARY SEARCH //
        bool sorted = false;
        while (sorted == false) {
            Linked * current = head;
            sorted = true;
            while (current && current -> next) {
                if (current -> full_name > current -> next -> full_name) {
                    swap(current -> full_name, current -> next -> full_name);
                    swap(current -> nomor, current -> next -> nomor);
                    swap(current -> kategori, current -> next -> kategori);
                    sorted = false;
            }
            current = current -> next;
            }
        }
    }

    void Tampilkan() {
        if (head == nullptr) {
            cout << "\nTidak Ada Pengguna Untuk Ditampilkan!" << endl;
        } else {
            Linked * tampilkan = head;
            while (tampilkan != nullptr) {
                cout << "\nFull Name: " << tampilkan -> full_name << endl;
                cout << "Nomor    : " << tampilkan -> nomor << endl;
                cout << "Kategori : " << tampilkan -> kategori << endl;
                tampilkan = tampilkan -> next;
            }
        }
    }

    void Tambahkan_Ke_Stack() {
        if (head == nullptr) {
            cout << "\nHarap Tambahkan Data Kontak Terlebih Dahulu!" << endl;
        } else {
            Linked * Stack = head;
            while (Stack != nullptr) {
                TambahkanStack(Stack -> full_name, Stack -> nomor, Stack -> kategori);
                Stack = Stack -> next;
            }
        }
    }

    void Tambahkan_Ke_Queue() {
        if (head == nullptr) {
            cout << "\nHarap Tambahkan Data Kontak Terlebih Dahulu!" << endl;
        } else {
            Linked * Queue = head;
            while (Queue != nullptr) {
                TambahkanQueue(Queue -> full_name, Queue -> nomor, Queue -> kategori);
                Queue = Queue -> next;
            }
        }
    }
};

// STACK //
void TambahkanStack(string nama, string nomor, string kategori) {
    if (top == stackMaksimal) {
        cout << "\nMaaf, Data Dalam Stack Sudah Penuh!" << endl;
    } else {
        arrayFull_Name[top] = nama;
        arrayNomor[top] = nomor;
        arrayKategori[top] = kategori;
        top ++;
    }
}

void ClearStack() {
    for (int i = top; i >= 0; i--) {
        arrayFull_Name[i] = "";
        arrayNomor[i] = "";
        arrayKategori[i] = "";
    }
    top = 0;
}

void Pencarian_Dengan_Nomor(string nomor) {
    bool found = false;
    cout << endl;
    for (int i = top -1; i >= 0; i--){
        if (arrayNomor[i] == nomor) {
            cout << "Full Name: " << arrayFull_Name[i] << endl;
            cout << "Nomor    : " << arrayNomor[i] << endl;
            cout << "Kategori : " << arrayKategori[i] << "\n" << endl;
            found = true;
        }
    }
    if (!found){
        cout << "Kontak Dengan Nomor " << nomor << " Tidak Ditemukan!\n" << endl;
    }
}

// QUEUE //
void TambahkanQueue(string nama, string nomor, string kategori) {
    if (back == queueMaksimal){
        cout << "Maaf, Antrian Queue Telah Penuh!" << endl;
    } else {
        if (back == 0) {
            queueFull_Name[0] = nama;
            queueNomor[0] = nomor;
            queueKategori[0] = kategori;
            front ++;
            back ++;
        } else {
            queueFull_Name[back] = nama;
            queueNomor[back] = nomor;
            queueKategori[back] = kategori;
            back ++;
        }
    }
}

void ClearQueue() {
    for (int i = 0; i < back; i++) {
        queueFull_Name[i] = "";
        queueNomor[i] = "";
        queueKategori[i] = "";
    }
    front = 0;
    back = 0;
}

void Pencarian_Dengan_Kategori(string kategori) {
    bool found = false;
    cout << endl;
    for (int i = 0; i < queueMaksimal; i++) {
        if (queueFull_Name[i] != "" && queueKategori[i] == kategori) {
            cout << "Full Name: " << queueFull_Name[i] << endl;
            cout << "Nomor    : " << queueNomor[i] << endl;
            cout << "Kategori : " << queueKategori[i] << "\n" << endl;
            found = true;
        } else {
            continue;
        }
    }
    if (!found) {
        cout << "Kontak Dengan Kategori " << kategori << " Tidak Ditemukan!\n" << endl;
    }
}

int Mengulangi(char pilihan) {
    if (pilihan == 't' || pilihan == 'T') {
        return (6);
    } else {
        return (1);
    }
}

int main(){
    LinkedList linkedlist;
    char tanyakan;
    int pilihan;

    do {
        system("clear"); // MEMBERSIHKAN TERMINAL DI LINUX
        cout << "╔╦╗┬ ┬  ╔═╗┌─┐┌┐┌┌┬┐┌─┐┌─┐┌┬┐" << endl;
        cout << "║║║└┬┘  ║  │ ││││ │ ├─┤│   │ " << endl;
        cout << "╩ ╩ ┴   ╚═╝└─┘┘└┘ ┴ ┴ ┴└─┘ ┴ \n" << endl;

        //system("cls"); // MEMBERSIHKAN TERMINAL DI WINDOWS
        //cout << "===============================" << endl;
        //cout << "    Pengelolaan Kontak C++" << endl;
        //cout << "===============================\n" << endl;

        cout << "1. Menyimpan Data Kontak" << endl;
        cout << "2. Cari Kontak Berdasarkan Nomor" << endl;
        cout << "3. Cari Kontak Berdasarkan Nama" << endl;
        cout << "4. Cari Kontak Berdasarkan Kategori" << endl;
        cout << "5. Tampilkan Seluruh Kontak" << endl;
        cout << "6. Keluar Dari Program\n" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan){
            case 0:
                {
                    cout << "Anda Harus Memilih Dari Nomor 1-6!" << endl;
                    pilihan = Mengulangi('T');
                    break;
                }
            case 1:
                {
                    string nama, nomor, kategori;
                    cout << "\nNama Kontak (ex:Rizky): ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Nomor (ex:+6257..): ";
                    cin >> nomor;
                    cout << "Kategori (ex:#Teman): ";
                    cin >> kategori;

                    linkedlist.Tambahkan(nama, nomor, kategori);

                    cout << "\nBerhasil Menyimpan Kontak Ke Database!" << endl;
                    cout << "\nIngin Mengulangi Program (Y/T): ";
                    cin >> tanyakan;
                    pilihan = Mengulangi(tanyakan);
                    break;
                }
            case 2:
                {
                    string nomor;
                    cout << "Masukan Nomor (ex:+6257..): ";
                    cin >> nomor;
                    if (top != 0) {
                        ClearStack();
                    }
                    linkedlist.Tambahkan_Ke_Stack();
                    Pencarian_Dengan_Nomor(nomor);
                    cout << "Ingin Mengulangi Program (Y/T): ";
                    cin >> tanyakan;
                    pilihan = Mengulangi(tanyakan);
                    break;
                }
            case 3:
                {
                    string nama;
                    cout << "Masukan Nama (ex:Sindy): ";
                    cin.ignore();
                    getline(cin, nama);
                    linkedlist.Pencarian_Dengan_Nama(nama);
                    cout << "Ingin Mengulangi Program (Y/T): ";
                    cin >> tanyakan;
                    pilihan = Mengulangi(tanyakan);
                    break;
                }
            case 4:
                {
                    string kategori;
                    cout << "Masukan Kategori (ex:#Keluarga): ";
                    cin >> kategori;
                    if (back != 0) {
                        ClearQueue();
                    }
                    linkedlist.Tambahkan_Ke_Queue();
                    Pencarian_Dengan_Kategori(kategori);
                    cout << "Ingin Mengulangi Program (Y/T): ";
                    cin >> tanyakan;
                    pilihan = Mengulangi(tanyakan);
                    break;
                }
            case 5:
                {
                    linkedlist.Pengurutan();
                    linkedlist.Tampilkan();
                    cout << "\nIngin Mengulangi Program (Y/T): ";
                    cin >> tanyakan;
                    pilihan = Mengulangi(tanyakan);
                    break;
                }
            case 6:
                {
                    cout << "Terimakasih Telah Menggunakan Program Ini!" << endl;
                    pilihan = Mengulangi('T');
                    break;
                }
            default:
                {
                    cout << "Maaf, Pilihan Yang Anda Masukan Tidak Valid!" << endl;
                    break;
                }
        }
    } while (pilihan != 6);

    return 0;
}