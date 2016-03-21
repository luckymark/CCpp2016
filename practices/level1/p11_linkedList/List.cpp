#include<cstdio>
#include<cstdlib>
#include<stack>
struct List {
    int value = 0, num = 0;
    List *next = NULL;

    void add(int value) {
        List *now = this;
        while (now->next != NULL) {
            now = now->next;
        }
        List *myNext = (List *) malloc(sizeof(List));
        myNext->next = NULL;
        myNext->num = now->num + 1;
        myNext->value = value;
        now->next = myNext;
    }

    void detele() {
        if (this->next == NULL) {
            printf("Error!\n");
            return;
        }
        List *now = this;
        while (now->next != NULL) {
            now = now->next;
        }
        free(now);
        List *pre = this;
        while (pre->next != now) {
            pre = pre->next;
        }
        pre->next = NULL;
        now = NULL;
    }

    void view() {
        List *now = this->next;
        while (now != NULL) {
            printf("%d ", now->value);
            now = now->next;
        }
        printf("\n");
    }

    int find(int number) {
        List *now = this->next;
        while (now != NULL) {
            if (now->value == number) {
                return now->num;
            }
            now = now->next;
        }
        return -1;
    }

    int nextFind(int prePosition, int number) {
        List *now = this->next;
        while (now != NULL && now->num <= prePosition) {
            now = now->next;
        }
        while (now != NULL) {
            if (now->value == number) {
                return now->num;
            }
            now = now->next;
        }
        return -1;
    }

    List *reverse() {
        List *now = this->next;
        std::stack<int> stack1;
        while (now != NULL) {
            stack1.push(now->value);
            now = now->next;
        }
        List *newList = (List *) malloc(sizeof(List));
        newList->next = NULL;
        newList->value = 0;
        newList->num = 0;
        while (!stack1.empty()) {
            detele();
            newList->add(stack1.top());
            stack1.pop();
        }
        free(this);
        return newList;
    }
};
int main() {
    List *myList = (List *) malloc(sizeof(List));
    myList->value = 0;
    myList->num = 0;
    myList->next = NULL;
    free(myList);
    myList = NULL;
    return 0;
}
