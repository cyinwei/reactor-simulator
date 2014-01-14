#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip> 
using namespace std;
class convert{
public:
	convert(const bool &is_flofile,string &ofname);
private:
	string doub_to_str(double a);
	vector<string> start(ifstream& sfile, vector<string>& Time_val,bool& start_chk);
	vector<string>values(ifstream &file,vector<string>& times,bool& s_chk);
	void write_to_file(vector<int>& loc,vector<vector<string>>& ts,vector<string>time_values,string &outfname);
	void vector_handler(ifstream &file,vector<string>& tv_temp,vector<vector<string>>& ts_temp);
	void vector_handler2(ifstream &file,vector<vector<string>>& ts_temp);
	vector<int> entry();
	void if_temp();//handles naming convention for input files if temp
	void if_flow();//handles naming convention for input files if flow
};