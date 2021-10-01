/*
This Program will function as template to calculate the time complexity of various
sorting algorithms. It will show time result for best, worst and average case.
*/

#include<iostream>
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void swap(int *xp, int *yp);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void sortfunc(int arr[], int n, char ch='q');

class complexity
{
    private:
        int n;
        double best;
        double worst;
        double average;
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
        void display(char ch='q')
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
    int ch=2;
    do
    {
        system("cls");
        cout << "\t\t\t\tTime Complexity\n";
        cout << "Choose the sorting algorithm:\n";
        cout << " 1. Quick Sort\n";
        cout << " 2. Exit\n";
        cout << "Enter your choice(1-2): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: c1.display('q');
                    c2.display('q');
                    c3.display('q');
                    c4.display('q');
                    break;
            case 2: break;
            default:cout << "Try Again...!";
        }
        cout << "\n\n";
        system("pause");
    }while(ch!=2);
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void sortfunc(int arr[], int n, char ch)
{
    switch(ch)
    {
        case 'q':   quicksort(arr,0,n-1);
                    break;
    }
}