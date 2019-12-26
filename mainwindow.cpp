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

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initComboBox();

    //set highlighter
    highlighter = new QSourceHighliter(ui->plainTextEdit->document());
    highlighter->setCurrentLanguage(QSourceHighliter::CodeCpp);

    //start with Cpp code
    ui->plainTextEdit->setPlainText(loadCppDemoCode());

    connect(ui->langComboBox,
            static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::languageChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComboBox() {
    ui->langComboBox->addItem("C", QSourceHighliter::CodeC);
    ui->langComboBox->addItem("C++", QSourceHighliter::CodeCpp);
    ui->langComboBox->addItem("Javascript", QSourceHighliter::CodeJs);
    ui->langComboBox->addItem("Java", QSourceHighliter::CodeJava);
    ui->langComboBox->addItem("C Sharp", QSourceHighliter::CodeCSharp);
    ui->langComboBox->addItem("Rust", QSourceHighliter::CodeRust);
    ui->langComboBox->addItem("Go", QSourceHighliter::CodeGo);
    ui->langComboBox->addItem("Bash", QSourceHighliter::CodeBash);
    ui->langComboBox->addItem("PHP", QSourceHighliter::CodePHP);
    ui->langComboBox->addItem("Python", QSourceHighliter::CodePython);
    ui->langComboBox->addItem("V lang", QSourceHighliter::CodeV);
    ui->langComboBox->addItem("SQL", QSourceHighliter::CodeSQL);
    ui->langComboBox->addItem("QML", QSourceHighliter::CodeQML);
    ui->langComboBox->addItem("Typescript", QSourceHighliter::CodeTypeScript);
    ui->langComboBox->addItem("YAML", QSourceHighliter::CodeYAML);
    ui->langComboBox->addItem("XML", QSourceHighliter::CodeXML);
    ui->langComboBox->addItem("ini", QSourceHighliter::CodeINI);
}

void MainWindow::languageChanged(int) {
    QSourceHighliter::Language lang = (QSourceHighliter::Language)ui->langComboBox->currentData().toInt();
    highlighter->setCurrentLanguage(lang);
    switch (lang) {
        case QSourceHighliter::CodeCpp:
            ui->plainTextEdit->setPlainText(loadCppDemoCode());
            break;
        case QSourceHighliter::CodeC:
            ui->plainTextEdit->setPlainText(loadCDemoCode());
            break;
        case QSourceHighliter::CodeJs:
            break;
        default:
            break;
    }
}

QString MainWindow::loadCppDemoCode() {
    const QString code = QStringLiteral("#include <iostream>\n"
                                  "\n"
                                  "using namespace std;\n"
                                  "int main(int argc, char *argv[]) {\n"
                                  "\tstd::cout << \"C++ Code Highlighting Demo\" << std::endl;\n"
                                  "\tint x = 10;\n"
                                  "\tstd::cout << x;\n"
                                  "return 0;");
    return code;
}

QString MainWindow::loadCDemoCode() {
    const QString code = QStringLiteral("#include <stdio.h>\n"
                                  "\n"
                                  "int main(int argc, char *argv[]) {\n"
                                  "\tprintf(\"C Code highlighting demo code\\n\");\n"
                                  "\tint x = 10;\n"
                                  "return 0;");
    return code;
}
