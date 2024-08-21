// Bit Manuplation

// 1 & 1 = 1
// 1 | 0 = 1 , 0 | 0 = 0
// !(x) = 0 if x is not zero -> 1 to 0 and 0 to 1
// negation (~) flips each bits of a number
// 2s complement = -x or ~x+1
// x >> y === x is divided by 2 y times  right shift
// x << y === multiplied by 2  left shift
// xor ^  1^0 == 0^1 == 1 , 1^1 == 0^0 == 0

// Ques
// 1 byte number (char)  1101 0101 => 0101 1101

// 1101 0101
// &
// x = 0000 1111   ~(-1 << 4)
// a = 0000 0101

// x << 4 == 11110000 & 11010101 = 11010000 (b)
// b >> 4 & a << 4

// #include <stdio.h>
// int swap(int n)
// {
//     int pad = ~(-1 << 4);
//     int a = n & pad;
//     int b = n & (pad << 4);
//     return ((a << 4) | (b >> 4));
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int ans = swap(n);
//     printf("%d\n", ans);
// }

// given a positive number integer, tell me if it a power of 2.
#include <stdio.h>
#include <stdbool.h>
bool powerOf2(int n)
{
    return (n & -n) == n;
}
int main()
{
    int n;
    scanf("%d", &n);

    bool ans1 = n & (n - 1);
    printf("%d\n", ans1);
    if (ans1 == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    bool ans = powerOf2(n);
    if (ans)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}

// int sign(int n){
//     return (n >> 31) | (!(!n)) ;  if return 1 means negative otherwise positive
// }

// now we have to differentiate only 0 and postive number

// int invert(int x, int n, int p)
// {
// }

// base 64 implementataion

// ek magician h hall me baithe h hm magician ke 52 cards h playing vale
// voh ek card audience se nikal vata h
// aur audience ko dikhata h
// fir 4 cards nikalata h
// aur uska ek dost magician baar baitha hota h

// there are 10 priosiner in a jail unhe raaat me ek box dikhaya ga
// unpe infinite no of black and white hall h



// 31 July 2024


// 14 August 2024
// float Binary Represnetation

// ques 

// revision pcb and os how works ?
