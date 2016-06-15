#ifndef SAFEARRAY_H
#define SAFEARRAY_H

class SafeArray
{
	public:
		SafeArray(int capbility)
		{
			data=new int[capbility];
			cap=capbility;
		}
		~SafeArray()
		{
			delete [] data;
		}
		void in(int p,int num);
		int out(int p);
	private:
		int *data;
		int cap;
};

#endif
