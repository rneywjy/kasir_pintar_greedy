/*
    Seorang kasir diberikan tugas untuk memberikan kembalian dengan jumlah
    lembar uang sesedikit mungkin. Pecahan uang yang tersedia adalah:
    Rp50.000, Rp20.000, Rp10.000, Rp5.000, Rp2.000, dan Rp1.000. Semua
    pecahan tersebut memiliki jumlah 10 lembar. Kembalian pembeli dapat
    bermacam-macam selama tidak melewati jumlah uang yang ada di kasir.

    Program ini menggunakan algoritma greedy. Dilengkapi dengan teknik-
    teknik bahasa C untuk memvalidasi input pengguna agar tidak terjadi
    runtime error (error saat program berjalan).

    Author: Roney Wijaya
*/

#include <stdio.h>
#include <string.h> // Untuk strlen()
#include <stdlib.h> // Untuk atoi()

/*
    Membuat fungsi sleep() bekerja di Windows maupun Mac/Linux
    dengan bantuan preprocessor. Kemudian mengimplementasikannya
    ke sebuah fungsi baru.
*/
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void molor(int detik){
    #ifdef _WIN32
        Sleep(detik * 1000);
    #else
        sleep(detik);
    #endif
}

/*
    Membuat tipe data buatan bernama "Pecahan" dengan struct yang berisi dua
    variabel integer, yaitu nilai untuk nilai uangnya dan stok untuk stok
    uangnya. Menggunakan typedef agar tidak perlu mengulangi kata kunci
    "struct" setiap kali deklarasi tipe data Pecahan ini. Tujuan dari variabel
    bautan ini adalah untuk memudahkan proses organisir data.
*/
typedef struct {
    int nilai;
    int stok;
} Pecahan;

/*
    *** Function prototype ***
    1. cekAngka untuk mengecek apakah suatu char adalah angka atau bukan.
        Akan mengembalikan 1 (true) jika char tersebut adalah angka.
    2. validasiInput untuk mengecek apakah suatu string memiliki char selain
        angka di dalamnya. Akan mengambalikan 1 (true) jika string tersebut
        tidak memiliki char selain angka di dalamnya.
*/
int cekAngka(char karakter);
int validasiInput(char input[50]);

int main(){
    /*
        Deklarasi variabel Pecahan untuk uang di kasir dan catatan untuk
        mendata jumlah pecahan uang yang digunakan.
    */
    Pecahan kasir[] = {
        {100000, 10},
        {50000, 10},
        {20000, 10},
        {10000, 10},
        {5000, 10},
        {2000, 10},
        {1000, 10}
    };

    Pecahan catatan[] = {
        {100000, 0},
        {50000, 0},
        {20000, 0},
        {10000, 0},
        {5000, 0},
        {2000, 0},
        {1000, 0}
    };

    // Menghitung jumlah pecahan uang di kasir secara dinamis dengan sizeof()
    int jumlahPecahan = sizeof(kasir)/sizeof(kasir[0]);

    // Menghitung jumlah uang di kasir
    int jumlahUang = 0;

    for (int i = 0; i < jumlahPecahan; i++){
        jumlahUang += kasir[i].nilai * kasir[i].stok;
    }

    // Membuat variabel untuk menampung uang belanja, bayar, dan kembalian
    int belanja = 0, bayar = 0, kembalian = 0;

    // Membuat variabel string untuk input validasi nanti
    char input_belanja[50] = {0};
    char input_bayar[50] = {0};

    // Looping input
    do {
        printf("Jumlah belanja Anda (Rp): ");
        fgets(input_belanja, sizeof(input_belanja), stdin);
        input_belanja[strlen(input_belanja) - 1] = '\0';

        printf("Jumlah bayar Anda (Rp): ");
        fgets(input_bayar, sizeof(input_bayar), stdin);
        input_bayar[strlen(input_bayar) - 1] = '\0';

        // Jika user memasukkan selain angka, maka kembali input dengan continue
        if (validasiInput(input_belanja) == 0 || validasiInput(input_bayar) == 0){
            printf("\nTolong masukkan input yang valid!\n\n");
            molor(1);
            continue;
        }

        /*
            Jika berhasil melewati pengecekan di atas, ubah variabel
            belanja, bayar ke integer dan hitung kembalian
        */
        belanja = atoi(input_belanja);
        bayar = atoi(input_bayar);

        kembalian = bayar - belanja;

        // Jika user memasukkan 0 pada belanja atau bayar maka kembali input
        if (belanja == 0 || bayar == 0){
            printf("\nTolong masukkan jumlah uang!\n\n");
            molor(1);
            continue;
        }

        // Mengecek kembalian
        if (kembalian > jumlahUang) {
            printf("\nMaaf, uang di kasir tidak cukup untuk kembalian Anda!\n\n");
            molor(1);
            continue;
        } else if (kembalian < 0) {
            printf("\nMaaf, uang Anda tidak cukup!\n\n");
            molor(1);
            continue;
        }

        // Jika berhasil melewati semua pengecekan, maka keluar dari loop
        break;
    } while (1);

    /*
        Melaksanakan algoritma greedy. Membuat penghitung i = 0 dan looping
        dengan kondisi selama i < jumlahPecahan. Kemudian mengecek apakah
        pecahan pada indeks i kurang dari sama dengan kembalian. Jika iya,
        kurangkan kembalian dengan nilai pecahan tersebut dan stoknya di kasir
        berkurang dan catatan pecahan tersebut bertambah. Sebelum mengurangi
        habis kembalian dengan algoritma greedy, simpan nilai kembalian tersebut
        ke variabel lain untuk keperluan cetak hasil akhir.
    */
    int i = 0;
    int kembaliansss = kembalian;

    while (i < jumlahPecahan){
        if (kasir[i].nilai <= kembalian && kasir[i].stok > 0){
            kembalian -= kasir[i].nilai;
            kasir[i].stok--;
            catatan[i].stok++;
        } else { i++; }
    }

    /*
        Cetak hasil dan mengecek apakah kembaliansss = 0. Jika iya, maka cetak
        "uang pas". Jika tidak, cetak semua pecahan yang digunakan dengan
        mengecek apakah stok di variabel pencatatan lebih dari nol.
    */

    int jumlahLembar = 0;

    if (kembaliansss == 0){
        molor(1);
        printf("\nUang Anda pas!\n");
        molor(1);
        printf("\nTerima kasih telah berbelaja!\n");
    } else {
        printf("\nDaftar pecahan dan jumlahnya dari kembalian: Rp%d\n\n", kembaliansss);
        molor(1);
    
        for (int i = 0; i < jumlahPecahan; i++){
            if (catatan[i].stok > 0){
                printf("Pecahan Rp%d sebanyak %d lembar.\n", kasir[i].nilai, catatan[i].stok);
                jumlahLembar += catatan[i].stok;
            }
        }
        molor(1);
        printf("\nJumlah lembar: %d lembar\n", jumlahLembar);
        molor(1);
        printf("\nTerima kasih telah berbelanja!\n");
    }
    return 0;
}

// Implementasi dari function prototype
int cekAngka(char karakter){
    if (karakter >= '0' && karakter <= '9'){
        return 1;
    }
    return 0;
}
// Memanfaatkan function cekAngka yang sudah dibuat
int validasiInput(char input[50]){
    // Jika panjang inputnya nol, maka kembalikan 0 (false)
    if (strlen(input) == 0) { return 0; }

    /*
        Jika ada satu saja char di dalam string input
        yang bukan angka, maka kembalikan 0 (false)
    */
    for (int i = 0; i < strlen(input); i++){
        if (cekAngka(input[i]) == 1){
            continue;
        } else {
            return 0;
        }
    }

    /*
        Jika string input lolos dari pengecekan for loop,
        maka kembalikan 1 (true)
    */
    return 1;
}
