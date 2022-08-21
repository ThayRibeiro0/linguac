#include <stdio.h>
#include <stdio.h>

int main(){
     printf("(D)\n\n");
     for(int i = 0; i <= 9;i++){
          for(int k = 0;k <= 9 - i;k++){
               printf(" ");
          }
          for(int j = 0;j <= i;j++){
               printf("*");
          }
          printf("\n");
     }
     return 0;
}