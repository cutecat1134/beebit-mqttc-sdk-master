/*
    Include glib.h, pbc.h, pbc_random.h 
 */
int setup(unsigned char* pk_path, unsigned char* mk_path);
/*  Function Name: setup
 *  
 *  Purpose:
 *  Generate system parameters, a public key, and a master key
 *  used in keygen, encrytion, decrption
 *
 *  Parameters:
 *  1. pk_path: the path of public key (Ex. ./cpabe_publickey)
 *  2. mk_path: the path of master key (Ex. ./cpabe_masterkey)
 *
 *  Return:
 *   0: success
 *  -1: fail
 */

int vkeygen(unsigned char* pk_path, unsigned char* mk_path, unsigned char* sk_path, int attr_no, char** argv);
/*  Function Name: vkeygen
 *  
 *  Purpose:
 *  Generate a secret key with the given attributes with public key and master key
 *  About the key attributes, please refer the following link 
 *  http://acsc.cs.utexas.edu/cpabe/cpabe-keygen.html
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. mk_path: the path of master key 
 *  3. pk_path: the path of secret key
 *  4. attr_no: the number of attributes
 *  5. argv: a serial of attributes in two forms, non-numerical and numerical, specified by string.
 *  (Ex. "boy", "student" for non-numerical attributes and "salary = 1000", "age >= 18" for numerical attributes)
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int keygen(unsigned char* pk_path, unsigned char* mk_path, unsigned char* sk_path, int attr_no, ...);
/*  Function Name: keygen
 *  
 *  Purpose:
 *  Generate a secret key with the given attributes with public key and master key
 *  About the key attributes, please refer the following link 
 *  http://acsc.cs.utexas.edu/cpabe/cpabe-keygen.html
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. mk_path: the path of master key 
 *  3. pk_path: the path of secret key
 *  4. attr_no: the number of attributes
 *  5. ...: a serial of attributes in two forms, non-numerical and numerical, specified by string.
 *  (Ex. "boy", "student" for non-numerical attributes and "salary = 1000", "age >= 18" for numerical attributes)
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int enc(unsigned char* pk_path, unsigned char* pt, unsigned char* policy_str, unsigned char** ct);
/*  Function Name: enc
 *  
 *  Purpose:
 *  Encrypt non-file plaintext into non-file ciphertext with public key and policy using CPABE.  
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. pt: the plaintext
 *  3. policy_str: the access policy (Please refer http://acsc.cs.utexas.edu/cpabe/cpabe-enc.html)
 *  (Ex. "boy and salary > 1000")
 *  4. ct: the ciphertext
 *
 *  Return:
 *   n: the length of ciphertext 
 *  -1: failed
 */

int fenc(unsigned char* pk_path, unsigned char* pt_path, unsigned char* policy_str, unsigned char* ct_path);
/*  Function Name: fenc
 *  
 *  Purpose:
 *  Encrypt file-based plaintext into file-based ciphertext with public key and policy using CPABE.  
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. pt_path: the path of plaintext
 *  3. policy_str: the access policy (Please refer http://acsc.cs.utexas.edu/cpabe/cpabe-enc.html)
 *  (Ex. "boy and salary > 1000")
 *  4. ct_path: the path of ciphertext
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int dec(unsigned char* pk_path, unsigned char* sk_path, unsigned char* ct, unsigned char** pt);
/*  Function Name: dec
 *  
 *  Purpose:
 *  Decrypt non-file ciphertext into non-file plaintext with public key and secret key using CPABE.  
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. sk_path: the path of secret key
 *  3. ct: the ciphertext
 *  4. pt: the plaintext
 *
 *  Return:
 *   n: the length of plaintext
 *  -1: failed
 */

int fdec(unsigned char* pk_path, unsigned char* sk_path, unsigned char* ct_path);
/*  Function Name: fdec
 *  
 *  Purpose:
 *  Decrypt file-based ciphertext into file-based plaintext with public key and secret key using CPABE.  
 *
 *  Parameters:
 *  1. pk_path: the path of public key
 *  2. sk_path: the path of secret key
 *  3. ct_path: the path of ciphertext
 *
 *  Return:
 *   0: success
 *  -1: failed
 */
