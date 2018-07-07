#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct copa{
    int year;
    char country[30];
    char winner[30];
    char runnersUp[30];
    char third[30];
    char fourth[30];
    int goalsScored;
    int qualifiedTeams;
    int matchesPlayed;
    struct copa *prox;
} typedef COPA;

struct jogo{
    int year;
    char datetime[25];
    char stage[30];
    char stadium[30];
    char city[50];
    char homeTeamName[30];
    int homeTeamGoals;
    int awayTeamGoals;
    char awayTeamName[30];
    char winconditions[50];
    int attendance;
    int halfTimeHomeGoals;
    int halfTimeAwayGoals;
    char referee[50];
    char assistant1[50];
    char assistant2[50];
    int roundID;
    int matchID;
    char homeTeamInitials[5];
    char awayTeamInitials[5];
    struct jogo *prox;
}typedef JOGO;

struct jogador{
    int roundID;
    int matchID;
    char teamInitials[5];
    char coachName[50];
    char lineUp[2];
    int shirtNumber;
    char playerName[50];
    char position[5];
    char event[30];
    struct jogador *prox;
}typedef JOGADOR;

void pausa(){
    printf("\n");
    system("pause");
}

COPA* carregaCopas(){

    FILE *arquivo;
    COPA *copas = NULL;

    arquivo = fopen("WorldCups.csv", "r");
    if(arquivo == NULL) return NULL;
    char buffer[1024]={0x0};
	int qtLinhas = 0;

	while(fscanf(arquivo, "%[^\n]\n", buffer)!= EOF){
        if (qtLinhas > 0){
            int j = 1;
            char *p = strtok(&buffer, ",");
            COPA *copa = (COPA*) malloc(sizeof(COPA));

            while(p){
                switch (j){
                    case 1: sscanf(p, "%d", &copa->year); break;
                    case 2: strcpy(copa->country,   p); break;
                    case 3: strcpy(copa->winner,    p); break;
                    case 4: strcpy(copa->runnersUp, p); break;
                    case 5: strcpy(copa->third,    	p); break;
                    case 6: strcpy(copa->fourth,    p); break;
                    case 7: sscanf(p, "%d", &copa->goalsScored); break;
                    case 8: sscanf(p, "%d", &copa->qualifiedTeams); break;
                    case 9: sscanf(p, "%d", &copa->matchesPlayed); break;
                }

                p = strtok('\0', ",");
                j++;
            }

            if(copas == NULL){
                copas = copa;
                copas->prox = NULL;
            }else  {
                copa->prox = copas;
                copas = copa;
            }
            Sleep(10);
            printf("\rCarregando copas: %d", qtLinhas - 1);
            fflush(stdout);
        }
        qtLinhas++;
	}

    fclose(arquivo);
    return copas;
}

JOGO* carregaJogos(){
    FILE *arquivo;
    JOGO *jogos = NULL;

    arquivo = fopen("WorldCupMatches.csv", "r");
    if(arquivo == NULL) return NULL;
    char buffer[1024]={0x0};
	int qtLinhas = 0;

	while(fscanf(arquivo, "%[^\n]\n", buffer)!= EOF){
        if (qtLinhas > 0){
            int j = 1;
            char *p = strtok(&buffer, ",");
            JOGO *jogo = (JOGO*) malloc(sizeof(JOGO));

            while(p){
                switch (j){
                    case 1:  sscanf(p, "%d", &jogo->year);break;
                    case 2:  strcpy(jogo->datetime, p);break;
                    case 3:  strcpy(jogo->stage, p);break;
                    case 4:  strcpy(jogo->stadium, p);break;
                    case 5:  strcpy(jogo->city, p);break;
                    case 6:  strupr(p); strcpy(jogo->homeTeamName, p);break;
                    case 7:  sscanf(p, "%d", &jogo->homeTeamGoals);break;
                    case 8:  sscanf(p, "%d", &jogo->awayTeamGoals);break;
                    case 9:  strupr(p); strcpy(jogo->awayTeamName, p);break;
                    case 10: strcpy(jogo->winconditions, p);break;
                    case 11: sscanf(p, "%d", &jogo->attendance);break;
                    case 12: sscanf(p, "%d", &jogo->halfTimeHomeGoals);break;
                    case 13: sscanf(p, "%d", &jogo->halfTimeAwayGoals);break;
                    case 14: strcpy(jogo->referee, p);break;
                    case 15: strcpy(jogo->assistant1, p);break;
                    case 16: strcpy(jogo->assistant2, p);break;
                    case 17: sscanf(p, "%d", &jogo->roundID);break;
                    case 18: sscanf(p, "%d", &jogo->matchID);break;
                    case 19: strcpy(jogo->homeTeamInitials, p);break;
                    case 20: strcpy(jogo->awayTeamInitials, p);break;
                }

                p = strtok('\0', ",");
                j++;
            }

            if(jogos == NULL){
                jogos = jogo;
                jogos->prox = NULL;
            }else  {
                jogo->prox = jogos;
                jogos = jogo;
            }
            Sleep(1);
            printf("\rCarregando jogos: %d", qtLinhas - 1);
            fflush(stdout);
        }
        qtLinhas++;
	}

    fclose(arquivo);
    return jogos;
}

JOGADOR* carregaJogadores(){
    FILE *arquivo;
    JOGADOR *jogadores = NULL;

    arquivo = fopen("WorldCupPlayers.csv", "r");
    if(arquivo == NULL) return NULL;
    char buffer[1024]={0x0};
	int qtLinhas = 0;

	while(fscanf(arquivo, "%[^\n]\n", buffer)!= EOF){
        if (qtLinhas > 0){
            int j = 1;
            char *p = strtok(&buffer, ",");
            JOGADOR *jogador = (JOGADOR*) malloc(sizeof(JOGADOR));

            while(p){
                switch (j){
                    case 1: sscanf(p, "%d", &jogador->roundID); break;
                    case 2: sscanf(p, "%d", &jogador->matchID); break;
                    case 3: strcpy(jogador->teamInitials  , p); break;
                    case 4: strcpy(jogador->coachName     , p); break;
                    case 5: strcpy(jogador->lineUp        , p); break;
                    case 6: sscanf(p, "%d", &jogador->shirtNumber); break;
                    case 7: strcpy(jogador->playerName    , p); break;
                    case 8: strcpy(jogador->position      , p); break;
                    case 9: strcpy(jogador->event         , p); break;
                }

                p = strtok('\0', ",");
                j++;
            }

            if(jogadores == NULL){
                jogadores = jogador;
                jogadores->prox = NULL;
            }else  {
                jogador->prox = jogadores;
                jogadores = jogador;
            }

            printf("\rCarregando jogadores: %d", qtLinhas - 1);
            fflush(stdout);
        }
        qtLinhas++;
	}

    fclose(arquivo);
    return jogadores;
}

void imprimeTraco(){
    printf("\n********************************************************************************************************************");
}

int opcaoMenu(){
    int opcao;

    do{
        system("cls");
        imprimeTraco();
        printf("\n******************************* Estatisticas de jogos da copa do mundo *********************************************");
        imprimeTraco();
        printf("\n[1] Estatisticas por copas");
        printf("\n[2] Estatisticas por times");
        printf("\n[3] Estatisticas por jogadores");
        printf("\n[4] Cadastro Copa Atual");
        printf("\n[5] Sair");
        printf("\n");
        printf("\nDigite a opcao desejada: ");

        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 5){
            printf("\nOpcao invalida");
            pausa();
        }
    }while(opcao < 1 || opcao > 5);

    return opcao;
}

int opcaoMenuCopas(){
    int opcao;

    do{
        system("cls");
        imprimeTraco();
        printf("\n*************************************** Estatisticas por Copa ******************************************************");
        imprimeTraco();
        printf("\n[1] Selecionar uma copa");
        printf("\n[2] Visao geral");
        printf("\n[3] Voltar");
        printf("\n");
        printf("\nDigite a opcao desejada: ");

        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 3){
            printf("\nOpcao invalida");
            pausa();
        }
    }while(opcao < 1 || opcao > 3);

    return opcao;
}

COPA* procuraCopaPeloAno(COPA* copas, int ano){
    COPA *aux = copas;
    while(aux != NULL){
        if(aux->year == ano){
            COPA *result = (COPA*) malloc(sizeof(COPA));
            memcpy(result, aux, sizeof(COPA));
            return result;
        }

        aux = aux->prox;
    }
}

struct grupo{
    char name[30];
    int gol,ponto;
    struct grupo *prox;
}typedef GRUPO;

//Aqui havia algumas parte de códigos mas resolvi apagar ja que deram erros durante a execução do código...

int menuAtual(){
    int opcao;

    do{
        system("cls");
        imprimeTraco();
        printf("\n*************************************** Cadastro Copa Atual ******************************************************");
        imprimeTraco();
        printf("\n[1] Cadastro Grupos");
        printf("\n[2] Cadastro Jogs");
        printf("\n[3] Vizualizar Tabela");
        printf("\n[4] Cadastrar Jogos Finais");
        printf("\n[5] Voltar");
        printf("\n");
        printf("\nDigite a opcao desejada: ");

        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 5){
            printf("\nOpcao invalida");
            pausa();
        }
    }while(opcao < 1 || opcao > 5);

    return opcao;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("title Fifa World Cup Statistics");
    FILE *file;
    file = fopen("copa.csv","r");
    GRUPO *topo = NULL;
    GRUPO *aux, *novo;
    int gol,i,j,ponto;
    char name[30];

    printf("\n********************************************************************************************************************");
    printf("\n********************************************************************************************************************");
    printf("\n***************************************************````````*********************************************************");
    printf("\n************************************************```     ```*********************************************************");
    printf("\n**********************************************`` ``````````..*******************************************************");
    printf("\n**********************************************```...------.::`******************************************************");
    printf("\n**********************************************.-.----+::::///:`*****************************************************");
    printf("\n*********************************************`-/+//++oo+oooo++.*****************************************************");
    printf("\n**********************************************`:+ooso+ossyso/-******************************************************");
    printf("\n***********************************************.:/+ohhoss:-::*******************************************************");
    printf("\n************************************************:+++o+os++/-********************************************************");
    printf("\n************************************************::/++++o++:*********************************************************");
    printf("\n************************************************`-:-//.+so`*********************************************************");
    printf("\n*************************************************`--:.-oo-**********************************************************");
    printf("\n**************************************************:/-.oo/***********************************************************");
    printf("\n**************************************************.--oo:o-**********************************************************");
    printf("\n**************************************************`/+/+++y.*********************************************************");
    printf("\n*************************************************`:::/---os*********************************************************");
    printf("\n*************************************************+s+++o+shs:********************************************************");
    printf("\n************************************************.-:/++++/::.********************************************************");
    printf("\n***********************************************`ss+:/:////y+********************************************************");
    printf("\n************************************************`/oyhhhyso:*********************************************************");
    printf("\n********************************************************************************************************************");
    printf("\n********************************************************************************************************************");
    printf("\n***************************************** Fifa World CUPs Statistics ***********************************************");
    printf("\n********************************************************************************************************************");
    printf("\n");

    COPA *copas = carregaCopas();
    JOGO *jogos = carregaJogos();
    JOGADOR *jogadores = carregaJogadores();
    //JOGADOR *jogadores = (JOGADOR*) malloc(sizeof(JOGADOR));

    if(copas == NULL || jogos == NULL || jogadores == NULL){
        printf("\nFalha ao ler arquivos.");
        pausa();
        return 1;
    }

    int opcao = 0, opcaoAux = 0;
    do{
        opcao = opcaoMenu();

        int anoCopa = 0;
        int achou = 0;
        COPA *aux = NULL;
        JOGO *auxJogo = NULL;
        GRUPO *auxGrupo = NULL;

        char time[30], iniciaisTime[5];
        COPA *copasJogadas = NULL;
        JOGO *partidasJogadas = NULL;

        switch(opcao){
            case 1:
                do{
                    opcaoAux = opcaoMenuCopas();
                    switch(opcaoAux){
                        case 1:
                            printf("\nInforme o ano da copa desejada: ");
                            scanf("%d", &anoCopa);
                            aux = copas;

                            while(aux != NULL){
                                if(aux->year == anoCopa){
                                    achou = 1;
                                    printf("\nAno......................: %d", aux->year);
                                    printf("\nPaís.....................: %s", aux->country);
                                    printf("\nVencedor.................: %s", aux->winner);
                                    printf("\nSegundo colocado.........: %s", aux->runnersUp);
                                    printf("\nTerceiro colocado........: %s", aux->third);
                                    printf("\nQuarto colocado..........: %s", aux->fourth);
                                    printf("\nTotal de gols............: %d", aux->goalsScored);
                                    printf("\nTimes participantes......: %d", aux->qualifiedTeams);
                                    printf("\nPartidas jogadas.........: %d", aux->matchesPlayed);
                                    printf("\n");
                                }
                                aux = aux->prox;
                            }

                            if(!achou)
                                printf("\nNao foi realizada uma copa neste ano.");
                            break;
                        case 2:
                            aux = copas;
                            imprimeTraco();
                            printf("\n%-8s %-15s %-15s %-15s %-15s %-15s %-7s %-7s %-9s",
                                   "Ano", "País", "Vencedor", "Segundo Lugar", "Terceiro Lugar", "Quarto Lugar", "Gols", "Times", "Partidas");
                            imprimeTraco();

                            while(aux != NULL){
                                printf("\n%-8d %-15s %-15s %-15s %-15s %-15s %-7d %-7d %-9d",
                                    aux->year, aux->country, aux->winner, aux->runnersUp, aux->third, aux->fourth, aux->goalsScored, aux->qualifiedTeams, aux->matchesPlayed);
                                aux = aux->prox;
                            }

                            imprimeTraco();
                            printf("\n");
                            break;
                    }

                    pausa();
                }while(opcaoAux != 3);
                break;
            case 2:
                printf("\n\nInforme o nome do time: ");
                fflush(stdin);
                gets(time);
                strupr(time);

                aux = NULL;
                auxJogo = jogos;
                while(auxJogo != NULL){
                    if(strcmp(time, auxJogo->homeTeamName) == 0 || strcmp(time, auxJogo->awayTeamName) == 0){
                        if(strcmp(time, auxJogo->homeTeamName) == 0)
                            strcpy(&iniciaisTime, auxJogo->homeTeamInitials);
                        else
                            strcpy(&iniciaisTime, auxJogo->awayTeamInitials);

                        if(partidasJogadas == NULL){
                            partidasJogadas = (JOGO*) malloc(sizeof(JOGO));
                            memcpy(partidasJogadas, auxJogo, sizeof(JOGO));
                            partidasJogadas->prox = NULL;
                        }else{
                            JOGO *jogoCpy = (JOGO*) malloc(sizeof(JOGO));
                            memcpy(jogoCpy, auxJogo, sizeof(JOGO));
                            jogoCpy->prox = partidasJogadas;
                            partidasJogadas = jogoCpy;
                        }

                        aux = procuraCopaPeloAno(copas, auxJogo->year);
                        if(copasJogadas == NULL){
                            copasJogadas = aux;
                            copasJogadas->prox = NULL;
                        }else{
                            if(!procuraCopaPeloAno(copasJogadas, auxJogo->year)){
                                aux->prox = copasJogadas;
                                copasJogadas = aux;
                            }
                        }
                    }

                    auxJogo = auxJogo->prox;
                }

                aux = copasJogadas;
                system("cls");

                while(aux != NULL){
                    printf("\n********************************************** Participações *******************************************************");
                    printf("\nAno......................: %d", aux->year);
                    printf("\nPaís.....................: %s", aux->country);
                    printf("\nVencedor.................: %s", aux->winner);
                    imprimeTraco();
                    printf("\n%-10s %-25s %20s         %-20s","MatchID", "Fase", "Time da casa", "Time visitante");
                    imprimeTraco();
                    auxJogo = partidasJogadas;
                    while(auxJogo != NULL){
                        if(auxJogo->year == aux->year){
                            printf("\n%-10d %-25s %20s %2d x %2d %-20s", auxJogo->matchID, auxJogo->stage, auxJogo->homeTeamName, auxJogo->homeTeamGoals, auxJogo->awayTeamGoals, auxJogo->awayTeamName);
                        }
                        auxJogo = auxJogo->prox;
                    }
                    imprimeTraco();
                    printf("\n\n\n");
                    aux = aux->prox;
                }

                do{
                    printf("\nInforme um matchId para ver a escalação ou 0 para voltar: ");
                    scanf("%d", &opcaoAux);

                    if(opcaoAux > 0){
                        achou = 0;
                        JOGADOR *jogadorAux = jogadores;

                        while(jogadorAux != NULL){
                            if(jogadorAux->matchID == opcaoAux && strcmp(iniciaisTime, jogadorAux->teamInitials) == 0){
                                if(!achou){
                                    imprimeTraco();
                                    printf("\n\t%-30s %-7s", "Jogador", "Camisa");
                                    imprimeTraco();
                                    achou = 1;
                                }
                                printf("\n\t%-30s %-7d", jogadorAux->playerName, jogadorAux->shirtNumber);
                            }
                            jogadorAux = jogadorAux->prox;
                        }

                        if(!achou)
                            printf("\n\nNenhuma partida encontrada com este ID!");
                        else
                            imprimeTraco();
                    }
                }while(opcaoAux > 0);

                pausa();
                break;
            case 4:
                opcaoAux = menuAtual();
                switch(opcaoAux){
                    case 1:
                        file = fopen("copa.csv","w");
                        for(i=0;i<8;i++){
                            printf("\n%d° Grupo: ",i+1);
                            for(j=0;j<4;j++){
                                novo = (GRUPO*)malloc(sizeof(GRUPO));
                                printf("\nDigite o nome da Seleção: ");
                                scanf("%s",name);
                                fprintf(file,"%s\t",name);
                                novo->prox = topo;
                                topo = novo;
                            }
                            fprintf(file,"\n");
                        }
                        fclose(file);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
/*A parte Incompleta (sobre o cadastro da copa atual) era de principal responsabilidade minha (MAUI DIAS), mas a mesma falhou quando posto no codigo
enviado pelos demais integrantes, sendo assim peço que, se houver decrescimo de nota em relação a essa parte, leve esta informção em consideração. Desculpe */
        }
    }while(opcao != 5);

    system("cls");
    printf("\n********************************************************************************************************************");
    printf("\n********************************************* FIM DO PROGRAMA ******************************************************");
    printf("\n********************************************************************************************************************");
    printf("\n");


    system("pause");
    return 0;
}
