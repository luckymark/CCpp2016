class SafeArray
{
    public:
        SafeArray(int capbility);
        ~SafeArray();
        void insert(int pos,int value);
        int get(int pos);
    private:
        int *data;
        int capbility;
};
