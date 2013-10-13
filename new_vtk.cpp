#include <vtkVersion.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkQuad.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
 /*
int main(int , char *[])
{
  // Create four points (must be in counter clockwise order)
  double p0[3] = {0.0, 0.0, 0.0};
  double p1[3] = {1.0, 0.0, 0.0};
  double p2[3] = {1.0, 1.0, 0.0};
  double p3[3] = {0.0, 1.0, 0.0};
  double p4[3] = {0.0, 0.0, 1.0};
  double p5[3] = {1.0, 0.0, 1.0};
  double p6[3] = {1.0, 1.0, 1.0};
  double p7[3] = {0.0, 1.0, 1.0};
 
  // Add the points to a vtkPoints object
  vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();
  points->InsertNextPoint(p0);
  points->InsertNextPoint(p1);
  points->InsertNextPoint(p2);
  points->InsertNextPoint(p3);
  points->InsertNextPoint(p4);
  points->InsertNextPoint(p5);
  points->InsertNextPoint(p6);
  points->InsertNextPoint(p7);
 
  // Create a quad on the four points
    vtkSmartPointer<vtkQuad> quad =
    vtkSmartPointer<vtkQuad>::New();quad->GetPointIds()->SetNumberOfIds(4);
	  vtkSmartPointer<vtkQuad> quad2 =
    vtkSmartPointer<vtkQuad>::New();quad2->GetPointIds()->SetNumberOfIds(4);
	    vtkSmartPointer<vtkQuad> quad3 =
    vtkSmartPointer<vtkQuad>::New();quad3->GetPointIds()->SetNumberOfIds(4);
  vtkSmartPointer<vtkQuad> quad4 =
    vtkSmartPointer<vtkQuad>::New();quad4->GetPointIds()->SetNumberOfIds(4);
  quad->GetPointIds()->SetId(0,0);
  quad->GetPointIds()->SetId(1,1);
  quad->GetPointIds()->SetId(2,2);
  quad->GetPointIds()->SetId(3,3);

    quad2->GetPointIds()->SetId(0,4);
  quad2->GetPointIds()->SetId(1,5);
  quad2->GetPointIds()->SetId(2,6);
  quad2->GetPointIds()->SetId(3,7);

    quad3->GetPointIds()->SetId(0,0);
  quad3->GetPointIds()->SetId(1,1);
  quad3->GetPointIds()->SetId(2,5);
  quad3->GetPointIds()->SetId(3,4);

  quad4->GetPointIds()->SetId(0,1);
  quad4->GetPointIds()->SetId(1,2);
  quad4->GetPointIds()->SetId(2,6);
  quad4->GetPointIds()->SetId(3,5);
 
  // Create a cell array to store the quad in
  vtkSmartPointer<vtkCellArray> quads =
    vtkSmartPointer<vtkCellArray>::New();
  quads->InsertNextCell(quad);
 quads->InsertNextCell(quad2);
 quads->InsertNextCell(quad3);
 quads->InsertNextCell(quad4);
  // Create a polydata to store everything in
  vtkSmartPointer<vtkPolyData> polydata =
    vtkSmartPointer<vtkPolyData>::New();
 
  // Add the points and quads to the dataset
  polydata->SetPoints(points);
  polydata->SetPolys(quads);
 
  // Setup actor and mapper
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
#if VTK_MAJOR_VERSION <= 5
  mapper->SetInput(polydata);
#else
  mapper->SetInputData(polydata);
#endif
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  // Setup render window, renderer, and interactor
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  renderer->AddActor(actor);
  renderWindow->Render();
  renderWindowInteractor->Start();
 
  return EXIT_SUCCESS;
}*/
/*void write_to_file(vector<int>& loc,vector<vector<string>>& ts,vector<string>time_values){
	string ofname;
	cout<<"Enter output file name:\n";
	cin>>ofname;
	ofstream appFile;//output stream to file
	appFile.open(ofname+".", ios::out | ios::app); //opens file for append, preventing overwriting
	for(int j=0;j<(loc.size());++j){
		appFile <<loc[j]<<" ";			//adds given string to file
	}
	appFile<<"\n";
	for(int g=0;g<(time_values.size());++g){
		appFile <<time_values[g]<<" ";			//adds given string to file
	}
	appFile<<"\n";
	for(int i=0;i<ts.size();++i){
		for(int k=0;k<ts[i].size();++k){
			appFile <<setprecision(4)<<stod(ts[i][k])<<" ";}		
	appFile<<"\n";
	}
	cout<<"File conversion completed\n";
}
//-------*/