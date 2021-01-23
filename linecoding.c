#include <stdio.h>

int main()
{
   int i,j,i1,j1,i2,j2,clk=1;
   int bits[8];
   printf("\n Enter the byte to be encoded:");
   for(int i=0;i<=7;i++)
   {
       scanf("%d",&bits[i]);
   }
   
   printf("\n Clock\n");
   for(j=0;j<=1;j++)
   {
        if(j)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        for(i=0;i<=15;i++)
        {
          if(((clk && !j)) ||(!clk && j))
          {
             printf("__");
          }
          else
          {
             printf("  ");
          }
          if(j==1)
          {
              printf("|");
          }
          else
          {
              printf(" ");
          }
          clk=!clk;
      }
    printf("\n");
    }
    printf("\nUnipolar");
    printf("\n");
    for(j=0;j<=1;j++)
    {
        if(j)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        for(i=0;i<=7;i++)
        {
            if(((bits[i] && !j)) ||(!bits[i] && j))
            {
                printf("_____");
            }
            else
            {
                printf("     ");
            }
            if(bits[i]==bits[i+1])
            {
                if(bits[i])
                {
                    if(j)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("_");
                    }
                }
                else if(bits[i]==0)
                {
                    if(j)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            if(!(bits[i]==bits[(i%7)+1]))
            {
                if(j)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
            clk=!clk;
        }
        printf("\n");
    }
    printf("\nNRZ-L\n");
    for(j1=0;j1<=2;j1++)
    {
        if(j1)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        for(i1=0;i1<=7;i1++)
        {
            if((bits[i1] && j1==2) ||(!bits[i1] && j1==0))
            {
                printf("_____");
            }
            else if((bits[i1] && j1==0) ||(!bits[i1] && j1==2))
            {
                printf("     ");
            }
            else
            {
                printf("     ");
            }
            if(bits[i1]==bits[i1+1])
            {
                if(!bits[i1])
                {
                    if(j1==2)
                    {
                        printf(" ");
                    }
                    else if(j1==0)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else if(bits[i1])
                {
                    if(j1==2)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            if(!(bits[i1]==bits[(i1%7)+1]))
            {
                if(j1)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\nNRZ-I\n");
    for(j=0;j<=2;j++)
    {
        int temp=0;//indicator of voltage changes
        for(i=0;i<=7;i++)
        {
            if(!bits[(i%7)-1] && !bits[i])//00 pair
            {
                if(temp)//vcc
                {
                    if(!j)
                    {
                        printf("______");
                        
                    }
                    else
                    {
                        printf("      ");
                    }
                }
                else//-vcc
                {
                    if(j==2)
                    {
                        printf("______");
                  
                    }
                    else
                    {
                        printf("      ");
                    }
                }
            }
            else if(!bits[(i%7)-1] && bits[i])//0 to 1 change
            {
                if(j)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                if(temp)
                {
                    if(j==2)
                    {
                        printf("_____");
                        
                    }
                    else
                    {
                        printf("     ");
                    }
                }
                else
                {
                    if(!j)
                    {
                        printf("_____");
                       
                    }
                    else
                    {
                        printf("     ");
                    }
                }
                temp=!temp;
                
            }
            else if(bits[(i%7)-1] && !bits[i])
            {
                if(temp)
                {
                    if(!j)
                    {
                        printf("______");
                        
                    }
                    else
                    {
                        printf("      ");
                    }
                }
                else
                {
                    if(j==2)
                    {
                        printf("______");
                        
                    }
                    else
                    {
                        printf("      ");
                    }
                }
                
            }
            else if(bits[(i%7)-1] && bits[i])//1 to 1 change
            {
                if(j)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                if(temp)
                {
                    if(j==2)
                    {
                        printf("_____");
                        
                    }
                    else
                    {
                        printf("     ");
                    }
                }
                else
                {
                    if(!j)
                    {
                        printf("_____");//instead of 5 _ ,6 _ is used
                        
                    }
                    else
                    {
                        printf("     ");
                    }
                }
                temp=!temp;
                
            }
        }
        printf("\n");
    }
    
    printf("\n RZ");
    printf("\n");
    for(j=0;j<=2;j++)
    {
       for(i=0;i<=15;i++)
        {
            if(clk)// for trailing edge the bit is grounded
            {
                if(bits[i/2])
                {
                    if(j==1)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                    if(j==0)
                    {
                        printf("__");
                    }
                    else
                    {
                        printf("  ");
                    }
                    if(j==1)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else
                {
                    if(j==2)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                    if(j==2)
                    {
                        printf("__");
                    }
                    else
                    {
                        printf("  ");
                    }
                    if(j==2)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            else
            {
                if(j==1)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            clk=!clk;
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Manchester\n");
    for(j2=0;j2<=2;j2++)
    {
        if(j2)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        for(i2=0;i2<=7;i2++)
        {
            if(bits[i2])
            {
                if(j2==2)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            if(j2)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
            if(!bits[i2])
            {
                if(j2==2)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            if(bits[i2]==bits[(i2%7)+1])
            {   
                if(j2)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
            else if(bits[i2]-bits[(i2%7)+1]==-1)
            {
                if(j2==2)
                {
                    printf("_");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("_");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\nDifferential Manchester\n");
    for(j2=0;j2<=2;j2++)
    {
        if(j2)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        for(i2=0;i2<=7;i2++)
        {
            if(!bits[i2])
            {
                if(j2==2)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            if(j2)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
            if(bits[i2])
            {
                if(j2==2)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("__");
                }
                else
                {
                    printf("  ");
                }
            }
            if(bits[i2]==bits[(i2%7)+1])
            {   
                if(j2)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
            else if(bits[i2]-bits[(i2%7)+1]==1)
            {
                if(j2==2)
                {
                    printf("_");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if(j2==0)
                {
                    printf("_");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
