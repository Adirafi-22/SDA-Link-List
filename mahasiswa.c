#include "mahasiswa.h"

// Membuat node baru
Mahasiswa* createNode(char *nama, int nilaiUTS) {
    Mahasiswa *newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newNode->nama, nama);
    newNode->nilaiUTS = nilaiUTS;
    newNode->next = NULL;
    return newNode;
}

// Insert data secara terurut berdasarkan Nama (Ascending)
void insertAscending(Mahasiswa **head, char *nama, int nilaiUTS) {
    Mahasiswa *newNode = createNode(nama, nilaiUTS);
    Mahasiswa *current = *head, *prev = NULL;

    while (current != NULL && strcmp(current->nama, nama) < 0) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Insert data secara terurut berdasarkan Nilai UTS (Descending)
void insertDescending(Mahasiswa **head, char *nama, int nilaiUTS) {
    Mahasiswa *newNode = createNode(nama, nilaiUTS);
    Mahasiswa *current = *head, *prev = NULL;

    while (current != NULL && current->nilaiUTS > nilaiUTS) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Membuat salinan L1 tetapi diurutkan berdasarkan Nilai UTS (Descending)
Mahasiswa* sortByNilaiDescending(Mahasiswa *head) {
    Mahasiswa *sortedList = NULL;
    while (head != NULL) {
        insertDescending(&sortedList, head->nama, head->nilaiUTS);
        head = head->next;
    }
    return sortedList;
}

// Menampilkan daftar mahasiswa berdasarkan Nama (Ascending)
void printListAscending(Mahasiswa *head) {
    printf("\nData Mahasiswa (Ascending Nama):\n");
    while (head != NULL) {
        printf("%s - %d\n", head->nama, head->nilaiUTS);
        head = head->next;
    }
}

// Menampilkan daftar mahasiswa berdasarkan Nilai UTS (Descending)
void printListDescending(Mahasiswa *head) {
    printf("\nData Mahasiswa (Descending Nilai UTS):\n");
    while (head != NULL) {
        printf("%s - %d\n", head->nama, head->nilaiUTS);
        head = head->next;
    }
}

// Menghitung jumlah elemen dalam list
int countElements(Mahasiswa *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Menyalin mahasiswa dengan nilai UTS > 70 ke L2
void copyList(Mahasiswa *L1, Mahasiswa **L2) {
    while (L1 != NULL) {
        if (L1->nilaiUTS > 70)
            insertAscending(L2, L1->nama, L1->nilaiUTS);
        L1 = L1->next;
    }
}

// Menghapus nama duplikat di L2
void removeDuplicates(Mahasiswa **head) {
    Mahasiswa *current = *head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->nama, current->next->nama) == 0) {
            Mahasiswa *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Menghapus semua elemen dalam list
void destroyList(Mahasiswa **head) {
    Mahasiswa *current = *head;
    while (current != NULL) {
        Mahasiswa *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

