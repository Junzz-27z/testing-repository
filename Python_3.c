#include <stdio.h>

char nilaiHuruf(int nilai) {
    if (nilai >= 85) {
        return 'A';
    } else if (nilai >= 75) {
        return 'B';
    } else if (nilai >= 60) {
        return 'C';
    } else if (nilai >= 45) {
        return 'D';
    } else {
        return 'E';
    }
}

int hitungLulus(int arr[], int n) {
    int lulus = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 75) {
            lulus++;
        }
    }
    return lulus;
}

int main() {
    int jumlahMahasiswa;
    int jumlahLulus;
    int jumlahRemedial;
    int nilai[40];

    do {
        printf("Masukkan jumlah mahasiswa (1-40): ");
        scanf("%d", &jumlahMahasiswa);
        if (jumlahMahasiswa < 1 || jumlahMahasiswa > 40) {
            printf("Jumlah tidak valid!\n");
        }
    } while (jumlahMahasiswa < 1 || jumlahMahasiswa > 40);

    for (int i = 0; i < jumlahMahasiswa; i++) {
        do {
            printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
            scanf("%d", &nilai[i]);
            if (nilai[i] < 0 || nilai[i] > 100) {
                printf("Nilai tidak valid!\n");
            }
        } while (nilai[i] < 0 || nilai[i] > 100);
    }

    jumlahLulus = hitungLulus(nilai, jumlahMahasiswa);
    jumlahRemedial = jumlahMahasiswa - jumlahLulus;

    printf("\n===== REKAP KUIS DASAR PEMROGRAMAN (KKM 75) =====\n");
    printf("No | Nilai | Huruf | Keterangan\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("%2d |%6d |   %c   | %s\n",
               i + 1,
               nilai[i],
               nilaiHuruf(nilai[i]),
               (nilai[i] >= 75) ? "Lulus" : "Remedial");
    }

    printf("Jumlah lulus    : %d\n", jumlahLulus);
    printf("Jumlah remedial : %d\n", jumlahRemedial);

    return 0;
}