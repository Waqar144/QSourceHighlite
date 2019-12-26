#ifndef QSOURCEHIGHLITER_H
#define QSOURCEHIGHLITER_H

#include <QSyntaxHighlighter>

class QSourceHighliter : public QSyntaxHighlighter
{
public:
    explicit QSourceHighliter(QTextDocument *doc);

    //languages
    /*********
     * When adding a language make sure that its value is a multiple of 2
     * This is because we use the next number as comment for that language
     * In case the language doesn't support multiline comments in the traditional C++
     * sense, leave the next value empty. Otherwise mark the next value as comment for
     * that language.
     * e.g
     * CodeCpp = 200
     * CodeCppComment = 201
     */
    enum Language {
        CodeCpp = 200,
        CodeCppComment = 201,
        CodeJs = 202,
        CodeJsComment = 203,
        CodeC = 204,
        CodeCComment = 205,
        CodeBash = 206,
        CodePHP = 208,
        CodePHPComment = 209,
        CodeQML = 210,
        CodeQMLComment = 211,
        CodePython = 212,
        CodeRust = 214,
        CodeRustComment = 215,
        CodeJava = 216,
        CodeJavaComment = 217,
        CodeCSharp = 218,
        CodeCSharpComment = 219,
        CodeGo = 220,
        CodeGoComment = 221,
        CodeV = 222,
        CodeVComment = 223,
        CodeSQL = 224,
        CodeJSON = 226,
        CodeXML = 228,
        CodeCSS = 230,
        CodeCSSComment = 231,
        CodeTypeScript = 232,
        CodeTypeScriptComment = 233,
        CodeYAML = 234,
        CodeINI = 236
    };
    Q_ENUM(Language)

protected:
    void highlightBlock(const QString &text) override;

private:
    void highlightSyntax(const QString &text);
    int highlightIntegerLiterals(const QString &text, int i);
    int highlightStringLiterals(QChar strType, const QString &text, int i);
    void cssHighlighter(const QString &text);
    void ymlHighlighter(const QString &text);
    void xmlHighlighter(const QString &text);
};

#endif // QSOURCEHIGHLITER_H
