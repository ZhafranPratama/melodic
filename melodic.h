#ifndef MELODIC_H_INCLUDED
#define MELODIC_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmUser *adrUser;
typedef struct elmPlaylist *adrPlaylist;
typedef struct elmSong *adrSong;
typedef struct relation *adrRelation;

struct elmUser {
    string username;
    string password;
    adrPlaylist firstPlaylist;
    adrUser next;
    adrUser prev;
};

struct elmPlaylist {
    string namaPlaylist;
    adrRelation firstSong;
    adrPlaylist next;
    adrPlaylist prev;
};

struct elmSong {
    string title;
    string artist;
    string genre;
    int duration;
    adrSong next;
    adrSong prev;
};

struct relation {
    adrSong Song;
    adrRelation next;
    adrRelation prev;
};

struct userList {
    adrUser first;
    adrUser last;
};

struct songList {
    adrSong first;
    adrSong last;
};

void testHeader();
void testBranchGit();
void createListUser(userList &L);
bool isEmptyUser(userList L);
bool isEmptyPlaylist(adrUser p);
adrUser createElemenUser(string username, string password);
adrPlaylist createElemenPlaylist(string namaPlaylist);
void addUser(userList &L, adrUser p);
void addPlaylist(adrUser &p, adrPlaylist q);
adrSong createElemenSong(string artist, string title, string genre, int duration);
adrRelation createElemenRelation(adrSong song);
void createListSong(songList &L);
void addSong(songList &L, adrSong p);

void addInfoSong(songList &L, userList &U);
//MENGHAPUS LAGU 
adrSong searchSongByTitle(songList L, string title);
void deleteSongFromList(songList &L, adrSong p);
void deleteSongInAllPlaylists(userList &L, adrSong song);
void deleteSongByTitle(userList &L, songList &S, string title);

// MENGHAPUS PLAYLIST
void deletePlaylistByName(adrUser &user, string namaPlaylist);

//FITUR ADMIN :MENGEDIT INFORMASI LAGU BERDASARKAN JUDUL
void editSongByTitle(songList &L, userList &U, string title);

//MENAMPILKAN SELURUH DAFTAR LAGU YANG ADA
void printAllSongs(songList L);

//FITUR ADMIN MENAMPILKANS SELURUH USER YANG ADA
void displayUserList(userList L);

//MENAMPILKAN PLAYLIST YANG USER TERSEBUT MILIKI
void showUserPlaylists(adrUser user);

// MENAMPILKAN LAGU DALAM PLAYLIST
void displaySongsInPlaylist(adrPlaylist playlist);

//MENAMBAHKAN LAGU KE DALAM PLAYLIST
void addSongToPlaylist(adrPlaylist &playlist, adrSong song);

//MENAMBAHKAN FITUR LOGIN
void login(userList &L, songList &sL, adrSong &S, bool &isFirstRun);

//MENAMBAHKAN FITUR SEARCH USER BY USERNAME 
adrUser searchUserByUsn(userList L, string username);

//MENAMBAHKAN FITUR ADD SONG TO FAVORITE
void favSong(adrUser &u, adrSong s);

//MENAMBAHKAN FITUR REKOMENDASI LAGU
void songRecomendation(songList sL);

//TAMPILAN ADMIN DI MAIN
void tampilanAdmin(songList &sL, userList &uL);
void tampilanUser(songList &L, adrUser &U, adrSong &S, bool &isFirstRun);

//TAMPILAN PLAY
void statusPlay(bool &isFirstRun, bool isPlaylist, adrSong S, adrRelation R);

#endif