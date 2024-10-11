#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int LENGTH = 12;

double mean(double nums[], int min, int max)
{
    double sum = 0;
    for (int i = min; i < max; i++) {
        sum += nums[i];
    }
    return sum / (max - min);
}

int compare(const void* a, const void* b) {
    return (*(double*)b - *(double*)a);
}

int main()
{
    FILE *in_file;
    in_file = fopen("sales_reports.txt", "r");
    char sales[20];
    double num[LENGTH];
    char *months[] = {"January", "Febraury", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    int i = 0;
    while(i < LENGTH) {
        if (fgets(sales, 20, in_file) != NULL) {
            sales[strcspn(sales, "\n")] = '\0';
            num[i] = strtod(sales, NULL);
            i++;
        }
    }

    printf("Monthly sales report for 2024\n%-10s%5s\n", "Month", "Sales");
    for (int i = 0; i < LENGTH; i++) {
        printf("%-10s%5.2lf\n", months[i], num[i]);
    }
    
    int min = 0;
    int max = 0;
    double sum = 0;
    for (int i = 0; i < LENGTH; i++) {
        if (num[i] < num[min]) {
            min = i;
        }
        if (num[i] > num[max]) {
            max = i;
        }
        sum += num[i];
    }
    double avg = sum / LENGTH;
    printf("\nSales summary report:\nMinimum sales\t%.2lf  (%s)\n", num[min], months[min]);
    printf("Maximum sales\t%.2lf  (%s)\n", num[max], months[max]);
    printf("Average sales\t%.2lf\n", avg);
    
    printf("\nSix-Month moving average report:\n");
    printf("%-17s%.2lf\n", "January-June", mean(num, 0, 6));
    printf("%-17s%.2lf\n", "February-July", mean(num, 1, 7));
    printf("%-17s%.2lf\n", "March-August", mean(num, 2, 8));
    printf("%-17s%.2lf\n", "April-September", mean(num, 3, 9));
    printf("%-17s%.2lf\n", "May-October", mean(num, 4, 10));
    printf("%-17s%.2lf\n", "June-November", mean(num, 5, 11));
    printf("%-17s%.2lf\n", "July-December", mean(num, 6, 12));
    
    printf("\nSales report (highest to lowest):\n%-12s%5s\n", "Month", "Sales");
    double sorted_nums[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        sorted_nums[i] = num[i];
    }
    int indexes[LENGTH];
    qsort(sorted_nums, LENGTH, sizeof(double), compare);
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (sorted_nums[i] == num[j]) {
                indexes[i] = j;
            }
        }
    }
    for (int i = 0; i < LENGTH; i++) {
        printf("%-12s$%.2lf\n", months[indexes[i]], num[indexes[i]]);
    }
    
    fclose(in_file);
    
    return 0;
}
