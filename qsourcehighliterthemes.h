#ifndef QSOURCEHIGHLITERTHEMES_H
#define QSOURCEHIGHLITERTHEMES_H

#include "qsourcehighliter.h"

class QSourceHighliterTheme
{
public:
    static QHash<QSourceHighliter::Language, QTextCharFormat> theme(QSourceHighliter::Themes);
private:
    static QHash<QSourceHighliter::Language, QTextCharFormat> formats();
    static QHash<QSourceHighliter::Language, QTextCharFormat> monokai();
};

#endif // QSOURCEHIGHLITERTHEMES_H
