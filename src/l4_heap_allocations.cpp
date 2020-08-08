#include <stdlib.h>
#include <iostream>

int main(){

    // Allocation size of 2 ints on heap   
    int *p = (int*)malloc(2*sizeof(int));
    p[0] = 1; 
    p[1] = 2;

    // Reallocate memory to 4 ints
    p = (int*)realloc(p,4*sizeof(int));
    p[2] = 3;
    p[3] = 4;

    std::cout << "Address: " << p+0 << " Value: " << *p+0 << std::endl;
    std::cout << "Address: " << p+1 << " Value: " << *p+1 << std::endl;
    std::cout << "Address: " << p+2 << " Value: " << *p+2 << std::endl;
    std::cout << "Address: " << p+3 << " Value: " << *p+3 << std::endl;

    free(p);

}