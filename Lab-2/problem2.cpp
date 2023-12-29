#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void sum_row(int **num, int rows, int columns); //average of pixels within row function


int main()
{

    int rows, columns; // Define variables for the columns of the array, rows of the arrays and the maximum 

}

void sum_row(int **num, int maxBright, int rows, int columns)
{
    double sum = 0;
    for (int i = 0; i < rows; i++) // read integers from image file
    {
        for (int j = 0; j < columns; j++)
        {
            sum += num[i][j];
        }

        cout << "Avg Row(" << i + 1 << ") is " << sum / rows;

        sum = 0;

        cout << endl;
    }
}
