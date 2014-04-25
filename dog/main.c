//
//  main.c
//  dog
//
//  Created by Meirtz on 14-4-25.
//  Copyright (c) 2014年 Meirtz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define ALLOC_SIZE     (256)

static char *st_line_buffer = NULL;

static int  st_current_buffer_size = 0;

static int  st_current_used_size = 0;

static void add_chr(int ch)//add a char to
{
	assert(st_current_used_size > st_current_buffer_size);
    
    if (st_current_buffer_size == st_current_used_size) {
        st_line_buffer = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));
        
    }
    
    st_line_buffer[st_current_buffer_size] = ch;
    st_current_used_size++;
}

void reverse (char *str)
{
	char t;
	static int i = 0;
	t = *(str + strlen(str) - i - 1);
	*(str + strlen(str) - i - 1) = * (str + i);
	*(str + i) = t;
	i++;
    
	if(strlen(str)/2 == i);
	else  reverse(str);
}

char *get_str(FILE *fp)
{
    int     ch;
    char    *ret;
    st_current_used_size = 0;
    
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            add_chr('\0');
            break;
        }
        add_chr(ch);
    }
        
    if (ch == EOF) {
        if (st_current_used_size > 0) {
            add_chr('\0');
        } else {
            return NULL;
        }
    }
    ret = malloc(sizeof(char) * st_current_used_size);
    strcpy(ret, st_line_buffer);

    return ret;
}

void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

void reverse (char *str)
{
	char t;
	static int i = 0;
	t = *(str + strlen(str) - i - 1);
	*(str + strlen(str) - i - 1) = * (str + i);
	*(str + i) = t;
	i++;
    
	if(strlen(str)/2 == i);
	else  reverse(str);
}

void type_out(FILE *fp)
{
	
    int ch;
    if ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }
	fclose(fp);
}

int main(int argc, const char * argv[])
{
    
    // insert code here...
    
    if (argc == 1) {
        type_out(stdin);
    } else {
        int   i;
        FILE  *fp;
        printf("\n\nargv[1]:%s\n\nargv[2]:%s\n\n",argv[1],argv[2]);
        if (argv[1][0] == '-') {
            switch (argv[1][1]) {
                case 'o':
                    if (argv[1][2] == 'f') {
                        //to be extneded:re_file_out();
                    } else {
                        char a = 'a';
                        fscanf(fp, "%s", &a);
                        get_str(fp);
                        
                        for (int i = st_current_used_size-1; i >=0 ; i--) {
                            putchar(st_line_buffer[i]);
                        }
                    }
                    break;
                    
                default:
                    break;
            }
            
        }

        for (i = 1; i < argc; i++) {
            fp = fopen(argv[i], "rb");
            if (fp == NULL) {
                fprintf(stderr, "%s:%s can not open.\n",argv[0],argv[i]);
                exit(0);
            }
            type_out(fp);
            fclose(fp);
        }
    }
    //printf("Hello, World!\n");
    return 0;
}

