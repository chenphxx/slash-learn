#include "database.h"


void escape_string(char *input)
{
    int new_length = 0;

    for (unsigned int index = 0; input[index] != 0; index++)
    {
        if (input[index] == '\"' || input[index] == '\\')
            new_length += 2;  // 每转义字符变成两个字符
        else
            new_length += 1;  // 其他字符保持不变
    }

    // 分配新的字符串空间
    char *escaped_string = (char*)malloc((new_length + 1) * sizeof(char));
    unsigned int new_index = 0;

    // 进行转义
    for (unsigned int index = 0; input[index] != 0; index++)
    {
        if (input[index] == '\"' || input[index] == '\\')
        {
            escaped_string[new_index++] = '\\';  // 添加转义字符
            escaped_string[new_index++] = input[index];  // 添加原字符
        }
        else
        {
            escaped_string[new_index++] = input[index];  // 其他字符直接复制
        }
    }
    escaped_string[new_index] = '\0';  // 添加字符串结束符

    strcpy(input, escaped_string);  // 将转义后的字符串复制回原输入
    free(escaped_string);  // 释放临时字符串内存
}

char *get_infor(char *str)
{
    char temp[300];
    fgets(temp, 300 * sizeof(char), stdin);
    temp[strcspn(temp, "\n")] = 0;  // 去掉fgets保留的\n

    strcpy(str, temp);
    return str;
}

void insert_data(char *table, char *query)
{
    char *zh_index = (char *)malloc(20 * sizeof(char));  // zh_index
    fputs("zh_index: ", stdout);
    fgets(zh_index, 20 * sizeof(char), stdin);
    zh_index[strcspn(zh_index, "\n")] = 0;  // 去掉fgets保留的\n

    char *en_index = (char *)malloc(20 * sizeof(char));  // en_index
    fputs("en_index: ", stdout);
    fgets(en_index, 20 * sizeof(char), stdin);
    en_index[strcspn(en_index, "\n")] = 0;

    char *code_snippet = (char *)malloc(300 * sizeof(char));  // code_snippet
    fputs("code_snippet: ", stdout);
    fgets(code_snippet, 300 * sizeof(char), stdin);
    code_snippet[strcspn(code_snippet, "\n")] = 0;
    escape_string(code_snippet);  // 对代码中的引号以及反斜杠进行转义

    char *zh_comment = (char *)malloc(300 * sizeof(char));  // zh_comment
    fputs("zh_comment: ", stdout);
    fgets(zh_comment, 300 * sizeof(char), stdin);
    zh_comment[strcspn(zh_comment, "\n")] = 0;

    sprintf(query, "INSERT INTO %s VALUES (\"%s\", \"%s\", \"%s\", \"%s\");", table, zh_index, en_index, code_snippet, zh_comment);

    free(zh_index);
    free(en_index);
    free(code_snippet);
    free(zh_comment);
}
