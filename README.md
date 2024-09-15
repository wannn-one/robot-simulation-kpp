# 🚀 Robot Simulation using A* and Manual Movement

## 📜 Project Overview

Program ini mensimulasikan pergerakan robot di peta grid 2D. Robot dapat bergerak dalam dua mode:

1. **Pergerakan Manual**: Robot bergerak berdasarkan urutan perintah manual (Atas, Bawah, Kiri, Kanan).
2. **Algoritma A***: Robot menggunakan algoritma A* untuk menemukan jalur terpendek dari posisi awal ('S') ke tujuan ('F').

Peta grid direpresentasikan sebagai vektor string, di mana:
- `S` adalah posisi awal robot.
- `F` adalah tujuan akhir robot.
- `.` adalah jalur yang dapat dilewati.
- `X` adalah dinding yang tidak bisa dilewati robot (kecuali setelah bertemu dengan mekanik).

### ⚙️ Features

- **Pergerakan manual**: Input perintah (`U`, `D`, `L`, `R`) untuk menggerakkan robot.
- **Algoritma A***: Temukan jalur terpendek secara otomatis dari `S` ke `F`.
- **Mekanik** (`M`): Robot dapat melewati dinding setelah bertemu dengan mekanik.
- **Electrical** (`E`): Robot dapat meningkatkan kecepatan menjadi 2x setelah bertemu dengan electrical.
- **Official** (`O`): Robot diajak membuat konten dengan official, sehingga menggandakan waktu perjalanan.
- **Programmer** (`P`): Easter egg! Robot bertemu dengan programmer yang membuat program ini.

## 📦 File Structure

Program ini terbagi menjadi 3 komponen utama:

1. Class

- Class `Node`
    - Digunakan dalam algoritma A* untuk merepresentasikan simpul pada peta grid.
    - Memiliki atribut seperti koordinat `(x, y)`, nilai `f`, `g`, `h`, dan pointer ke parent untuk tracking jalur.

- Class `Robot`
    - Mengelola pergerakan manual dan pencarian jalur menggunakan algoritma A*.
    - Mengatur posisi robot, kecepatan, dan interaksi dengan elemen khusus di peta (`M`, `E`, `O`, `P`).

2. File

Struktur file pada kedua mode pergerakan robot adalah sebagai berikut:

```
- 📂 include
    - 📄 node.hpp
    - 📄 robot.hpp
- 📂 src
    - 📄 node.cpp
    - 📄 robot.cpp
    - 📄 main.cpp
📄 Makefile
```

- `include/node.hpp`: Deklarasi class `Node` untuk algoritma A*.
- `include/robot.hpp`: Deklarasi class `Robot` untuk mengatur pergerakan robot.
- `src/node.cpp`: Implementasi class `Node`.
- `src/robot.cpp`: Implementasi class `Robot`.
- `src/main.cpp`: Program utama untuk menjalankan simulasi robot.

## 📝 How it works?

1. **Pergerakan Manual**
- Kamu memberikan urutan perintah (`U`, `D`, `L`, `R`) untuk menggerakkan robot secara manual.
- Robot bergerak di dalam peta sesuai dengan perintah ini.
- Setiap langkah memakan waktu 2 menit, kecuali diubah oleh elemen peta lainnya.
2. **Algoritma A***
- Robot secara otomatis menghitung jalur terpendek menggunakan algoritma A*.
- Robot akan bergerak di dalam grid, menghindari dinding (`X`) dan mencapai tujuan (`F`).
- Heuristik yang digunakan adalah jarak Manhattan (selisih baris dan kolom).

## 🚀 How to run?

Untuk meng-compile dan menjalankan program, kamu bisa menggunakan **Makefile** yang sudah disediakan.

1. **Compile Program**
```bash
make
```

2. **Run Program**
```bash
./robot
```

3. **Clean Program**
```bash
make clean
```

## 📄 Example Input and Output
### 1. Pergerakan Manual

Input

```
4 4
S...
....
....
...F
6
DDDRRR
```

Output

```
Robot berhasil mencapai tujuan
Robot telah berjalan selama 12 menit
```

### 2. Algoritma A*

Input

```
4 4
S...
....
....
...F
```

Output

```
Robot berhasil mencapai tujuan
Robot telah berjalan selama 12 menit
```

## 📚 References

- [A* Search Algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm)
- [Manhattan Distance](https://en.wikipedia.org/wiki/Taxicab_geometry)
- [C++ Standard Library](http://www.cplusplus.com/reference/)
- [Makefile Tutorial](https://makefiletutorial.com/)