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
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::printDebug);
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
    case QSourceHighliter::CodeGo:
        ui->plainTextEdit->setPlainText(loadGoDemoCode());
        break;
    case QSourceHighliter::CodeYAML:
        ui->plainTextEdit->setPlainText(loadYAMLDemoCode());
        break;
    default:
        break;
    }
}

void MainWindow::printDebug() {
    qDebug () << ui->plainTextEdit->toPlainText();
}

QString MainWindow::loadCppDemoCode() {
    return QStringLiteral("#include <iostream>\n"
                                  "\n"
                                  "using namespace std;\n"
                                  "int main(int argc, char *argv[]) {\n"
                                  "\tstd::cout << \"C++ Code Highlighting Demo\" << std::endl;\n"
                                  "\tint x = 10;\n"
                                  "\tstd::cout << x;\n"
                                  "return 0;");
}

QString MainWindow::loadCDemoCode() {
    return QStringLiteral("#include <stdio.h>\n"
                                  "\n"
                                  "int main(int argc, char *argv[]) {\n"
                                  "\tprintf(\"C Code highlighting demo code\\n\");\n"
                                  "\tint x = 10;\n"
                                  "return 0;");
}

QString MainWindow::loadGoDemoCode()
{
    return QStringLiteral("package main\n"
    "\n"
    "import (\n"
      "\t\"net/http\"\n"
    ")\n"
    "\n"
    "/**\n"
    " * @brief main\n"
    " */\n"
    "func main() {\n"
    "\tfmt.print(\"hello\")"
    "\tlog.SetFlags(log.LstdFlags | log.Lshortfile)\n"
    "\n"
        "\t// Parse and handle flags\n"
        "\tflags := flags.NewFlags()\n"
        "\tflags.Parse()\n"
    "\n"
        "\t// Build the application\n"
        "\ttviewApp = tview.NewApplication()\n"
        "\twtfApp := app.NewWtfApp(tviewApp, config, flags.Config)\n"
        "\twtfApp.Start()\n"
    "\n"
        "\tif err := tviewApp.Run(); err != nil {\n"
            "\t\tfmt.Printf(\"\\n%s %v\\n\", aurora.Red(\"ERROR\"), err)\n"
            "\t\tos.Exit(1)\n"
        "\t}\n"
                          "}");
}

QString MainWindow::loadYAMLDemoCode()
{
    return QStringLiteral("url: http://google.com/google\nbcd: \"hello\"\nasd: 123\nfor: true\n\n# "
                          "Crowdin configuration file\n# see: "
                          "https://support.crowdin.com/configuration-file/\n#\n# you will need the Java CLI client\n# "
                          "see: https://support.crowdin.com/cli-tool/\n\nproject_identifier: abc\n\n# the api key "
                          "has to be provided by ~/.crowdin.yaml\n#api_key: XXXX\n\nfiles:\n  - file\n    "
                          "# source files filter\n    source: '/src/languages/QOwnNotes_en.ts'\n    "
                          "# where translations live\n    "
                          "translation: '/src/languages/QOwnNotes_%locale_with_underscore%.ts'\n    "
                          "#translation: '/src/languages/QOwnNotes_%locale%.ts'\n    "
                          "#translation: 'src/languages/QOwnNotes_%two_letters_code%.ts'\n    "
                          "#\"languages_mapping\" : "
                          "{\n      #\"two_letters_code\" : {\n        #\"pt\" : \"pt_PT\",\n       "
                          " #\"pt-BR\" : \"pt_BR\"\n      #}\n    #}\n    \"languages_mapping\" : {\n      "
                          "\"locale_with_underscore\" : {\n        \"ar_SA\" : \"ar\",\n        "
                          "\"ca_ES\" : \"ca\",\n        \"cs_CZ\" : \"cs\",\n        \"de_DE\" : \"de\",\n      }\n    }");
}
