#if 0

int value, total = 0;
while (fgets(buf, BUFSIZE, input) != NULL) {
    if (sscanf(buf, "%d", &value) == 1)             // sscanf 进行判断。不错的思想
        total += value;
    fputs(buf, output);
}
fprintf(output, "%d\en", total);

#endif 