#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "include/mysql.h"

using namespace std;


/**
 * @brief 将字符串中的"以及\进行转义
 * 
 * @param input 目标字符串
 * @return 无
 */
void escape_string(char* input);

/**
 * @brief 获取要写入的参数
 * 
 * @param NULL
 * @return 返回获取的字符串
 */
char *get_infor(char *str);

/**
 * @brief 向数据库写入数据
 * 
 * @param query 目标语句
 * @param table 目标表格
 * @return 返回一条SQL写入语句
 */
void insert_data(char *table, char *query);


int main(void)
{
    SetConsoleOutputCP(65001);  // 更改控制台编码为UTF-8

    MYSQL my_sql;
    MYSQL_RES *res;
    MYSQL_ROW row;

    mysql_init(&my_sql);

    if (!mysql_real_connect(&my_sql, "localhost", "root", "147819", "code_data", 3306, NULL, 0))
    {
        cout << "数据库连接失败: " << mysql_error(&my_sql) << endl;
        return 1;
    }
    else
    {
        cout << "数据库连接成功" << endl;
    }

    char *query = (char *)malloc(1000 * sizeof(char));
    insert_data("C", query);
    mysql_query(&my_sql, query);
    free(query);

    // 执行 SQL 查询
    if (mysql_query(&my_sql, "SELECT * FROM C;"))
    {
        cout << "语句查询错误: " << mysql_error(&my_sql) << endl;
        mysql_close(&my_sql);
        return 1;
    }

    // 获取查询结果
    res = mysql_store_result(&my_sql);
    if (res == NULL)
    {
        cout << "结果存储错误: " << mysql_error(&my_sql) << endl;
        mysql_close(&my_sql);
        return 1;
    }

    // 获取字段数量
    int num_fields = mysql_num_fields(res);

    // 输出查询结果
    while ((row = mysql_fetch_row(res)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            cout << (row[i] ? row[i] : "NULL") << "\t";  // 如果为空 则输出 "NULL"
        }
        cout << endl;
    }

    mysql_free_result(res);  // 释放结果集
    mysql_close(&my_sql);  // 关闭连接
    return 0;
}


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
    char* escaped_string = (char*)malloc((new_length + 1) * sizeof(char));
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
    char temp[300];  // zh_index
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
