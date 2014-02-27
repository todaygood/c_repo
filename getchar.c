#include <stdio.h>
 
int main()
{
        char c;
        for(;;){
                c=getchar();
                if(c == 'q') // Compare input to 'q' character
                        break;
                fprintf(stdout, "%c\n", c);
        }
        return 0;
}


