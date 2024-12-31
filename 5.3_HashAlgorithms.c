/*
To reduce the probability of hash collision, hash function should have the following properties:

*/
// Additive Hash --------------------------------------------------------------
int addHash(char* key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;// Big prime number
    for(int i = 0; i< strlen(key); i++)
    {
        hash = (hash + (unsigned char)key[i]) % MODULUS;
    }

    return (int)hash;
}

// multiplicative Hash --------------------------------------------------------
int mulHash(char* key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for(int i = 0; i< strlen(key); i++)
    {
        hash = (31 * hash + (unsigned char)key[i]) % MODULUS;
    }

    return (int)hash;
}
// XOR Hash -------------------------------------------------------------------

//  Decimal => Binary
//  0 ^ 0 = 0 (two bits are the same)
//  0 ^ 1 = 1 (two bits are different)
int xorHash(char* key)
{
    int hash = 0;
    const int MODULUS = 1000000007;

    for(int i = 0; i < strlen(key); i++)
    {
        hash ^ = (unsigned char)key[i];
    }

    return hash % MODULUS;
}

// Rotate Hash ----------------------------------------------------------------
int rotHash(char* key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;

    for(int i = 0; i < strlen(key); i++)
    {
        hash = (hash << 4) ^ (hash >> 28) ^ (unsigned char)key[i];
    }

    return (int)hash;
}


/// ------------------ T   E   S   T ------------------
void testHash()
{
    char* key;
    int choice;
    do{

        printf("Your choice and key: ");
        scanf("%d %s", &choice, key);

        switch (choice)
        {
        case 1:
            printf("Additive Hash: %d\n", addHash(key));
            break;
        case 2:
            printf("Multiplicative Hash: %d\n", mulHash(key));
            break;
        case 3:
            printf("XOR Hash: %d\n", xorHash(key));
            break;
        case 4:
            printf("Rotate Hash: %d\n", rotHash(key));
            break;
        case 5:
            printf("Exit\n");
            break;
        }
    } while (choice != 5);
}
    
int main()
{
    testHash();
    return 0;
}