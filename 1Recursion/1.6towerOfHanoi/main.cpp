#include <iostream>

// Tower of Hanoi
// In this problem we have to move n rings such that the smaller ring is on top
// and largest on bottom, from pillar 'A' to 'C' using a auxillary/ helping
// pillar B, also no larger ring should be on a smaller ring

void TOH(int n, int A, int B, int C){
    // here n belongs to number of pillars
    // and A, B, C are the pillars
    if(n==1){
        std::cout << A << " to " << C << "using B" << std::endl;
    }
}

int main()	{
    
    return 0;
}