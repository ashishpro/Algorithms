#include<iostream>

struct arr_index
{
    int row;
    int col;
};


arr_index sol3_nLgn(int arr[][5],int max_row ,int max_col, int curr_row, int curr_col)
{   
    // 2 dimensional
    // Find a peak in the array.
    // Complexity : O(nLog n)
    // Solution : Divide and Conquer

    arr_index result;
    int mid_row = curr_row/2;
    curr_row = mid_row;
    int global_max_mid = 0;
    int global_max_mid_row = mid_row;
    int global_max_mid_col = 0;

    for (size_t cntr = 0; cntr < curr_col; cntr++)
    {
        if (arr[mid_row][cntr] > global_max_mid)
        {
            global_max_mid = arr[mid_row][cntr];
            global_max_mid_col = cntr;
        }
    }
    // std::cout<<"Global:"<<global_max_mid<<std::endl;

    if (( global_max_mid_col == 0 || arr[global_max_mid_row][global_max_mid_col] >= arr[global_max_mid_row - 1][global_max_mid_col]) &&
    (global_max_mid_col == max_col - 1 || arr[global_max_mid_row][global_max_mid_col] >= arr[global_max_mid_row + 1][global_max_mid_col]))
    {
        result.row = global_max_mid_row;
        result.col = global_max_mid_col;
        return result;
    }
    else if( mid_row == 0 && arr[global_max_mid_row][global_max_mid_col] < arr[global_max_mid_row - 1][global_max_mid_col]){
        return sol3_nLgn(arr, 5, 5, global_max_mid_row - 1, global_max_mid_col);
    }
    else{
        return sol3_nLgn(arr, 5, 5, global_max_mid_row + 1, global_max_mid_col);
    }

}

int sol2_Lgn(int *arr, int len, int low, int high){
    // 1 dimensional
    // Find a peak in the array.
    // Complexity : O(Log n)
    // Solution : Divide and Conquer

    int mid_index = low + (high - low)/2;

    if ( (mid_index==0) || (arr[mid_index] >= arr[mid_index - 1])  && 
    (mid_index==len-1)||(arr[mid_index] >= arr[mid_index + 1]) )
    {
        return mid_index;
    }

    else if (mid_index == 0 && (arr[mid_index] < arr[mid_index-1]))
        return sol2_Lgn(arr, len, low, (mid_index -1));

    else
        return sol2_Lgn(arr, len, (mid_index +1), high);
}

void sol1_On(int *arr, int len){
    // 1 Dimensional
    // Complexity : O(n)
    // Solution : Linear
    std::cout<<"Array len: "<<len<<std::endl;
    for (size_t i = 0; i < len; i++)
    {
        if (i==0){
            if (arr[i] >= arr[i+1]) std::cout<<"peek: "<<arr[i]<<std::endl;
        }
        else if (i==len-1){
            if (arr[i] >= arr[i-1]) std::cout<<"peek: "<<arr[i]<<std::endl;
        }
        else{
            if (arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) std::cout<<"peek: "<<arr[i]<<std::endl;
        }

    }
}

int main()
{
    int arr[5][5] = {{1,2,3,4,5},
                     {8,2,1,1,4},
                     {0,1,2,1,3},
                     {6,3,4,1,2},
                     {2,7,9,3,5}};
    arr_index result;
    result = sol3_nLgn(arr, 5, 5, 5, 5);
    std::cout<<"SOL3 2D: O(nLogN)"<<std::endl;
    std::cout<<"Peek pos: "<<std::endl;
    std::cout<<"row: "<<result.row<<" col: "<<result.col<<std::endl;
    std::cout<<"Value: "<<arr[result.row][result.col]<<std::endl;
    // int arr[5] = {4,5,2,7,5};
    int arr_1d[6] = {1,7,3,4,2,10};
    // int arr[2] = {1,9};
    int len_arr = sizeof(arr_1d)/sizeof(arr_1d[0]);
    std::cout<<"SOL1 1D: O(n)"<<std::endl;
    sol1_On(arr_1d ,len_arr);
    std::cout<<"SOL2 1D: O(LogN)"<<std::endl;
    int peek = sol2_Lgn(arr_1d, 6, 0, 5);
    std::cout<<"peek :"<<arr_1d[peek]<<" with index: "<<peek<<std::endl;
    return 0;
}