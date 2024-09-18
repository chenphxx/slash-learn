#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "include/mysql.h"
#include "database.h"

using namespace std;


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
