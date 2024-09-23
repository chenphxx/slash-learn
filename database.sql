-- 新建数据库用于存储数据
CREATE DATABASE code_data;
USE code_data;

DROP DATABASE code_data;

-- C
CREATE TABLE C
(
	count_index INT AUTO_INCREMENT,  -- 自动递增列, 数据类型必须为整数
	zh_index VARCHAR(50),
	en_index VARCHAR(50),
	code_snippet TEXT,
	zh_comment TEXT,
	PRIMARY KEY (count_index)  -- 主键必须是 AUTO_INCREMENT 列
);

-- 新建一系列表
CREATE TABLE CPP LIKE C;  -- C++
CREATE TABLE Rust LIKE C;  -- Rust
CREATE TABLE Python LIKE C;  -- Python
CREATE TABLE MySQL LIKE C;  -- Mysql
CREATE TABLE Git LIKE C;  -- Git
CREATE TABLE Go LIKE C;  -- Go
CREATE TABLE Lisp LIKE C;  -- Lisp
CREATE TABLE Assembly LIKE C;  -- Assembly
CREATE TABLE Java LIKE C;  -- Java
CREATE TABLE JavaScript LIKE C;  -- JavaScript
CREATE TABLE HTML LIKE C;  -- HTML
CREATE TABLE CSS LIKE C;  -- CSS
CREATE TABLE STM32 LIKE C;  -- STM32
CREATE TABLE C51 LIKE C;  -- C51

SELECT * FROM C;

INSERT INTO C VALUES ("整型", "int", "int val1 = 171;", "整型数据");
