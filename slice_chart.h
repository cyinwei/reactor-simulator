#include <vtkAxesActor.h>
#include <vtkActor.h>
#include<vtkArrowSource.h>
#include<vtkConeSource.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include<vtkGlyph3D.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkInteractorStyleTrackballActor.h>
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
#include <vtkSliderRepresentation2D.h>
#include <vtkWeakPointer.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>




/*dont worry about this for now still building, it mirrors interactor but has a couple of differences since it makes a
vector field vice using cells*/
using namespace std;

class slice_chart{
	public:
		slice_chart(vector<vtkSmartPointer<vtkFloatArray> >&core_data, vtkSmartPointer<vtkPolyData>&polydata,
			vtkSmartPointer<vtkPoints> &points,vtkSmartPointer<vtkCellArray>&cells);
		void sldr(vtkSmartPointer<vtkSliderRepresentation2D>&sliderRep);
		void axisptr(vtkSmartPointer<vtkRenderer> &renderer,vtkSmartPointer<vtkRenderWindowInteractor>& renwinint,vtkSmartPointer<vtkRenderWindow>&renwin,
					 vtkSmartPointer<vtkAxesActor>& axes,vtkSmartPointer<vtkOrientationMarkerWidget>& o_widget);
		void arrowfield();
		vtkSmartPointer<vtkLookupTable> colortable();
		void arrowfield_animate();
	private:
		vector<vtkSmartPointer<vtkFloatArray> > c_data;
		vtkSmartPointer<vtkPolyData> pdata;
		vtkSmartPointer<vtkPoints> pnts;
		vtkSmartPointer<vtkCellArray> cell_arr;
		vtkSmartPointer<vtkLookupTable> ctable;

};