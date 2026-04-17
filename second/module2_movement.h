#pragma once
#include "globals.h"
#include "module1_ui.h"

void moveField(char map[][19], int but);
void eliminationSticking(char map[][19]);
void funcBeckShip(char map[][19], int button1, int a, int b);
void drawingShips(char map[][19], int but);

void moveField(char map[][19], int but) {
    char a, b, c;
    c = 42; b = 64;
    if      (user == 0) a = 127;
    else if (user == 1) a = 4;
    else if (user == 3 || user == 4) a = 88;

    if (but == 80) {
        if      (map[y+1][x]==a && e==1) { map[y][x]=a; y++; map[y][x]=b; }
        else if (map[y+1][x]==' '&& e==1) { map[y][x]=a; y++; map[y][x]=b; e=0; }
        else if (map[y+1][x]==c  && e==1) { map[y][x]=a; y++; map[y][x]=b; e=2; }
        else if (map[y+1][x]==a  && e==0) { map[y][x]=' '; y++; map[y][x]=b; e=1; }
        else if (map[y+1][x]==' '&& e==0) { map[y][x]=' '; y++; map[y][x]=b; }
        else if (map[y+1][x]==c  && e==0) { map[y][x]=' '; y++; map[y][x]=b; e=2; }
        else if (map[y+1][x]==c  && e==2) { map[y][x]=c;  y++; map[y][x]=b; }
        else if (map[y+1][x]==' '&& e==2) { map[y][x]=c;  y++; map[y][x]=b; e=0; }
        else if (map[y+1][x]==a  && e==2) { map[y][x]=c;  y++; map[y][x]=b; e=1; }
    }
    else if (but == 72) {
        if      (map[y-1][x]==a && e==1) { map[y][x]=a; y--; map[y][x]=b; }
        else if (map[y-1][x]==' '&& e==1) { map[y][x]=a; y--; map[y][x]=b; e=0; }
        else if (map[y-1][x]==c  && e==1) { map[y][x]=a; y--; map[y][x]=b; e=2; }
        else if (map[y-1][x]==a  && e==0) { map[y][x]=' '; y--; map[y][x]=b; e=1; }
        else if (map[y-1][x]==' '&& e==0) { map[y][x]=' '; y--; map[y][x]=b; }
        else if (map[y-1][x]==c  && e==0) { map[y][x]=' '; y--; map[y][x]=b; e=2; }
        else if (map[y-1][x]==c  && e==2) { map[y][x]=c;  y--; map[y][x]=b; }
        else if (map[y-1][x]==' '&& e==2) { map[y][x]=c;  y--; map[y][x]=b; e=0; }
        else if (map[y-1][x]==a  && e==2) { map[y][x]=c;  y--; map[y][x]=b; e=1; }
    }
    else if (but == 77) {
        if      (map[y][x+1]==a && e==1) { map[y][x]=a; x++; map[y][x]=b; }
        else if (map[y][x+1]==' '&& e==1) { map[y][x]=a; x++; map[y][x]=b; e=0; }
        else if (map[y][x+1]==c  && e==1) { map[y][x]=a; x++; map[y][x]=b; e=2; }
        else if (map[y][x+1]==a  && e==0) { map[y][x]=' '; x++; map[y][x]=b; e=1; }
        else if (map[y][x+1]==' '&& e==0) { map[y][x]=' '; x++; map[y][x]=b; }
        else if (map[y][x+1]==c  && e==0) { map[y][x]=' '; x++; map[y][x]=b; e=2; }
        else if (map[y][x+1]==c  && e==2) { map[y][x]=c;  x++; map[y][x]=b; }
        else if (map[y][x+1]==' '&& e==2) { map[y][x]=c;  x++; map[y][x]=b; e=0; }
        else if (map[y][x+1]==a  && e==2) { map[y][x]=c;  x++; map[y][x]=b; e=1; }
    }
    else if (but == 75) {
        if      (map[y][x-1]==a && e==1) { map[y][x]=a; x--; map[y][x]=b; }
        else if (map[y][x-1]==' '&& e==1) { map[y][x]=a; x--; map[y][x]=b; e=0; }
        else if (map[y][x-1]==c  && e==1) { map[y][x]=a; x--; map[y][x]=b; e=2; }
        else if (map[y][x-1]==a  && e==0) { map[y][x]=' '; x--; map[y][x]=b; e=1; }
        else if (map[y][x-1]==' '&& e==0) { map[y][x]=' '; x--; map[y][x]=b; }
        else if (map[y][x-1]==c  && e==0) { map[y][x]=' '; x--; map[y][x]=b; e=2; }
        else if (map[y][x-1]==c  && e==2) { map[y][x]=c;  x--; map[y][x]=b; }
        else if (map[y][x-1]==' '&& e==2) { map[y][x]=c;  x--; map[y][x]=b; e=0; }
        else if (map[y][x-1]==a  && e==2) { map[y][x]=c;  x--; map[y][x]=b; e=1; }
    }
}

void eliminationSticking(char map[][19]) {
    if (map[y][x] == '@') map[y][x] = ' ';
}

void funcBeckShip(char map[][19], int button1, int a, int b) {
    char a1 = (user == 0) ? (char)127 : (char)4;
    int pr = 0, count = 0;

    if (button1 == 50) { 
        for (int i = 0; i < b; i++)
            if (map[(y+1)-i][x+1] != a1 && map[(y+1)-i][x-1] != a1) count++;
        if (map[y+1][x] != a1 && map[y-(b-2)][x] != a1) count++;
        for (int i = 1; i <= (b-3); i++)
            if (map[y-i][x] != '-') count++;
        if (count == a) {
            for (int i = 0; i < (b-2); i++) map[y-i][x] = a1;
            count = 0; pr = 1;
        } else {
            if (map[y][x] == '@') map[y][x] = ' ';
            else if (map[y][x] == '9') map[y][x] = a1;
            count = 0;
        }
        if (user == 0) { int z=0; for(int i=3;i<15;i++){for(int j=3;j<15;j++){if(map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1)break;} }
        if (user == 1) { int z=0; for(int i=2;i<12;i++){for(int j=41;j<53;j++){if(map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1)break;} }
        if (pr == 1) { ++ship; printStuff(0,0); }
    }
    else if (button1 == 49) { 
        for (int i = 0; i < b; i++)
            if (map[y+1][(x-1)+i] != a1 && map[y-1][(x-1)+i] != a1) count++;
        if (map[y][x-1] != a1 && map[y][x+(b-2)] != a1) count++;
        for (int i = 1; i <= (b-3); i++)
            if (map[y][x+i] != '|') count++;
        if (count == a) {
            for (int i = 0; i < (b-2); i++) map[y][x+i] = a1;
            count = 0; pr = 1;
        } else {
            if (map[y][x] == '@') map[y][x] = ' ';
            else if (map[y][x] == '9') map[y][x] = a1;
            count = 0;
        }
        if (user == 0) { int z=0; for(int i=3;i<15;i++){for(int j=3;j<15;j++){if(map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1)break;} }
        if (user == 1) { int z=0; for(int i=3;i<15;i++){for(int j=41;j<53;j++){if(map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1)break;} }
        if (pr == 1) { ++ship; printStuff(0,0); }
    }

    if (button1 == 8) {
        if (user == 0) for(int i=4;i<14;i++) for(int j=4;j<14;j++) map[i][j]=' ';
        else           for(int i=2;i<12;i++) for(int j=42;j<52;j++) map[i][j]=' ';
        ship = 0;
    }
    if (button1 == 27) {
        for(int i=4;i<14;i++) for(int j=4;j<14;j++) mapfield1.map[i][j]=' ';
        for(int i=2;i<12;i++) for(int j=42;j<52;j++) mapfield2.map[i][j]=' ';
        system("cls"); esc = 1;
    }
}

void drawingShips(char map[][19], int but) {
    if (ship == 0 && map[y][x] == '@') {
        menuBeckShip("\t\tPostavte 4-palubnyy korabl");
        funcBeckShip(map, but, 10, 6);
    } else if ((ship == 1 || ship == 2) && map[y][x] == '@') {
        menuBeckShip("\t\tPostavte 3-palubnyy korabl");
        funcBeckShip(map, but, 8, 5);
    } else if ((ship == 3 || ship == 4 || ship == 5) && map[y][x] == '@') {
        menuBeckShip("\t\tPostavte 2-palubnyy korabl");
        funcBeckShip(map, but, 6, 4);
    } else if ((ship == 6 || ship == 7 || ship == 8 || ship == 9) && map[y][x] == '@') {
        menuBeckShip("\t\tPostavte 1-palubnyy korabl");
        funcBeckShip(map, but, 4, 3);
    } else if (ship == 10) {
        system("cls");
        ship = 11;
    }
}
