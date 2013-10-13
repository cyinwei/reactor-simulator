#include"Slider.h"
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
	vector<vtkSmartPointer<vtkFloatArray> > Flar;
	vtkPolyDataMapper *mapper;
	

private:
	bool start_chk;
	int inc_scalar;
protected:
  vtkAnimationCueObserver();
  };
  