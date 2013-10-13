#include"make_cells.h"
#include <stdexcept>
//this is to make all points in rx, used by interactor
void Rxbuild::point_build(vtkSmartPointer<vtkPoints>& points){
	for(int i=0;i<53;++i){
		 if(i!=0){i+=3;}
		for(int j=8;j<23;j+=2){//int j=4;j<12;++j	
			points->InsertNextPoint(j, 0, (i));	
		}
		for(int k=4;k<27;k+=2){//int k=2;k<14;++k
			points->InsertNextPoint(k, 2, i);
			}			
		for(int m=4;m<7;m+=2)//2,4							
			for(int l=2;l<29;l+=2){//int l=1;l<15;++l
				points->InsertNextPoint(l, m, i);
				}
		for(int n=8;n<23;n+=2)//4,12
			for(int p=0;p<31;p+=2){//16
				points->InsertNextPoint(p, n, i);
				}
		for(int q=24;q<27;q+=2)	//12,14
			for(int r=2;r<29;r+=2){//nt r=1;r<15;++r
				points->InsertNextPoint(r, q, i);
				}
		for(int s=4;s<27;s+=2){//int s=2;s<14;++s
			points->InsertNextPoint(s, 28, i);
			}
		for(int t=8;t<23;t+=2){//int t=4;t<12;++t
			points->InsertNextPoint(t, 30, i);
			}
		}
}
//this is a test for now 
void Rxbuild::point_slice(vtkSmartPointer<vtkPoints>& points,vector<vtkSmartPointer<vtkFloatArray> >& Farray,vtkSmartPointer<vtkCellArray>&cells,vtkSmartPointer<vtkPolyData> polyd){
	int L=10;//flow rate factor
	string f="FlowRate";
	vector<vector<double> > tran;
	tran.reserve(663);
	get_data(f,tran);	
	for(int i=0;i<27;++i){
		 if(i!=0){i+=2;}
	for(int p=0;p<15;++p)//16
		points->InsertNextPoint(p, 0, i);
	}
	
	int x=0;
	for(int g=0;g<663;++g){
		vtkSmartPointer<vtkFloatArray> t=vtkSmartPointer<vtkFloatArray>::New();
		t->Allocate(300);
		for(int z=0;z<13;++z)
			for(int j=89;j<104;++j){
				t->InsertNextTuple1(L-tran[g][(j+z*193)]);	
				++x;

			}
		Farray.push_back(t);
	}
for(int z=0;z<12;++z)
for(int i=0;i<14;++i ){
	vtkSmartPointer<vtkQuad> quad =//top bottom
		vtkSmartPointer<vtkQuad>::New();
		quad->GetPointIds()->SetNumberOfIds(4);
		quad->GetPointIds()->SetId(0,i+z*15);
		quad->GetPointIds()->SetId(1,1+i+z*15);
		quad->GetPointIds()->SetId(2,16+i+z*15);
		quad->GetPointIds()->SetId(3,15+i+z*15);
		cells->InsertNextCell(quad);}

	polyd->SetPoints(points);
	polyd->SetPolys(cells);
}



//make a box cell out quads
void Rxbuild::make_box( int x[4],vtkSmartPointer<vtkCellArray> &cells){
	for(int i=0;i<2;++i){
	vtkSmartPointer<vtkQuad> quad =//top bottom
		vtkSmartPointer<vtkQuad>::New();
	quad->GetPointIds()->SetNumberOfIds(4);
	quad->GetPointIds()->SetId(0,x[0]+i*224);
	quad->GetPointIds()->SetId(1,x[1]+i*224);
	quad->GetPointIds()->SetId(2,x[3]+i*224);
	quad->GetPointIds()->SetId(3,x[2]+i*224);
	cells->InsertNextCell(quad);
	}
for(int j=0;j<2;++j){
	vtkSmartPointer<vtkQuad> quad =//top bottom
		vtkSmartPointer<vtkQuad>::New();
	quad->GetPointIds()->SetNumberOfIds(4);
	quad->GetPointIds()->SetId(0,x[0]+j);//0,1,10,11
	quad->GetPointIds()->SetId(1,x[0]+j+224);
	quad->GetPointIds()->SetId(2,x[2]+j+224);
	quad->GetPointIds()->SetId(3,x[2]+j);
	cells->InsertNextCell(quad);
		}
for(int j=0;j<2;++j){
	int p=x[0];
	int q=x[1];
	if(j==1){
		p=x[2]; 
		q=x[3];
}
	vtkSmartPointer<vtkQuad> quad =//top bottom
		vtkSmartPointer<vtkQuad>::New();
	quad->GetPointIds()->SetNumberOfIds(4);
	quad->GetPointIds()->SetId(0,p);//0,1,11,1
	quad->GetPointIds()->SetId(1,p+224);
	quad->GetPointIds()->SetId(2,q+224);
	quad->GetPointIds()->SetId(3,q);
	cells->InsertNextCell(quad);
		}
}
//full rx build for interactor
void Rxbuild:: make_full_cells(vtkSmartPointer<vtkCellArray>&cells,const int& q,const int& p){
	if(q<0||q>12){runtime_error("can not set lowerbound <0 or >12");}
	if(p<q||p>13){runtime_error("can not set upper bound >13or less than lower bound");}
	for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=0;i<7;++i){	
			int x[4]={i+z*224+y*206,i+1+z*224+y*206,i+10+z*224+y*206,i+11+z*224+y*206};
		make_box(x,cells);}
for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=8;i<19;++i){	
			int x[4]={i+z*224+y*183,i+1+z*224+y*183,i+13+z*224+y*183,i+14+z*224+y*183};
		make_box(x,cells);}		
		
for(int y=0;y<7;++y)
	for(int z=q;z<p;++z)
		for(int i=48;i<63;++i){	
			int x[4]={i+z*224+y*16,i+1+z*224+y*16,i+16+z*224+y*16,i+17+z*224+y*16};
		make_box(x,cells);}
		
for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=20;i<33;++i){	
			int x[4]={i+z*224+y*156,i+1+z*224+y*156,i+14+z*224+y*156,i+15+z*224+y*156};
		make_box(x,cells);}
		

		for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=34;i<47;++i){	
			int x[4]={i+z*224+y*127,i+1+z*224+y*127,i+15+z*224+y*127,i+16+z*224+y*127};
		make_box(x,cells);}
		

}

void Rxbuild:: make_threefourth_cells(vtkSmartPointer<vtkCellArray>&cells,const int& q,const int& p){
	if(q<0||q>12){runtime_error("can not set lowerbound <0 or >12");}
	if(p<q||p>13){runtime_error("can not set upper bound >13or less than lower bound");}
	for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=0;i<7;++i){
			if(y<1 || i<3){
			int x[4]={i+z*224+y*206,i+1+z*224+y*206,i+10+z*224+y*206,i+11+z*224+y*206};
			make_box(x,cells);}}
for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=8;i<19;++i){	
			if(y<1 || i<13){
			int x[4]={i+z*224+y*183,i+1+z*224+y*183,i+13+z*224+y*183,i+14+z*224+y*183};
			make_box(x,cells);}}		
		
for(int y=0;y<7;++y)
	for(int z=q;z<p;++z)
		for(int i=48;i<63;++i){
			if(y<3 || i<55){
			int x[4]={i+z*224+y*16,i+1+z*224+y*16,i+16+z*224+y*16,i+17+z*224+y*16};
			make_box(x,cells);}}
		
for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=20;i<33;++i){	
			if(y<1 || i<26){
			int x[4]={i+z*224+y*156,i+1+z*224+y*156,i+14+z*224+y*156,i+15+z*224+y*156};
			make_box(x,cells);}}
		

		for(int y=0;y<2;++y)
	for(int z=q;z<p;++z)
		for(int i=34;i<47;++i){	
			if(y<1 || i<40){
			int x[4]={i+z*224+y*127,i+1+z*224+y*127,i+15+z*224+y*127,i+16+z*224+y*127};
			make_box(x,cells);}}
		

}

//get data from files to input into points
void Rxbuild::get_data(const string& fname, vector<vector<double> > &transfer){
	ifstream datas(fname.c_str());//open file
	if (!datas){ cout<<"can't open file";}
	double values=0;
	string stemp="0";
	int line_no=0;
	while(getline(datas,stemp)){
		if(line_no>1){//go to the line where values start and start reading values into vectors, each line represents values
			vector<double> v;
			v.reserve(2509);
			stringstream tss(stemp);//(cont.) at a certain time, 
			while(tss>>values){
				if(values>13)values=13;
				if(values<-5)values=-5;
				v.push_back(values);
			}
			transfer.push_back(v);//push back each value vector into this for later accessing
		}
		++line_no;//used to increment to the right line, check above loop
	}
	datas.close();//close file
	
}
//input data into array for points for interactor
void Rxbuild::get_tuples(vector<vtkSmartPointer<vtkFloatArray> >& Farray){
	int b=0;
	double L=13;//flow rate factor
	string f="FlowRate";
	vector<vector<double> > tran;
	tran.reserve(663);
	get_data(f,tran);
	for(int j=0;j<663;++j){
		vtkSmartPointer<vtkFloatArray> t=
					vtkSmartPointer<vtkFloatArray>::New();
		t->Allocate(3136);
		//t->SetNumberOfComponents(3);
	for(int z=0;z<14;++z){int point=0;
		if(z<13)b=z;
		else {b=(z-1);}
			for(int i=0;i<89;++i){
				t->InsertTuple1(point+z*224,L-tran[j][i+b*193]);
				//t->InsertTuple3(point+z*224,L-tran[j][i+b*193],0,0);
				if(point==3||point==13||point==26||point==40||point==55||point==71||point==87){
					++point;
					t->InsertTuple1(point+z*224,L-tran[j][i+b*193]);
					//t->InsertTuple3(point+z*224,L-tran[j][i+b*193],1,1);
				//ensure to test
				}
				++point;
		}		
		for(int i=89;i<104;++i){//problem is here
			t->InsertTuple1(point+z*224,L-tran[j][i+b*193]);
			t->InsertTuple1(point+16+z*224,L-tran[j][i+b*193]);
			//t->InsertTuple3(point+z*224,L-tran[j][i+b*193],0,0);
			//t->InsertTuple3(point+16+z*224,L-tran[j][i+b*193],0,0);
			
			if(point==103){
				t->InsertTuple1(point+1+z*224,L-tran[j][i+b*193]);
				t->InsertTuple1(point+17+z*224,L-tran[j][i+b*193]);
				//t->InsertTuple3(point+1+z*224,L-tran[j][i+b*193],0,0);
				//t->InsertTuple3(point+17+z*224,L-tran[j][i+b*193],0,0);
				++point;
			}
			++point;
		}
		point+=16;
		for(int i=104;i<193;++i){
				t->InsertTuple1(point+z*224,L-tran[j][i+b*193]);
				//t->InsertTuple3(point+z*224,L-tran[j][i+b*193],0,0);
				if(point==135||point==151||point==167||point==182||point==196||point==209||point==219){
					++point;
					t->InsertTuple1(point+z*224,L-tran[j][i+b*193]);
					//t->InsertTuple3(point+z*224,L-tran[j][i+b*193],0,0);
				}
				++point;
		}
	}	
	Farray.push_back(t);
	
	}
}
//make center slice vertically for interactor
void Rxbuild::make_center(vtkSmartPointer<vtkCellArray>&cells,const char& select){
	switch(select){
		case 'a':
			for(int z=0;z<13;++z)
				for(int i=96;i<111;++i){	
				int x[4]={i+z*224,i+1+z*224,i+16+z*224,i+17+z*224};
				make_box(x,cells);}
			break;

		case 'b':
				for(int z=0;z<13;++z){
					for(int y=0;y<2;++y)
						for(int i=3;i<4;++i){	
							int x[4]={i+z*224+y*206,i+1+z*224+y*206,i+10+z*224+y*206,i+11+z*224+y*206};
							make_box(x,cells);}

					for(int y=0;y<2;++y)
						for(int i=13;i<14;++i){	
							int x[4]={i+z*224+y*183,i+1+z*224+y*183,i+13+z*224+y*183,i+14+z*224+y*183};
							make_box(x,cells);}

					for(int y=0;y<2;++y)
						for(int i=26;i<27;++i){	
							int x[4]={i+z*224+y*156,i+1+z*224+y*156,i+14+z*224+y*156,i+15+z*224+y*156};
							make_box(x,cells);}
	
					for(int y=0;y<2;++y)
						for(int i=40;i<41;++i){	
							int x[4]={i+z*224+y*127,i+1+z*224+y*127,i+15+z*224+y*127,i+16+z*224+y*127};
							make_box(x,cells);}
	
					for(int y=0;y<7;++y)
						for(int i=55;i<56;++i){	
							int x[4]={i+z*224+y*16,i+1+z*224+y*16,i+16+z*224+y*16,i+17+z*224+y*16};
							make_box(x,cells);}
				}
			break;
		default: 
			std::cout<<"not a choice"; break;
	}
}
//make a vertical cross with two center slices, for interactor
void Rxbuild::make_cross(vtkSmartPointer<vtkCellArray>&cells){
	for(int z=0;z<13;++z){
		for(int i=96;i<111;++i){	
			int x[4]={i+z*224,i+1+z*224,i+16+z*224,i+17+z*224};
			make_box(x,cells);}

	for(int y=0;y<2;++y)
		for(int i=3;i<4;++i){	
			int x[4]={i+z*224+y*206,i+1+z*224+y*206,i+10+z*224+y*206,i+11+z*224+y*206};
			make_box(x,cells);}

	for(int y=0;y<2;++y)
		for(int i=13;i<14;++i){	
			int x[4]={i+z*224+y*183,i+1+z*224+y*183,i+13+z*224+y*183,i+14+z*224+y*183};
			make_box(x,cells);}

	for(int y=0;y<2;++y)
		for(int i=26;i<27;++i){	
			int x[4]={i+z*224+y*156,i+1+z*224+y*156,i+14+z*224+y*156,i+15+z*224+y*156};
			make_box(x,cells);}
	
	for(int y=0;y<2;++y)
		for(int i=40;i<41;++i){	
			int x[4]={i+z*224+y*127,i+1+z*224+y*127,i+15+z*224+y*127,i+16+z*224+y*127};
			make_box(x,cells);}
	
	for(int y=0;y<7;++y)
		for(int i=55;i<56;++i){	
		int x[4]={i+z*224+y*16,i+1+z*224+y*16,i+16+z*224+y*16,i+17+z*224+y*16};
		make_box(x,cells);}
	}
}




//this is the point build for slice chart, not complet yet, builds a horizontal slice
void Rxbuild::point_slice_build(vtkSmartPointer<vtkPoints>& points,vector<vtkSmartPointer<vtkFloatArray> >& Farray,vtkSmartPointer<vtkCellArray>&cells,vtkSmartPointer<vtkPolyData> polydb){
	for(int i=0;i<1;++i){
		 if(i!=0){i+=3;}
		for(int j=4;j<11;++j){	
			points->InsertNextPoint(j, 0, i);	
		}
		for(int k=2;k<13;++k){
			points->InsertNextPoint(k, 1, i);
			}			
		for(int m=2;m<4;++m)						
			for(int l=1;l<14;++l){
				points->InsertNextPoint(l, m, i);
				}
		for(int n=4;n<11;++n)
			for(int p=0;p<15;++p){//16
				points->InsertNextPoint(p, n, i);
				}
		for(int q=11;q<13;++q)	
			for(int r=1;r<14;++r){//nt r=1;r<15;++r
				points->InsertNextPoint(r, q, i);
				}
		for(int s=2;s<13;++s){//int s=2;s<14;++s
			points->InsertNextPoint(s, 13, i);
			}
		for(int t=4;t<11;++t){//int t=4;t<12;++t
			points->InsertNextPoint(t, 14, i);
			}
		}
}


//input data into array for points for slice_chart, still constructing and testing
void Rxbuild::get_tuples_for_slice(vector<vtkSmartPointer<vtkFloatArray> >& Farray,int slice_sel){
	string f="FlowRate";
	vector<vector<double> > tran;
	tran.reserve(663);
	get_data(f,tran);
	for(int j=0;j<663;++j){
		vtkSmartPointer<vtkFloatArray> t=
					vtkSmartPointer<vtkFloatArray>::New();
		//t->Allocate(3136);
		t->SetNumberOfComponents(3);
	for(int z=slice_sel;z<(slice_sel+1);++z){
		for(int i=0;i<193;++i)
			t->InsertNextTuple3(0,0,tran[j][i+z*193]);
	}	
	Farray.push_back(t);
	
	}
}
