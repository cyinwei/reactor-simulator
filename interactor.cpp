#include"interactor.h"
//constructor, has choices in what to build
Interactor::Interactor(vector<vtkSmartPointer<vtkFloatArray>>&core_data, vtkSmartPointer<vtkPolyData>&polydata,
		vtkSmartPointer<vtkPoints> &points,vtkSmartPointer<vtkCellArray>&cells,
		vtkSmartPointer<vtkLookupTable>&cTable ):c_data(core_data),pdata(polydata),pnts(points),
			cell_arr(cells),ctable(cTable){
					Rxbuild relap(c_data);//handles data and builds reactor
					relap.point_build(pnts);
					relap.get_tuples(c_data);//set scalors
					char choice='0';
					std::cout<<"\n make a choice a, b, c, or d\n";
					std::cin>>choice;
					switch(choice){
					case 'a':
						relap.make_full_cells(cell_arr,0,13); break;//make reactor cellarray/first y(not implemented yet)/second y(not implemented yet)/first z /second z
					case 'b':
						relap.make_full_cells(cell_arr,1,2); break;
					case 'c':
						relap.make_center(cells,'b'); break;
					case 'd':
						relap.make_cross(cells);break;
					default:
						std::cout<<"not a choice, bye\n"; break;
					}
					
					pdata->SetPoints(pnts);
					pdata->SetPolys(cell_arr);
					pdata->Update();
					interact();
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
	o_widget->SetViewport( 0.8, 0.0, 0.9, 0.4 );
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

