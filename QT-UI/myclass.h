#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include "ui_myclass.h"
#include <string.h>
#include <stdlib.h>

class MyClass : public QMainWindow
{
	Q_OBJECT
	

private slots:
	void action();

public:
	MyClass(QApplication *app,QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();
    QApplication *ap;
	bool flow_checked;
	bool temp_checked;
private:
	Ui::MyClassClass ui;
	std::string outfilename;

};

#endif // MYCLASS_H
