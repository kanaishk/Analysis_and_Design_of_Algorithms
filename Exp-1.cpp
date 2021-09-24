/*
This Program will function as template to calculate the time complexity of various
sorting algorithms. It will show time result for best, worst and average case.
*/

#include<iostream>
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

int* bestarr(int n);
int* worstarr(int n);
int* averagearr(int n);
void swap(int *xp, int *yp);
void bubblesort(int arr[], int n);
void insertionsort(int arr[], int n);
void selectionsort(int arr[], int n);
void sortfunc(int arr[], int n, char ch='b');

class complexity
{
    private:
        int n;
        double best;
        double worst;
        double average;
        double return_dur(int* arr, int n, char ch)
        {
            // Get starting timepoint
            auto start = high_resolution_clock::now();

            // Call the function, here sort()
            sortfunc(arr,n,ch);

            // Get ending timepoint
            auto stop = high_resolution_clock::now();

            // Get duration. Substart timepoints to
            // get durarion. To cast it to proper unit
            // use duration cast method
            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
        }
        void calc_complex(char ch)
        {
            int* arr;
            // Best case
            arr=bestarr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            best=return_dur(arr,n,ch);
            delete arr;
            arr=NULL;
            // Worst case
            arr=worstarr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            worst=return_dur(arr,n,ch);
            delete arr;
            arr=NULL;
            // Average case
            arr=averagearr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            average=return_dur(arr,n,ch);
            delete arr;
            arr=NULL;
        }
    public:
        complexity(int k)
        {
            n=k;
        }
        void display(char ch='b')
        {
            calc_complex(ch);
            cout << "For " << n << " elements:\n";
            cout << "Best Case:\t" << best << "\n";
            cout << "Worst Case:\t" << worst << "\n";
            cout << "Average Case:\t" << average << "\n\n";
        }
};

int main()
{
    complexity c1(1000), c2(5000), c3(10000), c4(20000);
    int ch=4;
    do
    {
        system("cls");
        cout << "\t\t\t\tTime Complexity\n";
        cout << "Choose the sorting algorithm:\n";
        cout << " 1. Bubble Sort\n";
        cout << " 2. Insertion Sort\n";
        cout << " 3. Selection Sort\n";
        cout << " 4. Exit\n";
        cout << "Enter your choice(1-4): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: c1.display('b');
                    c2.display('b');
                    c3.display('b');
                    c4.display('b');
                    break;
            case 2: c1.display('i');
                    c2.display('i');
                    c3.display('i');
                    c4.display('i');
                    break;
            case 3: c1.display('s');
                    c2.display('s');
                    c3.display('s');
                    c4.display('s');
                    break;
            case 4: break;
            default:cout << "Try Again...!";
        }
        cout << "\n\n";
        system("pause");
    }while(ch!=4);
    return 0;
}

int* bestarr(int n)
{
    int* arr=new int[n];
    if(!arr)
    {
        cout << "Cannot initialize memory";
        return NULL;
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=i;
    }
    return arr;
}

int* worstarr(int n)
{
    int* arr=new int[n];
    if(!arr)
    {
        cout << "Cannot initialize memory";
        return NULL;
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=n-i;
    }
    return arr;
}

int* averagearr(int n)
{
    int* arr=new int[n];
    if(!arr)
    {
        cout << "Cannot initialize memory";
        return NULL;
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%n;
    }
    return arr;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void sortfunc(int arr[], int n, char ch)
{
    switch(ch)
    {
        case 'b':   bubblesort(arr,n);
                    break;
        case 'i':   insertionsort(arr,n);
                    break;
        case 's':   selectionsort(arr,n);
                    break;
    }
}
