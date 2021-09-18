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
void bubblesort(int* &arr, int n);

class complexity
{
    private:
        int n;
        double best;
        double worst;
        double average;
        double return_dur(int* arr, int n)
        {
            // Get starting timepoint
            auto start = high_resolution_clock::now();

            // Call the function, here sort()
            bubblesort(arr,n);

            // Get ending timepoint
            auto stop = high_resolution_clock::now();

            // Get duration. Substart timepoints to
            // get durarion. To cast it to proper unit
            // use duration cast method
            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
        }
        void calc_complex()
        {
            int* arr;
            // Best case
            arr=bestarr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            best=return_dur(arr,n);
            delete arr;
            arr=NULL;
            // Worst case
            arr=worstarr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            worst=return_dur(arr,n);
            delete arr;
            arr=NULL;
            // Average case
            arr=averagearr(n);
            if(!arr)
            {
                cout << "Unable to intialize";
                return;
            }
            average=return_dur(arr,n);
            delete arr;
            arr=NULL;
        }
    public:
        complexity(int k)
        {
            n=k;
        }
        void display()
        {
            calc_complex();
            cout << "For " << n << " elements:\n";
            cout << "Best Case:\t" << best << "\n";
            cout << "Worst Case:\t" << worst << "\n";
            cout << "Average Case:\t" << average << "\n";
        }
};

int main()
{
    system("cls");
    int* arr=bestarr(10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete arr;
    arr=worstarr(10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubblesort(arr,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete arr;
    arr=averagearr(10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete arr;
    /*complexity c1(1000), c2(5000), c3(10000), c4(20000);
    c1.display();
    c2.display();
    c3.display();
    c4.display();*/
    system("pause");
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

void bubblesort(int* &arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]<arr[i])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
    }
}
