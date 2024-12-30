#include <iostream>
#include "simpleVector.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	SimpleVector<float> flt_vec(7);
	flt_vec.push_back(0.2);
	flt_vec.push_back(1.5);
	flt_vec.push_back(3.8);
	flt_vec.push_back(9.6);
	flt_vec.push_back(7.4);
//	flt_vec.printVec();
	
//	flt_vec.push_back(4.7);
//	flt_vec.push_back(5.1);
//	flt_vec.push_back(8.3);
//	flt_vec.push_back(6.2);
	flt_vec.printVec();
	
	flt_vec.pop_back();
	flt_vec.printVec();
	
	cout<<"size : "<<flt_vec.size()<<endl;
	cout<<"capacity : "<<flt_vec.capacity()<<endl;
	flt_vec.resize(14);
	flt_vec.printVec();
	cout<<"capacity : "<<flt_vec.capacity()<<endl;
	
	flt_vec.sortData();
	flt_vec.printVec();
	return 0;
}
