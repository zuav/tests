#include <string.h>
#include <iostream>
#include <iomanip>
#include <openssl/blowfish.h>

#define MAX_LEN    255
#define BUF_SIZE   256
#define BLOCK_SIZE 8        // in bytes

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: blowfish string" << std::endl;
        return 1;
    }

    int len = strlen(argv[1]);
    if (len > MAX_LEN) {
        std::cout << "Maximum argument length is 255" << std::endl;
        return 1;
    }

    unsigned char keydata[] = "needs to know what it was initialized with";
    int keydatalen = 16;
    BF_KEY key;
    BF_set_key(&key, keydatalen, keydata);

    unsigned char buf[BUF_SIZE];
    memset(buf, 0, len+1);
    int num1 = 0;
    unsigned char ivec1[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    BF_cfb64_encrypt((unsigned char *)argv[1], buf, len, &key, ivec1, &num1, BF_ENCRYPT);

    unsigned char enc[BUF_SIZE];
    memset(enc, 0, len+1);
    int num2 = 0;
    unsigned char ivec2[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    BF_cfb64_encrypt(buf, enc, len, &key, ivec2, &num2, BF_DECRYPT);


    std::cout << "Original:         " << argv[1] << std::endl
              << "Crypted (in hex): ";
    for (int i=0; i<len; ++i)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << unsigned(buf[i]);
    std::cout << std::endl
              << "Decrypted:        " << enc << std::endl
              << "Comparison:       " << (strcmp(argv[1], (char *)enc) == 0 ? "OK" : "FAILED") << std::endl;

    return 0;
}
