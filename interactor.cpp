#include"interactor.h"
#include "make_cells.h"
#include "Slider.h"
#include"Animation.h"
using namespace std;
//constructor, has choices in what to build
Interactor::Interactor(vector<vtkSmartPointer<vtkFloatArray> >&core_data, vtkSmartPointer<vtkPolyData>&polydata,
		vtkSmartPointer<vtkPoints> &points,vtkSmartPointer<vtkCellArray>&cells,
		vtkSmartPointer<vtkLookupTable>&cTable ):c_data(core_data),pdata(polydata),pnts(points),
			cell_arr(cells),ctable(cTable){
					Rxbuild relap(c_data);//handles data and builds reactor
					relap.point_build(pnts);
					relap.get_tuples(c_data);//set scalors
					char choice='0';
					std::cout<<"\n make a choice a, b, c, d, or e\n";
					std::cin>>choice;
					switch(choice){
					case 'a':
						relap.make_full_cells(cell_arr,0,13); break;//make reactor cellarray/first y(not implemented yet)/second y(not implemented yet)/first z /second z
					case 'b':
						relap.make_full_cells(cell_arr,2,3); break;
					case 'c':
						relap.make_center(cells,'b'); break;
					case 'd':
						relap.make_cross(cells);break;
					case 'e':
						relap.make_threefourth_cells(cell_arr,0,13);break;
					default:
						std::cout<<"not a choice, bye\n"; break;
					}
					
					pdata->SetPoints(pnts);
					pdata->SetPolys(cell_arr);
					pdata->Update();
					interact();
					//interact_animate();
				}
vtkSmartPointer<vtkLookupTable> Interactor::ct_for_bar(){
	  vtkSmartPointer<vtkLookupTable> lut =
    vtkSmartPointer<vtkLookupTable>::New();
	  lut->SetTableRange(-3, 13); 
  lut->SetNumberOfTableValues(10);
  lut->Build();
  lut->SetTableValue(0, 0, 0, 1, 1);  //blue
  lut->SetTableValue(1, 0,1,1, 1); // 
  lut->SetTableValue(2, 0,1,0.78, 1); // blueish green
  lut->SetTableValue(3, 0,1,0.3137, 1); // 
  lut->SetTableValue(4, 0,1,0, 1); // green
  lut->SetTableValue(5, 0.5, 1, 0, 1); // yellow green
  lut->SetTableValue(6, 1,1,0, 1); // yellow
  lut->SetTableValue(7, 1,0.68,0, 1); // 
  lut->SetTableValue(8, 1,0.2745,0, 1); // orange
  lut->SetTableValue(9, 1, 0, 0, 1); // red
  return lut;
}

//axis at the corner to determine direction
void Interactor:: axisptr(vtkSmartPointer<vtkRenderer> &renderer,vtkSmartPointer<vtkRenderWindowInteractor>& renwinint,vtkSmartPointer<vtkRenderWindow>&renwin,
	vtkSmartPointer<vtkAxesActor>& axes,vtkSmartPointer<vtkOrientationMarkerWidget>& o_widget){
	axes = vtkSmartPointer<vtkAxesActor>::New();
	axes->SetYAxisLabelText("Z");
	axes->SetZAxisLabelText("Y");
	o_widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
	o_widget->SetOutlineColor( 0.9300, 0.5700, 0.1300 );
	o_widget->SetOrientationMarker( axes );
	o_widget->SetInteractor(renwinint);
	o_widget->SetViewport( 0.7, 0.0, 0.8, 0.4 );
	o_widget->SetEnabled( 1 );
	o_widget->InteractiveOn();
	
}

//helps build slider, trying to keep interact function minimal
void Interactor::sldr(vtkSmartPointer<vtkSliderRepresentation2D>&sliderRep){
	sliderRep->SetMinimumValue(0);
	sliderRep->SetMaximumValue(c_data.size()-1);
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
}

//makes window and structure
void Interactor::interact(){
	pdata->GetPointData()->SetScalars(c_data[0]);//set point values 
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();	
//-------------------------------------------------------------
		vtkSmartPointer<vtkScalarBarActor> scalarBar = 
		vtkSmartPointer<vtkScalarBarActor>::New();
  scalarBar->SetLookupTable(mapper->GetLookupTable());
  scalarBar->SetTitle("Flow Rate");
  scalarBar->SetNumberOfLabels(4);
  scalarBar->SetLookupTable( ct_for_bar());
  //------------------------------------------------------------
	vtkSmartPointer<vtkTextActor> textActor = 
		vtkSmartPointer<vtkTextActor>::New();
	textActor->GetTextProperty()->SetFontSize ( 65 );
	textActor->SetPosition(980,600);
	// textActor->SetPosition2 ( 1010, 60 );
	textActor->SetInput ( ">13" );
	textActor->GetTextProperty()->SetColor ( 1.0,1.0,1.0 ); 
		vtkSmartPointer<vtkTextActor> textActor2 = 
		vtkSmartPointer<vtkTextActor>::New();
	textActor2->GetTextProperty()->SetFontSize ( 65 );
	textActor2->SetPosition(980,50);
	// textActor->SetPosition2 ( 1010, 60 );
	textActor2->SetInput ( "<-3" );
	textActor2->GetTextProperty()->SetColor ( 1.0,1.0,1.0 );
  //-----------------------------------------------------------
#if VTK_MAJOR_VERSION <= 5
	mapper->SetInput(pdata);//map poly data to everything else
#else
	mapper->SetInputData(pdata);
#endif  			
	mapper->SetScalarRange(0,10);//color map utility
	mapper->SetLookupTable(ctable);//color map mapping
	mapper->SetInterpolateScalarsBeforeMapping(1);//interpolate
//----------------------------------------------------------------------------------------
	vtkSmartPointer<vtkActor> actor = 
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);//map actor
	actor->RotateX(270);//rotate
 //-------------------Visualize------------------------------------------------------------------
	vtkSmartPointer<vtkRenderer> renderer = 
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow = 
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);
	renderer->AddActor(actor);
	renderer->AddActor2D(scalarBar);
	renderer->AddActor2D ( textActor );
	renderer->AddActor2D ( textActor2 );
	renderer->SetBackground(0, 0, 0);
	renderWindow->SetSize(1400, 800);
	vtkSmartPointer<vtkAxesActor> axes;
	vtkSmartPointer<vtkOrientationMarkerWidget> owidget;
	axisptr(renderer,renderWindowInteractor,renderWindow,axes,owidget);
	renderer->ResetCamera();
	renderWindow->Render();
  //----------------------------------------slider
  	vtkSmartPointer<vtkSliderRepresentation2D> slider =
		vtkSmartPointer<vtkSliderRepresentation2D>::New();
	sldr(slider);
 
	vtkSmartPointer<vtkSliderWidget> sliderWidget =//create slider widget
		vtkSmartPointer<vtkSliderWidget>::New();
	sliderWidget->SetInteractor(renderWindowInteractor);
	sliderWidget->SetRepresentation(slider);
	sliderWidget->SetAnimationModeToAnimate();
	sliderWidget->EnabledOn();

    vtkSmartPointer<vtkSliderCallback> callback =//callback function see head for command info
		vtkSmartPointer<vtkSliderCallback>::New();
	callback->polyd = pdata;
	callback->v_Flar = c_data;
	callback->selector='b';//slider type selection, the char determines what type of slider needed interactor or slice_chart
	sliderWidget->AddObserver(vtkCommand::InteractionEvent,callback);

	renderWindowInteractor->Initialize();
	renderWindow->Render();
	renderWindowInteractor->Start();
}




void Interactor::interact_animate(){
	pdata->GetPointData()->SetScalars(c_data[0]);//set point values 
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();	
//-------------------------------------------------------------
		vtkSmartPointer<vtkScalarBarActor> scalarBar = 
		vtkSmartPointer<vtkScalarBarActor>::New();
  scalarBar->SetLookupTable(mapper->GetLookupTable());
  scalarBar->SetTitle("Flow Rate");
  scalarBar->SetNumberOfLabels(4);
  scalarBar->SetLookupTable( ct_for_bar());
  //------------------------------------------------------------
	vtkSmartPointer<vtkTextActor> textActor = 
		vtkSmartPointer<vtkTextActor>::New();
	textActor->GetTextProperty()->SetFontSize ( 65 );
	textActor->SetPosition(980,600);
	// textActor->SetPosition2 ( 1010, 60 );
	textActor->SetInput ( ">13" );
	textActor->GetTextProperty()->SetColor ( 1.0,1.0,1.0 ); 
			vtkSmartPointer<vtkTextActor> textActor2 = 
		vtkSmartPointer<vtkTextActor>::New();
	textActor2->GetTextProperty()->SetFontSize ( 65 );
	textActor2->SetPosition(980,50);
	// textActor->SetPosition2 ( 1010, 60 );
	textActor2->SetInput ( "<-3" );
	textActor2->GetTextProperty()->SetColor ( 1.0,1.0,1.0 );
  //-----------------------------------------------------------
#if VTK_MAJOR_VERSION <= 5
	mapper->SetInput(pdata);//map poly data to everything else
#else
	mapper->SetInputData(pdata);
#endif  			
	mapper->SetScalarRange(0,10);//color map utility
	mapper->SetLookupTable(ctable);//color map mapping
	mapper->SetInterpolateScalarsBeforeMapping(1);//interpolate
//----------------------------------------------------------------------------------------
	vtkSmartPointer<vtkActor> actor = 
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);//map actor
	actor->RotateX(270);//rotate
 //-------------------Visualize------------------------------------------------------------------
	vtkSmartPointer<vtkRenderer> renderer = 
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow = 
		vtkSmartPointer<vtkRenderWindow>::New();
	cout<<renderWindow->GetActualSize();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);
	renderer->AddActor(actor);
	renderer->AddActor2D(scalarBar);
	renderer->AddActor2D ( textActor );
	renderer->AddActor2D ( textActor2 );
	renderer->SetBackground(0, 0, 0);
	renderWindow->SetSize(1400, 800);
	vtkSmartPointer<vtkAxesActor> axes;
	vtkSmartPointer<vtkOrientationMarkerWidget> owidget;
	axisptr(renderer,renderWindowInteractor,renderWindow,axes,owidget);
	renderer->ResetCamera();
	renderWindow->Render();


	vtkSmartPointer<vtkAnimationScene> scene =
		vtkSmartPointer<vtkAnimationScene>::New();
  scene->SetModeToSequence();
  scene->SetLoop(0);
  scene->SetFrameRate(5);
  scene->SetStartTime(1);
  //scene->SetEndTime(times[times.size()-1]); //for real time
  scene->SetEndTime((663)); //for long time steps
  //scene->SetEndTime((times.size()/(1.5)));//for short time steps
  // Create Cue observer.
  vtkSmartPointer<vtkAnimationCueObserver> observer =
    vtkSmartPointer<vtkAnimationCueObserver>::New();
	observer->Renderer=renderer;
	observer->RenWin=renderWindow;
	observer->coltable=ctable;
	observer->Flar=c_data;
    observer->pdata=pdata;
	observer->mapper=mapper;
	observer->actor=actor;
	observer->is_scalar=true;
  // Create an Animation Cue.
	vector<vtkSmartPointer<vtkAnimationCue> > Cues;
	Cues.reserve(600);
	for(int i=0;i<663;++i){
		vtkSmartPointer<vtkAnimationCue> cue1 =
			vtkSmartPointer<vtkAnimationCue>::New();
		Cues.push_back(cue1);
	}
for(int j=0;j<663;++j){
  //Cues[j]->SetStartTime(times[j]);                               //real time
  //if(j==(times.size()-1)) Cues[j]->SetEndTime(times[j]+2);
	//else Cues[j]->SetEndTime(times[j+1]);
	Cues[j]->SetStartTime(0);//.1+(j/10));                            //short time
	if(j==(663-1)) Cues[j]->SetEndTime(1);
	else Cues[j]->SetEndTime(1);//(.2+(j/10));
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