#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BinaryConversion(char ch, int *arr, int *p);
void EncodedDataFunc(int *arr, int bitCount, char *encodedData);
void DecodedDataFunc(char *encodedData);

int main()
{
    printf("Enter Data for encoding $ ");
    char inputData[1000];
    fgets(inputData, sizeof(inputData), stdin);

    int len = strlen(inputData);
    if (len > 0 && inputData[len - 1] == '\n')
        inputData[len - 1] = '\0';

    printf("Data $ %s\n", inputData);

    int arr[len * 8];
    int p = 0;

    for (int i = 0; inputData[i] != '\0'; i++)
    {
        BinaryConversion(inputData[i], arr, &p);
    }

    int paddedLength = ((p + 5) / 6) * 6;
    while (p < paddedLength)
    {
        arr[p++] = 0;
    }

    char encodedData[paddedLength / 6 + 1];
    EncodedDataFunc(arr, p, encodedData);

    printf("Encoded Data: %s\n", encodedData);

    printf("Decoding...\n");
    DecodedDataFunc(encodedData);

    return 0;
}

void EncodedDataFunc(int *arr, int bitCount, char *encodedData)
{
    const char encodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int index = 0;

    for (int i = 0; i < bitCount; i += 6)
    {
        int decimalValue = 0;
        for (int j = 0; j < 6; j++)
        {
            decimalValue = (decimalValue << 1) | arr[i + j];
        }
        encodedData[index++] = encodingTable[decimalValue];
    }

    encodedData[index] = '\0';
}

void DecodedDataFunc(char *encodedData)
{
    const char encodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int size = 0;
    int i = 0;
    while (encodedData[i] != '\0')
    {
        size++;
        i++;
    }

    int decodarr[size * 8];
    int p = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= 65; j++)
        {
            if (encodingTable[j] == encodedData[i])
            {
                BinaryConversion(j, decodarr, &p);
                break;
            }
        }
    }

    for (int i = 0; i < (size * 8); i++)
    {
        printf("%d", decodarr[i]);
    }
    printf("\n");
}

void BinaryConversion(char ch, int *arr, int *p)
{
    int asciiValue = ch;
    for (int i = 7; i >= 0; i--)
    {
        int k = asciiValue >> i;
        if (k & 1)
            arr[*p] = 1;
        else
            arr[*p] = 0;

        (*p)++;
    }
}

// 31 July 2024
