#include <iostream>
#include <cassert>
using namespace std;
using ll = unsigned long long;
constexpr ll g = 123456789;
constexpr ll p = 7974611;

// cacluate __g^x (mod __p)
ll mod_pow(ll __g, ll x, ll __p){
    ll result = 1;
    __g = __g % p;
    while (x){
        if (x & 1){
            result = (result * __g) % __p;
        }
        __g = (__g * __g) % __p;
        x >>= 1;
    }
    return result;
}

void test(){
    assert(mod_pow(3, 1, 7) == 3);
    assert(mod_pow(3, 10, 7) == 4);
    assert(mod_pow(13, 11, 24) == 13);
    assert(mod_pow(8, 4, 9) == 1);
    assert(mod_pow(113, 120, 7) == 1);
    assert(mod_pow(8234, 1661, 144) == 80);
}

int main(){
    test();
    constexpr ll a = 456456;
    constexpr ll b = 123123;

    cout << "Alice Send : " << mod_pow(g, a, p) << endl;
    cout << "Bob Send : " << mod_pow(g, b, p) << endl;

    cout << "Hacker Stealed : " << mod_pow(g, a, p) << " from Alice" << endl;
    cout << "Hacker Stealed : " << mod_pow(g, b, p) << " from Bob" << endl;

    ll pass_from_bob = mod_pow(g, b, p);
    cout << "Alice trying to make key,,, \n" << "Result : " << mod_pow(pass_from_bob, a, p) << endl;

    ll pass_from_alice = mod_pow(g, a, p);
    cout << "Bob trying to make key,,, \n" << "Result : " << mod_pow(pass_from_alice, b, p) << endl;
}