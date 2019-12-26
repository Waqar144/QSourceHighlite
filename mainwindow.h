#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qsourcehighliter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    enum Langs {
        Cpp = 0,
        C,
        Javascript
    };
    Q_ENUM(Langs)


private:
    Ui::MainWindow *ui;
    QSourceHighliter *highlighter;

    /* STATIC FUNCTIONS */
    void initComboBox();

    /* STATIC FUNCTIONS */
    static QString loadCppDemoCode();
    static QString loadCDemoCode();

private slots:
    void languageChanged(int);

};
#endif // MAINWINDOW_H
