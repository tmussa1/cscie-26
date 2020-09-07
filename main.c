#include <stdio.h>
#include <limits.h>
#include <mem.h>
#include <stdlib.h>
#include <ctype.h>

int determineMonth(char date[20]);
void findDifferenceBetweenTwoDates();
void readNumbersAndCalculateMinMaxSum(int size);
void readFromFileAndCountLetters(char * fileLocation);

//Question 1
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

//Question 2
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

//Helper method for question 2
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

//Question 5
void readFromFileAndCountLetters(char * fileLocation){
    int character;
    FILE *file;
    file = fopen(fileLocation, "r");

    char letters[26];
    long letterCounts [26];

    if (file) {
        while ((character = getc(file)) != EOF){
            int index;

            if(tolower(character)  >= 'a' && tolower(character) <= 'z'){
                index = tolower(character) - 'a';
                letterCounts[index] += 1L;
                letters[index] = tolower(character);
            }
        }
        fclose(file);
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26 - i - 1; j++) {
            if(letterCounts[j] < letterCounts[j + 1]){
                long temp = letterCounts[j];
                char tempLetter = letters[j];
                letterCounts[j] = letterCounts[j + 1];
                letters[j] = letters[j + 1];
                letterCounts[j + 1] = temp;
                letters[j + 1] = tempLetter;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        printf("Letters sorted by occurrence: Letter %c, Count %d \n", letters[i], letterCounts[i]);
    }

    //Reference used - https://stackoverflow.com/questions/31495311/clion-c-cant-read-open-txt-file-in-project-directory
}

void main() {

    //Please uncomment this method to run one by one

    //readNumbersAndCalculateMinMaxSum(100);

    //findDifferenceBetweenTwoDates();

    //readFromFileAndCountLetters("C:\\Users\\12028\\Desktop\\MS in CS\\CSCI E-26\\projects\\fileToRead.txt");

}
