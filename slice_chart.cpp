#include"slice_chart.h"
#include "Slider.h"
#include "make_cells.h"
#include<vtkCubeSource.h>
//still testing dont worry about this now
//Constructor
slice_chart::slice_chart(vector<vtkSmartPointer<vtkFloatArray>>&core_data, vtkSmartPointer<vtkPolyData>&polydata,
			vtkSmartPointer<vtkPoints> &points,vtkSmartPointer<vtkCellArray>&cells):c_data(core_data),pdata(polydata),pnts(points),
				cell_arr(cells){
					Rxbuild relap(c_data);
					//relap.point_slice(pnts,c_data,cell_arr,pdata);
					
					relap.get_tuples_for_slice(c_data);
					//relap.point_slice(pnts,c_data,cell_arr,pdata);
					relap.point_build(pnts);
					arrowfield();
				}
//same function as in interactor.h
void slice_chart:: axisptr(vtkSmartPointer<vtkRenderer> &renderer,vtkSmartPointer<vtkRenderWindowInteractor>& renwinint,vtkSmartPointer<vtkRenderWindow>&renwin,
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
//same function as in interactor.h
void slice_chart::sldr(vtkSmartPointer<vtkSliderRepresentation2D>&sliderRep){
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

vtkSmartPointer<vtkLookupTable> slice_chart::colortable(){
	  vtkSmartPointer<vtkLookupTable> lut =
    vtkSmartPointer<vtkLookupTable>::New();
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
//this is kind of like interact funtion in interact but what it does is build a slice but uses a vector field instead of cells
void slice_chart::arrowfield(){
	vtkSmartPointer<vtkArrowSource> arrow = 
		vtkSmartPointer<vtkArrowSource>::New();
   arrow->SetTipResolution(6);
   arrow->SetTipRadius(.1);
   arrow->SetTipLength(0.35);
   arrow->SetShaftResolution(6);
   arrow->SetShaftRadius(0.03);
   
   vtkSmartPointer<vtkGlyph3D> glyph = 
		vtkSmartPointer<vtkGlyph3D>::New();
   glyph->SetInputConnection(pdata->GetProducerPort());
   glyph->SetSourceConnection(arrow->GetOutputPort());
   glyph->SetVectorModeToUseVector();
   //glyph->SetColorModeToColorByScalar();
   glyph->SetColorModeToColorByVector();
   glyph->SetScaleModeToDataScalingOff();
   glyph->OrientOn();
   glyph->SetScaleFactor(.2);
  // glyph->SetScaleModeToScaleByVectorComponents();
   glyph->SetScaleModeToScaleByVector();
	pdata->SetPoints(pnts);
	pdata->SetPolys(cell_arr);
	pdata->Update();
	pdata->GetPointData()->SetVectors(c_data[0]);
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	
#if VTK_MAJOR_VERSION <= 5
	mapper->SetInputConnection(glyph->GetOutputPort());
#else
	mapper->SetInputData(pdata);
#endif  	
	mapper->ScalarVisibilityOn();
	mapper->SetScalarRange(0,13);
	mapper->SetLookupTable(colortable());
	//mapper->Set
	//mapper->SetInterpolateScalarsBeforeMapping(1);
	//mapper->InterpolateScalarsBeforeMappingOn()	;	
//----------------------------------------------------------------------------------------
	vtkSmartPointer<vtkActor> actor = 
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->RotateX(270);
	actor->GetProperty()->SetPointSize(100);
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
	callback->selector='a';//ensure slider is for arrow source type
	sliderWidget->AddObserver(vtkCommand::InteractionEvent,callback);
	renderWindowInteractor->Initialize();
	renderWindow->Render();
//-------------------------------------------------------------------------------------------
	renderWindowInteractor->Start();

}