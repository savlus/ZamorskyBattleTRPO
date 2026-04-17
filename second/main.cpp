
#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include "module1_ui.h"
#include "module2_movement.h"
#include "module3_battle.h"

// ========== ОПРЕДЕЛЕНИЕ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ ==========
int x = 9;
int y = 9;
int e = 0;
int ship = 0;
int user = 0;
int esc = 0;

Field mapfield1, mapfield2, mapfield3, mapfield4;

int main() {
    ConsoleWindow();

menuGameAgain:
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    CursorVisible();
    changFont();

    int viborSea  = 0;
    int buttonSea1 = 0;
    int buttonSea2 = 0;

    LogoSea();

    do {
        if (buttonSea2 == 80 || viborSea == 0) {
            if (viborSea < 4 && viborSea != 0) ++viborSea; else viborSea = 1;
            fViborSea(viborSea);
            buttonSea1 = _getch();
            if (buttonSea1 == 13) { printStuff(0, 12); break; }
            else if (buttonSea1 == 27) { system("cls"); x=21; y=9; ship=0; user=0; esc=0; goto menuGameAgain; }
            else if (buttonSea1 != 224) { viborSea=0; printStuff(0,12); continue; }
            buttonSea2 = _getch();
            if (buttonSea2 == 77 || buttonSea2 == 75) { viborSea=0; printStuff(0,12); continue; }
            printStuff(0, 12);
        } else if (buttonSea2 == 72) {
            if (viborSea <= 4 && viborSea > 1) --viborSea; else viborSea = 4;
            fViborSea(viborSea);
            buttonSea1 = _getch();
            if (buttonSea1 == 13) { printStuff(0, 12); break; }
            else if (buttonSea1 == 27) { system("cls"); x=21; y=9; ship=0; user=0; esc=0; goto menuGameAgain; }
            else if (buttonSea1 != 224) { viborSea=0; printStuff(0,12); continue; }
            buttonSea2 = _getch();
            if (buttonSea2 == 77 || buttonSea2 == 75) { viborSea=0; printStuff(0,12); continue; }
            printStuff(0, 12);
        }
    } while (true);

    system("cls");

    if (viborSea == 1) {
        while (true) {
            if (esc == 1) { x=9; y=9; ship=0; user=0; esc=0; goto menuGameAgain; }

            printStuff(0, 0);
            LogoSea();

            if (ship == 12) { x=48; y=9; ship=0; user=1; system("cls"); }

            if (user == 0 && ship != 13) {
                OkrasField(mapfield1.map, 6, 9, 6, 0, 0, 10, 13);
                OkrasField(mapfield2.map, 6, 9, 6, 0, 0, 10, 39);
                if (ship != 11 && ship != 13) { menuBeckShip("\tIGROK 1"); printStuff(0,31); }
            } else if (user == 1 && ship != 13) {
                OkrasField(mapfield1.map, 6, 9, 0, 0, 0, 10, 13);
                OkrasField(mapfield2.map, 6, 9, 0, 6, 0, 10, 39);
                if (ship != 11 && ship != 13) { menuBeckShip("\tIGROK 2"); printStuff(0,31); }
            }

            int but = 0;
            if (_kbhit()) but = _getch();

            if (user == 0 && ship != 11 && ship != 12) { moveField(mapfield1.map, but); drawingShips(mapfield1.map, but); }
            if (user == 1 && ship != 11 && ship != 12) { moveField(mapfield2.map, but); drawingShips(mapfield2.map, but); }

            if (ship == 11 || ship == 12) {
                printStuff(0, 0); LogoSea();
                string msg1 = (user == 0)
                    ? "\t\t1 - skryt korabli i smenit igroka"
                    : "\t\t1 - skryt korabli i pereyt k strelbe";
                printStuff(0, 31);
                OkrasMenu(msg1, 6);                              cout << "\n\n";
                OkrasMenu("\t\tBackspace - steret pole", 6);     cout << "\n\n";
                OkrasMenu("\t\tEsc - glavnoe menyu", 6);         cout << "\n\n";

                if (but == 49) {
                    if (user == 0) { eliminationSticking(mapfield1.map); ship = 12; }
                    else           { ship = 13; eliminationSticking(mapfield2.map); system("cls"); }
                } else if (but == 8) {
                    if (user == 0) for(int i=4;i<14;i++) for(int j=4;j<14;j++) mapfield1.map[i][j]=' ';
                    else           for(int i=2;i<12;i++) for(int j=42;j<52;j++) mapfield2.map[i][j]=' ';
                    system("cls"); ship = 0;
                }
            }

            if (but == 27) esc = 1;

            int hit_user1 = 0, hit_user2 = 0, numWin = 0;

            while (ship == 13) {
                printStuff(0, 0);
                int but2 = 0;
                LogoSea();
                OkrasField(mapfield3.map, 6, 9, 0, 0, 12, 10, 13);
                OkrasField(mapfield4.map, 6, 9, 0, 0, 12, 10, 39);
                if (_kbhit()) but2 = _getch();

                if (user == 1 || user == 3) {
                    user = 3;
                    printStuff(0, 31);
                    OkrasMenu("\t\t\t    HOD IGROKA 1.", 12); cout << "\n\n";
                    OkrasMenu("\t\t    Probel - vystrel", 6);
                    moveField(mapfield4.map, but2);

                    if (but2 == 32) {
                        if (mapfield2.map[y][x] == ' ') {
                            mapfield4.map[y][x] = '*'; user = 4;
                            int z=0;
                            for(int i=3;i<15;i++){for(int j=3;j<15;j++){if(mapfield3.map[i][j]==' '){z=1;x=j;y=i;mapfield3.map[i][j]=' ';break;}}if(z==1){e=0;break;}}
                        } else if (mapfield2.map[y][x] == 4) {
                            mapfield4.map[y][x] = 88;
                            if (mapfield4.map[y][x] == 88) outlineAroundShip(mapfield2.map, mapfield4.map, 4);
                            int z=0;
                            for(int i=3;i<15;i++){for(int j=3;j<15;j++){if(mapfield4.map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1){e=0;break;}}
                            hit_user1++; user = 3;
                        }
                    }
                    if (but2 == 27) {
                        for(int i=4;i<14;i++) for(int j=4;j<14;j++){mapfield1.map[i][j]=' ';mapfield3.map[i][j]=' ';}
                        for(int i=2;i<12;i++) for(int j=42;j<52;j++){mapfield2.map[i][j]=' ';mapfield4.map[i][j]=' ';}
                        system("cls"); esc=1; break;
                    }
                }
                else if (user == 4) {
                    printStuff(0, 31);
                    OkrasMenu("\t\t\t    HOD IGROKA 2.", 12); cout << "\n\n";
                    OkrasMenu("\t\t    Probel - vystrel", 6);
                    moveField(mapfield3.map, but2);

                    if (but2 == 32) {
                        if (mapfield1.map[y][x] == ' ') {
                            mapfield3.map[y][x] = '*'; user = 3;
                            int z=0;
                            for(int i=1;i<15;i++){for(int j=41;j<53;j++){if(mapfield4.map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1){e=0;break;}}
                        } else if (mapfield1.map[y][x] == 127) {
                            mapfield3.map[y][x] = 88;
                            if (mapfield3.map[y][x] == 88) outlineAroundShip(mapfield1.map, mapfield3.map, 127);
                            int z=0;
                            for(int i=3;i<15;i++){for(int j=3;j<15;j++){if(mapfield3.map[i][j]==' '){z=1;x=j;y=i;break;}}if(z==1){e=0;break;}}
                            hit_user2++; user = 4;
                        }
                    }
                    if (but2 == 27) {
                        for(int i=4;i<14;i++) for(int j=4;j<14;j++){mapfield1.map[i][j]=' ';mapfield3.map[i][j]=' ';}
                        for(int i=2;i<12;i++) for(int j=42;j<52;j++){mapfield2.map[i][j]=' ';mapfield4.map[i][j]=' ';}
                        system("cls"); esc=1; break;
                    }
                }

                if      (hit_user1 == 20) { system("cls"); numWin=1; winn(numWin); break; }
                else if (hit_user2 == 20) { system("cls"); numWin=2; winn(numWin); break; }
            }

            if (esc == 1) {
                for(int i=4;i<14;i++) for(int j=4;j<14;j++) mapfield1.map[i][j]=' ';
                for(int i=2;i<12;i++) for(int j=42;j<52;j++) mapfield2.map[i][j]=' ';
                system("cls");
            }
        }
    }
    else if (viborSea == 2) {
        do {
            system("cls"); LogoSea(); mapInstr();
            int butt = _getch();
            if (butt == 27) esc = 1;
        } while (esc == 0);
        if (esc == 1) { system("cls"); x=9; y=9; ship=0; user=0; esc=0; goto menuGameAgain; }
    }
    else if (viborSea == 3) {
        system("cls"); LogoSea();
        int butt;
        do {
            mapAutor();
            if (_kbhit()) { butt = _getch(); if (butt == 27) break; }
        } while (true);
        system("cls"); x=9; y=9; ship=0; user=0; esc=0; goto menuGameAgain;
    }
    else if (viborSea == 4) {
        system("cls"); return 0;
    }

    return 0;
}
