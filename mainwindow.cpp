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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLangsEnum();
    initLangsComboBox();
    initThemesComboBox();

    //set highlighter
    highlighter = new QSourceHighliter(ui->plainTextEdit->document());
    highlighter->setCurrentLanguage(QSourceHighliter::CodeGo);

    //start with Cpp code
    ui->plainTextEdit->setPlainText(loadGoDemoCode());

    connect(ui->langComboBox,
            static_cast<void (QComboBox::*) (const QString&)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::languageChanged);
    connect(ui->themeComboBox,
            static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::themeChanged);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::printDebug);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLangsEnum()
{
    using namespace QSourceHighlite;
    MainWindow::_langStringToEnum =
            QHash<QString, QSourceHighliter::Language> {
        {QLatin1String("Bash"),        QSourceHighliter::CodeBash},
        {QLatin1String("C"),           QSourceHighliter::CodeC},
        {QLatin1String("C++"),         QSourceHighliter::CodeCpp},
        {QLatin1String("CMake"),       QSourceHighliter::CodeCMake},
        {QLatin1String("CSharp"),      QSourceHighliter::CodeCSharp},
        {QLatin1String("Css"),         QSourceHighliter::CodeCSS},
        {QLatin1String("Go"),          QSourceHighliter::CodeCSharp},
        {QLatin1String("Html"),        QSourceHighliter::CodeXML},
        {QLatin1String("Ini"),         QSourceHighliter::CodeINI},
        {QLatin1String("Java"),        QSourceHighliter::CodeJava},
        {QLatin1String("Javascript"),  QSourceHighliter::CodeJava},
        {QLatin1String("Json"),        QSourceHighliter::CodeJSON},
        {QLatin1String("Make"),        QSourceHighliter::CodeMake},
        {QLatin1String("Php"),         QSourceHighliter::CodePHP},
        {QLatin1String("Python"),      QSourceHighliter::CodePython},
        {QLatin1String("Qml"),         QSourceHighliter::CodeQML},
        {QLatin1String("Rust"),        QSourceHighliter::CodeRust},
        {QLatin1String("Sh"),          QSourceHighliter::CodeBash},
        {QLatin1String("Sql"),         QSourceHighliter::CodeSQL},
        {QLatin1String("Typescript"),  QSourceHighliter::CodeTypeScript},
        {QLatin1String("V"),           QSourceHighliter::CodeV},
        {QLatin1String("Vex"),         QSourceHighliter::CodeVex},
        {QLatin1String("Xml"),         QSourceHighliter::CodeXML},
        {QLatin1String("Yaml"),        QSourceHighliter::CodeYAML}
    };
}

void MainWindow::initThemesComboBox()
{
    ui->themeComboBox->addItem("Monokai", QSourceHighliter::Themes::Monokai);
    ui->themeComboBox->addItem("debug", QSourceHighliter::Themes::Monokai);
}

void MainWindow::initLangsComboBox() {
    ui->langComboBox->addItem("Bash");
    ui->langComboBox->addItem("C");
    ui->langComboBox->addItem("C++");
    ui->langComboBox->addItem("CSharp");
    ui->langComboBox->addItem("CMake");
    ui->langComboBox->addItem("Javascript");
    ui->langComboBox->addItem("Java");
    ui->langComboBox->addItem("Rust");
    ui->langComboBox->addItem("Go");
    ui->langComboBox->addItem("Html");
    ui->langComboBox->addItem("Php");
    ui->langComboBox->addItem("Make");
    ui->langComboBox->addItem("Python");
    ui->langComboBox->addItem("V");
    ui->langComboBox->addItem("Sql");
    ui->langComboBox->addItem("Qml");
    ui->langComboBox->addItem("Typescript");
    ui->langComboBox->addItem("Yaml");
    ui->langComboBox->addItem("Xml");
    ui->langComboBox->addItem("Ini");
}

void MainWindow::themeChanged(int) {
    QSourceHighliter::Themes theme = (QSourceHighliter::Themes)ui->themeComboBox->currentData().toInt();
    highlighter->setTheme(theme);
}

void MainWindow::languageChanged(const QString &lang) {
    QFile f(QDir::currentPath() + "/../test_files/" + lang + ".txt");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        const auto text = f.readAll();
        ui->plainTextEdit->setPlainText(QString::fromUtf8(text));
        highlighter->setCurrentLanguage(_langStringToEnum.value(lang));
    }
    f.close();
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
