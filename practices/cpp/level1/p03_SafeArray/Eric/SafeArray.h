#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H
class SafeArray
{
    public:
    SafeArray() = default;
    SafeArray(int arrayLengthSource)
    {
        arrayMaxLocation = arrayLengthSource;
        array = new int[arrayLengthSource];
    }
    int set(int number, int location);
    int get(int location);
    private:
    bool isSafe(int location);
    int arrayMaxLocation;
    int arrayLessLocation = -1;
    int *array;
};
#endif