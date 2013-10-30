#include"Animation.h"
#include<vtkCamera.h>
vtkAnimationCueObserver::vtkAnimationCueObserver(){		
	this->inc_scalar=1;
	this->start_chk=true;
	this->Renderer=0;
	this->RenWin=0;
}
void vtkAnimationCueObserver:: StartCue(){
	if(start_chk==true){
	
		start_chk=false;}
	else{
			if(is_scalar)
				pdata->GetPointData()->SetScalars(Flar[inc_scalar]);
			else
				pdata->GetPointData()->SetVectors(Flar[inc_scalar]);
			++inc_scalar;
			if(inc_scalar%5==0)
				Renderer->GetActiveCamera()->Azimuth(20.0);
			pdata->Update();
			Renderer->Render();
	
	}
}

void vtkAnimationCueObserver:: Tick(){
		//Renderer->ResetCamera();
    }
void vtkAnimationCueObserver::EndCue() { }