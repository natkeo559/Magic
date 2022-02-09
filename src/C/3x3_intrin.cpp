#include <iostream>
#include <algorithm>
#include <vector>
#include <immintrin.h>


void print(const std::vector<unsigned short int>& v)
{
    for (int e : v) {
        std::cout << " " << e;
    }
    std::cout << std::endl;
}


bool check(const std::vector<unsigned short int>& v){

    __m128i t1 = _mm_set_epi16(v[0],v[0],v[0],v[1],v[2],v[2],v[3],v[6]);
    __m128i t2 = _mm_set_epi16(v[1],v[3],v[4],v[4],v[5],v[4],v[4],v[7]);
    __m128i t3 = _mm_set_epi16(v[2],v[6],v[8],v[7],v[8],v[6],v[5],v[8]);
    __m128i r2 = _mm_set_epi16(15, 15, 15, 15, 15, 15, 15, 15);
    
    __m128i r1 = _mm_add_epi16(t1,t2);
    r1 = _mm_add_epi16(r1,t3);
    
    if(_mm_test_all_ones(_mm_cmpeq_epi8(r1,r2))) {
        return 1;
    }
    else{
        return 0;
    }
}



int main(){
    std::vector<unsigned short int> v = {1,2,3,4,5,6,7,8,9};
    // vector should be sorted at the beginning.
    int x = 0;
    while (std::next_permutation(v.begin(), v.end())){
        if(check(v)){
            print(v);
        }
    }

    return 0;
}