extern int * BubbleSort(int *, int);
extern int * SelectionSort(int *, int);
extern int * InsertionSort(int *, int);
extern int * QuickSort(int *, int);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int FillWithRandomInts(int * array1, int * array2, int length);

void _SelectionSort(int * a, int n);

void _BubbleSort(int * a, int n);

void _QuickSort(int * a, int n);

void _InsertionSort(int * a, int n);

int main(){

    int arr1[10000], arr2[10000], arr3[10000], arr4[10000],
        arr5[10000], arr6[10000], arr7[10000], arr8[10000];

    clock_t start = 0, end = 0;

    double times[8] = {0,0,0,0,0,0,0,0};

    FillWithRandomInts(arr1,arr5,10000);
    FillWithRandomInts(arr2,arr6,10000);
    FillWithRandomInts(arr3,arr7,10000);
    FillWithRandomInts(arr4,arr8,10000);

    start = clock();
    BubbleSort(arr1,10000);
    end = clock();
    times[0] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    SelectionSort(arr2,10000);
    end = clock();
    times[1] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    QuickSort(arr3,10000);
    end = clock();
    times[2] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    InsertionSort(arr4,10000);
    end = clock();
    times[3] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    _BubbleSort(arr5,10000);
    end = clock();
    times[4] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    _SelectionSort(arr6,10000);
    end = clock();
    times[5] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    _QuickSort(arr7,10000);
    end = clock();
    times[6] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    _InsertionSort(arr8,10000);
    end = clock();
    times[7] = ((double) (end - start)) / CLOCKS_PER_SEC;

    for(int i = 0; i < 8; i++){
        printf("%f\n",times[i]);
    }

    return 0;
}

int FillWithRandomInts(int * array1, int * array2, int length){

    int a = 0;

    for(int i = 0; i < length; i++){

        a = rand() % 10000;
        array1[i] = a;
        array2[i] = a;
    }

    return 0;
}

void _SelectionSort(int * a, int n){
  int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void _BubbleSort(int * a, int n){
  int i, t, s = 1;
  while (s) {
      s = 0;
      for (i = 1; i < n; i++) {
          if (a[i] < a[i - 1]) {
              t = a[i];
              a[i] = a[i - 1];
              a[i - 1] = t;
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
  for (i = 0, j = n - 1;; i++, j--) {
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
