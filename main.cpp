#include <iostream>
#include "simpleVector.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	cout<<"constructor : "<<endl;
	SimpleVector<float> flt_vec(7);
	flt_vec.printVec();
	cout<<endl;
	
	float input_1 = 3.8;
	flt_vec.push_back(&input_1);
	float input_2 = 1.5;
	flt_vec.push_back(&input_2);
	float input_3 = 0.2;
	flt_vec.push_back(&input_3);
	float input_4 = 9.6;
	flt_vec.push_back(&input_4);
	float input_5 = 7.4;
	flt_vec.push_back(&input_5);
	cout<<"push_back : "<<endl;
	flt_vec.printVec();
	cout<<endl;
	
	cout<<"pop_back : "<<endl;
	flt_vec.pop_back();
	flt_vec.printVec();
	cout<<endl;
	
	cout<<"size : "<<flt_vec.size()<<endl;
	cout<<"capacity : "<<flt_vec.capacity()<<endl;
	cout<<endl;
	
	cout<<"resize : "<<endl;
	flt_vec.resize(14);
	flt_vec.printVec();
	cout<<endl;

	cout<<"sort : "<<endl;
	flt_vec.sortData();
	flt_vec.printVec();
	cout<<endl;
	
	cout<<"copy : "<<endl;
	SimpleVector<float> cpy_vec=flt_vec;
	cpy_vec.printVec();
	return 0;
}
