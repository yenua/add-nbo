#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    uint32_t num1, num2, total;
    
    if (argc != 3)
    {
        printf("Usage: add-nbo <file1> <file2>\n");
        return 1;
    }
    
    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");
    
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("File not found.\n");
        return 1;
    }
    
    fread(&num1, sizeof(num1), 1, fp1);
    fread(&num2, sizeof(num2), 1, fp2);
    
    num1 = ntohl(num1);
    num2 = ntohl(num2);
    
    total = num1 + num2;
    
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, total, total);
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
