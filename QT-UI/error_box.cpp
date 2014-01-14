#include "error_box.h"

Error_box::Error_box(string &error_mes, QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	ui.error_message->setText(error_message.fromStdString(error_mes));
}

Error_box::~Error_box()
{

}
