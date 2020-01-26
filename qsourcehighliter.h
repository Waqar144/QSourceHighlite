/*
 * Copyright (c) 2019 Waqar Ahmed -- <waqar.17a@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 */
#ifndef QSOURCEHIGHLITER_H
#define QSOURCEHIGHLITER_H

#include <QSyntaxHighlighter>

namespace QSourceHighlite {

class QSourceHighliter : public QSyntaxHighlighter
{
public:
    explicit QSourceHighliter(QTextDocument *doc);

    enum Themes {
        Monokai = 1
    };

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
        //languages
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
        CodeINI = 236,


        //code highlighting
        CodeBlock = 999,
        CodeKeyWord = 1000,
        CodeString = 1001,
        CodeComment = 1002,
        CodeType = 1003,
        CodeOther = 1004,
        CodeNumLiteral = 1005,
        CodeBuiltIn = 1006,
    };
    Q_ENUM(Language)

    void setCurrentLanguage(Language language);
    Q_REQUIRED_RESULT Language currentLanguage();
    void setTheme(Themes theme);

protected:
    void highlightBlock(const QString &text) override;

private:
    void highlightSyntax(const QString &text);
    Q_REQUIRED_RESULT int highlightNumericLiterals(const QString &text, int i);
    Q_REQUIRED_RESULT int highlightStringLiterals(QChar strType, const QString &text, int i);

    /**
     * @brief returns true if c is octal
     * @param c the char being checked
     * @returns true if the number is octal, false otherwise
     */
    Q_REQUIRED_RESULT static constexpr inline bool isOctal(const char c) {
        return (c >= '0' && c <= '7');
    }

    /**
     * @brief returns true if c is hex
     * @param c the char being checked
     * @returns true if the number is hex, false otherwise
     */
    Q_REQUIRED_RESULT static constexpr inline bool isHex(const char c) {
        return (
            (c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')
        );
    }

    void cssHighlighter(const QString &text);
    void ymlHighlighter(const QString &text);
    void xmlHighlighter(const QString &text);
    void initFormats();

    QHash<Language, QTextCharFormat> _formats;
    Language _language;
};
}
#endif // QSOURCEHIGHLITER_H
