# Proglan-NAZI-PROJECT-TANK-

Tugas Mata Kuliah Pemrograman Lanjut (2020)

Program permainan yang menggunakan pustaka SFML (Simple and Fast Multimedia Library) untuk grafis dan audio.

untuk lebih detail dapat dilihat pada laporan

https://youtu.be/Q9eFCcpZfP0

## Komponen Utama:

Header Files: 
- #include <SFML/Graphics.hpp>: Untuk grafis.
- #include <SFML/Window.hpp>: kanvas/jendela permainan.
- #include <SFML/Audio.hpp>: Untuk audio.
- #include <iostream>: Untuk input/output standar.
- #include <Windows.h>: Untuk fungsi Windows.
- #include <vector>: Untuk penggunaan vektor.
- #include <math.h>: Untuk fungsi matematika.

Konstanta dan Variabel Global:
- bKiri, bKanan: Batas kiri dan kanan untuk posisi objek.
- rSpeed, airspeed: Kecepatan rudal dan kecepatan udara.
- scoreTank1, scoreTank2, scoreHitler: Skor awal untuk dua pemain dan target.
- screenx, screeny: Ukuran layar.
- tank1x, tank1y, tank2x, tank2y: Posisi awal tank.

Bagian Program:
- Menu dan Tutorial: Membuat jendela untuk menu utama dan tutorial dengan menggunakan gambar latar belakang dan musik.
- Game Window: Menyediakan kanvas/jendela utama permainan dengan ukuran 1600x900 piksel.
- Elemen Grafis dan Audio: Mengatur berbagai elemen grafis seperti latar belakang, tank, rudal, dan airdrop. Juga memuat berbagai file audio untuk efek suara dan musik latar.
- Logika Permainan: Mengontrol pergerakan tank menghindari peluru dari lawan.
- Pengendalian Input: Mengatur pergerakan tank dengan menggunakan input keyboard (W, A, S, D untuk tank 1 dan tombol arrowkey untuk tank 2).

###Fungsionalitas Kunci:
- Menu dan Tutorial: Menampilkan menu awal, tutorial, dan skor dengan musik latar dan gambar.
- Jendela Permainan: Menyediakan tampilan grafis untuk permainan, termasuk tank, rudal, dan airdrop.
- Audio: Memutar efek suara untuk tembakan, tabrakan, dan musik latar.
- Kontrol Permainan: Mengatur gerakan tank, peluru, dan logika tabrakan untuk menentukan skor.
