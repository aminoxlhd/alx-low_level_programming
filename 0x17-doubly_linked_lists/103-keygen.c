#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f1(int arg1)
{
    return ((arg1 ^ 0x3b) & 0x3f);
}


int f2(char* arg1, int arg2)
{
    int var_10 = 0;
    for (int i = 0; i < arg2; i = (i + 1))
    {
        var_10 = (var_10 + *(arg1 + i));
    }
    return ((var_10 ^ 0x4f) & 0x3f);
}

int f3(char* arg1, int arg2)
{
    int var_10 = 1;
    for (int i = 0; i < arg2; i = (i + 1))
    {
        var_10 = (*(arg1 + i) * var_10);
    }
    return ((var_10 ^ 0x55) & 0x3f);
}

int f4(char* arg1, int arg2)
{
    int var_10 = *arg1;
    for (int i = 0; i < arg2; i = (i + 1))
    {
        if (arg1[i] > var_10)
        {
            var_10 = arg1[i];
        }
    }
    srand((var_10 ^ 0xe));
    return (rand() & 0x3f);
}

int f5(char* arg1, int arg2)
{
    int var_10 = 0;
    for (int i = 0; i < arg2; i = (i + 1))
    {
        var_10 = (var_10 + (*(arg1 + i) * *(arg1 + i)));
    }
    int rax_12;
    rax_12 = (var_10 ^ 0xef);
    return (rax_12 & 0x3f);
}

int f6(char arg1)
{
    int var_10 = 0;
    for (int i = 0; arg1 > i; i = (i + 1))
    {
        var_10 = rand();
    }
    int rax_3;
    rax_3 = (var_10 ^ 0xe5);
    return (rax_3 & 0x3f);
}


int main(int argc, char** argv, char** envp)
{
	char *key = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char* rax_2 = argv[1];
	char* rax_4 = argv[2];
	char code[6];
	int rax_8 = strlen(rax_2);
	int rax_10 = f1(rax_8);

	code[0] = key[rax_10];
	int rax_16 = f2(rax_2, rax_8);
	code[1] = key[rax_16];
	int rax_23 = f3(rax_2, rax_8);
	code[2] = key[rax_23];
	int rax_30 = f4(rax_2, rax_8);
	code[3] = key[rax_30];
	int rax_37 = f5(rax_2, rax_8);
	code[4] = key[rax_37];
	int rax_46 = f6(*rax_2);
	code[5] = key[rax_46];
	printf("%s", code);
}
