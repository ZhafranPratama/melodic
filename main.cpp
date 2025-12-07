#include <iostream>
#include "melodic.h"
using namespace std;

int main(){
    int admin;
    userList L;
    songList sL;
    adrSong S;

    createListUser(L);
    createListSong(sL);

    login(L, sL, S);

    return 0;
}