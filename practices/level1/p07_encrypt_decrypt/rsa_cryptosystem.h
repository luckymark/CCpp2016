#ifndef rsa_crytosystem_h__
#define rsa_crytosystem_h__

void generate_keys(long long int public_key[], long long int private_key[]);

int rsa_encrypt(long long int public_key[], int m);

int rsa_decode(long long int private_key[], int c);

int rsa_string_encrypt(char *m, int *c, long long int public_key[]);

int rsa_string_decode(int *c, char *m, long long int private_key[]);

#endif
