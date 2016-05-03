class Safearray {
public:
    safearray(int num) {
        data = new int[num];
    }
    ~safearray() {
	delete[]data;
    }
    void putin(int item);
    bool safe(int item);
private:
    int *data;
    int i = 0;
};
