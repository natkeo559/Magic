#include <algorithm>
#include <immintrin.h>
#include <iostream>
#include <vector>

void print(const std::vector<unsigned short int> &v){
    for (int i = 0; i <= 8; i++){
        if ((i + 1) % 3 == 0){
            std::cout << v[i] << std::endl;
        } else{
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}

bool check(const std::vector<unsigned short int> &v){

    __m128i t1 = _mm_set_epi16(v[0], v[0], v[0], v[1], v[2], v[2], v[3], v[6]);
    __m128i t2 = _mm_set_epi16(v[1], v[3], v[4], v[4], v[5], v[4], v[4], v[7]);
    __m128i t3 = _mm_set_epi16(v[2], v[6], v[8], v[7], v[8], v[6], v[5], v[8]);
    __m128i r2 = _mm_set_epi16(15, 15, 15, 15, 15, 15, 15, 15);

    __m128i r1 = _mm_add_epi16(t1, t2);
    r1 = _mm_add_epi16(r1, t3);

    if (_mm_test_all_ones(_mm_cmpeq_epi8(r1, r2))){
        return 1;
    } else{
        return 0;
    }
}

std::vector<unsigned short int> findPermutation(int n, int k){
    /*
    Based on:
    https://stackoverflow.com/questions/31216097/given-n-and-k-return-the-kth-permutation-sequence
    */

    int *numbers = new int[n];
    int *indices = new int[n];

    // initialise the numbers 1, 2, 3...
    for (int i = 0; i < n; i++)
        numbers[i] = i + 1;

    int divisor = 1;
    for (int place = 1; place <= n; place++){
        if((k / divisor) == 0)
            break;  // all the remaining indices will be zero

        // compute the index at that place:
        indices[n-place] = (k / divisor) % place;
        divisor *= place;
    }

    // permute the numbers array according to the indices:
    for (int i = 0; i < n; i++){
        int index = indices[i] + i;

        // take the element at index and place it at i, moving the rest up
        if(index != i){
            int temp = numbers[index];
            for(int j = index; j > i; j--)
               numbers[j] = numbers[j-1];
            numbers[i] = temp;
        }
    }
    std::vector<unsigned short int> r;
    // print out the permutation:
    for (int i=0; i<n;i++){
       r.push_back(numbers[i]);
    }
    return r;
}

int main(){
    std::vector<unsigned short int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int x = 0;
    int c = 163440;
    while (x!=c && std::next_permutation(v.begin(), v.end())){
        int i = 362880 - x++;
        if (check(v)){
            std::cout << x << ":" << std::endl;
            print(v);
            std::cout << i << ":" << std::endl;
            print(findPermutation(9, i-1));
        }
    }
    return 0;
}