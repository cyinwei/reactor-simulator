#include "myclass.h"
#include "error_box.h"
#include "loadingwindow.h"
#include <QtGui/QApplication>
#include <iostream>
#include <stdlib.h>
#include "error_box.h"
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
using namespace std;

int main(int argc, char *argv[])
try{ 
	//throw runtime_error("taco");
	QApplication *a=new QApplication(argc, argv);
	MyClass w(a);
	//Loadingwin w;
	w.show();
	a->exec();
	return 0;
	// Create a sphere
  /*vtkSmartPointer<vtkSphereSource> sphereSource = 
    vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->SetCenter(0.0, 0.0, 0.0);
  sphereSource->SetRadius(5.0);
 
  vtkSmartPointer<vtkPolyDataMapper> mapper = 
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(sphereSource->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor = 
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  renderer->AddActor(actor);
  renderer->SetBackground(.3, .6, .3); // Background color green
 
  renderWindow->Render();
  renderWindowInteractor->Start();
 
  return EXIT_SUCCESS;*/
	
}
catch(exception& e){
	QApplication *a=new QApplication(argc, argv);
	string temp=e.what();
	Error_box box(temp);
	box.show();
	a->exec();
	return 1;}
catch(...){
	QApplication *a=new QApplication(argc, argv);
	string temp="oops unknown error, email Rafael at rafsalas1987@hotmail.com";
	Error_box box(temp);
	box.show();
	a->exec();
	return 2;}