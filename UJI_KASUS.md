# Dokumentasi Uji Kasus (Test Cases)

Berikut adalah log pengujian langsung dari terminal (raw output) untuk memverifikasi keamanan (*error handling*) dan fungsionalitas algoritma greedy pada program kasir.

## 1. Pengujian Keamanan & Validasi (Error Handling)

### A. Validasi Input Karakter (Mencegah Runtime Error)
Menguji fungsionalitas `validasiInput()` dan `cekAngka()` yang memastikan semua karakter yang dimasukkan murni angka numerik. Program akan menolak huruf atau simbol.
```console
Jumlah belanja Anda (Rp): abcd100
Jumlah bayar Anda (Rp): defgh900

Tolong masukkan input yang valid!

Jumlah belanja Anda (Rp): 
```

### B. Validasi Input Nilai Nol
Memastikan program menolak input bernilai nol pada variabel `belanja` maupun `bayar` untuk mencegah kesalahan flow program.
```console
Jumlah belanja Anda (Rp): 0
Jumlah bayar Anda (Rp): 100000

Tolong masukkan jumlah uang!

Jumlah belanja Anda (Rp): 
```
```console
Jumlah belanja Anda (Rp): 100000
Jumlah bayar Anda (Rp): 0

Tolong masukkan jumlah uang!

Jumlah belanja Anda (Rp): 
```

## 2. Pengujian Logika Kasir & Batas (Boundary Cases)

### A. Uang Pembeli Kurang
Menguji sistem verifikasi keamanan jika uang yang dimasukkan lebih kecil dari tagihan (`kembalian < 0`).
```console
Jumlah belanja Anda (Rp): 100000
Jumlah bayar Anda (Rp): 50000

Maaf, uang Anda tidak cukup!

Jumlah belanja Anda (Rp): 
```

### B. Uang Pembeli Pas
Menguji kondisi eksekusi program jika tagihan terbayar lunas tanpa sisa (`kembalian == 0`).
```console
Jumlah belanja Anda (Rp): 100000
Jumlah bayar Anda (Rp): 100000

Uang Anda pas!

Terima kasih telah berbelaja!
```

### C. Uang Kasir Tidak Mencukupi (Over-limit Kembalian)
Menguji batas ketersediaan dana kasir. Program secara dinamis menghitung limit kasir dan memblokir transaksi jika kembalian melebihi total dana yang ada di laci.
```console
Jumlah belanja Anda (Rp): 10000
Jumlah bayar Anda (Rp): 3000000

Maaf, uang di kasir tidak cukup untuk kembalian Anda!

Jumlah belanja Anda (Rp): 
```

### D. Pengurasan Total Uang Kasir (Maximum Extrema Limit)
Menguji skenario batas maksimal ekstrem di mana kembalian memakan **seluruh** uang di dalam kasir secara pas (Rp1.880.000 atau total 70 lembar). Ini membuktikan bahwa array struct `Pecahan` dan variabel iterasi `kasir[i].stok--` bekerja sempurna tanpa menyebabkan *underflow* stok.
```console
Jumlah belanja Anda (Rp): 1   
Jumlah bayar Anda (Rp): 1880001

Daftar pecahan dan jumlahnya dari kembalian: Rp1880000

Pecahan Rp100000 sebanyak 10 lembar.
Pecahan Rp50000 sebanyak 10 lembar.
Pecahan Rp20000 sebanyak 10 lembar.
Pecahan Rp10000 sebanyak 10 lembar.
Pecahan Rp5000 sebanyak 10 lembar.
Pecahan Rp2000 sebanyak 10 lembar.
Pecahan Rp1000 sebanyak 10 lembar.

Jumlah lembar: 70 lembar

Terima kasih telah berbelanja!
```

## 3. Pengujian Algoritma Greedy (Skenario Normal)
Mengevaluasi akurasi dan efisiensi algoritma untuk meminimalisir jumlah lembaran uang fisik yang diberikan kepada pelanggan.

### Kasus A: Kombinasi Pecahan Beragam (Rp177.000)
Algoritma secara akurat turun ke nilai pecahan yang lebih kecil setelah mengurangi lembar dengan pecahan yang paling besar terlebih dahulu.
```console
Jumlah belanja Anda (Rp): 123000
Jumlah bayar Anda (Rp): 300000

Daftar pecahan dan jumlahnya dari kembalian: Rp177000

Pecahan Rp100000 sebanyak 1 lembar.
Pecahan Rp50000 sebanyak 1 lembar.
Pecahan Rp20000 sebanyak 1 lembar.
Pecahan Rp5000 sebanyak 1 lembar.
Pecahan Rp2000 sebanyak 1 lembar.

Jumlah lembar: 5 lembar

Terima kasih telah berbelanja!
```

### Kasus B: Melompati Pecahan Menengah (Rp107.000)
Mengecek apakah algoritma pintar melewatkan iterasi pecahan yang tidak digunakan (seperti Rp50.000, Rp20.000, Rp10.000) ketika tidak dibutuhkan.
```console
Jumlah belanja Anda (Rp): 93000
Jumlah bayar Anda (Rp): 200000

Daftar pecahan dan jumlahnya dari kembalian: Rp107000

Pecahan Rp100000 sebanyak 1 lembar.
Pecahan Rp5000 sebanyak 1 lembar.
Pecahan Rp2000 sebanyak 1 lembar.

Jumlah lembar: 3 lembar

Terima kasih telah berbelanja!
```

### Kasus C: Pencatatan Stok Ganda (Rp97.000)
Menunjukkan bahwa algoritma dapat mengambil beberapa lembar dari nominal pecahan yang sama, sehingga stok Rp20.000 tercatat berkurang 2 lembar.
```console
Jumlah belanja Anda (Rp): 303000
Jumlah bayar Anda (Rp): 400000

Daftar pecahan dan jumlahnya dari kembalian: Rp97000

Pecahan Rp50000 sebanyak 1 lembar.
Pecahan Rp20000 sebanyak 2 lembar.
Pecahan Rp5000 sebanyak 1 lembar.
Pecahan Rp2000 sebanyak 1 lembar.

Jumlah lembar: 5 lembar

Terima kasih telah berbelanja!
```
