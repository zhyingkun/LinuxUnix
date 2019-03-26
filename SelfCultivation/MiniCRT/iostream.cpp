// iostream.cpp
#include "minicrt.h"
#include "iostream.h"

#ifdef WIN32
#include <Windows.h>
#endif

namespace std {
	stdout_stream::stdout_stream() : ofstream(){
		fp = stdout;
	}
	stdout_stream cout;
	ofstream::ofstream():fp(0){}
	ofstream::ofstream(const char* filename, ofstream::openmode md):fp(0){
		open(filename, md);
	}
	ofstream::~ofstream(){
		close();
	}
	ofstream& ofstream::operator<<(char c){
		fputc(fp, c);
		return *this;
	}
	ofstream& ofstream::operator<<(int n){
		fprintf(fp, "%d", n);
		return *this;
	}
	ofstream& ofstream::operator<<(const char* str){
		fprintf(fp, "%s", str);
		return *this;
	}
	ofstream& ofstream::operator<<(ofstream& (*manip)(ofstream&)){
		return manip(*this);
	}

	void ofstream::open(const char* filename, ofstream::openmode md){
		char mode[4];
		close();
		switch(md){
		case out | trunc:
			strcpy(mode, "w");
			break;
		case out | in | trunc:
			strcpy(mode, "w+");
			break;
		case out | trunc | binary:
			strcpy(mode, "wb");
			break;
		case out | in | trunc | binary:
			strcpy(mode, "wb+");
			break;		
		}
		fp = fopen(filename, mode);
	}
	void ofstream::close(){
		if (fp != NULL){
			fclose(fp);
			fp = NULL;
		}
	}
	ofstream& ofstream::write(const char* buf, unsigned size){
		fwrite(fp, buf, 1, size);
		return *this;
	}
}
