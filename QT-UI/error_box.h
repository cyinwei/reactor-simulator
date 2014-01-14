#ifndef ERROR_BOX_H
#define ERROR_BOX_H

#include <QtGui/QDialog>
#include <qstring.h>
#include "ui_Error_box.h"
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;

class Error_box : public QDialog
{
	Q_OBJECT

public:
	Error_box(string &error_mes, QWidget *parent = 0, Qt::WFlags flags = 0);
	~Error_box();
private:
	Ui::Dialog ui;
	QString error_message;

};

#endif // Error_box