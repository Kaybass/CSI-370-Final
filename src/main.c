extern int * BubbleSort(int *, int);
extern int * SelectionSort(int *, int);
extern int * InsertionSort(int *, int);
extern int * QuickSort(int *, int);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _ARRAY_LENGTH 10000

#define _ASMBUBTIME   0
#define _CEEBUBTIME   4
#define _ASMSELTIME   1
#define _CEESELTIME   5
#define _ASMINSTIME   3
#define _CEEINSTIME   7
#define _ASMQCKTIME   2
#define _CEEQCKTIME   6

int FillWithRandomInts(int * array1, int * array2, int length);

int Check(int * array1, int * array2, int length);

void _SelectionSort(int * a, int n);

void _BubbleSort(int * a, int n);

void _QuickSort(int * a, int n);

void _InsertionSort(int * a, int n);

int main(){

    int arr1[_ARRAY_LENGTH], arr2[_ARRAY_LENGTH], arr3[_ARRAY_LENGTH], arr4[_ARRAY_LENGTH],
        arr5[_ARRAY_LENGTH], arr6[_ARRAY_LENGTH], arr7[_ARRAY_LENGTH], arr8[_ARRAY_LENGTH];

    clock_t start = 0, end = 0;

    double times[8] = {0,0,0,0,0,0,0,0};

    //initialize arrays
    FillWithRandomInts(arr1,arr5,_ARRAY_LENGTH);
    FillWithRandomInts(arr2,arr6,_ARRAY_LENGTH);
    FillWithRandomInts(arr3,arr7,_ARRAY_LENGTH);
    FillWithRandomInts(arr4,arr8,_ARRAY_LENGTH);


    //Get the time it takes to do the algorithms
    start = clock();
    BubbleSort(arr1,_ARRAY_LENGTH);
    end = clock();
    times[_ASMBUBTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    SelectionSort(arr2,_ARRAY_LENGTH);
    end = clock();
    times[_ASMSELTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    QuickSort(arr3,_ARRAY_LENGTH);
    end = clock();
    times[_ASMQCKTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    InsertionSort(arr4,_ARRAY_LENGTH);
    end = clock();
    times[_ASMINSTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    _BubbleSort(arr5,_ARRAY_LENGTH);
    end = clock();
    times[_CEEBUBTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    _SelectionSort(arr6,_ARRAY_LENGTH);
    end = clock();
    times[_CEESELTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    _QuickSort(arr7,_ARRAY_LENGTH);
    end = clock();
    times[_CEEQCKTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;
    start = clock();
    _InsertionSort(arr8,_ARRAY_LENGTH);
    end = clock();
    times[_CEEINSTIME] = ((double) (end - start)) / CLOCKS_PER_SEC;

    if(!Check(arr1,arr5,_ARRAY_LENGTH)){

        printf("\nArrays were properly sorted and ");

        if(times[_ASMBUBTIME] <= times[_CEEBUBTIME])
            printf("I won the BubbleSort by %f seconds\n", (times[_CEEBUBTIME] - times[_ASMBUBTIME]));

        else
            printf("I lost the BubbleSort by %f seconds :o(\n", (times[_ASMBUBTIME] - times[_CEEBUBTIME]));

        printf("The times were %f seconds for my sort and %f seconds for the C sort\n\n", times[_ASMBUBTIME], times[_CEEBUBTIME]);
    }
    else
        printf("\nSomething went horribly wrong oh no!\n");

    if(!Check(arr2,arr6,_ARRAY_LENGTH)){

        printf("\nArrays were properly sorted and ");

        if(times[_ASMSELTIME] <= times[_CEESELTIME])
            printf("I won the SelectionSort by %f seconds\n", (times[_CEESELTIME] - times[_ASMSELTIME]));

        else
            printf("I lost the SelectionSort by %f seconds :o(\n", (times[_ASMSELTIME] - times[_CEESELTIME]));

        printf("The times were %f seconds for my sort and %f seconds for the C sort\n\n", times[_ASMSELTIME], times[_CEESELTIME]);
    }
    else
        printf("\nSomething went horribly wrong oh no!\n");

    if(!Check(arr1,arr5,_ARRAY_LENGTH)){

        printf("\nArrays were properly sorted and ");

        if(times[_ASMQCKTIME] <= times[_CEEQCKTIME])
            printf("I won the QuickSort by %f seconds\n", (times[_CEEQCKTIME] - times[_ASMQCKTIME]));

        else
            printf("I lost the QuickSort by %f seconds :o(\n", (times[_ASMQCKTIME] - times[_CEEQCKTIME]));

        printf("The times were %f seconds for my sort and %f seconds for the C sort\n\n", times[_ASMQCKTIME], times[_CEEQCKTIME]);
    }
    else
        printf("\nSomething went horribly wrong oh no!\n");

    if(!Check(arr1,arr5,_ARRAY_LENGTH)){

        printf("\nArrays were properly sorted and ");

        if(times[_ASMINSTIME] <= times[_CEEINSTIME])
            printf("I won the InsertionSort by %f seconds\n", (times[_CEEINSTIME] - times[_ASMINSTIME]));

        else
            printf("I lost the InsertionSort by %f seconds :o(\n", (times[_ASMINSTIME] - times[_CEEINSTIME]));

        printf("The times were %f seconds for my sort and %f seconds for the C sort\n\n", times[_ASMINSTIME], times[_CEEINSTIME]);
    }
    else
        printf("\nSomething went horribly wrong oh no!\n");

    return 0;
}

int FillWithRandomInts(int * array1, int * array2, int length){

    int a = 0;

    for(int i = 0; i < length; i++){

        a = rand() % _ARRAY_LENGTH;
        array1[i] = a;
        array2[i] = a;
    }

    return 0;
}

int Check(int * array1, int * array2, int length){

    for(int i = 0; i < length; i++){

        if(!(array1[i] == array2[i]))
            return 1;
    }

    return 0;
}

void _SelectionSort(int * array, int length){

    int i, j, m, t;

    for (i = 0; i < length; i++) {

        for (j = i, m = i; j < length; j++) {

            if (array[j] < array[m])
                m = j;
        }

        t = array[i];
        array[i] = array[m];
        array[m] = t;
    }
}

void _BubbleSort(int * array, int length){

    int i, t, s = 1;

    while (s) {

        s = 0;

        for (i = 1; i < length; i++) {

            if (array[i] < array[i - 1]) {

                t = array[i];
                array[i] = array[i - 1];
                array[i - 1] = t;
                s = 1;
            }
        }
    }
}

void _QuickSort(int * a, int n){

    int i, j, p, t;

    if (n < 2)
        return;

    p = a[n / 2];

    for (i = 0, j = n - 1;; i++, j--){

        while (a[i] < p)
            i++;

        while (p < a[j])
            j--;

        if (i >= j)
            break;

        t = a[i];

        a[i] = a[j];
        a[j] = t;
    }
    _QuickSort(a, i);
    _QuickSort(a + i, n - i);
}

void _InsertionSort(int * a, int n){

    int i, j, t;

    for (i = 1; i < n; i++) {

        t = a[i];

        for (j = i; j > 0 && t < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }

        a[j] = t;
    }
}
