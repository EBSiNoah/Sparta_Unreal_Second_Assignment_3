#include <algorithm>
#include <iostream>

using namespace std;

template <typename Element> class SimpleVector
{
	private:
		Element* s_vec;
		int cnt;
		int space;

	public:		
		SimpleVector()
		{
			s_vec = new Element[10];
			cnt=0;
			space = 10;
		}
		
		SimpleVector(int length)
		{
			s_vec = new Element[length];
			cnt=0;
			space = length;
		}
		
		SimpleVector(const SimpleVector& obj)
		{
			s_vec=obj.s_vec;
			cnt=obj.cnt;
			space=obj.space;
		}
		
		~SimpleVector()
		{
			delete[] s_vec;
			cnt=0;
			space = 0;
		}
		
		void push_back(Element val)
		{
			if(cnt<space)
			{
				s_vec[cnt]=val;
			}
			else
			{
				space+=5;
				Element* after = new Element[space];
				int idx=0;
				while(idx<cnt)
				{
					after[idx]=s_vec[idx];
					idx++;
				}
				delete[] s_vec;
				after[cnt]=val;
				idx=0;
				s_vec=new Element[space];
				while(idx<cnt+1)
				{
					s_vec[idx]=after[idx];
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
				cout<<"pop is work?"<<endl;
				Element* after = new Element[space];
				while(idx<cnt-1)
				{
					after[idx]=s_vec[idx];
					idx++;
				}
				delete[] s_vec;
				s_vec = new Element[space];
				idx=0;
				while(idx<cnt-1)
				{
					s_vec[idx]=after[idx];
					idx++;
				}
				delete[] after;
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
				cout<<"resize is work?"<<endl;
				space = newCapacity;
				Element* after = new Element[newCapacity];
				int idx=0;
				
				while(idx < cnt)
				{
					after[idx]=s_vec[idx];
					idx++;
				}
				delete[] s_vec;
				idx=0;
				s_vec = new Element[newCapacity];
				while(idx < cnt)
				{
					s_vec[idx]=after[idx];
					idx++;
				}
				delete[] after;
			}
		}
		
		void sortData()
		{
			sort(s_vec, s_vec+cnt);
		}
		
		void printVec()
		{
			int idx=0;
			while(idx<space)
			{
/*				if(idx<=cnt)
				{
					cout<<s_vec[idx]<<" | ";
				}
				else
				{
					cout<<"empty | ";
				}*/
				cout<<s_vec[idx]<<" | ";
				idx++;
			}
			cout<<endl;
		}
};
