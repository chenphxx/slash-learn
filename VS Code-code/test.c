#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_infor(char *str)
{
    char temp[300];  // zh_index
    fgets(temp, 300 * sizeof(char), stdin);
    temp[strcspn(temp, "\n")] = 0;  // 去掉fgets保留的\n

    strcpy(str, temp);
    return str;
}

int main(void)
{
    char *str1 = (char *)malloc(100 * sizeof(char));
    get_infor(str1);
    fputs(str1, stdout);
    free(str1);

    return 0;
}
