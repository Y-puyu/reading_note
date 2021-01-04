/*
** Print an hexadecimal dump of the specified file. If no filename argument is
** given, print a dump of the standard input instead.
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 64
    /*
** 
Function to dump the contents of a stream.
*/
    void
    dump(FILE *stream)
{
    long
        offset;
    unsigned char
        data[16];
    int
        len;
    char
        buffer[BUFFER_SIZE];
    /*
** Initialize the buffer that will be used for output.
*/
    memset(buffer, ' ', BUFFER_SIZE - 1);
    buffer[45] = '*';
    buffer[62] = '*';
    buffer[BUFFER_SIZE-1] = '\0';
    offset = 0;
    while ((len = fread(data, 1, 16, stream)) > 0)
    {
        char
            *hex_ptr;
        char
            *char_ptr;
        int
            i;
        /*
** Start building the output buffer with the offset.
*/
        sprintf(buffer, "%06X ", offset);
        /*
** Prepare pointers to the hex and character portions of the
** buffer and initialize them to spaces.
*/
        hex_ptr = buffer + 8;
        char_ptr = buffer + 46;
        memset(hex_ptr, ' ', 35);
        memset(char_ptr, ' ', 16);
        /*
** Now translate the data to both of the output forms and store
** it in the buffer.
*/
        for (i = 0; i < len; i += 1)
        {
            /*
** Convert the next character to hex. Must overwrite
** the NUL that sprintf inserts with a space.
*/
            sprintf(hex_ptr, "%02X", data[i]);
            hex_ptr += 2;
            *hex_ptr = ' ';
            /*
** Leave a space between each group of 4 values in the
** hex portion of the line.
*/
            if (i % 4 == 3)
                hex_ptr++;
            /*
** If the character is printable, put it in the char
** portion of the line, else put a dot in.
*/
            if (isprint(data[i]) || data[i] == ' ' )
                *char_ptr++ = data[i];
            else
                *char_ptr++ = '.';
        }
        /*
** Print the line and then update the offset for the next time
** through the loop.
*/
        puts(buffer);
        offset += len;
    }
}
/*
** 
Main program. Dump the file (if there is an argument) or stdin.
*/
int main(int ac, char **av)
{
    if (ac <= 1)
        dump(stdin);
    else
    {
        FILE
            *stream;
        stream = fopen(av[1], "rb");
        if (stream == NULL)
        {
            perror(av[1]);
            exit(EXIT_FAILURE);
        }
        dump(stream);
        fclose(stream);
    }
    return EXIT_SUCCESS;
}