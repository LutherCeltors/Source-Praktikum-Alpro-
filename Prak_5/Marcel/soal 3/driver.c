#include <stdio.h>
#include "operasi.h"

int main() {
    // Step 1: Buat data vital dan lokasi
    Vital v1 = MakeVital(120, 80, 98.5);
    Vital v2 = MakeVital(150, 70, 94.0);  // Tidak sehat
    Lokasi l1 = MakeLokasi(0, 0);
    Lokasi l2 = MakeLokasi(1, 2);

    // Step 2: Buat pasien
    Pasien p1 = MakePasien("Andi", v1, l1);
    Pasien p2 = MakePasien("Budi", v2, l2);

    // Step 3: Cetak info pasien
    printf("=== Info Pasien 1 ===\n");
    PrintPasien(p1);

    printf("\n=== Info Pasien 2 ===\n");
    PrintPasien(p2);

    // Step 4: Cek kesehatan
    printf("\nIs p1 sehat? %s\n", IsSehat(v1) ? "YA" : "TIDAK");
    printf("Is p2 sehat? %s\n", IsSehat(v2) ? "YA" : "TIDAK");

    // Step 5: Bandingkan vital
    printf("\nCompare Vital p1 vs p2: %d\n", CompareVital(v1, v2));  // Expected: 1

    // Step 6: Ubah lokasi p1
    printf("\nPindah Pasien 1 ke (+2, +1)\n");
    PindahPasien(&p1.l, 2, 1);
    PrintLokasi(p1.l);

    // Step 7: Reset vital p2
    printf("\nReset Vital Pasien 2:\n");
    ResetVital(&p2.v);
    PrintVital(p2.v);

    // Step 8: Gunakan Mutator
    printf("\nUpdate Detak jantung p1 menjadi 95:\n");
    SetDetak(&p1.v, 95);
    printf("Detak jantung p1: %d\n", GetDetak(p1.v));

    return 0;
}
