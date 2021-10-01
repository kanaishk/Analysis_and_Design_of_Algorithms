/*
This Program will function as template to calculate the time complexity of various
sorting algorithms. It will show time result for best, worst and average case.
*/

#include<iostream>
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void merge(int array[], int const left, int const mid, int const right);
void mergesort(int array[], int const begin, int const end);
void sortfunc(int arr[], int n, char ch='m');

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
        void display(char ch='m')
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
        cout << " 1. Merge Sort\n";
        cout << " 2. Exit\n";
        cout << "Enter your choice(1-2): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: c1.display('m');
                    c2.display('m');
                    c3.display('m');
                    c4.display('m');
                    break;
            case 2: break;
            default:cout << "Try Again...!";
        }
        cout << "\n\n";
        system("pause");
    }while(ch!=2);
    return 0;
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
        {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergesort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergesort(array, begin, mid);
    mergesort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void sortfunc(int arr[], int n, char ch)
{
    switch(ch)
    {
        case 'm':   mergesort(arr,0,n-1);
                    break;
    }
}
