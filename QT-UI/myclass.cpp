#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip> 
#include "convert.h"
#include "myclass.h"
//#include "mysec.h"

using namespace std;

MyClass::MyClass(QApplication *app,QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), ap(app)
{	
	QString taco;
	ui.setupUi(this); 
	connect(ui.OkButton, SIGNAL(clicked()), this, SLOT(action()));
	//connect(ui.FlowBubble, SIGNAL(clicked()), this, SLOT(set_bool()));
}

MyClass::~MyClass()
{

}

void MyClass:: action(){
		/*MyClass r(ap);
		r.show();
		ap.exec();*/

	/*string stuff=ui.lineEdit->text().toStdString();
	ofstream appFile;//output stream to file
	appFile.open(stuff+".", ios::out | ios::app); 
	appFile <<"test worked";
	
	if(ui.FlowBubble->isChecked())
		appFile <<" second test worked";
	appFile.close();*/
	convert make_file(ui.FlowBubble->isChecked(),ui.lineEdit->text().toStdString());
	
}

