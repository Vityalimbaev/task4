#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QTextEdit>
#include <QTextStream>
#include <QPushButton>
class MainWindow : public QWidget
{
Q_OBJECT
public:
MainWindow(QWidget *parent = 0);
~MainWindow();
private:
QTextEdit * textEdit;
QPushButton * buttonOpen;
QPushButton * buttonSave;
public slots:
void open();
void save();
};
#endif // MAINWINDOW_H
