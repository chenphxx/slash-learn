## MySQL配置

--- 

首先下载QT源码, 选择`添加或移除组件` 

![](D:\marktext-image\2024-09-19-17-33-51-image.png) 

![](D:\marktext-image\2024-09-19-15-05-54-image.png) 

选择`Sources`, 等待下载完成 

![](D:\marktext-image\2024-09-19-15-06-36-image.png) 

--- 

从MySQL安装目录 

```
C:\Program Files\MySQL\MySQL Server 9.0\lib
```

![](D:\marktext-image\2024-09-19-15-08-54-image.png) 

拷贝`libmysql.dll`, `libmysql.lib`到地址 

```
C:\Qt\6.7.2\mingw_64\bin
```

从MySQL安装目录 

```
C:\Program Files\MySQL\MySQL Server 9.0\bin
```

拷贝`libcrypto-3-x64.dll`, `libssl-3-x64.dll`到地址 

```
C:\Qt\6.7.2\mingw_64\bin
```

![](D:\marktext-image\2024-09-19-15-34-50-image.png) 

--- 

将MySQL中`include`, `lib`两个文件夹拷贝到另一个临时的文件夹中 

```
C:\Program Files\MySQL\MySQL Server 9.0
```

![](D:\marktext-image\2024-09-19-15-12-12-image.png) 

临时文件夹地址 

```
C:\Users\chenphxx\Documents\qt-mysql
```

![](D:\marktext-image\2024-09-19-15-13-17-image.png) 

--- 

打开目录 

```
C:\Qt\6.7.2\Src\qtbase\src\plugins\sqldrivers
```

使用记事本打开文件`.cmake.conf` 

![](D:\marktext-image\2024-09-19-15-14-47-image.png) 

将刚刚新建的临时文件夹中两个文件夹的地址添加到配置文件中, 添加的文件为`include`和`lib/libmysql.lib` 

![](D:\marktext-image\2024-09-19-15-15-24-image.png) 

```
SET(FEATURE_sql_mysql ON)
SET(MySQL_INCLUDE_DIR "C:/Users/chenphxx/Documents/qt-mysql/include")
SET(MySQL_LIBRARY "C:/Users/chenphxx/Documents/qt-mysql/lib/libmysql.lib")
```

--- 

修改完成后, 使用QT打开项目, 选择`CMakeLists.txt`打开 

```
C:\Qt\6.7.2\Src\qtbase\src\plugins\sqldrivers
```

![](D:\marktext-image\2024-09-19-15-18-23-image.png) 

随后点击锤子图标编译`release`版本 

![](D:\marktext-image\2024-09-19-15-19-25-image.png) 

编译完成后, 打开`build`文件夹, 选择`plugins`-`sqldrivers` 

```
C:\Qt\6.7.2\Src\qtbase\src\plugins\sqldrivers\build\Desktop_Qt_6_7_2_MinGW_64_bit-Release\plugins\sqldrivers
```

将文件`qsqlmysql.dll`, `qsqlmysql.debug`拷贝到QT安装目录下 

![](D:\marktext-image\2024-09-19-15-21-52-image.png) 

目标地址 

```
C:\Qt\6.7.2\mingw_64\plugins\sqldrivers
```

![](D:\marktext-image\2024-09-19-15-23-51-image.png) 

--- 

在项目`.pro`配置中添加 

```qt
QT += sql 
```

使用下面这段程序来测试是否能够正常连接到数据库 

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("code_data");
    db.setUserName("root");
    db.setPassword("147819");
    bool ok = db.open();
    if (ok){
        qDebug() << "link success";
    }
    else {
        qDebug() <<  "link failed";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

![](D:\marktext-image\2024-09-19-15-38-44-image.png) 


