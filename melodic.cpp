#include "melodic.h"

void login(userList L){
    string username, password;
    adrUser p;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    if (username == "admin" && password == "admin") {
        tampilanAdmin();
    }else {
        p = searchUserByUsn(L, username);
        if (p != nullptr) {
            if (password == p->password) {
                tampilanUser();
            } else {
                cout << "Password salah! Harap login kembali";
                login(L);
            }
        } else {
            cout << "User tidak valid! Harap login kembali";
            login(L);
        }
    }
}

void favSong(adrUser &u, adrSong s) {
    adrPlaylist p = u->firstPlaylist;
    addSongToPlaylist(p, s);
}

void songRecomendation(songList sL){
    adrSong p = sL.first;
    string mood;
    cout << "Mood saat ini apa?";
    cin >> mood;

    if (p == nullptr) {
        cout << "Tidak ada lagu yang tersedia.\n";
        return;
    }

    cout << "==== DAFTAR LAGU ====\n";

    while (p != nullptr) {
        if (mood == "Happy") {
            if (p->genre == "Pop" || p->genre == "Hip-Hop") {
                cout << "Title    : " << p->title << endl;
                cout << "Artist   : " << p->artist << endl;
                cout << "Genre    : " << p->genre << endl;
                cout << "Duration : " << p->duration << " detik\n";
                cout << "---------------------------\n";
            }
        } else if (mood == "Sad") {
            if (p->genre == "Ballad") {
                cout << "Title    : " << p->title << endl;
                cout << "Artist   : " << p->artist << endl;
                cout << "Genre    : " << p->genre << endl;
                cout << "Duration : " << p->duration << " detik\n";
                cout << "---------------------------\n";
            }
        } else if (mood == "Bersemangat") {
            if (p->genre == "Dangdut" || p->genre == "Rock") {
                cout << "Title    : " << p->title << endl;
                cout << "Artist   : " << p->artist << endl;
                cout << "Genre    : " << p->genre << endl;
                cout << "Duration : " << p->duration << " detik\n";
                cout << "---------------------------\n";
            }
        } else if (mood == "Santai") {
            if (p->genre == "Jazz" || p->genre == "Indie") {
                cout << "Title    : " << p->title << endl;
                cout << "Artist   : " << p->artist << endl;
                cout << "Genre    : " << p->genre << endl;
                cout << "Duration : " << p->duration << " detik\n";
                cout << "---------------------------\n";
            }
        } 
        p = p->next;
    }
}

adrUser searchUserByUsn(userList L, string username){
    adrUser p;
    p = L.first;
    while (p != nullptr && p->username != username) {
        p = p->next;
    }

    return p;
}

void createListUser(userList &L){
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyUser(userList L){
    return L.first == nullptr && L.last == nullptr;
}

bool isEmptyPlaylist(adrUser p){
    return p->firstPlaylist == nullptr;
}


adrUser createElemenUser(string username, string password){
    adrUser u;
    adrPlaylist p;
    string namaPlaylist = "Favorite Song";
    u = new elmUser;
    p = new elmPlaylist;
    p = createElemenPlaylist(namaPlaylist);

    u->username = username;
    u->password = password;
    u->next = nullptr;
    u->prev = nullptr;
    u->firstPlaylist = p;

    return u;
}

adrPlaylist createElemenPlaylist(string namaPlaylist){
    adrPlaylist q;
    q = new elmPlaylist;

    q->namaPlaylist= namaPlaylist;
    q->firstSong = nullptr;
    q->next = nullptr;
    q->prev = nullptr;

    return q;
}

void addUser(userList &L, adrUser p){
    string namaPlaylist = "Favorite Song";
    if (isEmptyUser(L)) {
        L.first = p;
        L.last = p;
    }else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void addPlaylist(adrUser &p, adrPlaylist q){
    adrPlaylist r;
    r = p->firstPlaylist;
    while (r->next != nullptr) {
        r = r->next;
    }
    r->next = q;
    q->prev = r;
}

adrSong createElemenSong(string artist, string title, string genre, int duration){
    adrSong q;
    q = new elmSong;

    q->artist= artist;
    q->title = title;
    q-> genre = genre;
    q-> duration = duration;
    q->next = nullptr;
    q->prev = nullptr;

    return q;
}

adrRelation createElemenRelation(adrSong song) {
    adrRelation r = new relation;

    r->Song = song;   
    r->next = nullptr;    
    r->prev = nullptr;

    return r;
}

void createListSong(songList &L){
    L.first = nullptr;
    L.last = nullptr;
}

void addSong(songList &L, adrSong p) {
    if (L.first == nullptr) {          
        L.first = p;
        L.last = p;
    } else {                           
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adrSong searchSongByTitle(songList L, string title) {
    // MENCARI LAGU BERDASARKAN TITLE
    adrSong p = L.first;

    while (p != nullptr) {
        if (p->title == title) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteSongFromList(songList &L, adrSong p) {
    // MENGHAPUS LAGU DARI LIST LAGU 
    if (p == nullptr) 
    return ;

    if (p == L.first && p == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else if (p == L.first) {
        L.first = p->next;
        L.first->prev = nullptr;
    } else if (p == L.last) {
        L.last = p->prev;
        L.last->next = nullptr;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
}
void deleteSongInAllPlaylists(userList &L, adrSong song) {
    // MENGHAPUS LAGU TERTENTU DARI SEMUA PLAYLIST, DARI SEMUA USER
    adrUser u = L.first;         
    adrPlaylist p;               
    adrRelation r;               
    adrRelation q;               

    while (u != nullptr) {
        p = u->firstPlaylist;    

        while (p != nullptr) {
            r = p->firstSong;    

            while (r != nullptr) {
                q = r;           
                r = r->next;

                if (q->Song == song) {
                    if (q == p->firstSong && q->next == nullptr) {
                        p->firstSong = nullptr;
                    } else if (q == p->firstSong) {
                        p->firstSong = q->next;
                        p->firstSong->prev = nullptr;
                    }else {
                        q->prev->next = q->next;
                        if (q->next != nullptr) {
                            q->next->prev = q->prev;
                        }
                    }
                }
            }
            p = p->next;   
        }
        u = u->next;       
    }
}

void deleteSongByTitle(userList &L, songList &S, string title) {
    //MENCARI LAGU, DI HAPUS DARI PLAYLIST, DIHAPUS DARI LIST
    adrSong p = searchSongByTitle(S, title);
    if (p == nullptr) {
        cout << "Lagu " << title << " tidak ditemukan.\n";
        return;
    }
    deleteSongInAllPlaylists(L, p);
    deleteSongFromList(S, p);
    cout << "Lagu " << title << " berhasil dihapus dari semua playlist dan list lagu.\n";
}

// HAPUS PLAYLIST
void deletePlaylistByName(adrUser &user, string namaPlaylist) {
    if (user == nullptr) 
    return ;

    adrPlaylist p = user->firstPlaylist;

    // cari playlist milik user yang login
    while (p != nullptr && p->namaPlaylist != namaPlaylist) {
        p = p->next;
    }
    // jika tidak ditemukan
    if (p == nullptr) {
        cout << "Playlist dengan nama \"" << namaPlaylist << "\" tidak tersedia.\n";
        return;
    }

    // HAPUS semua relation (lagu dalam playlist)
    adrRelation r = p->firstSong;
    adrRelation temp;

    while (r != nullptr) {
        temp = r;
        r = r->next;
        delete temp;
    }

    // HAPUS PLAYLIST DARI DLL USER
    if (p == user->firstPlaylist && p->next == nullptr) {
        // hanya 1 playlist
        user->firstPlaylist = nullptr;

    } else if (p == user->firstPlaylist) {
        // playlist pertama
        user->firstPlaylist = p->next;
        p->next->prev = nullptr;

    } else if (p->next == nullptr) {
        // playlist terakhir
        p->prev->next = nullptr;

    } else {
        // playlist di tengah
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
    cout << "Playlist \"" << namaPlaylist << "\" berhasil dihapus.\n";
}

//Procedure untuk admin mengedit data lagu berdasarkan nama
void editSongByTitle(songList &L, string title) {
    adrSong p = searchSongByTitle(L, title);
    string newTitle, newArtist, newGenre;
    int newDuration;
    if (p == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
        return;
    }

    cout << "Title baru : ";
    cin >> newTitle;

    cout << "Artist baru : ";
    cin >> newArtist;

    cout << "Genre baru : ";
    cin >> newGenre;

    cout << "Duration baru: ";
    cin >> newDuration;

    p->title    = newTitle;
    p->artist   = newArtist;
    p->genre    = newGenre;
    p->duration = newDuration;

    cout << "Update berhasil.\n";
}

// menampilkan seluruh lagu
void printAllSongs(songList L) {
    adrSong p = L.first;

    if (p == nullptr) {
        cout << "Tidak ada lagu yang tersedia.\n";
        return;
    }

    cout << "==== DAFTAR LAGU ====\n";

    while (p != nullptr) {
        cout << "Title    : " << p->title << endl;
        cout << "Artist   : " << p->artist << endl;
        cout << "Genre    : " << p->genre << endl;
        cout << "Duration : " << p->duration << " detik\n";
        cout << "---------------------------\n";

        p = p->next;
    }
}

//menampilkan user yang ada(admin)
void displayUserList(userList L) {
    adrUser p = L.first;

    if (p == nullptr) {
        cout << "Tidak ada user.\n";
        return;
    }

    cout << "LIST USER\n";
    while (p != nullptr) {
        cout << "Username : " << p->username << endl;
        cout << " ";
        p = p->next;
    }
}
// menampilkan playlist
void showUserPlaylists(adrUser user) {
    int a;
    adrRelation r;
    int idx;
    if (user->firstPlaylist == nullptr) {
        cout << "Kamu belum memiliki playlist.\n";
        return;
    }

    adrPlaylist p = user->firstPlaylist;
    idx = 1;

    cout << "\nDaftar Playlist :" << user->username << "\n";

    while (p != nullptr) {
        cout << idx << ". " << p->namaPlaylist << endl;
        r = p->firstSong;
         a = 1;

        if (r == nullptr) {
            cout << "   (Playlist ini kosong)\n";
        } else {
            while (r != nullptr) {
                cout << "   " << a << ". "
                     << r->Song->title << " | "
                     << r->Song->artist << " | "
                     << r->Song->genre << " | Durasi: "
                     << r->Song->duration << " detik\n";

                r = r->next;
                a ++;
            }
        }
        cout << endl;
        p = p->next;
        idx++;
    }
}

// menampilkan lagu dalam playlist
void displaySongsInPlaylist(adrPlaylist playlist) {
   adrRelation r;
    if (playlist == nullptr) {
        cout << "Playlist tidak ditemukan.\n";
        return;
    }
     r = playlist->firstSong;
    if (r == nullptr) {
        cout << "Playlist \"" << playlist->namaPlaylist << "\" masih kosong.\n";
        return;
    }
    cout << "LAGU DALAM PLAYLIST \"" << playlist->namaPlaylist << "\" ====\n";

    while (r != nullptr) {
        cout << "Title    : " << r->Song->title << endl;
        cout << "Artist   : " << r->Song->artist << endl;
        cout << "Genre    : " << r->Song->genre << endl;
        cout << "Duration : " << r->Song->duration << " detik" << endl;
        cout << "--------------------------\n";

        r = r->next;
    }
}

// menambahkan lagu ke playlist
void addSongToPlaylist(adrPlaylist &playlist, adrSong song) {
    adrRelation r;
    adrRelation p;

    if (playlist == nullptr || song == nullptr) {
        cout << "Playlist atau lagu tidak valid.\n";
        return;
    }

    r = createElemenRelation(song);

    // Playlist kosong
    if (playlist->firstSong == nullptr) {
        playlist->firstSong = r;
    } else {
         p = playlist->firstSong;

        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = r;
        r->prev = p;
    }

    cout << "Lagu \"" << song->title << "\" berhasil ditambahkan ke playlist \""
         << playlist->namaPlaylist << "\".\n";
}
