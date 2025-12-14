#include "melodic.h"
#include <thread>
#include <chrono>

void login(userList &L, songList &sL, adrSong &S, history &h){
    string username, password;
    adrSong currentSongList = nullptr;
    adrRelation currentSongPlaylist = nullptr;
    bool isPlaylist = false;
    adrUser p;
    cout << "============================================================\n";
    cout << "                          L O G I N                         \n";
    cout << "============================================================\n";
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    if (username == "admin" && password == "admin") {
        tampilanAdmin(sL, L, S , h);
    }else {
        p = searchUserByUsn(L, username);
        if (p != nullptr) {
            if (password == p->password) {
                tampilanUser(sL, p, S, currentSongPlaylist, currentSongList, isPlaylist,h);
            } else {
                cout << "Password salah! Harap login kembali" << endl;
                login(L, sL, S,h);
            }
        } else {
            cout << "User tidak valid! Harap login kembali" << endl;
            login(L, sL, S,h);
        }
    }
}
void createHistory(history &H) {
    H.first = nullptr;
}

void push(history &H, adrSong s) {
    if (s == nullptr) return;
    adrHistory p = new elmHistory;
    p->song = s;
    p->next = H.first;
    H.first = p;
}

void showHistory(history H) {
    if (H.first == nullptr) {
        cout << "History lagu masih kosong.\n";
    } else {
        cout << "================== HISTORY LAGU ================== \n";
        int i = 1;
        adrHistory p = H.first;

        while (p != nullptr) {
            cout << i << ". "
                << p->song->title << " | "
                << p->song->artist << " | "
                << p->song->genre << endl;
            p = p->next;
            i++;
        }
        cout << "================================================== \n";
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

void addInfoSong(songList &L, userList &U, adrSong &S, history &h){
    string artist, title, genre;
    int duration;
    string jawaban;
    adrSong p;
    
    cout << "Masukkan Judul Lagu   : ";
    cin >> title;
    cout << "Masukkan Nama Artist  : ";
    cin >> artist;
    cout << "Masukkan Genre Lagu   : ";
    cin >> genre;
    cout << "Masukkan Durasi (detik): ";
    cin >> duration;
    
    p = createElemenSong(artist, title, genre, duration);
    addSong(L, p);
    cout << "Lagu \"" << title << "\" berhasil ditambahkan!\n";

    cout << "Apakah anda ingin kembali ke main menu? (iya / tidak)\n";
    cin >> jawaban;

    if (jawaban == "iya") {
        tampilanAdmin(L, U, S,h);   
    } else if (jawaban == "tidak") {
        cout << "Terima kasih\n";
        return;
    }
}



adrSong searchSongByTitle(songList L, string title) {
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

void deleteSongByTitle(userList &L, songList &S, string title, adrSong &s,history &h) {

    adrSong p = searchSongByTitle(S, title);
    string jawaban;
    if (p == nullptr) {
        cout << "Lagu " << title << " tidak ditemukan.\n";
        return;
    }
    deleteSongInAllPlaylists(L, p);
    deleteSongFromList(S, p);
    cout << "Lagu " << title << " berhasil dihapus dari semua playlist dan list lagu.\n";
     
    cout << "Apakah anda ingin kembali ke main menu? (iya / tidak)\n";
    cin >> jawaban;
    if (jawaban == "iya") {
        tampilanAdmin(S, L, s, h);   
    } else if (jawaban == "tidak") {
        cout << "Terima kasih\n";
        return;
    }
}

void deletePlaylistByName(adrUser &user, string namaPlaylist) {
    if (user == nullptr) 
    return ;

    adrPlaylist p = user->firstPlaylist;

    while (p != nullptr && p->namaPlaylist != namaPlaylist) {
        p = p->next;
    }
    if (p == nullptr) {
        cout << "Playlist dengan nama \"" << namaPlaylist << "\" tidak tersedia.\n";
        return;
    }

    adrRelation r = p->firstSong;
    adrRelation temp;

    while (r != nullptr) {
        temp = r;
        r = r->next;
        delete temp;
    }

    if (p == user->firstPlaylist && p->next == nullptr) {
        user->firstPlaylist = nullptr;

    } else if (p == user->firstPlaylist) {
        user->firstPlaylist = p->next;
        p->next->prev = nullptr;

    } else if (p->next == nullptr) {
        p->prev->next = nullptr;

    } else {
        
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
    cout << "Playlist \"" << namaPlaylist << "\" berhasil dihapus.\n";
}


void editSongByTitle(songList &L, userList &U, string title , adrSong &s, history &h){
    adrSong p = searchSongByTitle(L, title);
    string newTitle, newArtist, newGenre;
    string jawaban;
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

    cout << "Apakah anda ingin kembali ke main menu? (iya / tidak)\n";
    cin >> jawaban;

    if (jawaban == "iya") {
        tampilanAdmin(L, U, s,h);  
    } else {
        cout << "Terima kasih\n";
        return;
    }
}

void printAllSongs(songList L) {
    adrSong p = L.first;

    if (p == nullptr) {
        cout << "Tidak ada lagu yang tersedia.\n";
        return;
    }

    cout << "================== DAFTAR LAGU ================== \n";

    while (p != nullptr) {
        cout << "Title    : " << p->title << endl;
        cout << "Artist   : " << p->artist << endl;
        cout << "Genre    : " << p->genre << endl;
        cout << "Duration : " << p->duration << " detik\n";
        cout << "------------------------------------------------------------\n";

        p = p->next;
    }
}

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

void showUserPlaylists(adrUser user) {
    int a;
    adrRelation r;
    int idx;
    if (user->firstPlaylist->next == nullptr) {
        cout << "Kamu belum memiliki playlist.\n";
        return;
    }

    adrPlaylist p = user->firstPlaylist->next;
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
        cout << "------------------------------------------------------------\n";
        r = r->next;
    }
}


void addSongToPlaylist(adrPlaylist &playlist, adrSong song) {
    adrRelation r;
    adrRelation p;

    if (playlist == nullptr || song == nullptr) {
        cout << "Playlist atau lagu tidak valid.\n";
        return;
    }

    r = createElemenRelation(song);

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

}

void tampilanAdmin(songList &sL, userList &uL, adrSong &s, history &h) {
    int admin;
    string title;
        cout << "============================================================\n";
        cout << "                     T A M P I L A N  M E N U               \n";
        cout << "============================================================\n";

        cout << "Apa Yang Ingin Anda Lakukan\n";
        cout << "------------------------------------------------------------\n";
        cout << "1. Menambahkan lagu\n";
        cout << "2. Menghapus lagu\n";
        cout << "3. Edit lagu\n";
        cout << "4. Lihat daftar lagu\n";
        cout << "5. Kembali ke LOGIN\n";
        cout << "------------------------------------------------------------\n";
        cout << "Masukkan pilihan (1 - 5): ";

        cin >> admin;


    if (admin == 1) {
        addInfoSong(sL, uL , s,h);            
    } 
    else if (admin == 2) {
        cout << "Masukkan Title lagu yang ingin dihapus: ";
        cin >> title;
        deleteSongByTitle(uL, sL, title, s,h);   
    } 
    else if (admin == 3) {
        cout << "Masukkan Title lagu yang ingin diedit: ";
        cin >> title;
        editSongByTitle(sL, uL,  title, s,h);         
    }
    else if (admin == 4) {
        printAllSongs(sL);
        tampilanAdmin(sL, uL , s,h);
    }
    else if (admin == 5) {
        login(uL, sL, s,h);
    } 
    else {
        cout << "Input Tidak Sesuai\n";
        tampilanAdmin(sL, uL, s,h);
    }
}

void statusPlay(bool isPlaylist, adrSong S, adrRelation R, songList L) {
    cout << "------------------------------------------------------------\n";
    cout << "                         S O N G                             \n";
    cout << "------------------------------------------------------------\n";
    if (isPlaylist) {
        if (R == nullptr) {
            cout << "Prev Song    : " 
             << "None" << endl;
        cout << "Current Song : " << "None" << endl;
        cout << "Next Song    : " 
             << "None" << endl;
        } else {
        cout << "Prev Song    : " 
             << (R->prev == nullptr ? L.last->title : R->prev->Song->title) << endl;
        cout << "Current Song : " << (R == nullptr ? "None" : R->Song->title) << endl;
        cout << "Next Song    : " 
             << (R->next == nullptr ? L.first->title : R->next->Song->title) << endl;
        }
    } else if (!isPlaylist) {
        if (S == nullptr) {
            cout << "Prev Song    : " << "None" << endl;
            cout << "Current Song : " << "None" << endl;
            cout << "Next Song    : " << "None" << endl;
        }else {
        cout << "Prev Song    : " 
             << (S->prev == nullptr ? L.last->title : S->prev->title) << endl;
        cout << "Current Song : " << (S == nullptr ? "None" : S->title) << endl;
        cout << "Next Song    : " 
             << (S->next == nullptr ? L.first->title : S->next->title) << endl;
        }
    }
    cout << "------------------------------------------------------------\n";
}

void playSongFromList(songList L, adrSong &current, string title) {
    if (title == "acak") {
        if (L.first == nullptr) return;

        int count = 0;
        adrSong p = L.first;
        while (p != nullptr) {
            count++;
            p = p->next;
        }

        int r = rand() % count;
        p = L.first;
        while (r--) p = p->next;

        current = p;
    } else {
        current = searchSongByTitle(L, title);
    }

    if (current == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    }
}

void nextSongList(adrSong &current, songList S) {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
    } else if (current == nullptr || current->next == nullptr) {
        current = S.first;
    }
}

void prevSongList(adrSong &current, songList S) {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
    } else if (current == nullptr || current->prev == nullptr) {
        current = S.last;
    }
}

void playSongFromPlaylist(adrPlaylist playlist, adrRelation &current, string title) {
    if (playlist == nullptr) return;

    if (title == "acak") {
        int count = 0;
        adrRelation r = playlist->firstSong;
        while (r != nullptr) {
            count++;
            r = r->next;
        }

        if (count == 0) return;

        int idx = rand() % count;
        r = playlist->firstSong;
        while (idx--) r = r->next;

        current = r;
    } else {
        adrRelation r = playlist->firstSong;
        while (r != nullptr && r->Song->title != title) {
            r = r->next;
        }
        current = r;
    }

    if (current == nullptr) {
        cout << "Lagu tidak ditemukan di playlist.\n";
    }
}

void nextPlaylistSong(adrRelation &current) {
    if (current != nullptr && current->next != nullptr)
        current = current->next;
}

void prevPlaylistSong(adrRelation &current) {
    if (current != nullptr && current->prev != nullptr)
        current = current->prev;
}

void tampilanUser(songList &L, adrUser &U, adrSong &S, adrRelation &currentSongPlaylist, adrSong &currentSongList, bool &isPlaylist, history &h) {
    int user;
    string pilihan;
    string title;
    string namaPlaylist;
    adrPlaylist p;
    int a ;
    statusPlay(isPlaylist, currentSongList, currentSongPlaylist, L);
    cout << "\n============================================================\n";
    cout << "                     T A M P I L A N  M E N U               \n";
    cout << "============================================================\n\n";
    cout << "Apa Yang Ingin Anda Lakukan\n";
    cout << "------------------------------------------------------------\n";
    cout << "1. Menampilkan Seluruh Lagu\n";
    cout << "2. Melihat Play List\n";
    cout << "3. Melihat Favorite Song\n";
    cout << "4. Melihat Daftar Lagu Sesuai Mood Anda\n";
    cout << "5. Play Next Song\n";
    cout << "6. Play Previous Song\n";
    cout << "7. Tambahkan lagu ke favorite Song\n";
    cout << "8. Tambahkan lagu ke Playlist \n";
    cout << "9. Lihat history lagu \n";
    cout << "0. Keluar dari aplikasi\n";
    cout << "------------------------------------------------------------\n";
    cout << "Masukkan (0 - 9): ";
    cin >> user;
    cout << "------------------------------------------------------------\n";

     if (user == 1) {
                printAllSongs(L);
                cout << "============================================================\n";
                cout << "Apa Yang Ingin Anda Lakukan\n";
                cout << "1. Memutar lagu\n";
                cout << "2. Menambahkan lagu ke Play List\n";
                cout << "3. Menambah lagu ke Favorite Song\n";
                cout << "4. Back to menu\n";
                cout << "Masukkan (1 - 4): ";
                cin >> a;
                cout << "============================================================\n";
                if (a == 1){
                cout << "Lagu apa yang ingin anda dengarkan? (masukkan title / acak)\n";
                cin >> pilihan;
                    if (pilihan == "acak") {
                        cout << "Memutar lagu secara acak...\n";
                        playSongFromList(L, currentSongList, pilihan);
                        isPlaylist = false;
                        push(h, currentSongList);
                    } else {
                        title = pilihan;
                        cout << "Memutar lagu berjudul: " << title << "\n";
                         playSongFromList(L, currentSongList, pilihan);
                         isPlaylist = false;
                         push(h, currentSongList);
                    }
                    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                }else if(a == 2){
                    cout << "Lagu apa yang ingin anda tambahkan ke dalam playlist? (masukkan title)\n";
                    cin >> title;
                    cout << "Playlist mana yang ingin ditambahkan lagu " << title << "?\n";
                    cin >> namaPlaylist;

                    adrSong s = searchSongByTitle(L, title);
                    if (s != nullptr) {
                        adrPlaylist p = U->firstPlaylist;
                        bool found = false;

                        while (p != nullptr) {
                            if (p->namaPlaylist == namaPlaylist) {
                                addSongToPlaylist(p, s);
                                cout << "Lagu \"" << title << "\" berhasil ditambahkan ke playlist \"" << namaPlaylist << "\".\n";
                                found = true;
                                break;
                            }
                            p = p->next;
                        }

                        if (!found) {
                            cout << "Playlist \"" << namaPlaylist << "\" tidak ditemukan!\n";
                        }

                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }

                    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

                }
                else if (a == 3){
                    cout << "Lagu apa yang ingin anda tambahkan ke Favorite Song? (masukkan title)\n";
                    cin >> title;
                    adrSong s = searchSongByTitle(L, title);
                    if (s != nullptr) {
                        favSong(U, s); 
                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }
                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                }else if(a == 4){
                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                }
    }else if (user == 2){
        showUserPlaylists(U);
                cout << "============================================================\n";
                cout << "Apa Yang Ingin Anda Lakukan\n";
                cout << "1. Melihat Lagu dalam PlayList\n";
                cout << "2. Back To Menu\n";
                cout << "Masukkan (1/2): ";
                cin >> a;
                cout << "============================================================\n";
                
                if (a == 1){
                    cout << "Playlist mana yang ingin anda lihat? Masukkan nama playlist:\n";
                    cin >> namaPlaylist;
                    
                    p = U->firstPlaylist;
                    while (p != nullptr && p->namaPlaylist != namaPlaylist) {
                        p = p->next;
                    } 
                    if (p == nullptr) {
                      cout << "Playlist tidak ditemukan.\n";
                    }
                    else {
                     displaySongsInPlaylist(p);
                     cout << "============================================================\n";
                        cout << "Apa Yang Ingin Anda Lakukan\n";
                        cout << "1. Memutar Lagu dalam PlayList\n";
                        cout << "2. Back To Menu\n";
                        cout << "Masukkan (1/2): ";
                        cin >> a;
                    cout << "============================================================\n";
                            if (a == 1){
                                cout << "Lagu apa yang ingin anda dengarkan? (masukkan title / acak)\n";
                                cin >> pilihan;

                                if (pilihan == "acak") {
                                    cout << "Memutar lagu secara acak...\n";
                                    playSongFromPlaylist(p, currentSongPlaylist, pilihan);
                                    isPlaylist = true;
                                    push(h, currentSongPlaylist->Song);
                                } else {
                                    title = pilihan;
                                    cout << "Memutar lagu berjudul: " << title << "\n";
                                    playSongFromPlaylist(p, currentSongPlaylist, pilihan);
                                    isPlaylist = true;
                                    if (currentSongPlaylist != nullptr){
                                    push(h, currentSongPlaylist->Song);
                                    }
                                }
                                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                            }else if(a == 2){
                                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

                            }
                    }       

        }else if(a ==2){
           tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

        }

    } else if (user == 3){
        displaySongsInPlaylist(U->firstPlaylist);
                cout << "============================================================\n";
                cout << "Apa Yang Ingin Anda Lakukan\n";
                cout << "1. Memutar Lagu\n";
                cout << "2. Back To Menu\n";
                cout << "Masukkan (1/2): ";
                cin >> a;
                cout << "============================================================\n";
            if (a == 1){
                 cout << "Lagu apa yang ingin anda dengarkan? (masukkan title / acak)\n";
                cin >> pilihan;

                if (pilihan == "acak") {
                    cout << "Memutar lagu secara acak...\n";
                    playSongFromPlaylist(p, currentSongPlaylist, pilihan);
                    isPlaylist = true;
                } else {
                    title = pilihan;
                    cout << "Memutar lagu berjudul: " << title << "\n";
                    playSongFromPlaylist(p, currentSongPlaylist, pilihan);
                    isPlaylist = true;
                }
                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

            }else if(a == 2){
                tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

            }
           
    }else if (user == 4){
        songRecomendation(L);
                cout << "============================================================\n";
                cout << "Apa Yang Ingin Anda Lakukan\n";
                cout << "1. Memutar lagu\n";
                cout << "2. Menambahkan lagu ke Play List\n";
                cout << "3. Menambah lagu ke Favorite Song\n";
                cout << "4. Back to menu\n";
                cout << "Masukkan (1/2/3/4): ";
                cin >> a;
                cout << "============================================================\n";
                if (a == 1){
                cout << "Lagu apa yang ingin anda dengarkan? (masukkan title / acak)\n";
                cin >> pilihan;
                    if (pilihan == "acak") {
                        cout << "Memutar lagu secara acak...\n";
                    } else {
                        title = pilihan;
                        cout << "Memutar lagu berjudul: " << title << "\n";
                    }
                   tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                }else if(a == 2){
                    cout << "Lagu apa yang ingin anda tambahkan ke dalam playlist? (masukkan title)\n";
                    cin >> title;
                    cout << "Playlist mana yang ingin ditambahkan lagu " << title << "?\n";
                    cin >> namaPlaylist;

                    adrSong s = searchSongByTitle(L, title);
                    if (s != nullptr) {
                        adrPlaylist p = U->firstPlaylist;
                        bool found = false;

                        while (p != nullptr) {
                            if (p->namaPlaylist == namaPlaylist) {
                                addSongToPlaylist(p, s);
                                cout << "Lagu \"" << title << "\" berhasil ditambahkan ke playlist \"" << namaPlaylist << "\".\n";
                                found = true;
                                break;
                            }
                            p = p->next;
                        }

                        if (!found) {
                            cout << "Playlist \"" << namaPlaylist << "\" tidak ditemukan!\n";
                        }

                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }

                    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                }
                else if (a == 3){
                    cout << "Lagu apa yang ingin anda tambahkan ke Favorite Song? (masukkan title)\n";
                    cin >> title;
                    adrSong s = searchSongByTitle(L, title);
                    if (s != nullptr) {
                        favSong(U, s); 
                    } else {
                        cout << "Lagu tidak ditemukan!\n";
                    }
                    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

                 }else if (a == 4){
                    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
                 }
    }else if (user == 5){
        if (isPlaylist){
            if (currentSongPlaylist->next == nullptr) {
                currentSongList = currentSongPlaylist->Song;
                nextSongList(currentSongList, L);
                isPlaylist = false;
            }else {
                nextPlaylistSong(currentSongPlaylist);
            }
            push(h, currentSongList);
            tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        } else {
            nextSongList(currentSongList, L);
            push(h, currentSongList);
            tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        }
    }else if (user == 6){
        if (isPlaylist){
            if (currentSongPlaylist->prev == nullptr) {
                currentSongList = currentSongPlaylist->Song;
                prevSongList(currentSongList, L);
                isPlaylist = false;
            } else {
                prevPlaylistSong(currentSongPlaylist);
            }
            push(h, currentSongList);
            tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        } else {
            prevSongList(currentSongList, L);
            push(h, currentSongList);
            tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        }
    }else if (user == 7){
        adrSong songToAdd = nullptr;

    if (isPlaylist) {
        if (currentSongPlaylist != nullptr)
            songToAdd = currentSongPlaylist->Song;
    } else {
        songToAdd = currentSongList;
    }

    if (songToAdd == nullptr) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        return;
    }

    favSong(U, songToAdd);
    cout << "Lagu \"" << songToAdd->title 
         << "\" berhasil ditambahkan ke Favorite Song.\n";

    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

    }else if (user ==8){
    adrSong songToAdd = nullptr;
    string namaPlaylist;

    if (isPlaylist) {
        if (currentSongPlaylist != nullptr)
            songToAdd = currentSongPlaylist->Song;
    } else {
        songToAdd = currentSongList;
    }

    if (songToAdd == nullptr) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);
        return;
    }

    cout << "Masukkan nama playlist tujuan:\n";
    cin >> namaPlaylist;

    adrPlaylist p = U->firstPlaylist;
    bool found = false;

    while (p != nullptr) {
        if (p->namaPlaylist == namaPlaylist) {
            addSongToPlaylist(p, songToAdd);
            cout << "Lagu \"" << songToAdd->title
                 << "\" berhasil ditambahkan ke playlist \""
                 << namaPlaylist << "\".\n";
            found = true;
            break;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Playlist tidak ditemukan.\n";
    }

    tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist,h);

    } else if (user == 9){
        showHistory(h);
        tampilanUser(L, U, S, currentSongPlaylist, currentSongList, isPlaylist, h);
    }
    else if (user == 0){
        return;
    }
}

