#include <iostream>

using namespace std;

/*
Created by Ricardo Naranjo Polit
Problem name: A. Thanos Sort
Link: codeforces.com/problemset/problem/1145/a
Date: 03 / Apr. / 2019

Problems had:
1.- I was storing in the same array in line 46 i had aux[i-(sizeArray/2)] = array[i]; which is wrong
2.- When debugin, remember to delete the extras outputs before submitting

*/

short thanos_sort(short sizeArray, short * array){

  if(sizeArray==1)
    return 1;

  short aux = 0;

  short i = 0;

  cout << endl;

  for(i = 0; i < sizeArray; i++){

    if(array[i]>=aux)
      aux = array[i];
    else
      break;

  }

  if(i<sizeArray){

    short aux[sizeArray/2];

    short aux2[sizeArray/2];

    for(i = 0; i < sizeArray/2; i++)
      aux[i] = array[i];

    for(i = sizeArray/2; i < sizeArray; i++)
      aux2[i-(sizeArray/2)] = array[i];

    short a = thanos_sort(sizeArray/2,aux);

    short b = thanos_sort(sizeArray/2,aux2);

    return a > b ? a : b ;

  }else{

    return sizeArray;

  }


}

int main( ){

  short n = 0;

  cin >> n;

  short a[n];

  for(int i = 0; i < n; i++)
    cin >> a[i];

  cout << thanos_sort(n,a) << endl;

  return 0;
}
