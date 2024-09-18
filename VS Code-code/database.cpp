#include <iostream>
#include "include/mysql.h"

using namespace std;


char *update_query;  // 修改语句
char *object;  // 修改对象


int main(void)
{
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

    mysql_query(&my_sql, "delete from C where name = \"int\";");

    mysql_query(&my_sql, "insert into C values (\"int\", \"int val1 = 17;\", \"整型数据\");");
    mysql_query(&my_sql, "insert into C value(\"float\", \"float val1 = 41.71\", \"浮点型数据\");");

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
