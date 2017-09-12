#include <stdio.h>
#include <stdlib.h>

#define len 180

void tokenize(char *str, char **tokens)
{
    int l = 0, index = 0;
    int i = 0;
    int str_i;
    int tok_i;

    while(*str) {
        if (*str == ' ') {
            tokens[i] = malloc(sizeof(char) * l+1);
            if (tokens[i] == NULL) return;

            tok_i = 0;           
            for (str_i=index-len ; str_i<index ; str_i++) {
                tokens[i][tok_i] = str[str_i];
                tok_i++;
            }

            tokens[i][tok_i] = '\0';
            tokens[i++] = NULL;
            l = 0;
            index++;
        }
        str++;
        l++;
        index++;
    }       

    return;         
}

int main()
{
    char str[len] = "this is a test string";
    char **tokens = malloc(100 * sizeof(char *));

    if (str == NULL || tokens == NULL)
        return 1;

    printf("input string: %s\n", str);
    tokenize(str, tokens);

    return 0;
}
