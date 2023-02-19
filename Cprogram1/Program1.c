/*
 * Program1.c
 *
 *  Created on: Feb 18, 2023
 *      Author: rahul
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MONTHS 12
#define NAME_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    float sales;
} Sale;

void print_sales_report(Sale sales[]);
void sort_sales(Sale sales[]);
float average_sales(Sale sales[]);
float min_sales(Sale sales[]);
float max_sales(Sale sales[]);
void six_month_average(Sale sales[]);

int main() {
    Sale sales[MONTHS];
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July ", "August", "September", "October", "November", "December"};
    //char *months2[MONTHS] = {"January", "February", "March", "April", "May", "June", "July ", "August", "September", "October", "November", "December"};
    FILE *fp;
    int i;
    float sales_value;

    fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (i = 0; i < MONTHS; i++) {
        fscanf(fp, "%f", &sales_value);
        strcpy(sales[i].name, months[i]);
        sales[i].sales = sales_value;
    }
    fclose(fp);

    print_sales_report(sales);

    return 0;
}

void print_sales_report(Sale sales[]) {
    int i;

    printf("Monthly sales report for 2022\n");
    printf("Month\t\tSales\n");
    for (i = 0; i < MONTHS; i++) {
        // Insert a tab character between the month name and the sales value
        // All the sales values should be in a line when printed

        printf("%-15s$%.2f\n", sales[i].name, sales[i].sales);
        //printf("%s-%s\t%.2f \n", sales[i].name, sales[i+5].name, sum / 6);



    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales(sales), sales[0].name);
    printf("Maximum sales: $%.2f (%s)\n", max_sales(sales), sales[MONTHS-1].name);
    printf("Average sales: $%.2f\n", average_sales(sales));

    printf("\nSix-Month moving average report:\n");
    six_month_average(sales);

    sort_sales(sales);

    printf("\nSales report (highest to lowest):\n");
    printf("Month\t\tSales\n");
    for (i = 0; i < MONTHS; i++) {
        // Insert a tab character between the month name and the sales value
        // Space variable
        printf("%-15s$%.2f\n", sales[i].name, sales[i].sales);
        //printf("%s\t$%.2f \n", sales[i].name, sales[i].sales);
        // printf("%3s","%.2f\n", sales[i].name, sales[i].sales);



    }
}

void sort_sales(Sale sales[]) {
    int i, j;
    Sale temp;

    for (i = 0; i < MONTHS - 1; i++) {
        for (j = 0; j < MONTHS - i - 1; j++) {
            if (sales[j].sales < sales[j+1].sales) {
                temp = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = temp;
            }
        }
    }
}

float average_sales(Sale sales[]) {
    int i;
    float sum = 0;

    for (i = 0; i < MONTHS; i++) {
        sum += sales[i].sales;
    }

    return sum / MONTHS;
}

float min_sales(Sale sales[]) {
    return sales[0].sales;
}

float max_sales(Sale sales[]) {
    return sales[MONTHS-1].sales;
}

void six_month_average(Sale sales[]) {
    int i;
    float sum;

    for (i = 0; i < MONTHS - 5; i++) {
        sum = sales[i].sales + sales[i+1].sales + sales[i+2].sales + sales[i+3].sales + sales[i+4].sales + sales[i+5].sales;
        // Print in the following format:
/*January-June   42584.61
February-July    50741.66
March-August     53424.80
April-September  55294.64
May-October      60363.34
June-November    67537.62
July-December    73375.12 */

        //printf("Six-month average for %s: %.2f (%.2f, %.2f, %.2f, %.2f, %.2f, %.2f)\n", sales[i].name, sum / 6, sales[i].sales, sales[i+1].sales, sales[i+2].sales, sales[i+3].sales, sales[i+4].sales, sales[i+5].sales);
        printf("%s-%s\t$%.2f \n", sales[i].name, sales[i+5].name, sum / 6);

    }
}
