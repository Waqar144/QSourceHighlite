#include "qsourcehighliterthemes.h"

namespace QSourceHighlite {

static QHash<QSourceHighliter::Token, QTextCharFormat> formats()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats;

    QTextCharFormat defaultFormat = QTextCharFormat();

    _formats[QSourceHighliter::Token::CodeBlock] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeKeyWord] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeString] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeComment] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeType] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeOther] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeNumLiteral] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeBuiltIn] = defaultFormat;

    return _formats;
}

static QHash<QSourceHighliter::Token, QTextCharFormat> monokai()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats = formats();

    _formats[QSourceHighliter::Token::CodeBlock].setForeground(QColor(227, 226, 214));
    _formats[QSourceHighliter::Token::CodeKeyWord].setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::Token::CodeString].setForeground(QColor(230, 219, 116));
    _formats[QSourceHighliter::Token::CodeComment].setForeground(QColor(117, 113, 94));
    _formats[QSourceHighliter::Token::CodeType].setForeground(QColor(102, 217, 239));
    _formats[QSourceHighliter::Token::CodeOther].setForeground(QColor(249, 38, 114));
    _formats[QSourceHighliter::Token::CodeNumLiteral].setForeground(QColor(174, 129, 255));
    _formats[QSourceHighliter::Token::CodeBuiltIn].setForeground(QColor(166, 226, 46));

    return _formats;
}

QHash<QSourceHighliter::Token, QTextCharFormat>
        QSourceHighliterTheme::theme(QSourceHighliter::Themes theme) {
    switch (theme) {
    case QSourceHighliter::Themes::Monokai:
        return monokai();
    }
}

}
