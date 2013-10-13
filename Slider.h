#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkProperty2D.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSliderWidget.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkCommand.h>
#include <vtkWidgetEvent.h>
#include <vtkCallbackCommand.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSliderWidget.h>
#include <vtkSliderRepresentation2D.h>
#include <vtkProperty.h>
#include <vtkStructuredGrid.h>
#include<vector>
// This handles the slider
// Callback for the interaction

using namespace std;
class vtkSliderCallback : public vtkCommand
{
public:
  static vtkSliderCallback *New() 
    {
    return new vtkSliderCallback;
    }
  virtual void Execute(vtkObject *caller, unsigned long, void*)
    {
    vtkSliderWidget *sliderWidget = 
      reinterpret_cast<vtkSliderWidget*>(caller);
 		int i=(static_cast<vtkSliderRepresentation *>(sliderWidget->GetRepresentation())->GetValue());
		if(selector == 'a')
			polyd->GetPointData()->SetVectors(v_Flar[i]);//for slice chart
		else
			polyd->GetPointData()->SetScalars(v_Flar[i]);//for interactor
		
		polyd->Update();
		//ignore this for now
		//grid->GetCellData()->SetScalars(v_Flar[i]);
		//grid->Update();
  }
  vtkSliderCallback():polyd(0) {
	
  }
  vtkPolyData *polyd;
  char selector;
  //ignore this for now
  //vtkStructuredGrid *grid;
  vector<vtkSmartPointer<vtkFloatArray>> v_Flar;
  };