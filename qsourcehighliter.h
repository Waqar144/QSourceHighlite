#ifndef QSOURCEHIGHLITER_H
#define QSOURCEHIGHLITER_H

#include <QSyntaxHighlighter>

class QSourceHighliter : public QSyntaxHighlighter
{
public:
    explicit QSourceHighliter(QTextDocument *doc);

protected:
    void highlightBlock(const QString &text) override;
};

#endif // QSOURCEHIGHLITER_H
