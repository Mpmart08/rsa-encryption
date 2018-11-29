// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

int main()
{
    // Instantiate the one and only RSA_Algorithm object
    RSA_Algorithm RSA;
    
    // Loop from sz = 32 to 1024 inclusive
    // for each size choose 10 different key pairs
    // For each key pair choose 10 differnt plaintext 
    // messages making sure it is smaller than n.
    // If not smaller then n then choose another
    // For eacm message encrypt it using the public key (n,e).
    // After encryption, decrypt the ciphertext using the private
    // key (n,d) and verify it matches the original message.

    // your code here

    mpz_class M, C;

    // sizes 32 to 1024
    for (unsigned sz = 32; sz <= 1024; sz <<= 1) {
        // 100 key pairs
        for (unsigned i = 0; i < 10; ++i) {
            RSA.GenerateRandomKeyPair(sz);
            RSA.PrintNDE();
            // 100 messages
            for (unsigned j = 0; j < 10; ++j) {
                M = RSA.rng.get_z_bits(32);
                RSA.PrintM(M);
                C = RSA.Encrypt(M);
                RSA.PrintC(C);
                M = RSA.Decrypt(C);
            }
        }
    }
}
    
