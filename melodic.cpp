#include "melodic.h"

void testHeader(){
    cout << "pls jalan";
}

void testBranchGit(){
    cout << "ini buat test doang";
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


adrUser createElemenUser(string username, string password, adrPlaylist p){
    adrUser u;
    u = new elmUser;

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

                if (q->nextSong == song) {
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
    adrSong p = searchSongByName(S, title);
    if (p == nullptr) {
        cout << "Lagu " << title << " tidak ditemukan.\n";
        return;
    }
    deleteSongInAllPlaylists(L, p);
    deleteSongFromList(S, p);
    cout << "Lagu " << title << " berhasil dihapus dari semua playlist dan list lagu.\n";
}


