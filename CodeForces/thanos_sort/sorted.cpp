#include <iostream>

using namespace std;

/*

Created by Ricardo Naranjo Polit
changed
email:
  ricardo8polit@gmail.com

Problem name:
  A. Thanos Sort

Description:

  Thanos sort is a supervillain sorting algorithm, which works as follows: if the array is not sorted, snap your fingers* to remove the first or the second half of the items, and repeat the process.

  Given an input array, what is the size of the longest sorted array you can obtain from it using Thanos sort?

  *Infinity Gauntlet required.

  Input
    The first line of input contains a single number 𝑛 (1≤𝑛≤16) — the size of the array. 𝑛 is guaranteed to be a power of 2.

    The second line of input contains 𝑛 space-separated integers 𝑎𝑖 (1≤𝑎𝑖≤100) — the elements of the array.

  Output
    Return the maximal length of a sorted array you can obtain using Thanos sort. The elements of the array have to be sorted in non-decreasing order.

Examples:

  input
    4
    1 2 2 4
  output
    4

  input
    8
    11 12 1 2 13 14 3 4
  output
  2

  input
    4
    7 6 5 4
  output
    1

Ideas:
  I don't need to know what are in the max array, i only need to know it's size.
  I can use a recursive function and give it each half of the array.
  The breaking point is when the size of the array is 1, because that is the minimun size that it can have.

Link:
  codeforces.com/problemset/problem/1145/a

Date:
  03 / Apr. / 2019

Problems i had:
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
