#include "mahasiswa.h"

int main() {
    Mahasiswa *L1 = NULL;
    Mahasiswa *L2 = NULL;
    int jumlah, nilai;
    char nama[50];

    // Meminta jumlah mahasiswa dari user
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);
    getchar(); // Menghindari newline dari scanf
	
	int i;
    for (i = 0; i < jumlah; i++) {
        printf("Masukkan Nama Mahasiswa %d: ", i + 1);
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0; // Hapus newline dari fgets

        printf("Masukkan Nilai UTS %s: ", nama);
        scanf("%d", &nilai);
        getchar(); // Hindari newline dari scanf()

        insertAscending(&L1, nama, nilai);
    }

    // Tampilkan daftar mahasiswa dalam urutan nama (Ascending)
    printListAscending(L1);

    // Buat salinan L1 yang diurutkan berdasarkan Nilai UTS (Descending)
    Mahasiswa *sortedByNilai = sortByNilaiDescending(L1);

    // Tampilkan daftar mahasiswa dalam urutan nilai UTS (Descending)
    printListDescending(sortedByNilai);

    // Hitung jumlah mahasiswa
    printf("\nJumlah mahasiswa dalam list: %d\n", countElements(L1));

    // Copy mahasiswa dengan nilai UTS > 70 ke L2
    copyList(L1, &L2);
    printf("\nData Mahasiswa di L2 (Sebelum Hapus Duplikat):\n");
    printListAscending(L2);

    // Hapus nama yang duplikat di L2
    removeDuplicates(&L2);
    printf("\nData Mahasiswa di L2 (Setelah Hapus Duplikat):\n");
    printListAscending(L2);

    // Hapus semua list
    destroyList(&L1);
    destroyList(&L2);
    destroyList(&sortedByNilai);

    return 0;
}

