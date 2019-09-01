#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 65536

void minify() {
    unsigned char buff[BUFF_SIZE];
    unsigned char new[BUFF_SIZE];

    unsigned char *new_ptr = new;
    const unsigned char *new_end = new + BUFF_SIZE;

    size_t read_size = 0;

    const unsigned char *buff_ptr = buff;
    const unsigned char *end_buff = buff + read_size;

    unsigned char chr;

#define GET_CHR() if (buff_ptr == end_buff) { \
    if ((read_size = read(STDIN_FILENO, buff, BUFF_SIZE)) == 0) { goto end; } \
    end_buff = buff + read_size; \
    buff_ptr = buff; \
} \
chr = *(buff_ptr++);

#define PASS_CHR() *(new_ptr++) = chr; if (new_ptr == new_end) { write(STDOUT_FILENO, new, BUFF_SIZE); new_ptr = new; }

#define ABORT() exit(1)   

#define STRING_ITER() GET_CHR(); \
    PASS_CHR(); \
\
    if ('"' == chr) { \
        break; \
    } else if ('\\' == chr) { \
        GET_CHR(); \
        PASS_CHR(); \
    }

#define MAIN_ITER() GET_CHR(); \
\
    if (' ' == chr || '\f' == chr || '\n' == chr || '\r' == chr || '\v' == chr || '\t' == chr) { \
          continue; \
    } else { \
        PASS_CHR(); \
\
        if ('"' == chr) { \
            while (1) { \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
                STRING_ITER(); \
            } \
        } \
    }

    while (1) {
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
        MAIN_ITER();
    }  

    end:
    if (new_ptr != new) {
        write(STDOUT_FILENO, new, (new_ptr - new));
    }

}

int main(int argc, char *argv[]) {
    minify();

    return 0;
}

