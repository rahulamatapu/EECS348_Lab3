/*
 * Program2.c
 *
 *  Created on: Feb 18, 2023
 *      Author: rahul
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TD 6
#define FG 3
#define SAFETY 2
#define TD_2PT 8
#define TD_FG 7

void print_combo(int tds, int fgs, int safeties, int td2pts, int tdFGs) {
  printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pts, tdFGs, tds, fgs, safeties);
}
// Print the combinations in order of increasing number of TDs
void print_combo2(int tds, int fgs, int safeties, int td2pts, int tdFGs) {
  printf("%d TD, %d TD + 2pt, %d TD + FG, %d 3pt FG, %d Safety\n", tds, td2pts, tdFGs, fgs, safeties);
}

void find_combinations(int score) {
  int tds, fgs, safeties, td2pts, tdFGs;
  for (td2pts = 0; td2pts <= score / TD_2PT; td2pts++) {
    for (tdFGs = 0; tdFGs <= score / TD_FG; tdFGs++) {
      for (tds = 0; tds <= score / TD; tds++) {
        for (fgs = 0; fgs <= score / FG; fgs++) {
          for (safeties = 0; safeties <= score / SAFETY; safeties++) {
            if (td2pts * TD_2PT + tdFGs * TD_FG + tds * TD + fgs * FG + safeties * SAFETY == score) {

              print_combo(tds, fgs, safeties, td2pts, tdFGs);
            }
          }
        }
      }
    }
  }
}

int main() {
  int score;
  printf("Enter 0 or 1 to STOP\n");
  while (1) {
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if (score <= 1) {
      break;
    }
    printf("Possible combinations of scoring plays:\n");
    find_combinations(score);
  }
  return 0;
}

