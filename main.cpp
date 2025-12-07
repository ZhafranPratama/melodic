#include <iostream>
#include "melodic.h"
using namespace std;

int main(){
    int admin;
    userList L;
    songList sL;
    adrSong S;
    bool isFirstRun = true;
    bool isPlay = false;

    createListUser(L);
    createListSong(sL);

    login(L, sL, S, isFirstRun);

    return 0;
}