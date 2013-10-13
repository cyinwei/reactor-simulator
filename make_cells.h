#include <vtkActor.h>
#include <vtkAxesActor.h>
#include <vtkCellArray.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkFloatArray.h>
#include <vtkLookupTable.h>
#include <vtkMultiThreader.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPropAssembly.h>
#include <vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkWeakPointer.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include <vtkQuad.h>
#include <vector>
#include<vtkScalarBarActor.h>
#include<vtkTextActor.h>
using namespace std;

class Rxbuild{
	
public:
	Rxbuild(vector<vtkSmartPointer<vtkFloatArray> >& Farray){}//constructor
	Rxbuild();//constructor
	void point_build(vtkSmartPointer<vtkPoints>& points);//make points for interactor
	//testing still
	void point_slice(vtkSmartPointer<vtkPoints>& points,vector<vtkSmartPointer<vtkFloatArray> >& Farray,vtkSmartPointer<vtkCellArray>&cells,vtkSmartPointer<vtkPolyData> polyd);
	//testing still
	void point_slice_build(vtkSmartPointer<vtkPoints>& points,vector<vtkSmartPointer<vtkFloatArray> >& Farray,vtkSmartPointer<vtkCellArray>&cells,vtkSmartPointer<vtkPolyData> polyd);
	
	void get_data(const string& fname,vector<vector<double> > &transfer);//get data from files
	void get_tuples(vector<vtkSmartPointer<vtkFloatArray> >& Farray);//put data into array points for interactor
	void get_tuples_for_slice(vector<vtkSmartPointer<vtkFloatArray> >& Farray,int slice_sel);//put data into array for points for slice chart still testing
	//makes cells for interactor
	void make_box(int x[4],vtkSmartPointer<vtkCellArray> &cells);
	//make full reactor for interactor
	void make_full_cells(vtkSmartPointer<vtkCellArray>&cells,const int& q,const int& p);
	void make_threefourth_cells(vtkSmartPointer<vtkCellArray>&cells,const int& q,const int& p);
	//make specific slices for interactor
	void make_center(vtkSmartPointer<vtkCellArray>&cells,const char& select);
	void make_cross(vtkSmartPointer<vtkCellArray>&cells);
};

