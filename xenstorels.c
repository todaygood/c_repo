#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char buf[100] ;
void  xenstore_w(char* key, char* value)           //将key/value的键值对写入xenstore
{
  char *a = " '", *b = "'", c[100] = "xenstore-write ";
  strcat(c, key);
  strcat(c, a);
  strcat(c, value);
  strcat(c, b);
  printf("%s\n", c);                        //使用xenstore-write命令，即xenstore-write key value
  system(c);
}


char* xenstore_r(char* key)               //从xenstore里读取键值为key的值
{
  FILE *stream;
  char a[100] = "xenstore-read ";
  memset(buf, '\0', sizeof(buf));           //设buf都设置为'\0'，防止乱码
  strcat(a, key);
  stream = popen(a, "r");                         //执行命令a，并创建读取其执行结果的流
  fread(buf, sizeof(char), sizeof(buf), stream);    //将流中的数据读取到buf中
  pclose(stream);
  printf("buf=%s\n", buf);
  return buf;
}




