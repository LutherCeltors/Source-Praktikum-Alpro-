#include <stdio.h>

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * Untuk tahun kelipatan 100, tahun kabisat harus habis dibagi 400
 * Untuk tahun selain kelipatan 100, tahun kabisat harus habis dibagi 4
 * @param year Tahun
 * @return Mengembalikan 1 jika tahun kabisat, 0 jika tidak
 */
int isLeapYear(int year)
{
  if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)){
    return 1;
  }else{
    return 0;
  }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
 * @param month Bulan (dalam rentang 1-12)
 * @param year Tahun
 * @return Mengembalikan jumlah hari dalam bulan tersebut
 */
int getDaysInMonth(int month, int year)
{
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    return 31;
  }else if (month == 2) {
    if (isLeapYear(year) == 1){
        return 29;
    }else{
        return 28;
    }
  }else{
    return 30;
  }
}

/**
 * Mengembalikan apakah tanggal valid
 * Tanggal yang valid mengikuti aturan berikut:
 * - 1 <= day <= jumlah hari dalam bulan
 * - 1 <= month <= 12
 * - year >= 1
 * @param day The day
 * @param month The month
 * @param year The year
 * @return mengembalikan 1 jika tanggal valid, 0 jika tidak
 */
int isValidDate(int day, int month, int year)
{
  if (1<= day && day <= getDaysInMonth(month, year) && 1 <= month && month <= 12 && year >= 1 ){
    return 1;
  }else{
    return 0;
  }
}

/**
 * Fungsi untuk menghitung jumlah hari sejak awal, yaitu day = 1, month = 1, year = 1
 * @param day Hari
 * @param month Bulan
 * @param year Tahun
 * @return Mengembalikan jumlah hari sejak awal
 */
int daysFromBeginning(int day, int month, int year)
{ 
  int sumDay;
  //jumlah hari 1 tahun sebelum menuju ke tahun yang sama.
  sumDay = 0;
  for (int y = 1; y<year; y++){
    for (int m = 1; m <= 12; m++){
        sumDay += getDaysInMonth(m, y);
    }
  }
  //Pada Tahun yang sama dengan target, dengan bulan berbeda
  for (int m = 1; m<month; m++){
    sumDay += getDaysInMonth(m, year);  
  }
  //Pada Bulan yang sama dan Tahun yang sama 
  sumDay += day;
  return sumDay;
}

/**
 * Fungsi untuk menghitung perbedaan hari dari dua tanggal yang valid (tanggal 2 - tanggal 1)
 * Note: input tanggal sudah valid
 * @param d1 Hari dari tanggal pertama
 * @param m1 Bulan dari tanggal pertama
 * @param y1 Tahun dari tanggal pertama
 * @param d2 Hari dari tanggal kedua
 * @param m2 Bulan dari tanggal kedua
 * @param y2 Tahun dari tanggal kedua
 * @return Mengembalikan perbedaan hari dari tanggal 2 - tanggal 1
 */
int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
  /*Dengan menggunakan fungsi daysFromBeginning maka selisih dari kedua tanggal yang dimasukkan ke dalam fungsi
  adalah selisih kedua tanggal*/
  return (daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1));
}

/**
 * Program utama:
 * - Menerima input d1,m1,y1
 * - Validasi tanggal pertama sampai input valid
 * - Menerima input d2,m2,y2
 * - Validasi tanggal kedua sampai input valid dan tanggal kedua lebih besar atau sama dengan dari tanggal pertama
 * - Mengeluarkan output selisih hari dari tanggal kedua - tanggal pertama
 */
int main()
{
    int d1 = 0, m1 = 0, y1 = 0;
    int d2 = 0, m2 = 0, y2 = 0;

    for (;;){
        scanf("%d %d %d", &d1, &m1, &y1);
        if ((isValidDate(d1, m1, y1)) == 1){
            break;       
        }else{
            printf("Tanggal tidak valid\n");
        }
    }//keluaran tanggal 1 valid
    for (;;){
        for (;;){
            scanf("%d %d %d", &d2, &m2, &y2);
            if ((isValidDate(d2, m2, y2)) == 1){
                break;
            }else{
                printf("Tanggal tidak valid\n");
            }
        }//keluaran tanggal 2 valid

        if (daysFromBeginning(d1, m1, y1) <= daysFromBeginning(d2, m2, y2)){
           break;
        }else{
           printf("Tanggal kedua lebih dulu\n");
        }
    }//Tanggal valid antara tanggal 1 dan tanggal 2

    printf("%d\n", (daysFromBeginning(d2, m2, y2)-daysFromBeginning(d1, m1, y1))); 
}