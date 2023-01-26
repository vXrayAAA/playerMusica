#include <stdio.h>
#include <windows.h>

int main() {
    char musica[100];
    printf("Insira o nome do arquivo de música (com a extensão): ");
    scanf("%s", musica);

    // reproduzir a música usando a função mciSendString
    mciSendString("open \"%s\" type mpegvideo alias mp3", musica, 0, 0);
    mciSendString("play mp3", NULL, 0, 0);

    // esperar até que a música termine
    mciSendString("status mp3 length", musica, 100, 0);
    int duracao = atoi(musica);
    Sleep(duracao);

    // parar e fechar a música
    mciSendString("stop mp3", NULL, 0, 0);
    mciSendString("close mp3", NULL, 0, 0);

    return 0;
}
