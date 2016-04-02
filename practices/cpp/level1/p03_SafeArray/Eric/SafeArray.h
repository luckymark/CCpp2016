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
    int set(int number, int index);
    int get(int index);
    private:
    bool isSafe(int index);
    int arrayMaxIndex;
    int arrayLessIndex = -1;
    int *array;
};
#endif