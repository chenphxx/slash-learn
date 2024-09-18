/**
 * @file database.h
 * @brief 数据库接口文件
 * 
 * @details 可能用到的一些数据库接口, 包括写入命令, 字符串转义等
 * 
 * @author chenphxx
 * @version V2024.9.18
 */
#ifndef DATABASE_H_
#define DATABASE_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

#endif
