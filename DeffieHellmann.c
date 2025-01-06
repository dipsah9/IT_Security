#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//function to calculate modular exponentiation
//comput (base ^exp) % mod
long long mod_exp(long long base, long long exp, long long  mod){
     long long result = 1;
     base = base % mod;

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1)
            result = (result * base) % mod;

        // exp must be even now
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;
    }

    return result;
}
int main(){

    //lets say bob and alice want to share some message. lets take p  = 15 and g = 9
    long long p = 23;
    long long g = 5;

    //publicly agreed values
    printf("Both parties agreed on the values p: %lld and g: %lld\n", p , g);
    printf("Prime number: %lld\n", p);
    printf("Private root: %lld\n\n", g);

    //lets give them both the private key
    long long alice_private_key = 10;
    long long bob_private_key  = 15;
    printf("Alice private key is: %lld\n",alice_private_key);
    printf("Bob private key is: %lld\n\n", bob_private_key);

    //lets calculate public key for both 
    long long alice_public_key = mod_exp(g,alice_private_key,p);
    long long bob_public_key = mod_exp(g, bob_private_key, p);

    printf("Alice public key is: %lld\n", alice_public_key);
    printf("Bob public key is: %lld \n",  bob_public_key);

    //lets calculate shared secret
    long long shared_secret_alice = mod_exp(bob_public_key,alice_private_key,p);
    long long shared_secret_bob = mod_exp(alice_public_key, bob_private_key, p);

    printf("The shared secret key for alice: %lld\n", shared_secret_alice);
    printf("The shared secret key for bob: %lld\n\n\n\n", shared_secret_bob);

    //verify shared_secret, if its match
    printf("Verification::\n");
    if(shared_secret_alice == shared_secret_bob){
        printf("The key exchange is sucessful and the shared secret key is: %lld\n", shared_secret_alice);
    }else{
        printf("The key exchange is not successfull\n");
    }

    return 0;

}