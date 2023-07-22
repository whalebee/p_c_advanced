#include <stdio.h>

int main() {
    

        int first_int = 4892; // number larger than 127 (max. value of char)
        int second_int = 99584; // same

        // char array to hold two integers:
        char array[8]; // ...assuming an integer size of 4 and char size of 1

        // Now, assuming you are on a little endian system (in which the least
        // significant bytes come first), you can add the two above integers to the
        // array like so:

        array[0] = first_int; // assigns first_int's least significant byte
        array[1] = first_int >> 8; // assigns first_int's 2nd least significant byte
        array[2] = first_int >> 16; // assigns first_int's 2nd most significant byte
        array[3] = first_int >> 24; // assigns first_int's most significant byte

        // repeat for second_int:

        array[4] = second_int;
        array[5] = second_int >> 8;
        array[6] = second_int >> 16;
        array[7] = second_int >> 24;

        // You can now prove that this char array holds the two integers like this:

        printf("First integer: %d\n", *((int*)array));
        printf("Second integer: %d\n", *((int*)(array + 4)));

    // fputs(test[0], stdout);

    /*for (i = 0; i < 16; i+=4)
    {
        scanf_s("%d", &test[0], 4);
    }

    for (i = 0; i < 16; i += 4)
    {
        printf("°ú¿¬ : %d \n", test[i]);
    }*/
    //d 

    return 0;
}
