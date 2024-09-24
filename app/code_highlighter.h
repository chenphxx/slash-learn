#ifndef CODE_HIGHLIGHTER_H
#define CODE_HIGHLIGHTER_H


#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>


// 声明 code_highlighter 类，继承自 QSyntaxHighlighter
class code_highlighter : public QSyntaxHighlighter
{
    Q_OBJECT  // 宏，用于信号与槽机制

public:
    // 构造函数, 接受一个 QTextDocument 对象作为父对象
    code_highlighter(QTextDocument *parent = nullptr);

protected:
    // 重写的函数, 用于高亮一行文本
    void highlightBlock(const QString &text) override;

private:
    // 定义高亮规则结构体
    struct highlighting_rule
    {
        QRegularExpression pattern;  // 正则表达式匹配模式
        QTextCharFormat format;      // 匹配后应用的文本格式
    };

    // 高亮规则的列表
    QVector<highlighting_rule> highlighting_rules;

    QTextCharFormat keyword_format;  // 关键字
    QTextCharFormat string_format;  // 字符串
    QTextCharFormat comment_format;  // 注释
    QTextCharFormat function_format;  // 函数
    QTextCharFormat type_format;  // 类型定义
    QTextCharFormat number_format;  // 数字
    QTextCharFormat preprocessor_format;  // 预处理命令
    QTextCharFormat punctuation_format;  // 符号
    QTextCharFormat parentheses_format;  // 括号
};


#endif // CODE_HIGHLIGHTER_H
