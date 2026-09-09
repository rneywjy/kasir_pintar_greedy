# Kalkulator Kembalian Kasir (C)

Program ini adalah simulasi mesin kasir yang bertugas memberikan kembalian dengan jumlah lembar uang sesedikit mungkin. Program ini dibangun menggunakan algoritma *greedy* dan dilengkapi dengan teknik validasi input yang ketat untuk mencegah terjadinya *runtime error*.

## Fitur Utama
* **Algoritma Greedy**: Menghitung rincian pecahan kembalian mulai dari Rp100.000 hingga Rp1.000 secara efisien.
* **Validasi Input Anti-Error**: Memastikan pengguna hanya memasukkan angka (tanpa huruf atau simbol lain), sehingga program tidak *crash* saat dijalankan.
* **Lintas Platform (Cross-Platform)**: Fungsi jeda waktu (`molor()`) menggunakan *C preprocessor* agar kompatibel di Windows maupun macOS/Linux.
* **Manajemen Stok**: Memastikan uang kembalian tidak melebihi stok uang tunai (masing-masing pecahan berjumlah 10 lembar) yang tersedia di kasir.

## Cara Instalasi dan Penggunaan
1. Pastikan kamu sudah memiliki *compiler* C (seperti GCC) yang terinstal di komputermu.
2. Buka terminal atau *command prompt*, lalu arahkan ke direktori tempat file `tes2.c` berada.
3. Kompilasi program dengan menjalankan perintah berikut:
   ```bash
   gcc tes2.c -o kasir
   ```
4. Jalankan program hasil kompilasi:
   * **Pengguna Mac/Linux:** `./kasir`
   * **Pengguna Windows:** `kasir.exe`
5. Ikuti instruksi di layar dengan memasukkan jumlah belanja dan uang pembayaran.

## Kredit & Lisensi
* **Author**: Roney Wijaya
* **Lisensi**: MIT License (Bebas digunakan dan dimodifikasi dengan tetap menyertakan kredit kepada penulis asli).
