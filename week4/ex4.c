#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define BUFFER_MAX  32 
#define CMD_START   "$ ) "

const char **environ;
char buffer[BUFFER_MAX];

void *strip(char *string)
{
    const char *pattern = "\n\t";
    char *byte = string;
    while ((byte = strpbrk(byte, pattern))) {
        strcpy(byte, byte+1);
        ++byte;
    }
}

char **split(const char *string)
{
    const char delim = ' ';
    int res_length = 0;
    char *bytes = strdup(string);
    char *byte = bytes;
    while ((byte = strpbrk(byte, &delim))) {
        ++res_length;
        ++byte;
    }
    char **result = malloc((res_length+2)*sizeof(char*));
    char *token;
    int i = 0;
    while ((token = strsep(&bytes, &delim))) {
        result[i++] = strdup(token);
    }
    result[i] = NULL;
    free(bytes);
    return result;
}

void exec(char **argv)
{
    char **byte = argv;
    char *command = malloc(sizeof(char*));
    while (*byte) {
        strcpy(&command[strlen(command)], *byte);
        strcpy(&command[strlen(command)], " ");
        ++byte;
    }
    pid_t childPid;
    int status;
    switch (childPid = fork()) {
        case -1:
            break;
        case 0:
            execl("/bin/sh", "sh", "-c", command, (char *) 0);
            _exit(127); // the given command is not found
        default:
            while (waitpid(childPid, &status, 0) == -1) {
                if (errno != EINTR) // child is in progress; no error occured
                    break;
                }
            break;
        }
    byte = argv;
    while (*byte)
    free(*byte++);  
    free(argv); // double-free?
}

int main(int argc, char **argv, char **envp)
{
    fputs("Simplistic shell EXTENDED. Welcome\n\n", stdout);
    int i = 0;
    char c;
    fputs(CMD_START, stdout);
    while (fread(&c, sizeof(char), 1, stdin)) {
        buffer[i] = c;
        ++i;
        if (c == '\n') {
            fputs(CMD_START, stdout);
            if (i != 1) {
                buffer[i] = '\0';
                strip(buffer);
                char **strings = split(buffer);
                exec(strings);
            }
            i = 0;
        }
    }
    fputs("\n\nSee you Space Cowboy\n", stdout);
    return 0;
}
