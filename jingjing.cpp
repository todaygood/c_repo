#define STRCPY(a, b)    strcpy(a ## _p, #b)

    int main()

    {

        char var1_p[20];

        char var2_p[30];

         /* 注意这里 */

        STRCPY(STRCPY(var1,var2),var2);

        /* 这里是否会展开为： strcpy(strcpy(var1_p,"var2")_p,"var2“）？

         * 答案是否定的：

         * 展开结果将是：  strcpy(STRCPY(var1,var2)_p,"var2")

         * ## 阻止了参数的宏展开!

         * 如果宏定义里没有用到 # 和 ##, 宏将会完全展开

         */

    }  
