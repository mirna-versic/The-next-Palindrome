#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string caseAllNines(string number, int length) {
    return (to_string)((int)pow(10.0, length) + 1);
}

string casePalindrome(string number, int length) {
    if (length % 2 != 0) {
        for (int i = length / 2; i >= 0; i--) {
            number[i] += 1;
            number[length - i -1] = number[i];

            if(number[i] != '0') break;
        }
    } else {
        for (int i = length / 2 - 1, j = length / 2; i >= 0; i--, j++) {
            number[i] += 1;
            number[j] += 1;

            if(number[i] != '0') break;
        }
    }

    return number;
}

string caseNotPalindrome(string number, int i, int j) {
    while (i >= 0) {
        number[j++] = number[i--];
    }

    return number;
}

//Computes indexes based on the information weather or not the length of the number is odd
void getIndexes (int* i, int* j, int length) {
    if (length % 2 == 0) {
        *i = length / 2 - 1;
        *j = length / 2;
    } else {
        *i = length / 2 - 1;
        *j = length / 2 + 1;
    }
}

string getNextPalindrome(string number, int length) {
    int i, j;
    unsigned int numOfNines = 0;

    if(length % 2 != 0 && number[length/2] == '9') numOfNines++;
    getIndexes(&i, &j, length);

    //Searches for the indexes from which on the number is not palindrome anymore
    while (number[i] == number[j] && i >= 0) {
        if(number[i] == '9') numOfNines += 2;
        i--;
        j++;
    }

    if (numOfNines == length) {
        number = caseAllNines(number, length);
    } else if (i < 0) {
        number = casePalindrome(number, length);
    }

    if (number[i] < number[j]){
        number = caseNotPalindrome(number, i, j);
        number = casePalindrome(number, length);
    } else {
        number = caseNotPalindrome(number, i, j);
    }

    return number;
}

int main(void) {
    int testCases;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        string number;
        cin >> number;

        cout << getNextPalindrome(number, number.length()) << endl;
    }

    return 0;
}
