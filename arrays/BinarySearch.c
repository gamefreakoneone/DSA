int Binary_search(int arr[], int X, int low, int high)
{

    while (low <= high) // till low is less than high i.e. there is atleast one integer in the considered part of array
    {

        int mid = low + (high - low) / 2; //compute the middle index

        if (arr[mid] == X) //if equal then return
            return mid;

        else if (arr[mid] < X) //if smaller then increase the lower limit
            low = mid + 1;

        else //if larger then decrease the upper limit
            high = mid - 1;
    }
    return -1;
}