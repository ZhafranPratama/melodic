# Melodic

### Deskripsi Aplikasi
Melodic adalah aplikasi pemutar musik berbasis C++ dengan menerapkan konsep struktur data double linked list dan multi linked list. Aplikasi ini memungkinkan pengguna untuk mengelola data lagu, playlist, serta memutar lagu baik dari daftar lagu utama maupun dari playlist pribadi.

Aplikasi Melodic mendukung sistem multi-user dengan dua peran, yaitu Admin dan User. Admin berperan dalam pengelolaan data lagu, sedangkan User dapat memutar lagu, mengelola playlist, menambahkan lagu favorit, melihat riwayat pemutaran lagu, serta mendapatkan rekomendasi lagu berdasarkan mood user.

### Fitur Fitur
- Sistem Login
1. Login sebagai Admin atau User
2. Validasi username dan password
3. Setiap user memiliki data playlist masing-masing

- Fitur Admin
1. Menambahkan lagu ke daftar lagu utama
2. Menghapus lagu dari daftar lagu dan seluruh playlist user
3. Mengedit informasi lagu (judul, artis, genre, dan durasi)
4. Melihat seluruh daftar lagu
5. Manajemen data lagu

- Fitur User
1. Menampilkan seluruh daftar lagu
2. Memutar lagu berdasarkan judul atau secara acak
3. Navigasi lagu
4. Pemutaran lagu berdasarkan genre yang sama
5. Manajemen Playlist
6. Rekomendasi Lagu Berdasarkan Mood
7. History Lagu

### Cara menjalankan program:
1. Build project dengan:
```g++ *.cpp -o melodic ```
2. Jalankan project dengan:
```melodic.exe```

Project ini merupakan hasil tugas besar implementasi struktur data yang dikerjakan oleh Muhammad Zhafran Pratama dan Michelle Angelina Wijaya
