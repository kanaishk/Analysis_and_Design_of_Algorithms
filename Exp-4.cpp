/*
This Program will function as template to calculate the time complexity of various
sorting algorithms. It will show time result for best, worst and average case.
*/

#include<iostream>
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void sortfunc(int arr[], int n, char ch='r');

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
        void display(char ch='r')
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
        cout << " 1. Radix Sort\n";
        cout << " 2. Exit\n";
        cout << "Enter your choice(1-2): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: c1.display('r');
                    c2.display('r');
                    c3.display('r');
                    c4.display('r');
                    break;
            case 2: break;
            default:cout << "Try Again...!";
        }
        cout << "\n\n";
        system("pause");
    }while(ch!=2);
    return 0;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void sortfunc(int arr[], int n, char ch)
{
    switch(ch)
    {
        case 'r':   radixsort(arr,n);
                    break;
    }
}
