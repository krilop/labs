#include "functions.h"

#define EXIT_FILE_OPEN_ERROR 1
#define EXIT_COUNT_OF_ARGS_ERROR 2
#define EXIT_UNCORRECT_FORMAT_ERROR 3

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        exit(EXIT_COUNT_OF_ARGS_ERROR);
    }

    char *nameOfFileResource = (char *) calloc(strlen(argv[1]) + strlen("../term2/lab3/") + 1, 1);
    strcat(strcat(nameOfFileResource, "../term2/lab3/"), argv[1]);
    FILE *resource = fopen(nameOfFileResource, "rb");
    if (resource == NULL)
        exit(EXIT_FILE_OPEN_ERROR);
    fseek(resource,0,SEEK_SET);

    headerFileBitMap header;
    fread(&header, sizeof(header), 1, resource);
    infoHeaderBitMap info;
    fread(&info, sizeof(info), 1, resource);
    int lessThanEight = 0;
    if (header.bfType != 0x4D42 || checkBitCount(info, &lessThanEight))
        exit(EXIT_UNCORRECT_FORMAT_ERROR);
    menu(nameOfFileResource, header, info, &resource);
    free(nameOfFileResource);
    fclose(resource);
    return 0;
}


