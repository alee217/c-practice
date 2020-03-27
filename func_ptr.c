#include <stdio.h>

int negate(int n) {return -n;}
void blek() {printf("blek\n");}

void func(int (*op) (int n)) {
    printf("%d\n", (*op) (3));
}

void blekening(void (* op)()) {
    (*op)();
}

int main(int argc, char** argv) {
    func(negate);
    blekening(blek);
}