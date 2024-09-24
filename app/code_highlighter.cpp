#include "code_highlighter.h"


// 构造函数
code_highlighter::code_highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    // 设置关键字的颜色为蓝色
    QStringList keyword_patterns;
    keyword_patterns << "\\bclass\\b" << "\\bif\\b" << "\\belse\\b"
                     << "\\bwhile\\b" << "\\bfor\\b" << "\\breturn\\b"
                     << "\\bint\\b" << "\\bfloat\\b" << "\\bvoid\\b";

    // 设置关键字格式
    keyword_format.setForeground(QColor(86, 157, 214)); // #569CD6
    keyword_format.setFontWeight(QFont::Bold);
    foreach (const QString &pattern, keyword_patterns)
    {
        highlighting_rule rule;
        rule.pattern = QRegularExpression(pattern);
        rule.format = keyword_format;
        highlighting_rules.append(rule);
    }

    // 设置字符串的颜色为棕色
    string_format.setForeground(QColor(206, 145, 120)); // #CE9178
    highlighting_rule string_rule;
    string_rule.pattern = QRegularExpression("\".*\"");
    string_rule.format = string_format;
    highlighting_rules.append(string_rule);

    // 设置注释的颜色为绿色, 字体为斜体
    comment_format.setForeground(QColor(106, 153, 85)); // #6A9955
    comment_format.setFontItalic(true);
    highlighting_rule comment_rule;
    comment_rule.pattern = QRegularExpression("//[^\n]*");
    comment_rule.format = comment_format;
    highlighting_rules.append(comment_rule);

    // 设置函数名的颜色为黄色
    function_format.setForeground(QColor(220, 220, 170)); // #DCDCAA
    highlighting_rule function_rule;
    function_rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
    function_rule.format = function_format;
    highlighting_rules.append(function_rule);

    // 设置类型的颜色为蓝绿色
    type_format.setForeground(QColor(78, 201, 176)); // #4EC9B0
    highlighting_rule type_rule;
    type_rule.pattern = QRegularExpression("\\b(int|float|void|char|double|bool)\\b");
    type_rule.format = type_format;
    highlighting_rules.append(type_rule);

    // 设置数字的颜色为淡绿色
    number_format.setForeground(QColor(181, 206, 168)); // #B5CEA8
    highlighting_rule number_rule;
    number_rule.pattern = QRegularExpression("\\b\\d+\\b");
    number_rule.format = number_format;
    highlighting_rules.append(number_rule);

    // 设置预处理器的颜色为紫色
    preprocessor_format.setForeground(QColor(197, 134, 192)); // #C586C0
    highlighting_rule preprocessor_rule;
    preprocessor_rule.pattern = QRegularExpression("^#.*");
    preprocessor_rule.format = preprocessor_format;
    highlighting_rules.append(preprocessor_rule);

    // 设置操作符和标点符号的颜色为浅灰色
    punctuation_format.setForeground(QColor(204, 204, 204)); // #CCCCCC
    highlighting_rule punctuation_rule;
    punctuation_rule.pattern = QRegularExpression("[{}()\\[\\].,;:+\\-*/%&|^~!=<>]");
    punctuation_rule.format = punctuation_format;
    highlighting_rules.append(punctuation_rule);

    // 设置括号匹配的颜色为黄色加粗
    parentheses_format.setForeground(QColor(215, 186, 125)); // #D7BA7D
    parentheses_format.setFontWeight(QFont::Bold);
    highlighting_rule parentheses_rule;
    parentheses_rule.pattern = QRegularExpression("[()]");
    parentheses_rule.format = parentheses_format;
    highlighting_rules.append(parentheses_rule);
}

// 重写 highlightBlock 函数, 该函数用于高亮每一行的文本
void code_highlighter::highlightBlock(const QString &text)
{
    // 遍历每一个高亮规则
    foreach (const highlighting_rule &rule, highlighting_rules)
    {
        // 查找匹配的部分并应用格式
        QRegularExpressionMatchIterator match_iterator = rule.pattern.globalMatch(text);
        while (match_iterator.hasNext())
        {
            QRegularExpressionMatch match = match_iterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
