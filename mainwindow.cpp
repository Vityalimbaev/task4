#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
textEdit = new QTextEdit();
buttonOpen = new QPushButton("Open");
connect(buttonOpen, SIGNAL(clicked()), SLOT(open()));
buttonSave = new QPushButton("Save");
connect(buttonSave, SIGNAL(clicked()), SLOT(save()));
QHBoxLayout * buttonsLayout = new QHBoxLayout();
buttonsLayout->addWidget(buttonOpen);
buttonsLayout->addWidget(buttonSave);
QVBoxLayout * layout = new QVBoxLayout();
layout->addLayout(buttonsLayout);
layout->addWidget(textEdit);
setLayout(layout);
}
MainWindow::~MainWindow()
{
}
void MainWindow::open() {
const QString& fileName = QFileDialog::getOpenFileName(this);
if (fileName.isEmpty()) {
return;
}
QFile file(fileName);
if (file.open(QIODevice::ReadOnly)) {
QTextStream in(&file);
textEdit->setText(in.readAll());
} else {
QMessageBox::warning(this, "Warn", file.errorString());
}
}
void MainWindow::save() {
const QString& fileName = QFileDialog::getSaveFileName(this);
if (fileName.isEmpty()) {
return;
}
QFile file(fileName);
if (file.open(QIODevice::WriteOnly)) {
QTextStream out(&file);
out << textEdit->toHtml();
} else {
QMessageBox::warning(this, "Warn", file.errorString());
}
}
