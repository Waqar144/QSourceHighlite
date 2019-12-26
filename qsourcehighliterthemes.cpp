#include "qsourcehighliterthemes.h"


QHash<QSourceHighliter::Language, QTextCharFormat>
        QSourceHighliterTheme::theme(QSourceHighliter::Themes theme) {
    switch (theme) {
    case QSourceHighliter::Themes::Monokai:
        return monokai();
    }
}

QHash<QSourceHighliter::Language, QTextCharFormat> QSourceHighliterTheme::formats()
{
    QHash<QSourceHighliter::Language, QTextCharFormat> _formats;

    QTextCharFormat defaultFormat = QTextCharFormat();
    defaultFormat.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    _formats[QSourceHighliter::CodeBlock] = defaultFormat;
    _formats[QSourceHighliter::CodeKeyWord] = defaultFormat;
    _formats[QSourceHighliter::CodeString] = defaultFormat;
    _formats[QSourceHighliter::CodeComment] = defaultFormat;
    _formats[QSourceHighliter::CodeType] = defaultFormat;
    _formats[QSourceHighliter::CodeOther] = defaultFormat;
    _formats[QSourceHighliter::CodeNumLiteral] = defaultFormat;
    _formats[QSourceHighliter::CodeBuiltIn] = defaultFormat;

    return _formats;
}

QHash<QSourceHighliter::Language, QTextCharFormat> QSourceHighliterTheme::monokai()
{
    QHash<QSourceHighliter::Language, QTextCharFormat> _formats = formats();

    _formats[QSourceHighliter::CodeBlock].setForeground(QColor(227, 226, 214));
    _formats[QSourceHighliter::CodeKeyWord].setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::CodeString].setForeground(QColor(230, 219, 116));
    _formats[QSourceHighliter::CodeComment].setForeground(QColor(117, 113, 94));
    _formats[QSourceHighliter::CodeType].setForeground(QColor(102, 217, 239));
    _formats[QSourceHighliter::CodeOther].setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::CodeNumLiteral].setForeground(QColor(174, 129, 255));
    _formats[QSourceHighliter::CodeBuiltIn].setForeground(QColor(166, 226, 46));

    return _formats;
}
