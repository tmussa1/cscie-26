#include <stdio.h>
#include <limits.h>
#include <mem.h>
#include <stdlib.h>

int determineMonth(char date[20]);

void readNumbersAndCalculateMinMaxSum(int size){

    int numbers[size];
    int index = 0;

    printf("Please enter a non-negative number\n");
    scanf("%d", (numbers + index));

    while(numbers[index] != 0){

        index++;

        printf("Please enter '0' to quit \n");

        scanf("%d", (numbers + index));
    }

    int max = 0, min = INT_MAX, sum = 0, i = 0;

    while(numbers[i] != 0) {

        if(numbers[i] > max){
            max = numbers[i];
        }

        if(numbers[i] < min){
            min = numbers[i];
        }

        sum += numbers[i];
        i++;
    }

    printf("Sum %d Maximum %d Minimum %d ", sum, max, min);

}

void findDifferenceBetweenTwoDates(){

    char firstMonth[20], firstDay[5], secondMonth[20], secondDay[5];

    int datesInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Please enter the first date \n");
    scanf("%s", firstMonth);

    while (getchar() != '\n') {
        scanf("%s", firstDay);
    }

    printf("Please enter the second date \n");
    scanf("%s", secondMonth);
    while (getchar() != '\n') {
        scanf("%s", secondDay);
    }

    int firstMonthIndex = determineMonth(firstMonth);
    int secondMonthIndex = determineMonth(secondMonth);

    int result = 0;

    for(int i = firstMonthIndex + 1; i < secondMonthIndex; i++){
        result += datesInMonths[i];
    }

    result += (datesInMonths[firstMonthIndex] - atoi(firstDay))+ atoi(secondDay);

    printf("Difference in dates %d \n", result);

}

int determineMonth(char date[20]) {

    char month[4];
    strncpy(month, date, 3);

    month[3] = '\0';

    char * months [12] = {"Jan", "Feb", "Mar", "Apr",
                           "May", "Jun", "Jul", "Aug", "Sep",
                           "Oct", "Nov", "Dec"};

    for(int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i;
        }
    }

    return 0;
}

void main() {

    readNumbersAndCalculateMinMaxSum(100);

    findDifferenceBetweenTwoDates();
}
