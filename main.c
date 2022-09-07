#include <stdio.h>
#include <windows.h>



int WINAPI WinMain(HINSTANCE hCopia, HINSTANCE hCopiaAnt, LPSTR szLinhaCmd, int iCmdMostrar) {
    int new_pontuation = 200;
    int pontuation_memory_address = 0x0475C2B0; // endereço, hexadecimal,que contém a pontuação do game


    HWND id_of_game = FindWindow(0, "C:\\Users\\Marcu\\Desktop\\teste.exe");  // id do jogo que o sistema operacional nomeou

    if(id_of_game == 0){
        printf("Error to access the program\n");
        return 1;
    }

    printf("Access granted\n");

    DWORD pId;

    GetWindowThreadProcessId(id_of_game, &pId);  // passa o id do processo que gerencia a janela

    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);  // identificador que permite alterar o conteúdo do processo

    if(hProc == 0)
    {
        printf("Erro to open process to modify\n");
        return 1;
    }

    // escreve na memória do processo do jogo: 4bits -> int
    BOOL write = WriteProcessMemory(
            hProc,
            (LPVOID)0x0061FF1C,
            &new_pontuation,
            (SIZE_T)sizeof(new_pontuation),
            NULL); //id do prcess de escrita, ponteiro void para o endereço e tamanho do tipo a ser gravado (return bytes gravado)
    if(write)
    {
        printf("HACKED!!!");
        return 0;
    }
    printf("FAILED TO WRITE IN MEMORY");
    return 1;
}
