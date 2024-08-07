#include <stdio.h>

int    del_elen(int *arr, int rem_ind, int size)
{
    int new_arr[size-1];
    // printf("rem_ind: %d\n", rem_ind);
    int index = 0;
    if (!(rem_ind == size - 1 && rem_ind == 0))
    {
        while (index < rem_ind)
        {
            new_arr[index] = arr[index];
            // printf("%d\n",new_arr[index]);
            index++;
        }
        

        index = index + 1;
        while (index < size)
        {
            new_arr[index-1] = arr[index];
            index++;
        }
        // new_arr[index-1] = arr[index];
        // new_arr[index] = arr[index+1];
    }

    
    int len = (int)(sizeof new_arr / sizeof(int));
    for (int i = 0; i < len; i++){
        printf("elem arr: %d\n", new_arr[i]);
    }
    return (len);
}


int main(void)
{
    int arr[] = {1,2,3,4,5,8,10,11,0,-123};
    int size = (int)(sizeof arr / sizeof(int));
    printf("Size of arr before: \t%d\n", size);
    int index_del = 6;
    // int *index_del_pointer = &index_del;

    int size_after = del_elen(arr, index_del, size);
    printf("Value of arr after: \t%d\n", size_after);
}