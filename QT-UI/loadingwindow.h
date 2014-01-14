#ifndef LOADINGWIN_H
#define LOADINGWIN_H

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include "ui_loadingwin.h"
#include <string.h>
#include <stdlib.h>

class Loadingwin : public QMainWindow
{
	Q_OBJECT
	
public:
	Loadingwin(QWidget *parent = 0, Qt::WFlags flags = 0){num=9;
		ui.setupUi(this);
		connect(ui.pushButton, SIGNAL(clicked()), ui.progressBar, SLOT(setValue(10)));
		//ui.progressBar->setProgress();
	}
	~Loadingwin(){}
	
	int num;

private:
	Ui::Loadingwindow ui;

};

#endif // LOADINGWIN_H


