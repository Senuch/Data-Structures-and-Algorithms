#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("Displaying Contents of Array\n");
    for(int i=0;i<array.length;i++)
    {
        printf("%d",*(array.A+i));
    }
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if((*arr).length<(*arr).size)
    {
        //Here we are first dereferencing the struct, followed by dereferencing the length variable, adding it to pointer base address followed by a whole dereference of the target index and setting the value.
        *((*arr).A+(*arr).length)=x;
        (*arr).length+=1;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index<=(*arr).length)
    {
        for(int i=(*arr).length; i>index; i--)
        {
            *((*arr).A+i)=*((*arr).A+(i-1));
        }
        *((*arr).A+index)=x;
        (*arr).length+=1;
    }
}

int Delete(struct Array *arr, int index)
{
    int x=0;
    if(index>=0 && index<(*arr).length-1)
    {
        x=*((*arr).A+index);
        for(int i=index; i<(*arr).length-1;i++)
        {
            *((*arr).A+i)=(*((*arr).A+i+1));
        }
        (*arr).length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr, int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
            return i;
    }
    return -1;
}

int LinearSearchTransposition(struct Array *arr, int key)
{
    int RESULT=LinearSearch(*arr,key);
    if(RESULT!=-1 && RESULT !=0)
    {
        *((*arr).A+RESULT)=(*((*arr).A+RESULT-1));
        *((*arr).A+RESULT-1)=key;
        return RESULT;
    }
    return -1;
}

int LinearSearchMoveToHead(struct Array *arr, int key)
{
    int RESULT=LinearSearch(*arr,key);
    if(RESULT!=-1 && RESULT!=0)
    {
        *((*arr).A+(*arr).length)=*((*arr).A);
        *((*arr).A)=key;
        return RESULT;
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return *(arr.A+index);
    }
}

int Set(struct Array *arr, int index, int value)
{
    if(index>=0 && index<(*arr).length)
    {
        *((*arr).A+index)=value;
    }
}

int Max(struct Array arr)
{
    int max=*(arr.A);

    for(int i=1;i<arr.length;i++)
    {
        if(max<*(arr.A+i))
        {
            max=*(arr.A+i);
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min=*(arr.A);

    for(int i=1;i<arr.length;i++)
    {
        if(min>*(arr.A+i))
        {
            min=*(arr.A+i);
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum=0;

    for(int i=0;i<arr.length;i++)
        sum+=*(arr.A+i);

    return sum;
}

void ReverseArray(struct Array *arr)
{
    int temp;
    for(int i=0,j=(*arr).length-1;i<j;i++,j--)
    {
        temp=*((*arr).A+i);
        *((*arr).A+i)=*((*arr).A+j);
        *((*arr).A+j)=temp;
    }
}

void InsertElementInSortedArray(struct Array *arr, int value)
{
    if((*arr).length==(*arr).size)
        return;
    *((*arr).A+(*arr).length)=value;
    for(int i=(*arr).length-1;i>=0;i--)
    {
        if(*((*arr).A+i)<=value)
            break;
        if(*((*arr).A+i)>value)
            *((*arr).A+i+1) = *((*arr).A+i);
        *((*arr).A+i)=value;
    }
    (*arr).length+=1;
}

int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        if(i+1>arr.length-1)
            return 0;
        if(*(arr.A+i)>(*(arr).A+i+1))
            return 1;
    }
}

// Move negative to the left while +ve to the right of array.
void RearrangePositiveNegative(struct Array *arr)
{
    int i=0;
    int j=(*arr).length-1;

    while(i<j)
    {
        if(*((*arr).A+i)>=0 && *((*arr).A+j)<0)
        {
            //SWAP I with J;
            int temp = *((*arr).A+i);
            *((*arr).A+i)=*((*arr).A+j);
            *((*arr).A+j)=temp;
        }
        if(*((*arr).A+i)<0)
            i++;
        if(*((*arr).A+j)>=0)
            j--;
    }
}

// Time complexity of this is O(m+n) because of the two arrays summed together.
int * MergeArrays(int *A, int lengthA, int *B, int lengthB)
{
    int i=0;
    int j=0;
    int k=0;
    int *merged_array=(int *)malloc((lengthA+lengthB)+sizeof(int));


    while(i<lengthA && j<lengthB)
    {
        if(*(A+i)<*(B+j))
            *(merged_array+k++)=*(A+i++);
        else
            *(merged_array+k++)=*(B+j++);
    }

    for(;i<lengthA;i++)
        *(merged_array+k++)=*(A+i);
    for(;j<lengthB;j++)
        *(merged_array+k++)=*(B+j);

    return merged_array;
}

// Time Complexity -> O(m+n) -> O(n)
int * Union(int *A, int lengthA, int *B, int lengthB)
{
    int i=0;
    int j=0;
    int k=0;
    int *merged_array=(int *)malloc((lengthA+lengthB)+sizeof(int));


    while(i<lengthA && j<lengthB)
    {
        if(*(A+i)<*(B+j))
            *(merged_array+k++)=*(A+i++);
        else if(*(A+i)>*(B+j))
            *(merged_array+k++)=*(B+j++);
        else
        {
            *(merged_array+k++)=*(A+i++);
            i++;
            j++;
        }
    }

    for(;i<lengthA;i++)
        *(merged_array+k++)=*(A+i);
    for(;j<lengthB;j++)
        *(merged_array+k++)=*(B+j);

    return merged_array;
}

// Time Complexity -> O(m+n) -> O(n)
int * Intersection(int *A, int lengthA, int *B, int lengthB)
{
    int i=0;
    int j=0;
    int k=0;
    int *merged_array=(int *)malloc((lengthA+lengthB)+sizeof(int));


    while(i<lengthA && j<lengthB)
    {
        if(*(A+i)==*(B+j))
        {
            *(merged_array+k++)=*(A+i++);
            j++;
        }
        else if(*(A+i)<*(B+j))
            i++;
        else
            j++;
    }

    return merged_array;
}

// Time Complexity -> O(m+n) -> O(n)
int * Difference(int *A, int lengthA, int *B, int lengthB)
{
    int i=0;
    int j=0;
    int k=0;
    int *merged_array=(int *)malloc((lengthA+lengthB)+sizeof(int));


    while(i<lengthA && j<lengthB)
    {
        if(*(A+i)<*(B+j))
        {
            *(merged_array+k++)=*(A+i++);
        }
        else if(*(A+i)==*(B+j))
        {
            i++;
            j++;
        }
        else
            j++;
    }

    return merged_array;
}

int main()
{
    //printf("Array ADT!\n");

    //int n=-1;
    //struct Array arr;

    //printf("Enter size of array:");
    //scanf("%d",&arr.size);
    //arr.A=(int *)malloc(arr.size*sizeof(int));
    //arr.length=0;

    //printf("Enter number count to fill in array:");
    //scanf("%d",&n);
    //arr.length=n;

    //for(int i=0;i<n;i++)
      //  scanf("%d",&arr.A[i]);

    // Displaying contents of an array.
    //Display(arr);

    //Append(&arr,99);

    //Display(arr);

    //Insert(&arr,0,-1);

    //Display(arr);

    //printf("Value deleted:%d\n",Delete(&arr,0));

    //Display(arr);

    //printf("Linear Search:%d\n",LinearSearch(arr,99));
    //Display(arr);
    //printf("Linear Transposition:%d\n",LinearSearchTransposition(&arr,99));
    //Display(arr);
    //printf("Linear move to head:%d\n",LinearSearchMoveToHead(&arr,99));
    //Display(arr);

    //printf("Get %d\n",Get(arr,0));
    //printf("Set %d\n",Set(&arr,0,-9));
    //Display(arr);
    //printf("Min %d\n",Min(arr));
    //printf("Max %d\n",Max(arr));
    //printf("Sum %d\n",Sum(arr));

    //ReverseArray(&arr);
    //Display(arr);
    //InsertElementInSortedArray(&arr,2);
    //Display(arr);
    //printf("is sorted %d",isSorted(arr));
    //RearrangePositiveNegative(&arr);
    //Display(arr);

    int arr1[]={1,2,3,5};
    int arr2[]={1,4,5,6,7};
    int *array=Intersection(arr1,4,arr2,5);

    for(int i=0;i<2;i++)
        printf("%d ",array[i]);

    return 0;
}
