#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    int oc;                     /*选项字符 */
    char ec;                    /*无效的选项字符*/
    char *b_opt_arg;            /*选项参数字串 */

    while((oc = getopt(argc, argv, ":ngl:")) != -1)
    {
        switch(oc)
        {
            case 'n':
                printf("My name is Lyong.\n");
                break;
             case 'g':
                printf("Her name is Xxiong.\n");
                break;
            case 'l':
                b_opt_arg = optarg;
                printf("Our love is %s\n", optarg);
                break;
            case '?':
                ec = (char)optopt;
                printf("无效的选项字符 \' %c \'!\n", ec);
                break;
            case ':':
                printf("缺少选项参数！\n");
                break;
        }
    }
    return 0;
}