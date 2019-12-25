#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

void MainWindow::languageChanged(int index) {
    switch (index) {
        case Cpp:
            ui->plainTextEdit->setPlainText(loadCppDemoCode());
            break;
        case C:
            ui->plainTextEdit->setPlainText(loadCDemoCode());
            break;
        case Javascript:
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
