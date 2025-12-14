#ifndef MELODIC_H_INCLUDED
#define MELODIC_H_INCLUDED
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

typedef struct elmUser *adrUser;
typedef struct elmPlaylist *adrPlaylist;
typedef struct elmSong *adrSong;
typedef struct relation *adrRelation;
extern atomic<bool> isPlaying;
extern atomic<bool> stopPlayer;
extern bool isPlaylist;

extern adrSong currentSongList;
extern adrRelation currentSongPlaylist;

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
typedef struct elmHistory *adrHistory;

struct elmHistory {
    adrSong song;
    adrHistory next;
};

struct history {
    adrHistory first;
};



void createHistory(history &H);
void push(history &H, adrSong s);
void showHistory(history H); 
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

void addInfoSong(songList &L, userList &U, adrSong &S, history &h);
adrSong searchSongByTitle(songList L, string title);
void deleteSongFromList(songList &L, adrSong p);
void deleteSongInAllPlaylists(userList &L, adrSong song);
void deleteSongByTitle(userList &L, songList &S, string title, adrSong &s,history &h);
void deletePlaylistByName(adrUser &user, string namaPlaylist);
void deleteSongInPlaylist(adrPlaylist &p, string title);
void editSongByTitle(songList &L, userList &U, string title , adrSong &s, history &h);
void printAllSongs(songList L);
void displayUserList(userList L);
void showUserPlaylists(adrUser user);
void displaySongsInPlaylist(adrPlaylist playlist);
void addSongToPlaylist(adrPlaylist &playlist, adrSong song);
void login(userList &L, songList &sL, adrSong &S, history & h);
adrUser searchUserByUsn(userList L, string username);
void favSong(adrUser &u, adrSong s);
void songRecomendation(songList sL);
void tampilanAdmin(songList &sL, userList &uL, adrSong &s, history &h);
void tampilanUser(songList &L, adrUser &U, adrSong &S, adrRelation &currentSongPlaylist, adrSong &currentSongList, bool &isPlaylist, history & h);
void playSongFromList(songList L, adrSong &currentSongList, string title);
void nextSongList(adrSong &current, songList S);
void prevSongList(adrSong &current, songList S);
void playSongFromPlaylist(adrPlaylist playlist, adrRelation &current, string title);
void nextPlaylistSong(adrRelation &current);
void prevPlaylistSong(adrRelation &current);

#endif