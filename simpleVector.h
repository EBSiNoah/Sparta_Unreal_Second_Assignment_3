#include <algorithm>
#include <iostream>

using namespace std;

template <typename Element> class SimpleVector
{
	private:
		Element** s_vec;
		int cnt;
		int space;

	public:		
		SimpleVector(int input_idx = 10)
		{
			space=input_idx;
			s_vec = new Element*[space];
			cnt=0;
			int idx=0;
			while(idx<space)
			{
				s_vec[idx]=nullptr;
				idx++;
			}
		}
		
		SimpleVector(const SimpleVector& obj)
		{
			cnt=obj.cnt;
			space=obj.space;
			s_vec = new Element*[space];
			int idx=0;
			while(idx<space)
			{
				s_vec[idx]=obj.s_vec[idx];
				idx++;
			}
		}
		
		SimpleVector& operator=(const SimpleVector& obj)
		{
			if(this != &obj)
			{
				delete[] s_vec;
				
				space = obj.space;
				cnt = obj.cnt;
				s_vec = new Element*[space];
				int idx=0;
				while(idx<space)
				{
					s_vec[idx]=obj.s_vec[idx];
					idx++;
				}
			}
			return *this;
		}
		
		~SimpleVector()
		{
			delete[] s_vec;
			cnt=0;
			space = 0;
			cout<<"destructor"<<endl;
		}
		
		void push_back(Element* val)
		{
			if(cnt<space)
			{
				s_vec[cnt]=val;
			}
			else
			{
				space+=5;
				Element** after = new Element*[space];
				int idx=0;
				while(idx<space)
				{
					if(idx<cnt)
					{
						after[idx]=s_vec[idx];
					}
					else
					{
						after[idx]=nullptr;
					}
					idx++;
				}
				delete[] s_vec;
				after[cnt]=val;
				idx=0;
				s_vec=new Element*[space];
				while(idx<space)
				{
					if(idx<cnt+1)
					{
						s_vec[idx]=after[idx];
					}
					else
					{
						s_vec[idx]=nullptr;
					}
					idx++;
				}
				delete[] after;
			}
			cnt++;
		}
		
		void pop_back()
		{
			int idx=0;
			if(cnt>0)
			{
				s_vec[cnt-1]=nullptr;
				cnt--;
			}
		}
		
		int size()
		{
			return cnt;
		}
		
		int capacity()
		{
			return space;
		}
		
		void resize(int newCapacity)
		{
			if(newCapacity > space)
			{
				space = newCapacity;
				Element** after = new Element*[newCapacity];
				int idx=0;
				
				while(idx < space)
				{
					if(idx<cnt)
					{
						after[idx]=s_vec[idx];
					}
					else
					{
						after[idx]=nullptr;
					}
					idx++;
				}
				delete[] s_vec;
				idx=0;
				s_vec = new Element*[newCapacity];
				while(idx < space)
				{
					if(idx<cnt)
					{
						s_vec[idx]=after[idx];
					}
					else
					{
						s_vec[idx]=nullptr;
					}
					idx++;
				}
				delete[] after;
			}
		}
		
		void sortData()
		{
			sort(s_vec, s_vec+cnt, [](Element* a, Element* b)
			{
				if (a == nullptr && b == nullptr) return false;
            	if (a == nullptr) return false;
            	if (b == nullptr) return true; 
            	return *a < *b;
			});
		}
		
		void printVec()
		{
			int idx=0;
			while(idx<space)
			{
				if(idx<cnt)
				{
					cout<<*s_vec[idx]<<" | ";
				}
				else
				{
					cout<<"empty | ";
				}
//				cout<<s_vec[idx]<<" | ";
				idx++;
			}
			cout<<endl;
		}
};
