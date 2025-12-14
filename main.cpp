#include <iostream>
#include "melodic.h"
#include <thread>
using namespace std;

int main(){
    int admin;
    bool isFirstRun = true;
    bool isPlay = false;
    userList U;
    songList S;
    adrSong aS;
    history h;


    createListUser(U);
    createListSong(S);
    createHistory(h);

 
    adrSong song1  = createElemenSong("Taylor_Swift",   "Love_Story",          "Pop",       235);
    adrSong song2  = createElemenSong("Queen",          "Bohemian_Rhapsody",   "Rock",      355);
    adrSong song3  = createElemenSong("Adele",          "Someone_Like_You",    "Ballad",    285);
    adrSong song4  = createElemenSong("Norah_Jones",    "Don't_Know_Why",      "Jazz",      210);
    adrSong song5  = createElemenSong("Drake",          "God's_Plan",          "Hip-Hop",   198);
    adrSong song6  = createElemenSong("Evie_Tamala",    "Selamat_Malam",       "Dangdut",   230);
    adrSong song7  = createElemenSong("Bruno_Mars",     "Grenade",             "Pop",       223);
    adrSong song8  = createElemenSong("Metallica",      "Enter_Sandman",       "Rock",      331);
    adrSong song9  = createElemenSong("Ed_Sheeran",     "Perfect",             "Ballad",    263);
    adrSong song10 = createElemenSong("Kunto_Aji",      "Rehat",               "Indie",     250);
    adrSong song11 = createElemenSong("Tiara_Andini",   "Merasa_Indah",        "Pop",       210);
    adrSong song12 = createElemenSong("Tulus",          "Monokrom",            "Indie",     257);
    adrSong song13 = createElemenSong("Alan_Walker",    "Faded",               "EDM",       212);
    adrSong song14 = createElemenSong("BTS",            "Spring_Day",          "K-Pop",     293);
    adrSong song15 = createElemenSong("Ariana_Grande",  "7_rings",             "Hip-Hop",   178);
    adrSong song16 = createElemenSong("Coldplay",       "Yellow",              "Indie",     274);
    adrSong song17 = createElemenSong("Sam_Smith",      "Stay_With_Me",        "Ballad",    172);
    adrSong song18 = createElemenSong("Maroon_5",       "Sugar",               "Pop",       235);
    adrSong song19 = createElemenSong("Linkin_Park",    "Numb",                "Rock",      184);
    adrSong song20 = createElemenSong("Raisa",          "Kali_Kedua",          "Pop",       245);
    adrSong song21 = createElemenSong("Hindia",         "Evaluasi",            "Indie",     278);
    adrSong song22 = createElemenSong("Dewa19",         "Pupus",               "Pop",       320);
    adrSong song23 = createElemenSong("Melody_Gardot",  "Baby_I’m_A_Fool",     "Jazz",      195);
    adrSong song24 = createElemenSong("Billie_Eilish",  "Lovely",              "Pop",       201);
    adrSong song25 = createElemenSong("Nadin_Amizah",   "Sorai",               "Indie",     260);
    adrSong song26 = createElemenSong("JKT48",          "Rapsodi",             "Pop",       248);
    adrSong song27 = createElemenSong("Imagine_Dragons","Believer",            "Rock",      204);
    adrSong song28 = createElemenSong("Tiesto",         "The_Business",        "EDM",       162);
    adrSong song29 = createElemenSong("Lewis_Capaldi",  "Bruises",             "Ballad",    223);
    adrSong song30 = createElemenSong("Fiersa_Besari",  "Celengan_Rindu",      "Indie",     252);

    adrSong songs[] = {song1, song2, song3, song4, song5, song6, song7, song8, song9, song10,
                    song11, song12, song13, song14, song15, song16, song17, song18, song19, song20,
                    song21, song22, song23, song24, song25, song26, song27, song28, song29, song30};

  
    for (int i = 0; i < 30; i++) {
        addSong(S, songs[i]);
    }

    adrUser user1 = createElemenUser("alice",   "alice123");
    adrUser user2 = createElemenUser("bob",     "bob123");
    adrUser user3 = createElemenUser("charlie", "charlie123");
    adrUser user4 = createElemenUser("diana",   "diana123");
    adrUser user5 = createElemenUser("eric",    "eric123");

    addUser(U, user1);
    addUser(U, user2);
    addUser(U, user3);
    addUser(U, user4);
    addUser(U, user5);


    adrPlaylist pl1_u1 = createElemenPlaylist("Chill_Vibes");
    adrPlaylist pl2_u1 = createElemenPlaylist("Morning_Acoustic");
    addPlaylist(user1, pl1_u1);
    addPlaylist(user1, pl2_u1);

    adrPlaylist pl1_u2 = createElemenPlaylist("Workout_Hits");
    adrPlaylist pl2_u2 = createElemenPlaylist("Rock_Arena");
    addPlaylist(user2, pl1_u2);
    addPlaylist(user2, pl2_u2);

    adrPlaylist pl1_u3 = createElemenPlaylist("Sad_Hours");
    adrPlaylist pl2_u3 = createElemenPlaylist("Jazz_Lounge");
    addPlaylist(user3, pl1_u3);
    addPlaylist(user3, pl2_u3);

    adrPlaylist pl1_u4 = createElemenPlaylist("Focus_Mode");
    adrPlaylist pl2_u4 = createElemenPlaylist("Night_Ride");
    addPlaylist(user4, pl1_u4);
    addPlaylist(user4, pl2_u4);

    adrPlaylist pl1_u5 = createElemenPlaylist("Happy_Vibes");
    adrPlaylist pl2_u5 = createElemenPlaylist("EDM_Party");
    addPlaylist(user5, pl1_u5);
    addPlaylist(user5, pl2_u5);

  
    addSongToPlaylist(user1->firstPlaylist, song1);
    addSongToPlaylist(user1->firstPlaylist, song3);
    addSongToPlaylist(user1->firstPlaylist, song11);

    addSongToPlaylist(pl1_u1, song10);
    addSongToPlaylist(pl1_u1, song12);
    addSongToPlaylist(pl1_u1, song25);

    addSongToPlaylist(pl2_u1, song9);
    addSongToPlaylist(pl2_u1, song16);
    addSongToPlaylist(pl2_u1, song23);

   addSongToPlaylist(user2->firstPlaylist, song2);
    addSongToPlaylist(user2->firstPlaylist, song19);
    addSongToPlaylist(user2->firstPlaylist, song27);

    addSongToPlaylist(pl1_u2, song13);
    addSongToPlaylist(pl1_u2, song15);
    addSongToPlaylist(pl1_u2, song28);

    addSongToPlaylist(pl2_u2, song8);
    addSongToPlaylist(pl2_u2, song19);
    addSongToPlaylist(pl2_u2, song27);

    addSongToPlaylist(user3->firstPlaylist, song6);
    addSongToPlaylist(user3->firstPlaylist, song22);
    addSongToPlaylist(user3->firstPlaylist, song26);

    addSongToPlaylist(pl1_u3, song29);
    addSongToPlaylist(pl1_u3, song3);
    addSongToPlaylist(pl1_u3, song17);

    addSongToPlaylist(pl2_u3, song4);
    addSongToPlaylist(pl2_u3, song23);
    addSongToPlaylist(pl2_u3, song12);
    
    addSongToPlaylist(user4->firstPlaylist, song14);
    addSongToPlaylist(user4->firstPlaylist, song20);
    addSongToPlaylist(user4->firstPlaylist, song24);

    addSongToPlaylist(pl1_u4, song10);
    addSongToPlaylist(pl1_u4, song16);
    addSongToPlaylist(pl1_u4, song21);

    addSongToPlaylist(pl2_u4, song27);
    addSongToPlaylist(pl2_u4, song28);
    addSongToPlaylist(pl2_u4, song13);

 
    addSongToPlaylist(user5->firstPlaylist, song7);
    addSongToPlaylist(user5->firstPlaylist, song18);
    addSongToPlaylist(user5->firstPlaylist, song20);

    addSongToPlaylist(pl1_u5, song1);
    addSongToPlaylist(pl1_u5, song11);
    addSongToPlaylist(pl1_u5, song24);

    addSongToPlaylist(pl2_u5, song28);
    addSongToPlaylist(pl2_u5, song13);
    addSongToPlaylist(pl2_u5, song15);
    login(U, S, aS,h);
    return 0;
}