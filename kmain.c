void cls() {

    char *text_video = (char*) 0x000B8000;
    int i;

    for (i = 0; i < 4000; i++) {
        *text_video++ = 0x00;
    }

    return;
}

int kmain(void) {

    cls();

    char *fb = (char *) 0x000B8000;

    *fb++ = 'c';
    *fb++ = 0x07;

    *fb++ = 'a';
    *fb++ = 0x07;

    *fb++ = 'f';
    *fb++ = 0x07;

    *fb++ = 'e';
    *fb++ = 0x07;

    *fb++ = 'O';
    *fb++ = 0x07;

    *fb++ = 'S';
    *fb++ = 0x07;

    return 0;
}