#include <stdio.h>
#include <stdlib.h>

// Time Complexity O(n.n!)
// Space Complexity O(n.n!)
void Perm(char s[],int k)
{
    static int A[3]={0,0,0};
    static char K[3]={0,0,0};

    if(s[k]=='\0')
    {
        printf("%s\n",K);
        return;
    }

    for(int i=0;s[i]!='\0';i++)
    {
        if(A[i]==0)
        {
            A[i]=1;
            K[k]=s[i];
            Perm(s,k+1);
            A[i]=0;
        }
    }

}

void Swap(char s[], int indexA, int indexB)
{
    char temp = s[indexA];
    s[indexA] = s[indexB];
    s[indexB] = temp;
}

// Time Complexity O(n.n!)
// Space Complexity O(n.n!)
void Perm2(char s[], int low, int high)
{
    if(low==high)
    {
        printf("%s\n",s);
        return;
    }
    for(int i=low;i<=high;i++)
    {
        Swap(s, i, low);
        Perm2(s,low+1,high);
        Swap(s, i, low);
    }
}

int main()
{
    printf("Permutation!\n");
    //Perm("abc",0);
    char s[]="abc";
    Perm2(s,0,2);
    //Swap(s,0,1);
    //printf("%s\n",s);
    return 0;
}
