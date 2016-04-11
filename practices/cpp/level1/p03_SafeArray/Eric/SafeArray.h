#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H
class SafeArray
{
    public:
    SafeArray() = default;
    SafeArray(int arrayLengthSource)
    {
        arrayMaxIndex = arrayLengthSource;
        array = new int[arrayLengthSource];
    }
	int &operator[](int index)
	{
		if(isSafe(index))
		{
			return array[index];
		}
		else
		{
			std::cerr << "FLOW!!!" << std::endl;
			return flowReturn;
		}
	}
    private:
    bool isSafe(int index);
    int arrayMaxIndex;
	int arrayLessIndex = -1;
    int *array;
	int flowReturn;
};
#endif