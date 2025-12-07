#include <iostream>
#include "melodic.h"
using namespace std;

int main(){
    int admin;
    bool isFirstRun = true;
    bool isPlay = false;
    userList U;
    songList S;
    adrSong aS;


    createListUser(U);
    createListSong(S);

    // =========================
    // 1. Tambah lagu global (real life)
    // =========================
    adrSong song1 = createElemenSong("Taylor_Swift", "Love_Story", "Pop", 235);
    adrSong song2 = createElemenSong("Queen", "Bohemian_Rhapsody", "Rock", 355);
    adrSong song3 = createElemenSong("Adele", "Someone_Like_You", "Ballad", 285);
    adrSong song4 = createElemenSong("Norah_Jones", "Don't_Know_Why", "Jazz", 210);
    adrSong song5 = createElemenSong("Drake", "God's_Plan", "Hip-Hop", 198);
    adrSong song6 = createElemenSong("Evie_Tamala", "Selamat_Malam", "Dangdut", 230);

    addSong(S, song1);
    addSong(S, song2);
    addSong(S, song3);
    addSong(S, song4);
    addSong(S, song5);
    addSong(S, song6);

    // =========================
    // 2. Tambah user dummy
    // =========================
    adrUser user1 = createElemenUser("alice", "alice123");
    adrUser user2 = createElemenUser("bob", "bob123");
    adrUser user3 = createElemenUser("charlie", "charlie123");

    addUser(U, user1);
    addUser(U, user2);
    addUser(U, user3);

    // =========================
    // 3. Tambah playlist tambahan untuk user2 dan user3
    // =========================
    adrPlaylist pl2_user2 = createElemenPlaylist("Chill_Vibes");
    adrPlaylist pl2_user3 = createElemenPlaylist("Workout_Hits");

    addPlaylist(user2, pl2_user2);
    addPlaylist(user3, pl2_user3);

    // =========================
    // 4. Tambah lagu ke playlist
    // =========================
    // user1 favorite
    addSongToPlaylist(user1->firstPlaylist, song1); // Love Story
    addSongToPlaylist(user1->firstPlaylist, song5); // God's Plan

    // user2 favorite
    addSongToPlaylist(user2->firstPlaylist, song3); // Someone Like You
    addSongToPlaylist(user2->firstPlaylist, song4); // Don't Know Why
    addSongToPlaylist(pl2_user2, song2);            // Bohemian Rhapsody

    // user3 favorite
    addSongToPlaylist(user3->firstPlaylist, song6); // Selamat Malam
    addSongToPlaylist(pl2_user3, song2);            // Bohemian Rhapsody
    addSongToPlaylist(pl2_user3, song4);            // Don't Know Why

    login(U, S, aS, isFirstRun);

    return 0;
}