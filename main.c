#include <stdio.h>

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// --- MERGE SORT ---
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        Here is the complete solution for your sorting assignment, including the implementation in C, execution trace tables, complexity analysis, and performance comparison.

---

### Input Data
* **Fixed-length IDs:** `324, 125, 456, 218, 102, 389, 275, 147` ($n = 8$)

---

## Part A: Merge Sort Execution & Trace

Merge Sort is a divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves. 

### Trace Table (Passes of Merge Sort)
| Pass / Level | Subarray Operations | Array State After Pass |
| :--- | :--- | :--- |
| **Initial Array** | Unsorted input | `324, 125, 456, 218, 102, 389, 275, 147` |
| **Pass 1 (Size 1 $\rightarrow$ 2)** | Merge `[324],[125]` $\rightarrow$ `[125, 324]`<br>Merge `[456],[218]` $\rightarrow$ `[218, 456]`<br>Merge `[102],[389]` $\rightarrow$ `[102, 389]`<br>Merge `[275],[147]` $\rightarrow$ `[147, 275]` | `125, 324, 218, 456, 102, 389, 147, 275` |
| **Pass 2 (Size 2 $\rightarrow$ 4)** | Merge `[125, 324]` & `[218, 456]` $\rightarrow$ `[125, 218, 324, 456]`<br>Merge `[102, 389]` & `[147, 275]` $\rightarrow$ `[102, 147, 275, 389]` | `125, 218, 324, 456, 102, 147, 275, 389` |
| **Pass 3 (Size 4 $\rightarrow$ 8)** | Merge `[125, 218, 324, 456]` & `[102, 147, 275, 389]` | `102, 125, 147, 218, 275, 324, 389, 456` |

---

## Part B: Quick Sort Execution & Trace

Quick Sort picks a pivot element and partitions the array such that elements smaller than the pivot go to the left and larger elements go to the right. Using the last element (`147`) as the initial pivot:

### Partition Trace
* **Initial Array:** `[324, 125, 456, 218, 102, 389, 275, 147]` (Pivot = `147`)
* **After Partition 1:** Elements smaller than `147` (`125, 102`) move left, larger elements (`324, 456, 218, 389, 275`) move right.
  * Array state: `[125, 102, 147, 324, 456, 218, 389, 275]`
* **Subsequent Partitions:** 
  * Left subsegment `[125, 102]` partitions around pivot `102` $\rightarrow$ `[102, 125]`
  * Right subsegment `[324, 456, 218, 389, 275]` recursively partitions until fully sorted.
* **Final Sorted Sequence:** `102, 125, 147, 218, 275, 324, 389, 456`

---

## Part C: Theoretical Analysis & Comparison

### Comparison Table
| Criterion | Merge Sort | Quick Sort |
| :--- | :--- | :--- |
| **Number of Passes** | $\log_2(n)$ (Fixed 3 passes for $n=8$) | Variable (Depends on pivot choice, avg $\approx \log_2 n$) |
| **Comparisons (Best/Avg)** | $O(n \log n)$ | $O(n \log n)$ |
| **Comparisons (Worst)** | $O(n \log n)$ | $O(n^2)$ |
| **Time Complexity** | $O(n \log n)$ | $O(n \log n)$ average, $O(n^2)$ worst-case |
| **Additional Space** | $O(n)$ (Auxiliary arrays for merging) | $O(\log n)$ (Recursion stack space) |
| **Stability** | Stable | Unstable |

### Final Conclusion & Justification
* **Merge Sort** guarantees $O(n \log n)$ performance in all cases and preserves stability, making it highly reliable when sorting records or IDs where stable ordering is required.
* **Quick Sort** is generally faster in practice due to lower constant factors and in-place sorting ($O(\log n)$ space), but suffers from a worst-case time complexity of $O(n^2)$ if poorly partitioned.
* **Recommendation:** For large fixed-length keys, **Quick Sort** is typically preferred for raw speed and low memory overhead unless stability is strictly required, in which case **Merge Sort** is the superior choice.

---

## C Source Code

```c
#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- MERGE SORT IMPLEMENTATION ---
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- QUICK SORT IMPLEMENTATION ---
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int data1[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int data2[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int n = sizeof(data1) / sizeof(data1[0]);

    printf("Original Array:\n");
    printArray(data1, n);

    printf("\n--- Merge Sort Execution ---\n");
    mergeSort(data1, 0, n - 1);
    printArray(data1, n);

    printf("\n--- Quick Sort Execution ---\n");
    quickSort(data2, 0, n - 1);
    printArray(data2, n);

    return 0;
}