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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsourcehighliter.h"

#include <QDebug>
#include <QDir>

using namespace QSourceHighlite;

QHash<QString, QSourceHighliter::Language> MainWindow::_langStringToEnum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLangsEnum();
    initLangsComboBox();
    initThemesComboBox();

    //set highlighter
    QFont f = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    ui->plainTextEdit->setFont(f);
    highlighter = new QSourceHighliter(ui->plainTextEdit->document());

    connect(ui->langComboBox,
            static_cast<void (QComboBox::*) (const QString&)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::languageChanged);
    connect(ui->themeComboBox,
            static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::themeChanged);

    ui->langComboBox->setCurrentText("Asm");
    languageChanged("Asm");
    //    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::printDebug);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLangsEnum()
{
    MainWindow::_langStringToEnum = QHash<QString, QSourceHighliter::Language> {
        { QLatin1String("Asm"), QSourceHighliter::CodeAsm },
        { QLatin1String("Bash"), QSourceHighliter::CodeBash },
        { QLatin1String("C"), QSourceHighliter::CodeC },
        { QLatin1String("C++"), QSourceHighliter::CodeCpp },
        { QLatin1String("CMake"), QSourceHighliter::CodeCMake },
        { QLatin1String("CSharp"), QSourceHighliter::CodeCSharp },
        { QLatin1String("Css"), QSourceHighliter::CodeCSS },
        { QLatin1String("Go"), QSourceHighliter::CodeGo },
        { QLatin1String("Html"), QSourceHighliter::CodeXML },
        { QLatin1String("Ini"), QSourceHighliter::CodeINI },
        { QLatin1String("Java"), QSourceHighliter::CodeJava },
        { QLatin1String("Javascript"), QSourceHighliter::CodeJava },
        { QLatin1String("Json"), QSourceHighliter::CodeJSON },
        { QLatin1String("Make"), QSourceHighliter::CodeMake },
        { QLatin1String("Php"), QSourceHighliter::CodePHP },
        { QLatin1String("Python"), QSourceHighliter::CodePython },
        { QLatin1String("Qml"), QSourceHighliter::CodeQML },
        { QLatin1String("Rust"), QSourceHighliter::CodeRust },
        { QLatin1String("Sql"), QSourceHighliter::CodeSQL },
        { QLatin1String("Typescript"), QSourceHighliter::CodeTypeScript },
        { QLatin1String("V"), QSourceHighliter::CodeV },
        { QLatin1String("Vex"), QSourceHighliter::CodeVex },
        { QLatin1String("Xml"), QSourceHighliter::CodeXML },
        { QLatin1String("Yaml"), QSourceHighliter::CodeYAML }
    };
}

void MainWindow::initThemesComboBox()
{
    ui->themeComboBox->addItem("Monokai", QSourceHighliter::Themes::Monokai);
    ui->themeComboBox->addItem("debug", QSourceHighliter::Themes::Monokai);
}

void MainWindow::initLangsComboBox() {
    ui->langComboBox->addItem("Asm");
    ui->langComboBox->addItem("Bash");
    ui->langComboBox->addItem("C");
    ui->langComboBox->addItem("C++");
    ui->langComboBox->addItem("CMake");
    ui->langComboBox->addItem("CSharp");
    ui->langComboBox->addItem("Css");
    ui->langComboBox->addItem("Go");
    ui->langComboBox->addItem("Html");
    ui->langComboBox->addItem("Ini");
    ui->langComboBox->addItem("Javascript");
    ui->langComboBox->addItem("Java");
    ui->langComboBox->addItem("Make");
    ui->langComboBox->addItem("Php");
    ui->langComboBox->addItem("Python");
    ui->langComboBox->addItem("Qml");
    ui->langComboBox->addItem("Rust");
    ui->langComboBox->addItem("Sql");
    ui->langComboBox->addItem("Typescript");
    ui->langComboBox->addItem("V");
    ui->langComboBox->addItem("Vex");
    ui->langComboBox->addItem("Xml");
    ui->langComboBox->addItem("Yaml");
}

void MainWindow::themeChanged(int) {
    QSourceHighliter::Themes theme = (QSourceHighliter::Themes)ui->themeComboBox->currentData().toInt();
    highlighter->setTheme(theme);
}

void MainWindow::languageChanged(const QString &lang) {
    highlighter->setCurrentLanguage(_langStringToEnum.value(lang));

    QFile f(QDir::currentPath() + "/../test_files/" + lang + ".txt");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        const auto text = f.readAll();
        ui->plainTextEdit->setPlainText(QString::fromUtf8(text));
    }
    f.close();
}
