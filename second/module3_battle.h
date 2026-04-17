
#pragma once
#include "globals.h"
#include "module1_ui.h"
#include "module2_movement.h"

void outlineAroundShipInsaid(char map2[][19], int ship, int numShip);
void outlineAroundShip(char map1[][19], char map2[][19], int ship);
void winn(int numWin);

void outlineAroundShipInsaid(char map2[][19], int ship, int numShip) {
    if (numShip == 1) {
        for (int i=0;i<ship;i++){
            if(map2[y+i][x+1]==' ') map2[y+i][x+1]='*';
            if(map2[y+i][x-1]==' ') map2[y+i][x-1]='*';
        }
        if(map2[y-1][x]==' ')   map2[y-1][x]='*';
        if(map2[y-1][x+1]==' ') map2[y-1][x+1]='*';
        if(map2[y-1][x-1]==' ') map2[y-1][x-1]='*';
        if(map2[y+ship][x]==' ')   map2[y+ship][x]='*';
        if(map2[y+ship][x+1]==' ') map2[y+ship][x+1]='*';
        if(map2[y+ship][x-1]==' ') map2[y+ship][x-1]='*';
    } else if (numShip == 2) {
        for (int i=0;i<ship;i++){
            if(map2[y-i][x+1]==' ') map2[y-i][x+1]='*';
            if(map2[y-i][x-1]==' ') map2[y-i][x-1]='*';
        }
        if(map2[y+1][x]==' ')   map2[y+1][x]='*';
        if(map2[y+1][x+1]==' ') map2[y+1][x+1]='*';
        if(map2[y+1][x-1]==' ') map2[y+1][x-1]='*';
        if(map2[y-ship][x]==' ')   map2[y-ship][x]='*';
        if(map2[y-ship][x+1]==' ') map2[y-ship][x+1]='*';
        if(map2[y-ship][x-1]==' ') map2[y-ship][x-1]='*';
    } else if (numShip == 3) {
        for (int i=0;i<ship;i++){
            if(map2[y+1][x+i]==' ') map2[y+1][x+i]='*';
            if(map2[y-1][x+i]==' ') map2[y-1][x+i]='*';
        }
        if(map2[y][x-1]==' ')     map2[y][x-1]='*';
        if(map2[y+1][x-1]==' ')   map2[y+1][x-1]='*';
        if(map2[y-1][x-1]==' ')   map2[y-1][x-1]='*';
        if(map2[y][x+ship]==' ')   map2[y][x+ship]='*';
        if(map2[y+1][x+ship]==' ') map2[y+1][x+ship]='*';
        if(map2[y-1][x+ship]==' ') map2[y-1][x+ship]='*';
    } else if (numShip == 4) {
        for (int i=0;i<ship;i++){
            if(map2[y+1][x-i]==' ') map2[y+1][x-i]='*';
            if(map2[y-1][x-i]==' ') map2[y-1][x-i]='*';
        }
        if(map2[y][x+1]==' ')     map2[y][x+1]='*';
        if(map2[y+1][x+1]==' ')   map2[y+1][x+1]='*';
        if(map2[y-1][x+1]==' ')   map2[y-1][x+1]='*';
        if(map2[y][x-ship]==' ')   map2[y][x-ship]='*';
        if(map2[y+1][x-ship]==' ') map2[y+1][x-ship]='*';
        if(map2[y-1][x-ship]==' ') map2[y-1][x-ship]='*';
    }
}

void outlineAroundShip(char map1[][19], char map2[][19], int ship) {
    if (map2[y+1][x]==88 && map2[y-1][x]==88 && map1[y+2][x]!=ship && map1[y-2][x]!=ship) {
        y++; outlineAroundShipInsaid(map2, 3, 2);
    } else if (map2[y+1][x]==88 && map2[y+2][x]==88 && map2[y-1][x]==88) {
        y+=2; outlineAroundShipInsaid(map2, 4, 2);
    } else if (map2[y-1][x]==88 && map2[y-2][x]==88 && map2[y+1][x]==88) {
        y-=2; outlineAroundShipInsaid(map2, 4, 1);
    }
    if (map2[y][x+1]==88 && map2[y][x-1]==88 && map1[y][x+2]!=ship && map1[y][x-2]!=ship) {
        x++; outlineAroundShipInsaid(map2, 3, 4);
    } else if (map2[y][x+1]==88 && map2[y][x+2]==88 && map2[y][x-1]==88) {
        x+=2; outlineAroundShipInsaid(map2, 4, 4);
    } else if (map2[y][x-2]==88 && map2[y][x+1]==88 && map2[y][x-1]==88) {
        x-=2; outlineAroundShipInsaid(map2, 4, 3);
    }
    if      (map1[y+1][x]!=ship && map1[y-1][x]!=ship && map1[y][x+1]!=ship && map1[y][x-1]!=ship)
        outlineAroundShipInsaid(map2, 1, 1);
    else if (map2[y+1][x]==88) {
        if      (map1[y+2][x]!=ship && map1[y-1][x]!=ship) outlineAroundShipInsaid(map2, 2, 1);
        else if (map2[y+2][x]==88) {
            if      (map1[y+3][x]!=ship && map1[y-1][x]!=ship) outlineAroundShipInsaid(map2, 3, 1);
            else if (map2[y+3][x]==88)                          outlineAroundShipInsaid(map2, 4, 1);
        }
    } else if (map2[y-1][x]==88) {
        if      (map1[y-2][x]!=ship && map1[y+1][x]!=ship) outlineAroundShipInsaid(map2, 2, 2);
        else if (map2[y-2][x]==88) {
            if      (map1[y-3][x]!=ship && map1[y+1][x]!=ship) outlineAroundShipInsaid(map2, 3, 2);
            else if (map2[y-3][x]==88)                          outlineAroundShipInsaid(map2, 4, 2);
        }
    } else if (map2[y][x+1]==88) {
        if      (map1[y][x+2]!=ship && map1[y][x-1]!=ship) outlineAroundShipInsaid(map2, 2, 3);
        else if (map2[y][x+2]==88) {
            if      (map1[y][x+3]!=ship && map1[y][x-1]!=ship) outlineAroundShipInsaid(map2, 3, 3);
            else if (map2[y][x+3]==88)                          outlineAroundShipInsaid(map2, 4, 3);
        }
    } else if (map2[y][x-1]==88) {
        if      (map1[y][x-2]!=ship && map1[y][x+1]!=ship) outlineAroundShipInsaid(map2, 2, 4);
        else if (map2[y][x-2]==88) {
            if      (map1[y][x-3]!=ship && map1[y][x+1]!=ship) outlineAroundShipInsaid(map2, 3, 4);
            else if (map2[y][x-3]==88)                          outlineAroundShipInsaid(map2, 4, 4);
        }
    }
}

void winn(int numWin) {
    do {
        printStuff(0, 0);
        LogoSea();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 12);
        cout << "\n\n\n";
        cout << "\t\t\t\t IGROK " << numWin << " POBEDIL !!!";
        cout << "\n\n";
        cout << "\t\t\t Nazhmi Esc dlya vyhoda v menyu";
        SetConsoleTextAttribute(h, 15);
        int btn = _getch();
        if (btn == 27) esc = 1;
    } while (esc == 0);
}
