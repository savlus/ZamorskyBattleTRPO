#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
using namespace std;

extern int x;
extern int y;
extern int e;
extern int ship;
extern int user;
extern int esc;

struct Field {
    char map[17][19] = {
        ".....IGROK--1.....",
        "..................",
        "....12345678910...",
        "...+----------+...",
        "..A|          |...",
        "..B|          |...",
        "..C|          |...",
        "..D|          |...",
        "..E|          |...",
        "..F|          |...",
        "..G|          |...",
        "..H|          |...",
        "..I|          |...",
        "..K|          |...",
        "...+----------+...",
        "..................",
        "..................",
    };
};

extern Field mapfield1, mapfield2, mapfield3, mapfield4;
