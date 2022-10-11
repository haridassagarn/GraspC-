// you can use includes, for example:
// #include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
int Merge(vector<int> & arr, int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
 
    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);    // NOTE
        }
    }
 
    // copy remaining elements
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    /* no need to copy the second half (since the remaining items
       are already in their correct position in the temporary array) */
 
    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
    return inversionCount;
}
 
// Sort array `arr[low…high]` using auxiliary array `aux`
int MergeSort(vector<int> & arr, int aux[], int low, int high)
{
    // base case
    if (high <= low) {        // if run size <= 1
        return 0;
    }
 
    // find midpoint
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
 
    // recursively split runs into two halves until run size <= 1,
    // then merges them and return up the call chain
 
    // split/merge left half
    inversionCount += MergeSort(arr, aux, low, mid);
 
    // split/merge right half
    inversionCount += MergeSort(arr, aux, mid + 1, high);
 
    // merge the two half runs
    inversionCount += Merge(arr, aux, low, mid, high);
 
    return inversionCount;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

int N = A.size();
 
    int aux[N];
    for (int i = 0; i < N; i++) {
        aux[i] = A[i];
    }
 
    // get the inversion count by performing merge sort on arr
     return MergeSort(A, aux, 0, N - 1);
}
