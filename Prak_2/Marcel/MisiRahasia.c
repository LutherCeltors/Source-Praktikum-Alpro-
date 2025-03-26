#include <stdio.h>
#include <string.h>

int isLeapYear(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int getDaysInMonth(int month, int year)
{
  if (month == 2)
  return isLeapYear(year) ? 29 : 28;
  return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

int isValidDate(int day, int month, int year)
{
  return (1<= day && day <= getDaysInMonth(month, year) && 1 <= month && month <= 12 && year >= 1 );
}

int daysFromBeginning(int day, int month, int year)
{ 
  int totalDays = 0;

  for (int y = 1; y < year; y++) {
      totalDays += isLeapYear(y) ? 366 : 365;
  }

  for (int m = 1; m < month; m++) {
      totalDays += getDaysInMonth(m, year);
  }

  totalDays += day;

  return totalDays;
}

int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
  /*Dengan menggunakan fungsi daysFromBeginning maka selisih dari kedua tanggal yang dimasukkan ke dalam fungsi
  adalah selisih kedua tanggal*/
  return (daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1));
}

const char *getDayOfWeek(int day, int month, int year) 
{
  if (month < 3) {
      month += 12;
      year -= 1;
  }
  
  int K = year % 100;
  int J = year / 100;
  
  int dayIndex = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
  
  const char *days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
  return days[dayIndex];
}

const char *getZodiac(int d, int m) 
{
  switch (m) {
    case 1: return d > 19 ? "Aquarius" : "Capricorn";
    case 2: return d > 18 ? "Pisces" : "Aquarius";
    case 3: return d > 20 ? "Aries" : "Pisces";
    case 4: return d > 19 ? "Taurus" : "Aries";
    case 5: return d > 20 ? "Gemini" : "Taurus";
    case 6: return d > 20 ? "Cancer" : "Gemini";
    case 7: return d > 22 ? "Leo" : "Cancer";
    case 8: return d > 22 ? "Virgo" : "Leo";
    case 9: return d > 22 ? "Libra" : "Virgo";
    case 10: return d > 22 ? "Scorpio" : "Libra";
    case 11: return d > 21 ? "Sagittarius" : "Scorpio";
    case 12: return d > 21 ? "Capricorn" : "Sagittarius";
  }
}

const char *getPasaran(int day, int month, int year) {
  const char *pasaran[] = {"Pahing", "Pon", "Wage", "Kliwon", "Legi"};
  int totalDays = daysFromBeginning(day, month, year) - daysFromBeginning(1, 1, 1900); 
  return pasaran[totalDays % 5]; 
}

int main() {
  char command[20];
  int d, m, y, d1, m1, y1, d2, m2, y2;

  while (1) {
      scanf("%s", command);
      if (strcmp(command, "SELESAI") == 0) break;

      if (strcmp(command, "VALIDASI") == 0) {
          scanf("%d %d %d", &d, &m, &y);
          printf("%s\n", (1 <= d && d <= getDaysInMonth(m, y) && 1 <= m && m <= 12 && y >= 1) ? "YA" : "TIDAK");
      } else if (strcmp(command, "HARI") == 0) {
          scanf("%d %d %d", &d, &m, &y);
          printf("%s\n", getDayOfWeek(d, m, y));
      } else if (strcmp(command, "SELISIH") == 0) {
          scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
          printf("%d\n", dateDifference(d1, m1, y1, d2, m2, y2));
      } else if (strcmp(command, "ZODIAK") == 0) {
          scanf("%d %d", &d, &m);
          printf("%s\n", getZodiac(d, m));
      } else if (strcmp(command, "PASARAN") == 0) {
          scanf("%d %d %d", &d, &m, &y);
          printf("%s\n", getPasaran(d, m, y));
      }
  }
  return 0;
}