#ifndef QSOURCEHIGHLITERTHEMES_H
#define QSOURCEHIGHLITERTHEMES_H

#include "qsourcehighliter.h"

namespace QSourceHighlite {

class QSourceHighliterTheme
{
public:
    static QHash<QSourceHighliter::Token, QTextCharFormat> theme(QSourceHighliter::Themes);
private:
    static QHash<QSourceHighliter::Token, QTextCharFormat> formats();
    static QHash<QSourceHighliter::Token, QTextCharFormat> monokai();
};
}
#endif // QSOURCEHIGHLITERTHEMES_H
