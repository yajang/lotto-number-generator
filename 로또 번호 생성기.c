#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    printf("==========\n");
    printf("로또 번호 생성기\n");
    printf("==========\n\n");
    
    printf("이번 주 로또 번호\n");
    
    int a;
    int lotto[6];
    int duplicate;
    int temp = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < 6; i++)
    {
        a = 1 + rand() % 45;
        duplicate = 0;
        
        for (int j = 0; j < i; j++)
        {
            if (a == lotto[j])
            {
                duplicate = 1;
                break;
            }
        }      
        
        if (duplicate == 0)
        {
            lotto[i] = a;
        } 
        else
        {
            i--;
        }    
    }
    
    for (int i = 0; i < 5; i++)
    {
        for ( int j = 0; j < 5 - i; j++)
        {
            if (lotto[j] > lotto[j + 1])
            {
                temp = lotto[j];
                lotto[j] = lotto[j + 1];
                lotto[j + 1] = temp;
            }
        }
    }     
    
    for (int i = 0; i < 6; i++)
    {
        printf(" %d", lotto[i]);       
    }    
    
    return 0;
}