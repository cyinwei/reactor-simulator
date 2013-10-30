#include <vtkActor.h>
#include <vtkAnimationCue.h>
#include <vtkAnimationScene.h>
#include <vtkCallbackCommand.h>
#include <vtkCell.h>
#include <vtkCellData.h>
#include <vtkCommand.h>
#include<vtkFloatArray.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkLookupTable.h>
#include <vtkMath.h>
#include <vtkPolyData.h>
#include<vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty2D.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSliderWidget.h>
#include <vtkSliderRepresentation2D.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkVersion.h>
#include<vector>
//-------------------------------------------------------------------------------------------------------------------

class vtkAnimationCueObserver : public vtkCommand
{
public:
  static vtkAnimationCueObserver *New()
    {
      return new vtkAnimationCueObserver;
    }
 
	virtual void Execute(vtkObject *vtkNotUsed(caller), unsigned long event, void *calldata){
      if(this->Renderer!=0)
        {
        vtkAnimationCue::AnimationCueInfo *info=
          static_cast<vtkAnimationCue::AnimationCueInfo *>(calldata);
        switch(event)
          {
          case vtkCommand::StartAnimationCueEvent:
            this->StartCue();
            break;
          case vtkCommand::EndAnimationCueEvent:
            this->EndCue();
            break;
          case vtkCommand::AnimationCueTickEvent:
            this->Tick();
            break;
          }
        }
      if(this->RenWin!=0)
        {
        this->RenWin->Render();
        }
    }
	void StartCue();
	void Tick();
	void EndCue();
	void helper( vtkFloatArray* temp);
	vtkSmartPointer<vtkActor> actor;
	vtkPolyData *pdata;
	vtkRenderer *Renderer;
	vtkRenderWindow *RenWin;
	vtkLookupTable *coltable;
	std::vector<vtkSmartPointer<vtkFloatArray> > Flar;
	vtkPolyDataMapper *mapper;
	bool is_scalar;
	

private:
	bool start_chk;
	int inc_scalar;
protected:
  vtkAnimationCueObserver();
  };
  