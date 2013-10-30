/*#include"Animation.h"
vtkAnimationCueObserver::vtkAnimationCueObserver(){		
	this->inc_scalar=1;
	this->start_chk=true;
	this->Renderer=0;
	this->RenWin=0;
}
void vtkAnimationCueObserver:: StartCue(){
	if(start_chk==true){
		helper(VFlar[0]);//carve out the reactor core out of the structured grid and add default color scalar values to cells
		grid->GetCellData()->SetScalars(VFlar[0]);
//------------------------------------------------------------------------------------------------------
	vtkSmartPointer<vtkDataSetMapper> mapper = // Create a mapper and actor
		vtkSmartPointer<vtkDataSetMapper>::New();
			mapper->SetInputConnection(sFilter->GetOutputPort());
			//mapper->SetScalarRange(400, 650);//for temp range
			mapper->SetScalarRange(-2, 10);
			mapper->SetLookupTable(coltable);
	 actor= vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			actor->RotateX(320);
			actor->RotateZ(25);
			Renderer->AddActor(actor);
			Renderer->ResetCamera();
			Renderer->Render();
		start_chk=false;}
	else{
		helper(VFlar[inc_scalar]);
		grid->GetCellData()->SetScalars(VFlar[inc_scalar]);
				++inc_scalar;
				grid->Update();
				Renderer->Render();}
	}
void vtkAnimationCueObserver:: Tick(){
		//actor->RotateWXYZ(1,0,1,0);
		
    }
void vtkAnimationCueObserver::helper(vtkFloatArray* temp){
	for(unsigned int h=0;h<13;++h){
		int f=1;	
		for(int g=0;g<2;++g){	
			temp->InsertValue((g*224+f*0)+h*225,1);
			temp->InsertValue((g*224+f*1)+h*225,1);
			temp->InsertValue((g*224+f*2)+h*225,1);
			temp->InsertValue((g*224+f*3)+h*225,1);
			temp->InsertValue((g*224+f*11)+h*225,1);
			temp->InsertValue((g*224+f*12)+h*225,1);
			temp->InsertValue((g*224+f*13)+h*225,1);
			temp->InsertValue((g*224+f*14)+h*225,1);
			temp->InsertValue((g*224+f*15)+h*225,1);
			temp->InsertValue((g*224+f*16)+h*225,1);
			temp->InsertValue((g*224+f*28)+h*225,1);
			temp->InsertValue((g*224+f*29)+h*225,1);
			temp->InsertValue((g*224+f*30)+h*225,1);
			temp->InsertValue((g*224+f*44)+h*225,1);
			temp->InsertValue((g*224+f*45)+h*225,1);
			temp->InsertValue((g*224+f*59)+h*225,1);
			f=-1;
		}
	}
}
void vtkAnimationCueObserver::EndCue() { }
*/