
#pragma once
#include "globals.h"

// ========== ОБЪЯВЛЕНИЯ ==========
void OkrasLogoSea(char map[][80]);
void OkrasMenu(string vibor, int color);
void OkrasField(char map[][19], int color1, int color2, int color3, int color4, int color5, int color6, int xPos);
void LogoSea();
void fViborSea(int count);
void menuBeckShip(string shipName);
void mapAutor();
void mapInstr();
void CursorVisible();
void printStuff(int px, int py);
void ConsoleWindow();
void changFont();
void OkrasLogoSea(char map[][80]) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 10; i++) {
        SetConsoleTextAttribute(h, (i % 2 == 0) ? 6 : 9);
        cout << "\t" << map[i] << "\n";
        SetConsoleTextAttribute(h, 15);
    }
}

void OkrasMenu(string vibor, int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    cout << vibor;
    SetConsoleTextAttribute(h, 15);
}

void OkrasField(char map[][19], int color1, int color2, int color3, int color4, int color5, int color6, int xPos) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 17; i++) {
        printStuff(xPos, i + 12);
        for (int j = 0; j < 19; j++) {
            unsigned char ch = (unsigned char)map[i][j];
            int col = color2;
            if      (ch == '.')  col = color1;
            else if (ch == 127)  col = color3;
            else if (ch == 4)    col = color4;
            else if (ch == 'X')  col = color5;
            else if (ch == '@')  col = color6;
            SetConsoleTextAttribute(h, col);
            cout << map[i][j];
            SetConsoleTextAttribute(h, 15);
        }
        cout << "\n";
    }
    mapfield2.map[0][12] = '2';
    mapfield4.map[0][12] = '2';
}

void LogoSea() {

    char mapLogo[10][80] = {
        " ####    #   #   #  ###  ####   #### #   # #   # #####",
        "    #  #   # ## ## #   # #   # #     #  #  #  ## #    ",
        " ###   ##### # # # #   # ####  #     ###   # # # #### ",
        "    #  #   # #   # #   # #     #     #  #  ##  # #    ",
        " ####  #   # #   #  ###  #      #### #   # #   # #####",
        "                                         ####   ###   ####",
        "                                          #    #   # #   #",
        "                                          #### #   #  ####",
        "                                          #  # #   #  #  #",
        "                                         #####  ###  #   #"
    };
    OkrasLogoSea(mapLogo);
}

void fViborSea(int count) {

    string s1 = " 1. \x88\x80\x93\x80\x94\x88 ";
    string s2 = " 2. \x8F\x88\x91\x80\x8D\x88\x95 ";
    string s3 = " 3. \x92\x82\x8E\x90\x96\x9B ";
    string s4 = " 4. \x88\x91\x95\x8E\x84";

    string oneVibor   = " 1. IGRAT ";
    string twoVibor   = " 2. PRAVILA ";
    string threeVibor = " 3. AVTORY ";
    string fourVibor  = " 4. VYHOD";

    int a1=9, a2=9, a3=9, a4=9;
    if      (count == 1) a1 = 6;
    else if (count == 2) a2 = 6;
    else if (count == 3) a3 = 6;
    else if (count == 4) a4 = 6;

    cout << "\n\n";
    cout << "\t\t\t\t"; OkrasMenu(oneVibor, a1);   cout << "\n\n";
    cout << "\t\t\t\t"; OkrasMenu(twoVibor, a2);   cout << "\n\n";
    cout << "\t\t\t\t"; OkrasMenu(threeVibor, a3); cout << "\n\n";
    cout << "\t\t\t\t"; OkrasMenu(fourVibor, a4);  cout << "\n\n";
}

void menuBeckShip(string shipName) {
    printStuff(0, 31);
    OkrasMenu(" === USTANOVITE KORABLI === ", 6); cout << "\n\n";
    OkrasMenu(shipName, 9);                        cout << "\n\n";
    OkrasMenu("\t\t1 - gorizontalno (sleva napravo)", 6); cout << "\n\n";
    OkrasMenu("\t\t2 - vertikalno (snizu vverh)", 6);     cout << "\n\n";
    OkrasMenu("\t\tBackspace - steret pole", 6);           cout << "\n\n";
    OkrasMenu("\t\tEsc - glavnoe menyu", 6);               cout << "\n\n";
}

void mapAutor() {
    const char* lines[] = {
        "   &&&&   &&&&  &&&&       &&&&  &&  &&    &&&    ",
        " &&&       &&   &&  &&   &&&     &&  &&  &&       ",
        " &&        &&   &&&&&&   &&      &&  &&  &&       ",
        " &&        &&   &&&&&&&  &&      &&  &&    &&     ",
        " &&&       &&   &&   &&  &&&     &&&&&&     &&    ",
        "   &&&&   &&&&  &&   &&    &&&&   &&&&   &&&      ",
    };
    int colors[] = {12, 6, 14, 10, 11, 9, 13};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    printStuff(0, 15);
    for (int c = 0; c < 7; c++) {
        printStuff(0, 15);
        for (int i = 0; i < 6; i++) {
            SetConsoleTextAttribute(h, colors[c]);
            cout << lines[i] << "\n";
        }
        SetConsoleTextAttribute(h, 15);
        Sleep(120);
    }
}

void mapInstr() {
    const char* lines[] = {
        "              === MORSKOY BOY - PRAVILA ===",
        "",
        "  Igrayut dvoe igrokov.",
        "",
        "  Sostav flotov (u kazhdogo igroka):",
        "",
        "    4 korablya po 1 kletke  (odnopalabnye)",
        "    3 korablya po 2 kletki  (dvuhpalubnyye)",
        "    2 korablya po 3 kletki  (tryohpalubnyye)",
        "    1 korabl  po 4 kletki  (chetyryohpalubnyy)",
        "",
        "  Pravila raspostanovki:",
        "    - mezhdu korablyami dolzhna byt pustaya kletka",
        "    - korably mogut kasatsya kraev polya",
        "",
        "  Igra:",
        "    - igroki poocheryodono strelyayut",
        "    - promah -> hod perehodit soperniku",
        "    - popodaniye -> igroku daruetsya eshchyo odin vystrel",
        "    - pobezhdayet tot, kto pervym potopil vse korabli",
        "",
        "  Upravleniye: strelki - dvizheniye, probel - vystrel, Esc - menyu",
    };
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    printStuff(0, 12);
    for (int i = 0; i < 22; i++) {
        SetConsoleTextAttribute(h, 6);
        cout << "  " << lines[i] << "\n";
        SetConsoleTextAttribute(h, 15);
    }
}

void CursorVisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(hConsole, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &ci);
}

void ConsoleWindow() {
    HWND w = GetConsoleWindow();
    SetWindowPos(w, HWND_TOP, 200, 100, 800, 1000, SWP_SHOWWINDOW);
}

void printStuff(int px, int py) {
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cd; cd.X = (SHORT)px; cd.Y = (SHORT)py;
    SetConsoleCursorPosition(hd, cd);
}

void changFont() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 16;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
