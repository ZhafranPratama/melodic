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

adrSong searchSongByName(songList L, string title) {
    adrSong p = L.first;

    while (p != nullptr) {
        if (p->title == title) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteSongByName(songList &L, string title) {
    adrSong p = searchSongByName(L, title);

    if (p == nullptr) {
        cout << "Lagu " << title << "tidak ditemukan!\n";
        return;
    }

    if (p == L.first && p == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    }
  
    else if (p == L.first) {
        L.first = p->next;
        L.first->prev = nullptr;
    }
    
    else if (p == L.last) {
        L.last = p->prev;
        L.last->next = nullptr;
    }
    
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;

    cout << "Lagu " << title << "berhasil dihapus!\n";
}
