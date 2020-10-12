#include <iostream>

//Factorial Function
int fact(int n){
    if(n<=1) return n;
    return fact(n-1)*n;
}

//Combination Function
int combination(int n, int r){
    if(n<r) return 0;

    int t1,t2,t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/t2*t3; // nCr = n!/ r! * (n-r)! 
}

int main()	{
    std::cout << fact(5) << std::endl;
    std::cout << combination(10,5) << std::endl;
    return 0;
}