// append.c -- 把多个文件的内容追加到一个文件中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(void)
{
    FILE *fa, *fs;          // fa指向追加的目的文件，fs指向源文件
    int files = 0;          // 追加文件的个数
    char file_app[SLEN];    // 被追加文件的名称
    char file_src[SLEN];    // 源文件的名称
    puts("Eter name of destination file: ");
    gets(file_app);
    if((fa = fopen(file_app, "a")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(2);
    }
    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(3);
    }
    puts("Enter name of first source file(empty line to quit) ");
    while(gets(file_src) && file_src[0] != 0)
    {
        if(strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if(ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if(ferror(fa) != 0)
                fpritnf(stderr, "Error in writing file %s.\n", file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file(empty line to quit): ");
        }
    }
    printf("Done. %d files appended.\n", files);
    fclose(fa);
    return 0;
}

void apend(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];      // 分配一次

    while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}