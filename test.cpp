#include "interactor.h"
#include "slice_chart.h"
using namespace std;

int main(){try{
	//declarations
	vector<vtkSmartPointer<vtkFloatArray>> core_data;//---------------------holds data values-----------
		core_data.reserve(663);
	vtkSmartPointer<vtkPolyData> polydata =
		vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints> points=//points used to set deminsions of grid
		vtkSmartPointer<vtkPoints>::New();
		points->Allocate(3136);
	vtkSmartPointer<vtkLookupTable>cTable = //----------build color table------
		vtkSmartPointer<vtkLookupTable>::New();
		cTable->Build();
		cTable->SetHueRange(0.0,0.667);
	vtkSmartPointer<vtkCellArray>cells = //--------------------array that holds cells
		vtkSmartPointer<vtkCellArray>::New(); 
		cells->Allocate(16000);
//two choices for now, interactor is the only one tested and working, see constructor of interactor for choices in what to build
	Interactor(core_data,polydata,points,cells,cTable );
	//slice_chart(core_data,polydata,points,cells);
	return EXIT_SUCCESS;
}
catch(exception& e){
	cerr<<e.what();
	return 1;
	}
catch(...){
	cerr<<"\nOh no! Unknown Error occurred!";
	return 2;}
}

