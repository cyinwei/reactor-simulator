/*#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkTriangle.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCellArray.h>
#include"Animation.h"
#include <vtkTextActor.h>
#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkProperty2D.h>
#include <vtkSliderWidget.h>
#include<vtkCubeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkWidgetEvent.h>
#include <vtkCallbackCommand.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSliderWidget.h>
#include <vtkSliderRepresentation2D.h>
#include <vtkProperty.h>
#include <vtkHexahedron.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkGlyph3DMapper.h>
#include <vtkPropAssembly.h>
#include <vtkMultiThreader.h>
#include <vtkSmartPointer.h>
#include <vtkWeakPointer.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkRectangularButtonSource.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include"Slider.h"
#include <vtkStructuredGridOutlineFilter.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridGeometryFilter.h>
#include<vtkStructuredGridGeometryFilter.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkTriangle.h>
//---------------
//#include"Animation.h"
#include <vtkTextActor.h>
#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkProperty2D.h>
#include <vtkSliderWidget.h>
#include <vtkPolyDataMapper.h>
#include <vtkWidgetEvent.h>
#include <vtkCallbackCommand.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSliderWidget.h>
#include <vtkSliderRepresentation2D.h>
#include <vtkProperty.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkPropAssembly.h>
#include <vtkMultiThreader.h>
#include <vtkSmartPointer.h>
#include <vtkWeakPointer.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkRectangularButtonSource.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkObjectFactory.h>
#include <vtkProperty.h>
//#include"Slider.h"

//--------------------------------------------------------------------------------------------------------------------
//initialize location and time vector with values from the file given
void loc_and_time(const string& fname,vector<int>& loc,vector<double>& times){
	ifstream datas(fname.c_str());//open file
	if (!datas){ cout<<"can't open file";}// remember to throw an exception
	times.reserve(600);//reserve space for vector, efficiency reasons
	loc.reserve(2123);
	string stemp1="0";//"stemp"s  are temp strings for reading lines into. itemp and dtemp are for temp numbers
	string stemp2="0";
	int itemp=0;
	double dtemp=0;
		getline(datas,stemp1);//next couple lines are for getting a line from a file and reading them into a vector
		getline(datas,stemp2);
		stringstream tss(stemp1);
		while(tss>>itemp){
			loc.push_back(itemp);}
		stringstream rss(stemp2);
		while(rss>>dtemp){
			times.push_back(dtemp);}
	datas.close();//close file
}
//--------------------------------------------------------------------------------------------------------------------
void build_Farray(const string& fname,vector<vtkSmartPointer<vtkFloatArray>>& Farray,vector<int>& cell_no){
	ifstream datas(fname.c_str());//open file
		if (!datas){ cout<<"can't open file";}
	double values=0;
	string stemp="0";
	int itemp=0;
	int line_no=0;
	while(getline(datas,stemp)){
		if(line_no>1){//go to the line where values start and start reading values into vectors, each line represents values
			vtkSmartPointer<vtkFloatArray> cell_val=
				vtkSmartPointer<vtkFloatArray>::New();
			stringstream tss(stemp);//(cont.) at a certain time, 
			int i=0;
			while(tss>>values){

			//	cell_val->InsertValue(cell_no[i],1000-values);
				cell_val->InsertValue(cell_no[i],10-values);
				++i;
			}
			Farray.push_back(cell_val);//push back each value vector into this for later accessing
		}
		++line_no;//used to increment to the right line, check above loop
	}
	datas.close();//close file
}
void f_helper(vtkFloatArray* temp){
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
void r_helper(vtkSmartPointer<vtkStructuredGrid>& structuredGridt){	
	for(unsigned int h=0;h<13;++h){
		int f=1;				//I did not format this per C++ convention because I thought that the addition of lines would not
		for(int g=0;g<2;++g){	//make the code look any cleaner. The loop blanks and adds default values to uneeded cells
			structuredGridt->BlankCell((g*224+f*0)+h*225); 
			structuredGridt->BlankCell((g*224+f*1)+h*225);
			structuredGridt->BlankCell((g*224+f*2)+h*225);
			structuredGridt->BlankCell((g*224+f*3)+h*225);
			structuredGridt->BlankCell((g*224+f*11)+h*225);
			structuredGridt->BlankCell((g*224+f*12)+h*225);
			structuredGridt->BlankCell((g*224+f*13)+h*225);
			structuredGridt->BlankCell((g*224+f*14)+h*225); 
			structuredGridt->BlankCell((g*224+f*15)+h*225);
			structuredGridt->BlankCell((g*224+f*16)+h*225); 
			structuredGridt->BlankCell((g*224+f*28)+h*225); 
			structuredGridt->BlankCell((g*224+f*29)+h*225);
			structuredGridt->BlankCell((g*224+f*30)+h*225);
			structuredGridt->BlankCell((g*224+f*44)+h*225); 
			structuredGridt->BlankCell((g*224+f*45)+h*225);
			structuredGridt->BlankCell((g*224+f*59)+h*225);
			f=-1;
		}
	}}
void blank_cells(vtkSmartPointer<vtkStructuredGrid>& grid,const char& slice,const int& lvl_1,const int& lvl_2){
	switch(slice){
	case 'a':
		for(int i=0;i<13;++i)
			if(i!=lvl_1&& i!=lvl_2)
				for(int j=0;j<224;++j)
					grid->BlankCell((j)+i*225);
		break;
	case 'b' :
		for(int i=0;i<13;++i)
			for(int q=0;q<7;++q)
				for(int k=0;k<8;++k)
					grid->BlankCell((k+15*q)+i*225);break;
	case 'c' :
		for(int i=0;i<13;++i)
			for(int q=0;q<7;++q)
				for(int k=0;k<8;++k)
					grid->BlankCell((k+15*q)+i*225);
		for(int i=0;i<13;++i)
			if(i!=lvl_1&& i!=lvl_2)
				for(int j=0;j<224;++j)
					grid->BlankCell((j)+i*225);

		break;
	default: cout<<"something is wrong";
	}
}
void make_reactor(vtkSmartPointer<vtkStructuredGrid>& Grid,vtkSmartPointer<vtkShrinkFilter>& Filter,vtkSmartPointer<vtkLookupTable>& cTable){
	Grid=vtkSmartPointer<vtkStructuredGrid>::New();
	vtkSmartPointer<vtkPoints> points=//points used to set deminsions of grid
		vtkSmartPointer<vtkPoints>::New();
	unsigned int numi = 16;
	unsigned int numj = 16;
	unsigned int numk = 14;
	for(unsigned int k = 0; k < 2*numk; k++){
		if(k!=0){k+=1;}
		for(unsigned int j = 0; j < numj; j++){
			for(unsigned int i = 0; i < numi; i++){
				points->InsertNextPoint(i, j, k);
			}
	    }
	} 
	Grid->SetDimensions(numi, numj, numk);
	Grid->SetPoints(points);
	r_helper(Grid);
		Filter=vtkSmartPointer<vtkShrinkFilter>::New();
	#if VTK_MAJOR_VERSION <= 5
		Filter->SetInputConnection(Grid->GetProducerPort());
	#else
		Filter->SetInputData(Grid);
	#endif
		Filter->SetShrinkFactor(1);
cTable = vtkSmartPointer<vtkLookupTable>::New();
	int tableSize =  10;// not sure if I need this
	cTable->SetNumberOfTableValues(tableSize);// not sure if I need this
	cTable->Build();
}
void make_animation(vector<int>& loc,vector<double>& times,vector<vtkSmartPointer<vtkFloatArray>>& Flar,const char& slice,int a, int b){
	vtkSmartPointer<vtkStructuredGrid> structuredGrid;
	vtkSmartPointer<vtkLookupTable> colorLookupTable;
	vtkSmartPointer<vtkShrinkFilter> s_Filter;
	make_reactor(structuredGrid,s_Filter,colorLookupTable);
	if (slice=='a'||slice=='b'||slice=='c') 
		blank_cells(structuredGrid,slice,a,b);
//---------------------------------------------------------------------------------------------------------------------
	// Create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderer> renderer= 
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow= 
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor= 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow); 
	renderer->SetBackground(.2, .3, .4);
	renderWindow->SetFullScreen(false);
	renderWindow->SetSize(1400, 800);
	renderWindow->Render();
	// Create an Animation Scene
	vtkSmartPointer<vtkAnimationScene> scene =
		vtkSmartPointer<vtkAnimationScene>::New();
  scene->SetModeToRealTime();
  scene->SetLoop(0);
  scene->SetFrameRate(1);
  scene->SetStartTime(0);
  //scene->SetEndTime(times[times.size()-1]); //for real time
  scene->SetEndTime((times.size()/600)); //for long time steps
  //scene->SetEndTime((times.size()/(1.5)));//for short time steps
  // Create Cue observer.
  vtkSmartPointer<vtkAnimationCueObserver> observer =
    vtkSmartPointer<vtkAnimationCueObserver>::New();
	observer->Renderer=renderer;
	observer->RenWin=renderWindow;
	observer->coltable=colorLookupTable;
	observer->VFlar=Flar;
    observer->grid=structuredGrid;
	observer->sFilter=s_Filter;
  // Create an Animation Cue.
	vector<vtkSmartPointer<vtkAnimationCue>> Cues;
	Cues.reserve(600);
	for(int i=0;i<times.size();++i){
		vtkSmartPointer<vtkAnimationCue> cue1 =
			vtkSmartPointer<vtkAnimationCue>::New();
		Cues.push_back(cue1);
	}
for(int j=0;j<times.size();++j){
  //Cues[j]->SetStartTime(times[j]);                               //real time
  //if(j==(times.size()-1)) Cues[j]->SetEndTime(times[j]+2);
	//else Cues[j]->SetEndTime(times[j+1]);
	Cues[j]->SetStartTime(0);//.1+(j/10));                            //short time
	if(j==(times.size()-1)) Cues[j]->SetEndTime((j/10)+.2);
	else Cues[j]->SetEndTime(.2+(j/10));
		//Cues[j]->SetStartTime(1+(j/10));
	//if(j==(times.size()-1)) Cues[j]->SetEndTime((j/5)+2);
	//else Cues[j]->SetEndTime(1+(j/5));
  scene->AddCue(Cues[j]);
  Cues[j]->AddObserver(vtkCommand::StartAnimationCueEvent,observer);
  Cues[j]->AddObserver(vtkCommand::EndAnimationCueEvent,observer);
  Cues[j]->AddObserver(vtkCommand::AnimationCueTickEvent,observer);
}	
  scene->Play();
  scene->Stop();
	renderWindowInteractor->Start();
}
void make_interactor(vector<vtkSmartPointer<vtkFloatArray>>& i_Flar,const int& t_steps,const char& slice){//t_steps used to initialize max slider value
	vtkSmartPointer<vtkStructuredGrid> structuredGrid;
		vtkSmartPointer<vtkShrinkFilter> shrinkFilter;//shrink filter sets space between cells
	vtkSmartPointer<vtkLookupTable> colorLookupTable;
	make_reactor(structuredGrid,shrinkFilter,colorLookupTable);//make data points, cells, and set up color table
	f_helper(i_Flar[0]);
	structuredGrid->GetCellData()->SetScalars(i_Flar[0]);
	if (slice=='a'||slice=='b') 
		blank_cells(structuredGrid,slice,0,12);
	double x[3];
	//structuredGrid->GetPointData()->AddArray();
		//cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3];

		
//------------------------------------------------------------------------------------------------------
	vtkSmartPointer<vtkDataSetMapper> mapper = // Create a mapper and actor
		vtkSmartPointer<vtkDataSetMapper>::New();
			mapper->SetInputConnection(shrinkFilter->GetOutputPort());
			//mapper->SetScalarRange(400, 650);//temperature
			mapper->SetScalarRange(-3, 10);
			mapper->SetLookupTable(colorLookupTable);
		//	mapper->SetInterpolateScalarsBeforeMapping(0);
	vtkSmartPointer<vtkActor> actor= 
		vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			actor->RotateX(270);
// Create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderer> renderer= 
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow= 
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor= 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow); 
  // Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(.2, .3, .4);
  // Render and interact
	renderWindow->SetFullScreen(false);
	renderWindow->SetSize(1400, 800);
	//-------------------------------------------------------------------------
	  vtkSmartPointer<vtkAxesActor> axes = 
    vtkSmartPointer<vtkAxesActor>::New();
	  axes->SetYAxisLabelText("Z");
	  axes->SetZAxisLabelText("Y");

	//axes->RotateY(45);
  vtkSmartPointer<vtkOrientationMarkerWidget> o_widget = 
    vtkSmartPointer<vtkOrientationMarkerWidget>::New();
  o_widget->SetOutlineColor( 0.9300, 0.5700, 0.1300 );
  o_widget->SetOrientationMarker( axes );
  o_widget->SetInteractor( renderWindowInteractor );
  o_widget->SetViewport( 0.8, 0.0, 0.9, 0.4 );
  o_widget->SetEnabled( 1 );
  o_widget->InteractiveOn();
  renderer->ResetCamera();
	renderWindow->Render();
	//-----------------------------------------------------------------
	vtkSmartPointer<vtkSliderRepresentation2D> sliderRep =//slider stuff starts here, see header file for command info
		vtkSmartPointer<vtkSliderRepresentation2D>::New();
 
  sliderRep->SetMinimumValue(0);
  sliderRep->SetMaximumValue(t_steps);
  sliderRep->SetValue(0);
  sliderRep->SetTitleText("Time Step");
  //Set color properties: Change the color of the knob that slides
  sliderRep->GetSliderProperty()->SetColor(1,0,0);//red
  // Change the color of the text indicating what the slider controls
  sliderRep->GetTitleProperty()->SetColor(1,0,0);//red
  // Change the color of the text displaying the value
  sliderRep->GetLabelProperty()->SetColor(1,0,0);//red
  // Change the color of the knob when the mouse is held on it
  sliderRep->GetSelectedProperty()->SetColor(0,1,0);//green
  // Change the color of the bar
  sliderRep->GetTubeProperty()->SetColor(1,1,0);//yellow
  // Change the color of the ends of the bar
  sliderRep->GetCapProperty()->SetColor(1,1,0);//yellow 
  sliderRep->GetPoint1Coordinate()->SetCoordinateSystemToDisplay();
  sliderRep->GetPoint1Coordinate()->SetValue(40 ,300);
  sliderRep->GetPoint2Coordinate()->SetCoordinateSystemToDisplay();
  sliderRep->GetPoint2Coordinate()->SetValue(340, 300);

  vtkSmartPointer<vtkSliderWidget> sliderWidget =//create slider widget
    vtkSmartPointer<vtkSliderWidget>::New();
  sliderWidget->SetInteractor(renderWindowInteractor);
  sliderWidget->SetRepresentation(sliderRep);
  sliderWidget->SetAnimationModeToAnimate();
  sliderWidget->EnabledOn();
 
  vtkSmartPointer<vtkSliderCallback> callback =//callback function see head for command info
    vtkSmartPointer<vtkSliderCallback>::New();
  callback->grid = structuredGrid;
  callback->v_Flar = i_Flar;
  sliderWidget->AddObserver(vtkCommand::InteractionEvent,callback);
  renderWindowInteractor->Initialize();
  renderWindow->Render();
  
  renderWindowInteractor->Start();

}
int main(){		
	string file;
	vector<int> cell_no;//holds cell location
	vector<double> time_step;//holds times
	cout<<"Type in File to be used: ";
	cin>>file;
	file="FlowRate";
	loc_and_time(file,cell_no,time_step);
	vector<vtkSmartPointer<vtkFloatArray>> Flarray;
	build_Farray(file,Flarray,cell_no);
	char selector;
	
	while(selector!='q'){
		cout<<"\nTo select interactor press 'i', to select animation press 'm' or 'a' or 'b' \nor 'c' or 'd' , to exit press 'q' \n:";
		cin>>selector;
		switch(selector){
			case 'i':
				make_interactor(Flarray,(time_step.size()-1),'b');//charn used here so that slicing doesn't happen, happens when eithe a or b
				break;
			case 'm':
				make_animation(cell_no,time_step,Flarray,'n',0,0);
					cout<<"this is the animation"; 
				break;
			case 'a':
				make_animation(cell_no,time_step,Flarray,'b',0,0);
				cout<<"this is the animation"; 
				break;
			case 'b':
				make_animation(cell_no,time_step,Flarray,'a',0,12);
				cout<<"this is the animation"; 
				break;
			case 'c':
				make_animation(cell_no,time_step,Flarray,'c',0,12);
				cout<<"this is the animation"; 
				break;
			case 'd':
				make_animation(cell_no,time_step,Flarray,'a',5,5);
				cout<<"this is the animation"; 
				break;
			case 'q':break;
			default:
				cout<<" Not one of the selections please select interactor press i, to select animation press a, to exit press q \n";
		}

	}

	
//	
	return EXIT_SUCCESS;
}

*/