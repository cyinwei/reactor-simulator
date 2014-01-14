#include "convert.h"
#include "error_box.h"
#include <qapplication.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

convert::convert(const bool &is_flofile,string &ofname){
	vector<string> time_values;
	vector<vector<string>>ts;//each vector is the values at a certain time step, number of vectors=number of time steps
	string fname_1="0";//file name
	string fname_2="0";
	int i=0;//iterator for later use needed to declare outside for loop because flow starts at i=0 and temp at i=1
	if(is_flofile){
		fname_1="mfr-3D-";//flow file name
		fname_2="mfr-3D-00";
	}
		else{//its a temperature file
			fname_1="tempf-3D-core-";
			fname_2="tempf-3D-core-00";
			i=1;
		}
		ifstream datas(fname_2.c_str());//open file and check to see if open 
		if (!datas){runtime_error("can't open file");}
		vector_handler(datas,time_values,ts);// collect data for vectors
		datas.close();

		for(;i<12;++i){// fill in vectors for remainder of files
			if(i<10)fname_2=fname_1+"0"+doub_to_str(i);//iterate through files
				else fname_2=fname_1+doub_to_str(i);

		datas.open(fname_2.c_str());
		if (!datas){ runtime_error("can't open file");}
		vector_handler2(datas,ts);// fill in vectors for remainder of values in all files
		datas.close();}
	vector<int>location=entry();// map location of cells in simulation to actual cell numbers
	write_to_file(location,ts,time_values,ofname);// write to file
}

//----------------------------------------------------------------------------------------------------------------------
string convert:: doub_to_str(double a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}
//----------------------------------------------------------------------------------------------------------------------
vector<string>convert:: start(ifstream& sfile, vector<string>& Time_val,bool& start_chk){//find startng point
	vector<string> data;
	int line_no=0;
	string tempstr="";
	string tempstr2="";
	string dtemp="0";
	stringstream tss;
	string line="";
	if(start_chk){
		while(getline(sfile,line)){
			if(line_no==53){
				tss<<line;
				tss>>tempstr;
				if(tempstr!="plotrec") runtime_error("Initial line condition not met, check format");//format1
				break;
			}
			++line_no;
		}
		start_chk=false;
	}
	else{
		getline(sfile,line);
		tss<<line;
		tss>>tempstr;
		if(sfile.eof())throw string("get_out");
		if(tempstr!="plotrec")runtime_error("Initial line condition not met, check format");
	}
	tss>>tempstr2;	
	Time_val.push_back(tempstr2);	
	while(tss>>dtemp){
			data.push_back(dtemp);
	}	
		return data;//return starting vector
}
//----------------------------------------------------------------------------------------------------------------------
vector<string>convert:: values(ifstream &file,vector<string>& times,bool& s_chk){//fill vector with values
	string val_line="0";
	vector<string>temp=start(file,times,s_chk);//find start point and make first line vector
	while(temp.size()!=193){//loop until all values filled
		string val_val="";//temporary stores stringstream indvidual strings until read into vector
		getline(file,val_line);
		stringstream vss(val_line);
		while(vss>>val_val){//read stringstream word into val_val
			temp.push_back(val_val);
		}
	}
	return temp;
}
//----------------------------------------------------------------------------------------------------------------------
void convert:: write_to_file(vector<int>& loc,vector<vector<string>>& ts,vector<string>time_values,string &outfname){
	ofstream appFile;//output stream to file
	appFile.open(outfname+".", ios::out | ios::app); //opens file for append, preventing overwriting
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
//----------------------------------------------------------------------------------------------------------------------
void convert:: vector_handler(ifstream &file,vector<string>& tv_temp,vector<vector<string>>& ts_temp){
	int argc;
	char **argv;
	bool start_chk=true;
	vector<vector<string>>temp3;
	int k=0;
	string tacos;
	while(true)try{ 
		vector<string>val1=values(file,tv_temp,start_chk);
		ts_temp.push_back(val1);
		
	}catch(string std){
	break;
	}
	catch(exception& e){
		QApplication *a=new QApplication(argc, argv);
		string temp=e.what();
		Error_box box(temp);
		box.show();
		a->exec();
	runtime_error("Initial line condition not met, check format");//format2
	}
}

void convert:: vector_handler2(ifstream &file,vector<vector<string>>& ts_temp){
	int argc;
	char **argv;
	bool start_chk=true;
	int i=0;
	vector<string>val;
	vector<string> temp2;//not used for the remaining files
	vector<vector<string>>temp3;
	//vector<string>temp1=values(file,temp2,start_chk);
		//loc1.insert(loc1.end(), temp1.begin(), temp1.end());
	while(true)try{
		vector<string>val1=values(file,temp2,start_chk);
		(ts_temp[i]).insert(ts_temp[i].end(), val1.begin(), val1.end());
		++i;
	}catch(string std){
		break;
	}
	catch(exception& e){
		QApplication *a=new QApplication(argc, argv);
		string temp=e.what();
		Error_box box(temp);
		box.show();
		a->exec();
	runtime_error("Initial line condition not met, check format");//format2
	}
}
//----------------------------------------------------------------------------------------------------------------------

vector<int>convert:: entry(){
	vector<int> a;
	for(int g=0;g<13;++g){
		for(int i=0;i<7;++i){
			a.push_back((60+i*15)+225*g);
		}
		for(int j=0;j<11;++j){
			a.push_back((31+j*15)+225*g);
		}
		for(int k=0;k<2;++k){
			for(int l=0;l<13;++l)
				a.push_back((17+k+l*15)+225*g);
		}
		for(int m=0;m<7;++m){
			for(int f=0;f<15;++f)
				a.push_back((4+m+f*15)+225*g);
		}
		for(int n=0;n<2;++n){
			for(int p=0;p<13;++p)
				a.push_back((26+n+p*15)+225*g);
		}
		for(int q=0;q<11;++q){
			a.push_back((43+q*15)+225*g);
		}
		for(int h=0;h<7;++h){
			a.push_back((74+h*15)+225*g);
		}
	}
	return a;
}
