//Open Problem2_v1
//Add a variable that counts how may time a function is called through the class


#include<iostream>
using namespace std;
class square
{
   private:
        int n,r; //private int
        float n1,r1; //private float
        int count=0;

    public:
        void input(); //public member functions
        void calc();
        void display();
        int getCount();

};
 void square::input()
{
        cout<<"Enter an integer:";
        cin>>n;
        cout<<"Enter a float no.:";
        cin>>n1;
        count++;

}
 void square::calc()
{
        r=n*n;
        r1=n1*n1;
        count++;
}
void square::display()
{
        cout<<"Square of integer:"<<r;
        cout<<"\nSquare of float:"<<r1<<endl;
        count++;
}

int square::getCount(){
    return count;
}

int main()
{
        square s;
        s.input();
        s.calc();
        s.display();

        cout << "A function is called " << s.getCount() << "times.";

}


void SelectionSort(int A[], int size) {
    int min_index;
    int temp;
    
    // First loop, repeat n - 1 times (from 0 to n - 2)
    for (int i = 0; i < size - 1; i++) {
        // Second loop, find the minimal value from the remaining unsorted elements.
        min_index = i;
        
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index])
                min_index = j;
        }
        
        // Swap that minimum element with the first of the unsorted elements.
        if (min_index != i) { // Save some computation by first checking if it is self
            temp = A[min_index];
            A[min_index] = A[i];
            A[i] = temp;
        }
    }
}


void MergeSort(int A[], int indexLeft, int indexRight) {
    // Input check. If any index < 0, or indexLeft >= indexRight, do nothing.
    if (indexLeft < 0 || indexRight < 0) return;
    if (indexLeft >= indexRight) return;

    // Find indexMiddle to divide the array into two parts.
    int indexMiddle = indexLeft + (indexRight - indexLeft) / 2;

    // Recursively call MergeSort to sort the first half and the second half of the array.
    MergeSort(A, indexLeft, indexMiddle);
    MergeSort(A, indexMiddle + 1, indexRight);

    // Merge the first half and the second half back into a sorted order, from small to large values.
    int tempA[indexRight - indexLeft + 1]; // to store the merged array
    int i = indexLeft, j = indexMiddle + 1; // i for left half array, j for right half array
    int k = 0; // k for temp array

    while (true) {
        if (A[i] <= A[j]) {
            tempA[k] = A[i];
            k++;
            i++;
        } else {
            tempA[k] = A[j];
            k++;
            j++;
        }
        if (i > indexMiddle) {
            // left half is done, place the remaining right half
            for (; j <= indexRight; j++, k++) {
                tempA[k] = A[j];
            }
            break;
        }
        if (j > indexRight) {
            // right half is done, place the remaining left half
            for (; i <= indexMiddle; i++, k++) {
                tempA[k] = A[i];
            }
            break;
        }
    }

    // Copy tempA back into A
    for (k = 0; k < indexRight - indexLeft + 1; k++) {
        A[indexLeft + k] = tempA[k];
    }
}

