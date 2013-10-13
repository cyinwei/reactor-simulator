#include <vtkActor.h>
#include <vtkAxesActor.h>
#include <vtkCellArray.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkFloatArray.h>
#include <vtkLookupTable.h>
#include <vtkMultiThreader.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPropAssembly.h>
#include <vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkWeakPointer.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>
//#include "Slider.h"
#include"Animation.h"
#include<vtkConeSource.h>
#include<vtkCylinderSource.h>
#include "make_cells.h"
class Interactor{
	public:
		Interactor(vector<vtkSmartPointer<vtkFloatArray> >&core_data, vtkSmartPointer<vtkPolyData>&polydata,
			vtkSmartPointer<vtkPoints> &points,vtkSmartPointer<vtkCellArray>&cells,
			vtkSmartPointer<vtkLookupTable>&cTable );
		void sldr(vtkSmartPointer<vtkSliderRepresentation2D>&sliderRep);
		void interact();//what actually builds window and structure
		void axisptr(vtkSmartPointer<vtkRenderer> &renderer,vtkSmartPointer<vtkRenderWindowInteractor>& renwinint,vtkSmartPointer<vtkRenderWindow>&renwin,
					 vtkSmartPointer<vtkAxesActor>& axes,vtkSmartPointer<vtkOrientationMarkerWidget>& o_widget);//small axis at the corner of window
		vtkSmartPointer<vtkLookupTable> ct_for_bar();
		void interact_animate();
	private:
		vector<vtkSmartPointer<vtkFloatArray> > c_data;//used to hold data
		vtkSmartPointer<vtkPolyData> pdata;//polydata is the structure
		vtkSmartPointer<vtkPoints> pnts;//points for poly data
		vtkSmartPointer<vtkCellArray> cell_arr;//used to hold all cells for polydata
		vtkSmartPointer<vtkLookupTable> ctable;//color table for color map

};


//ignore this for now
/*void chart_helper(vtkSmartPointer<vtkCellArray> &carray){
	for(int i=0;i<9;++i ){
	vtkSmartPointer<vtkQuad> quad =//top bottom
		vtkSmartPointer<vtkQuad>::New();
		quad->GetPointIds()->SetNumberOfIds(4);
		quad->GetPointIds()->SetId(0,0+i*2);
		quad->GetPointIds()->SetId(1,1+i*2);
		quad->GetPointIds()->SetId(2,3+i*2);
		quad->GetPointIds()->SetId(3,2+i*2);
		carray->InsertNextCell(quad);
	}
}

void color_chart(vtkSmartPointer<vtkPolyData>&cpolydata){
	vtkSmartPointer<vtkFloatArray> cfloat=vtkSmartPointer<vtkFloatArray>::New();
	cfloat->Allocate(10);
	vtkSmartPointer<vtkPoints> cpoints=
		vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> carray = 
		vtkSmartPointer<vtkCellArray>::New();		
		for(int i=0;i<10;++i){
			cpoints->InsertNextPoint(17,0,0+i);cfloat->InsertNextTuple1(10-(1+i));
			cpoints->InsertNextPoint(18,0,0+i);cfloat->InsertNextTuple1(10-(1+i));
		}
		cpolydata->SetPoints(cpoints);
		chart_helper(carray);
		cpolydata->SetPolys(carray);
		cpolydata->GetPointData()->SetScalars(cfloat);
}*/




