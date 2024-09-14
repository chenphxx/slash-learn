import mysql.connector


# 创建连接
conn = mysql.connector.connect(username = "root", host = "localhost", password = "147819", database = "data")

cursor = conn.cursor()
cursor.execute("select * from person")

result = cursor.fetchall()
# 根据结果的长度动态调整范围
for row in result:
    print(row)

# 关闭连接
cursor.close()
conn.close()
