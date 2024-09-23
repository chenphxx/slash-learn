-- 新建数据库用于存储数据
CREATE DATABASE code_data;
USE code_data;

DROP DATABASE code_data;

-- C
CREATE TABLE C
(
	count_index INT AUTO_INCREMENT, -- 自动递增列
	zh_index VARCHAR(50),
	en_index VARCHAR(50),
	code_snippet TEXT,
	zh_comment TEXT,
	PRIMARY KEY (count_index)
);

-- 新建一系列表
-- C++
CREATE TABLE CPP LIKE C;
-- Rust
CREATE TABLE Rust LIKE C;
-- Python
CREATE TABLE Python LIKE C;
-- Mysql
CREATE TABLE MySQL LIKE C;
-- Git
CREATE TABLE Git LIKE C;
-- Go
CREATE TABLE Go LIKE C;
-- Lisp
CREATE TABLE Lisp LIKE C;
-- Assembly
CREATE TABLE Assembly LIKE C;
-- Java
CREATE TABLE Java LIKE C;
-- JavaScript
CREATE TABLE JavaScript LIKE C;
-- HTML
CREATE TABLE HTML LIKE C;
-- CSS
CREATE TABLE CSS LIKE C;
-- STM32
CREATE TABLE STM32 LIKE C;
-- C51
CREATE TABLE C51 LIKE C;

DELETE FROM C WHERE en_index = "int";

SELECT * FROM C;

INSERT INTO C (zh_index, en_index, code_snippet, zh_comment) VALUES ("整型", "int", "int val1 = 171;", "整型数据");
































