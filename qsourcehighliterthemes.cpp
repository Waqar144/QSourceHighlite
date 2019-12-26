#include "qsourcehighliterthemes.h"


QHash<QSourceHighliter::Language, QTextCharFormat>
        QSourceHighliterTheme::theme(QSourceHighliter::Themes theme) {
    switch (theme) {
    case QSourceHighliter::Themes::Monokai:
        return monokai();
    }
}

QHash<QSourceHighliter::Language, QTextCharFormat> QSourceHighliterTheme::monokai()
{
    QHash<QSourceHighliter::Language, QTextCharFormat> _formats;

    QTextCharFormat defaultFormat = QTextCharFormat();
    defaultFormat.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    QTextCharFormat format = defaultFormat;
    format.setForeground(QColor(227, 226, 214));
    _formats[QSourceHighliter::CodeBlock] = format;

    format = defaultFormat;
    format.setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::CodeKeyWord] = format;

    format = defaultFormat;
    format.setForeground(QColor(230, 219, 116));
    _formats[QSourceHighliter::CodeString] = format;

    format = defaultFormat;
    format.setForeground(QColor(117, 113, 94));
    _formats[QSourceHighliter::CodeComment] = format;

    format = defaultFormat;
    format.setForeground(QColor(102, 217, 239));
    _formats[QSourceHighliter::CodeType] = format;

    format = defaultFormat;
    format.setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::CodeOther] = format;

    format = defaultFormat;
    format.setForeground(QColor(174, 129, 255));
    _formats[QSourceHighliter::CodeNumLiteral] = format;

    format = defaultFormat;
    format.setForeground(QColor(166, 226, 46));
    _formats[QSourceHighliter::CodeBuiltIn] = format;

    return _formats;
}
