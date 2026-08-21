#include <stdio.h> 
int main() 
{ 
    int a[10][10]; 
    int sparse[100][3], transpose[100][3], fast[100][3]; 
    int rowTerms[10], startPos[10]; 
    int r1, c1; 
    int i, j, k; 
    int count = 0, noncount = 0; 
    int choice; 
    printf("Enter the number of rows: "); 
    scanf("%d", &r1); 
    printf("Enter the number of columns: "); 
    scanf("%d", &c1); 
    printf("Enter the elements of matrix:\n"); 
    for(i=0;i<r1;i++) 
    { 
        for(j=0;j<c1;j++) 
        { 
            scanf("%d",&a[i][j]); 
        } 
    } 
 
    for(i=0;i<r1;i++) 
    { 
        for(j=0;j<c1;j++) 
        { 
            if(a[i][j]!=0) 
                noncount++; 
            else 
                count++; 
        } 
    } 
    printf("\nNon-zero elements = %d\n",noncount); 
    printf("Zero elements = %d\n",count); 
 
    sparse[0][0]=r1; 
    sparse[0][1]=c1; 
    sparse[0][2]=noncount; 
 
    k=1; 
 
    for(i=0;i<r1;i++) 
    { 
        for(j=0;j<c1;j++) 
        { 
            if(a[i][j]!=0) 
            { 
                sparse[k][0]=i; 
                sparse[k][1]=j; 
                sparse[k][2]=a[i][j]; 
                k++; 
            } 
        } 
    } 
 
    do 
    { 
        printf("\n------ MENU ------\n"); 
        printf("1. Display Triplet Form\n"); 
        printf("2. Simple Transpose\n"); 
        printf("3. Fast Transpose\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d",&choice); 
 
        switch(choice) 
        { 
            case 1: 
                printf("\nTriplet Representation:\n"); 
                for(i=0;i<=noncount;i++) 
                { 
                    printf("%d\t%d\t%d\n", 
                    sparse[i][0], 
                    sparse[i][1], 
                    sparse[i][2]); 
                } 
                break; 
            case 2: 
                transpose[0][0]=sparse[0][1]; 
                transpose[0][1]=sparse[0][0]; 
                transpose[0][2]=sparse[0][2]; 
 
                k=1; 
 
                for(i=0;i<c1;i++) 
                { 
                    for(j=1;j<=noncount;j++) 
                    { 
                        if(sparse[j][1]==i) 
                        { 
                            transpose[k][0]=sparse[j][1]; 
                            transpose[k][1]=sparse[j][0]; 
                            transpose[k][2]=sparse[j][2]; 
                            k++; 
                        } 
                    } 
                } 
 
printf("\nSimple Transpose:\n"); 
for(i=0;i<=noncount;i++) 
{ 
} 
printf("%d\t%d\t%d\n", 
transpose[i][0], 
transpose[i][1], 
transpose[i][2]); 
break; 
case 3: 
fast[0][0]=sparse[0][1]; 
fast[0][1]=sparse[0][0]; 
fast[0][2]=sparse[0][2]; 
for(i=0;i<c1;i++) 
rowTerms[i]=0; 
for(i=1;i<=noncount;i++) 
rowTerms[sparse[i][1]]++; 
startPos[0]=1; 
for(i=1;i<c1;i++) 
startPos[i]=startPos[i-1]+rowTerms[i-1]; 
for(i=1;i<=noncount;i++) 
{ 
int pos=startPos[sparse[i][1]]; 
fast[pos][0]=sparse[i][1]; 
fast[pos][1]=sparse[i][0]; 
fast[pos][2]=sparse[i][2]; 
 
                    startPos[sparse[i][1]]++; 
                } 
 
                printf("\nFast Transpose:\n"); 
                for(i=0;i<=noncount;i++) 
                { 
                    printf("%d\t%d\t%d\n", 
                    fast[i][0], 
                    fast[i][1], 
                    fast[i][2]); 
                } 
 
                break; 
            case 4: 
                printf("Program Ended.\n"); 
                break; 
 
            default: 
                printf("Invalid Choice!\n"); 
        } 
 
    }while(choice!=4); 
 
    return 0; 
} 