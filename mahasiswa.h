#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Mahasiswa
typedef struct Mahasiswa {
    char nama[50];
    int nilaiUTS;
    struct Mahasiswa *next;
} Mahasiswa;

// Prototype fungsi
Mahasiswa* createNode(char *nama, int nilaiUTS);
void insertAscending(Mahasiswa **head, char *nama, int nilaiUTS);
void insertDescending(Mahasiswa **head, char *nama, int nilaiUTS);
void printListAscending(Mahasiswa *head);
void printListDescending(Mahasiswa *head);
int countElements(Mahasiswa *head);
Mahasiswa* sortByNilaiDescending (Mahasiswa *head);
void copyList(Mahasiswa *L1, Mahasiswa **L2);
void removeDuplicates(Mahasiswa **head);
void destroyList(Mahasiswa **head);

#endif

