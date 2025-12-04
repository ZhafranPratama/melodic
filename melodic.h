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
    adrSong nextSong;
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

#endif