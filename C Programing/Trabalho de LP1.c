/*

TRABALHO DE LINGUAGENS DE PROGRAMACAO 1

Prof: Nuno Garcia

Curso: Engenharia Informatica

Elementos do grupo:
Davide Barruncho - 21104379
Yasmine Chede - 21104555
Andre Graos - 21105163
Leandro Dias - 21001921

*/

#include <stdio.h>
#include <string.h>

#define maxFICHA_DE_COMPONENTES 10000
#define maxFICHA_DE_POSTO_DE_TRABALHO 10000
#define maxFICHA_DE_FUNCIONARIO 10000
#define maxFICHA_DE_OPERACOES 10000
#define maxFICHA_DE_EMPRESA 10000

int numeroFICHA_DE_COMPONENTES;
int numeroFICHA_DE_POSTO_DE_TRABALHO;
int numeroFICHA_DE_FUNCIONARIO;
int numeroFICHA_DE_OPERACOES;
int numeroFICHA_DE_EMPRESA;

typedef struct dataAMD //Funcao para a data
{
    int dia;
    int mes;
    int ano;
} DATA;

DATA ler_data()
{
    int dia_max;

    DATA tmp;

    printf("Ano: ");
    do
    {
        scanf("%d",&tmp.ano);
        if(tmp.ano<2011)
        {
            printf("Introduziu errado o ano.\n ");
            printf("Introduza novamente o ano : ");
        }
    }
    while(tmp.ano<2011);

    printf("Mes: ");
    do
    {
        scanf("%d",&tmp.mes);
        if ((tmp.mes<1) || (tmp.mes>12))
        {
            printf("Introduziu errado o mes.\n");
            printf("Intoduza novamente o mes : ");
        }
    }
    while(tmp.mes<1 || tmp.mes>12);
    if (tmp.mes==1||tmp.mes==3||tmp.mes==5||
            tmp.mes==7||tmp.mes==8||tmp.mes==10||
            tmp.mes==12)
        dia_max=31;

    else

        if (tmp.mes==4||tmp.mes==6||tmp.mes==9||
                tmp.mes==11)
            dia_max=30;

        else
        {

            if (tmp.mes%4==0)
                dia_max=29;
            else
                dia_max=28;
        }
    printf("Dia: ");
    do
    {
        scanf("%d",&tmp.dia);
        if (tmp.dia<1 || tmp.dia>dia_max)
        {
            printf("Introduziu errado o dia.\n");
            printf("Introduza novamente o dia : ");
        }
    }
    while(tmp.dia<1 || tmp.dia>dia_max);

    return tmp;

}

typedef struct ficha_de_componentes //FUNCAO PARA QUALQUER FICHA DE COMPONENTES
{
    int id;
    char designacao[50];
    char nserie[50];
    DATA data;
    int garantia;
    int id_fornecedor;
    int id_fabricante;
    char tipo[50];
    char condicao[50];
    int id_posto_trabalho;
    char obs[100];

} FICHA_DE_COMPONENTES;

FICHA_DE_COMPONENTES ficha_de_componentes [maxFICHA_DE_COMPONENTES];

typedef struct ficha_de_posto_de_trabalho //FUNCAO PARA QUALQUER FICHA DE TRABALHO
{
    int id;
    char nome[50];
    char local[50];
    char seccao[50];
    char descricao[100];
    int id_funcionario;

} FICHA_DE_POSTO_DE_TRABALHO;

FICHA_DE_POSTO_DE_TRABALHO ficha_de_posto_de_trabalho [maxFICHA_DE_POSTO_DE_TRABALHO];

typedef struct ficha_de_funcionario //FUNCAO PARA QUALQUER FICHA DE FUNCIONARIO
{
    int id;
    char nome[50];
    char funcao[50];
    char descricao[100];

} FICHA_DE_FUNCIONARIO;

FICHA_DE_FUNCIONARIO ficha_de_funcionario [maxFICHA_DE_FUNCIONARIO];

typedef struct ficha_de_operacoes //FUNCAO PARA QUALQUER FICHA DE OPERACOES
{
    int id;
    int id_doc_int;
    int id_doc_ext;
    int id_posto_trabalho;
    int id_componente;
    int id_empresa;
    char tipo_op[50];
    DATA saida;
    DATA chegada;
    DATA ETA;
    int id_funcionario;
    DATA operacao;
    double montante;
    char obs[100];

} FICHA_DE_OPERACOES;

FICHA_DE_OPERACOES ficha_de_operacoes [maxFICHA_DE_OPERACOES];

typedef struct ficha_de_empresa //FUNCAO PARA QUALQUER FICHA DE EMPRESA
{
    int id;
    char nome[50];
    char tipo[50];
    char contacto[50];

} FICHA_DE_EMPRESA;

FICHA_DE_EMPRESA ficha_de_empresa [maxFICHA_DE_EMPRESA];

//CHAMAR AS FUNCOES PARA OS VARIOS MENUS

void criar_ficha_de_componentes();
void criar_ficha_de_posto_de_trabalho();
void criar_ficha_de_funcionario();
void criar_ficha_de_operacoes();
void criar_ficha_de_empresa();

void apagar_ficha_de_componentes();
void apagar_ficha_de_posto_de_trabalho();
void apagar_ficha_de_funcionario();
void apagar_ficha_de_operacoes();
void apagar_ficha_de_empresa();

void alterar_ficha_de_componentes();
void alterar_ficha_de_posto_de_trabalho();
void alterar_ficha_de_funcionario();
void alterar_ficha_de_operacoes();
void alterar_ficha_de_empresa();

void pesquisar_ficha_de_componentes();
void pesquisar_ficha_de_posto_de_trabalho();
void pesquisar_ficha_de_funcionario();
void pesquisar_ficha_de_operacoes();
void pesquisar_ficha_de_empresa();

void listar_ficha_de_componentes();
void listar_ficha_de_posto_de_trabalho();
void listar_ficha_de_funcionarios();
void listar_ficha_de_operacoes();
void listar_ficha_de_empresa();

void menu_ficha_de_componentes();
void menu_ficha_de_posto_de_trabalho();
void menu_ficha_de_funcionarios();
void menu_ficha_de_operacoes();
void menu_ficha_de_empresa();

void mostrar_ficha_de_componentes();
void mostrar_ficha_de_posto_de_trabalho();
void mostrar_ficha_de_funcionario();
void mostrar_ficha_de_operacoes();
void mostrar_ficha_de_empresa();

void gravar_ficheiro();
void ler_ficheiro();

DATA ler_data();

int main (void)
{
    ler_ficheiro();
    int opcao;

    do
    {

        puts("+--------------------------------Menu Principal-------------------------------+"
             "\n|                                                                             |"
             "\n|                1 - Ficha de Componentes                                     |"
             "\n|                 2 - Ficha de Posto de Trabalho                              |"
             "\n|                  3 - Ficha de Funcionario                                   |"
             "\n|                   4 - Ficha das Operacoes                                   |"
             "\n|                    5 - Ficha de Empresa                                     |"
             "\n|                     6 - Sair                                                |"
             "\n|                                                                             |"
             "\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            menu_ficha_de_componentes ();
            break;
        case 2:
            system("cls");
            menu_ficha_de_posto_de_trabalho ();
            break;
        case 3:
            system("cls");
            menu_ficha_de_funcionarios ();
            break;
        case 4:
            system("cls");
            menu_ficha_de_operacoes ();
            break;
        case 5:
            system("cls");
            menu_ficha_de_empresa ();
            break;
        case 6:
            gravar_ficheiro();
            break;
        default:
        {
            printf("\n Opcao nao existente!\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }

    }
    while(opcao !=6);
}

void gravar_ficheiro()
{

    int i;

    FILE *fp;
    fp = fopen("ficha_de_componentes.txt","w");   /* Arquivo ASCII, para escrita */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
    }
    else
    {



        for(i = 1; i < numeroFICHA_DE_COMPONENTES; i++)
        {
            if(ficha_de_componentes[i].id != NULL)
            {
                fprintf(fp,"%d| %s| %s| %d| %d| %d| %d| %d| %d| %s| %s| %d| %s|\n", ficha_de_componentes[i].id, ficha_de_componentes[i].designacao, ficha_de_componentes[i].nserie, ficha_de_componentes[i].data.ano, ficha_de_componentes[i].data.mes, ficha_de_componentes[i].data.dia, ficha_de_componentes[i].garantia,ficha_de_componentes[i].id_fornecedor,ficha_de_componentes[i].id_fabricante, ficha_de_componentes[i].tipo, ficha_de_componentes[i].condicao, ficha_de_componentes[i].id_posto_trabalho, ficha_de_componentes[i].obs);
            }
        }

    }
    fclose(fp);



    fp = fopen("ficha_de_posto_trabalho.txt","w");   /* Arquivo ASCII, para escrita */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
    }
    else
    {



        for(i = 1; i < numeroFICHA_DE_POSTO_DE_TRABALHO; i++)
        {
            if(ficha_de_posto_de_trabalho[i].id != NULL)
            {
                fprintf(fp,"%d| %s| %s| %s| %s| %d| \n", ficha_de_posto_de_trabalho[i].id, ficha_de_posto_de_trabalho[i].nome, ficha_de_posto_de_trabalho[i].local, ficha_de_posto_de_trabalho[i].seccao, ficha_de_posto_de_trabalho[i].descricao, ficha_de_posto_de_trabalho[i].id_funcionario);
            }
        }

    }
    fclose(fp);



    fp = fopen("ficha_de_funcionario.txt","w");   /* Arquivo ASCII, para escrita */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
    }
    else
    {



        for(i = 1; i < numeroFICHA_DE_FUNCIONARIO; i++)
        {
            if(ficha_de_funcionario[i].id != NULL)
            {
                fprintf(fp,"%d| %s| %s| %s| \n", ficha_de_funcionario[i].id, ficha_de_funcionario[i].nome, ficha_de_funcionario[i].funcao, ficha_de_funcionario[i].descricao);
            }
        }

    }
    fclose(fp);




    fp = fopen("ficha_de_operacoes.txt","w");   /* Arquivo ASCII, para escrita */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
    }
    else
    {



        for(i = 1; i < numeroFICHA_DE_OPERACOES; i++)
        {
            if(ficha_de_operacoes[i].id != NULL)
            {
                fprintf(fp,"%d| %d| %d| %d| %d| %d| %s| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %s|\n", ficha_de_operacoes[i].id, ficha_de_operacoes[i].id_doc_int, ficha_de_operacoes[i].id_doc_ext, ficha_de_operacoes[i].id_posto_trabalho, ficha_de_operacoes[i].id_componente, ficha_de_operacoes[i].id_empresa, ficha_de_operacoes[i].tipo_op, ficha_de_operacoes[i].saida.ano, ficha_de_operacoes[i].saida.mes, ficha_de_operacoes[i].saida.dia, ficha_de_operacoes[i].chegada.ano, ficha_de_operacoes[i].chegada.mes, ficha_de_operacoes[i].chegada.dia, ficha_de_operacoes[i].ETA.ano, ficha_de_operacoes[i].ETA.mes, ficha_de_operacoes[i].ETA.dia, ficha_de_operacoes[i].id_funcionario, ficha_de_operacoes[i].operacao.ano, ficha_de_operacoes[i].operacao.mes, ficha_de_operacoes[i].operacao.dia, ficha_de_operacoes[i].montante, ficha_de_operacoes[i].obs);
            }
        }

    }
    fclose(fp);

    puts("teste4");

    fp = fopen("ficha_de_empresa.txt","w");   /* Arquivo ASCII, para escrita */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
    }
    else
    {



        for(i = 1; i < numeroFICHA_DE_EMPRESA; i++)
        {
            if(ficha_de_empresa[i].id != NULL)
            {
                fprintf(fp,"%d| %s| %s| %s| \n", ficha_de_empresa[i].id, ficha_de_empresa[i].nome, ficha_de_empresa[i].tipo, ficha_de_empresa[i].contacto);
            }
        }

    }
    fclose(fp);



}

void ler_ficheiro()
{

    FILE *fp;
    int i = 1;
    numeroFICHA_DE_COMPONENTES = 1;


    fp=fopen("ficha_de_componentes.txt","r");

    if(fp!=NULL)
    {
        for(;;)
        {
            if(fscanf(fp,"%d| %[^|]| %[^|]| %d| %d| %d| %d| %d| %d| %[^|]| %[^|]| %d| %[^|]|\n", &ficha_de_componentes[i].id, ficha_de_componentes[i].designacao, ficha_de_componentes[i].nserie, &ficha_de_componentes[i].data.ano, &ficha_de_componentes[i].data.mes, &ficha_de_componentes[i].data.dia, &ficha_de_componentes[i].garantia, &ficha_de_componentes[i].id_fornecedor, &ficha_de_componentes[i].id_fabricante, ficha_de_componentes[i].tipo, ficha_de_componentes[i].condicao, &ficha_de_componentes[i].id_posto_trabalho, ficha_de_componentes[i].obs)==EOF) break;
            i++;
            numeroFICHA_DE_COMPONENTES++;

        }


        fclose(fp);

    }

    if(ficha_de_componentes[1].id != 1) numeroFICHA_DE_COMPONENTES = ficha_de_componentes[i-1].id + 1;



    numeroFICHA_DE_POSTO_DE_TRABALHO = 1;
    i = 1;


    fp=fopen("ficha_de_posto_trabalho.txt","r");

    if(fp!=NULL)
    {
        for(;;)
        {
            if(fscanf(fp,"%d| %[^|]| %[^|]| %[^|]| %[^|]| %d|\n", &ficha_de_posto_de_trabalho[i].id, ficha_de_posto_de_trabalho[i].nome, ficha_de_posto_de_trabalho[i].local, ficha_de_posto_de_trabalho[i].seccao, ficha_de_posto_de_trabalho[i].descricao, &ficha_de_posto_de_trabalho[i].id_funcionario)==EOF) break;
            i++;

            numeroFICHA_DE_POSTO_DE_TRABALHO++;
        }


        fclose(fp);

    }

    if(ficha_de_posto_de_trabalho[1].id != 1) numeroFICHA_DE_POSTO_DE_TRABALHO = ficha_de_posto_de_trabalho[i-1].id + 1;




    numeroFICHA_DE_FUNCIONARIO = 1;
    i = 1;


    fp=fopen("ficha_de_funcionario.txt","r");

    if(fp!=NULL)
    {
        for(;;)
        {
            if(fscanf(fp,"%d| %[^|]| %[^|]| %[^|]| \n", &ficha_de_funcionario[i].id, ficha_de_funcionario[i].nome, ficha_de_funcionario[i].funcao, ficha_de_funcionario[i].descricao)==EOF) break;
            i++;

            numeroFICHA_DE_FUNCIONARIO++;
        }


        fclose(fp);

    }

    if(ficha_de_funcionario[1].id != 1) numeroFICHA_DE_FUNCIONARIO = ficha_de_funcionario[i-1].id + 1;



    numeroFICHA_DE_OPERACOES = 1;
    i = 1;


    fp=fopen("ficha_de_operacoes.txt","r");

    if(fp!=NULL)
    {
        for(;;)
        {
            if(fscanf(fp,"%d| %d| %d| %d| %d| %d| %[^|]| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %[^|]|\n", &ficha_de_operacoes[i].id, &ficha_de_operacoes[i].id_doc_int, &ficha_de_operacoes[i].id_doc_ext, &ficha_de_operacoes[i].id_posto_trabalho, &ficha_de_operacoes[i].id_componente, &ficha_de_operacoes[i].id_empresa, ficha_de_operacoes[i].tipo_op, &ficha_de_operacoes[i].saida.ano, &ficha_de_operacoes[i].saida.mes, &ficha_de_operacoes[i].saida.dia, &ficha_de_operacoes[i].chegada.ano, &ficha_de_operacoes[i].chegada.mes, &ficha_de_operacoes[i].chegada.dia, &ficha_de_operacoes[i].ETA.ano, &ficha_de_operacoes[i].ETA.mes, &ficha_de_operacoes[i].ETA.dia, &ficha_de_operacoes[i].id_funcionario, &ficha_de_operacoes[i].operacao.ano, &ficha_de_operacoes[i].operacao.mes, &ficha_de_operacoes[i].operacao.dia, &ficha_de_operacoes[i].montante, ficha_de_operacoes[i].obs)==EOF) break;
            i++;

            numeroFICHA_DE_OPERACOES++;
        }


        fclose(fp);

    }

    if(ficha_de_operacoes[1].id != 1) numeroFICHA_DE_OPERACOES = ficha_de_operacoes[i-1].id + 1;




    numeroFICHA_DE_EMPRESA = 1;
    i = 1;


    fp=fopen("ficha_de_empresa.txt","r");

    if(fp!=NULL)
    {
        for(;;)
        {
            if(fscanf(fp," %d| %[^|]| %[^|]| %[^|]| \n", &ficha_de_empresa[i].id, ficha_de_empresa[i].nome, ficha_de_empresa[i].tipo, ficha_de_empresa[i].contacto)==EOF) break;
            i++;

            numeroFICHA_DE_EMPRESA++;
        }


        fclose(fp);

    }

    if(ficha_de_empresa[1].id != 1) numeroFICHA_DE_EMPRESA = ficha_de_empresa[i-1].id + 1;


}

void menu_ficha_de_componentes()
{

    int opcao;

    do
    {

        puts("+---------------------------Menu Ficha de Componentes-------------------------+"
             "\n|                                                                             |"
             "\n|                1 - Criar Ficha de Componentes                               |"
             "\n|                 2 - Apagar Ficha de Componentes                             |"
             "\n|                  3 - Listar Ficha de Componentes                            |"
             "\n|                   4 - Alterar Ficha de Componentes                          |"
             "\n|                    5 - Pesquisar Ficha de Componentes                       |"
             "\n|                     6 - Sair                                                |"
             "\n|                                                                             |"
             "\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            criar_ficha_de_componentes ();
            break;
        case 2:
            system("cls");
            apagar_ficha_de_componentes ();
            break;
        case 3:
            system("cls");
            listar_ficha_de_componentes ();
            break;
        case 4:
            system("cls");
            alterar_ficha_de_componentes ();
            break;
        case 5:
            system("cls");
            pesquisar_ficha_de_componentes ();
            break;

        case 6:
            system("cls");
            break;
        default:
        {
            printf("\n Opcao nao existente\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }
    }
    while(opcao !=6);

}

void criar_ficha_de_componentes()
{

    int i;
    i=numeroFICHA_DE_COMPONENTES;
    ficha_de_componentes[i].id=numeroFICHA_DE_COMPONENTES;

    system("cls");
    printf("Preencher dados da Ficha de Componentes\n---------------------------------------\n");
    rewind(stdin);
    printf("\n Adicionar Designacao: ");
    rewind(stdin);
    scanf("%s", ficha_de_componentes[i].designacao);
    printf("\n Adicionar Numero de Serie: ");
    rewind(stdin);
    scanf("%s", ficha_de_componentes[i].nserie);
    printf("\n Adicionar Data de Aquisicao(aaaa/mm/dd): ");
    ficha_de_componentes[i].data=ler_data();
    //data_de_aquisicao_componentes();
    printf("\n Garantia de quantos anos ? ");
    scanf("%d",&ficha_de_componentes[i].garantia);
    //data_de_garantia_componentes();
    printf("\n Adicionar Identificacao do Fornecedor: ");
    rewind(stdin);
    scanf("%d",&ficha_de_componentes[i].id_fornecedor);
    printf("\n Adicionar Identificacao do Fabricante: ");
    rewind(stdin);
    scanf("%d",&ficha_de_componentes[i].id_fabricante);
    printf("\n Adicionar Tipo: ");
    rewind(stdin);
    scanf("%s", ficha_de_componentes[i].tipo);
    printf("\n Adicionar Condicao: ");
    rewind(stdin);
    scanf("%s", ficha_de_componentes[i].condicao);
    printf("\n Adicionar Identificacao do Posto de Trabalho: ");
    rewind(stdin);
    scanf("%d",&ficha_de_componentes[i].id_posto_trabalho);
    printf("\n Adicionar Observacoes: ");
    rewind(stdin);
    scanf("%s", ficha_de_componentes[i].obs);

    mostrar_ficha_de_componentes(i);

    FICHA_DE_COMPONENTES ficha_componentes;

    ficha_componentes=ficha_de_componentes[i];

    numeroFICHA_DE_COMPONENTES++;


    system("cls");
}

void apagar_ficha_de_componentes()
{
    int numero;
    printf("Numero da Ficha de Componentes a Apagar: ");
    scanf("%d",&numero);
    int i;

    for(i=0; i<maxFICHA_DE_COMPONENTES; i++)
    {
        if(numero==ficha_de_componentes[i].id)
        {
            int j;

            for(j=i+1; j<maxFICHA_DE_COMPONENTES; j++)

            {
                ficha_de_componentes[j-1]=ficha_de_componentes[j];
            }

            numeroFICHA_DE_COMPONENTES--;
            system("pause");
            system("cls");
        }
    }
}

void listar_ficha_de_componentes()
{

    system("cls");
    if(numeroFICHA_DE_COMPONENTES==0)
    {

        printf("\n\n Nao existem Fichas de Componentes registados na base de dados\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        for(i=1; i<numeroFICHA_DE_COMPONENTES; i++)
        {
            mostrar_ficha_de_componentes(i);
        }

    }

    system("cls");

}

void alterar_ficha_de_componentes()
{

    system("cls");
    int n_ficha_de_componentes;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Componentes: ");
        scanf("%d",&n_ficha_de_componentes);
        if(n_ficha_de_componentes<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Componentes maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_componentes<=0);
    for( i=0; i<maxFICHA_DE_COMPONENTES; i++)
    {
        if(n_ficha_de_componentes==ficha_de_componentes[i].id)
        {
            system("cls");


            int opcao;
            do
            {


                printf ("+------------------------Menu Alterar Ficha de Componentes--------------------+");;
                printf ("\n|                                                                             |");
                printf ("\n|                1 - Identificacao                                            |");
                printf ("\n|                 2 - Designacao                                              |");
                printf ("\n|                  3 - Numero de serie                                        |");
                printf ("\n|                   4 - Data de Aquisicao                                     |");
                printf ("\n|                    5 - Garantia                                             |");
                printf ("\n|                     6 - Fornecedor                                          |");
                printf ("\n|                      7 - Fabricante                                         |");
                printf ("\n|                       8 - Tipo                                              |");
                printf ("\n|                        9 - Condicao                                         |");
                printf ("\n|                         10 - Identificao do Posto de Trabalho               |");
                printf ("\n|                          11 - Observacoes                                   |");
                printf ("\n|                           12 - Sair                                         |");
                printf ("\n|                                                                             |");
                printf ("\n+.............................................................................+");

                printf ("\n Introduza a opcao: ");

                scanf ("%d",&opcao);
                switch (opcao)
                {
                case 1:
                    system("cls");
                    printf("\n Introduza nova identificacao:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].id);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduza nova designacao:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_componentes[i].designacao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n Insira novo numero de serie:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].nserie);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    printf("\n Insira nova data de aquisicao:\n");
                    rewind(stdin);
                    ficha_de_componentes[i].data=ler_data();
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    printf("\n Quantos anos de garantia ?\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].garantia);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    system("cls");
                    printf("\n Insira novo Fornecedor:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].id_fornecedor);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    system("cls");
                    printf("\n Insira novo fabricante:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].id_fabricante);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    system("cls");
                    printf("\n Insira novo tipo:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_componentes[i].tipo);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 9:
                    system("cls");
                    printf("\n Insira nova condicao:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_componentes[i].condicao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 10:
                    system("cls");
                    printf("\n Insira nova identificacao do posto de trabalho:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_componentes[i].id_posto_trabalho);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 11:
                    system("cls");
                    printf("\n Insira novas obrservacoes:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_componentes[i].obs);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 12:
                    system("cls");
                    break;
                default:
                {
                    printf("\n Opcao nao existente\n ");
                    printf("\n Tente novamente \n ");
                }
                system("pause");
                system("cls");
                break;

                }
            }
            while(opcao !=12);

        }

    }

    if(numeroFICHA_DE_COMPONENTES<n_ficha_de_componentes)
    {
        system("cls");
        printf("\n\n O numero da Ficha de Componentes que indicou nao existe\n\n");
        system("pause");
        system("cls");
    }


    system("cls");

}

void pesquisar_ficha_de_componentes()
{
    system("cls");
    int n_ficha_de_componentes;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Componentes: ");
        scanf("%d",&n_ficha_de_componentes);
        if(n_ficha_de_componentes<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Componentes maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_componentes<=0);
    for( i=0; i<maxFICHA_DE_EMPRESA; i++)
    {
        if(n_ficha_de_componentes==ficha_de_componentes[i].id)
        {
            mostrar_ficha_de_componentes(i);
        }

        if(numeroFICHA_DE_COMPONENTES<n_ficha_de_componentes)
        {
            system("cls");
            printf("\n\n O numero da Ficha de Componentes que indicou nao existe\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    system("cls");
}


void mostrar_ficha_de_componentes(int i)
{

    printf("     +-------------------------Ficha de Componentes(N:%d)----------------------+\n\n",ficha_de_componentes[i].id);
    printf("                     Identificacao:%d\n",ficha_de_componentes[i].id);
    printf("                      Designacao:%s\n",ficha_de_componentes[i].designacao);
    printf("                       Numero de serie:%s\n",ficha_de_componentes[i].nserie);
    printf("                        Data de Aquisicao(dd/mm/aaaa):%d/%d/%d\n",ficha_de_componentes[i].data.dia,ficha_de_componentes[i].data.mes,ficha_de_componentes[i].data.ano);
    printf("                         Garantia(dd/mm/aaaa):%d/%d/%d\n",ficha_de_componentes[i].data.dia,ficha_de_componentes[i].data.mes,(ficha_de_componentes[i].data.ano)+(ficha_de_componentes[i].garantia));
    printf("                          Fornecedor:%d\n",ficha_de_componentes[i].id_fornecedor);
    printf("                           Fabricante:%d\n",ficha_de_componentes[i].id_fabricante);
    printf("                            Tipo:%s\n",ficha_de_componentes[i].tipo);
    printf("                             Condicao:%s\n",ficha_de_componentes[i].condicao);
    printf("                              Identificao do Posto de Trabalho:%d\n",ficha_de_componentes[i].id_posto_trabalho);
    printf("                               Observacoes:%s\n",ficha_de_componentes[i].obs);
    printf("                                                                            \n");
    printf("     +-------------------------Ficha de Componentes(N:%d)----------------------+\n\n",ficha_de_componentes[i].id);
    system("pause");

}

/***************************************************************************************************/

void menu_ficha_de_posto_de_trabalho()
{
    int opcao;
    do
    {

        printf ("+----------------------Menu Ficha de Posto de Trabalho------------------------+");
        printf ("\n|                                                                             |");
        printf ("\n|                1 - Criar Ficha de Posto de Trabalho                         |");
        printf ("\n|                 2 - Apagar Ficha de Posto de Trabalho                       |");
        printf ("\n|                  3 - Listar Ficha de Posto de Trabalho                      |");
        printf ("\n|                   4 - Alterar Ficha de Posto de Trabalho                    |");
        printf ("\n|                    5 - Pesquisar Ficha de Posto de Trabalho                 |");
        printf ("\n|                     6 - Sair                                                |");
        printf ("\n|                                                                             |");
        printf ("\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            criar_ficha_de_posto_de_trabalho ();
            break;
        case 2:
            system("cls");
            apagar_ficha_de_posto_de_trabalho();
            break;
        case 3:
            system("cls");
            listar_ficha_de_posto_de_trabalho();
            break;
        case 4:
            system("cls");
            alterar_ficha_de_posto_de_trabalho();
            break;
        case 5:
            system("cls");
            pesquisar_ficha_de_posto_de_trabalho();
            break;

        case 6:
            system("cls");
            break;
        default:
        {
            printf("\n Opcao nao existente\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }
    }
    while(opcao !=6);
}

void criar_ficha_de_posto_de_trabalho()
{

    int i;
    i=numeroFICHA_DE_POSTO_DE_TRABALHO;
    ficha_de_posto_de_trabalho[i].id=numeroFICHA_DE_POSTO_DE_TRABALHO;

    system("cls");
    printf("Preencher dados da Ficha de Posto de Trabalho\n---------------------------------------------\n");
    rewind(stdin);
    printf("\n Adicionar Nome: ");
    rewind(stdin);
    scanf("%s", ficha_de_posto_de_trabalho[i].nome);
    printf("\n Adicionar Local: ");
    rewind(stdin);
    scanf("%s", ficha_de_posto_de_trabalho[i].local);
    printf("\n Adicionar Seccao: ");
    rewind(stdin);
    scanf("%s", ficha_de_posto_de_trabalho[i].seccao);
    printf("\n Adicionar Descricao: ");
    rewind(stdin);
    scanf("%s", ficha_de_posto_de_trabalho[i].descricao);
    printf("\n Adicionar Identificacao do Funcionario: ");
    rewind(stdin);
    scanf("%d",&ficha_de_posto_de_trabalho[i].id_funcionario);

    mostrar_ficha_de_posto_de_trabalho(i);

    FICHA_DE_POSTO_DE_TRABALHO ficha_posto_trabalho;

    ficha_posto_trabalho=ficha_de_posto_de_trabalho[i];

    numeroFICHA_DE_POSTO_DE_TRABALHO++;


    system("cls");
}

void apagar_ficha_de_posto_de_trabalho()
{
    int numero;
    printf("Numero da Ficha de Posto de Trabalho a Apagar: ");
    scanf("%d",&numero);
    int i;
    for(i=0; i<maxFICHA_DE_POSTO_DE_TRABALHO; i++)
    {
        if(numero==ficha_de_posto_de_trabalho[i].id)
        {
            int j;

            for(j=i+1; j<maxFICHA_DE_POSTO_DE_TRABALHO; j++)
            {
                ficha_de_posto_de_trabalho[j-1]=ficha_de_posto_de_trabalho[j];
            }

            numeroFICHA_DE_POSTO_DE_TRABALHO--;
            system("pause");
            system("cls");
        }

    }

}

void listar_ficha_de_posto_de_trabalho()
{

    system("cls");
    if(numeroFICHA_DE_POSTO_DE_TRABALHO==0)
    {

        printf("\n\n Nao existem Fichas de Postos de Trabalho registados na base de dados\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        for(i=1; i<numeroFICHA_DE_POSTO_DE_TRABALHO; i++)
        {
            mostrar_ficha_de_posto_de_trabalho(i);
        }

    }

    system("cls");

}

void alterar_ficha_de_posto_de_trabalho()
{

    system("cls");
    int n_ficha_de_posto_de_trabalho;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Posto de Trabalho: ");
        scanf("%d",&n_ficha_de_posto_de_trabalho);
        if(n_ficha_de_posto_de_trabalho<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Posto de Trabalho maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_posto_de_trabalho<=0);
    for( i=0; i<maxFICHA_DE_POSTO_DE_TRABALHO; i++)
    {
        if(n_ficha_de_posto_de_trabalho==ficha_de_posto_de_trabalho[i].id)
        {
            system("cls");


            int opcao;
            do
            {


                printf ("+--------------------Menu Alterar Ficha de Posto de Trabalho-------------------+");
                printf ("\n|                                                                             |");
                printf ("\n|                1 - Nome                                                     |");
                printf ("\n|                 2 - Local                                                   |");
                printf ("\n|                  3 - Seccao                                                 |");
                printf ("\n|                   4 - Descricao                                             |");
                printf ("\n|                    5 - Identificao do funcionario                           |");
                printf ("\n|                     6 - Sair                                                |");
                printf ("\n|                                                                             |");
                printf ("\n+.............................................................................+");

                printf ("\n Introduza a opcao: ");

                scanf ("%d",&opcao);
                switch (opcao)
                {
                case 1:
                    system("cls");
                    printf("\n Introduza novo nome:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_posto_de_trabalho[i].nome);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduza novo local:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_posto_de_trabalho[i].local);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n Insira nova seccao:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_posto_de_trabalho[i].seccao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    printf("\n Insira nova descricao:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_posto_de_trabalho[i].descricao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    printf("\n Insira nova identificao de funcionario:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_posto_de_trabalho[i].id_funcionario);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    system("cls");
                    break;
                default:
                {
                    printf("\n Opcao nao existente\n ");
                    printf("\n Tente novamente \n ");
                }
                system("pause");
                system("cls");
                break;

                }
            }
            while(opcao !=6);

        }

    }

    if(numeroFICHA_DE_POSTO_DE_TRABALHO<n_ficha_de_posto_de_trabalho)
    {
        system("cls");
        printf("\n\n O numero da Ficha do Posto de Trabalho que indicou nao existe\n\n");
        system("pause");
        system("cls");
    }


    system("cls");

}

void pesquisar_ficha_de_posto_de_trabalho()
{
    system("cls");
    int n_ficha_de_posto_de_trabalho;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha do Posto de Trabalho: ");
        scanf("%d",&n_ficha_de_posto_de_trabalho);
        if(n_ficha_de_posto_de_trabalho<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha do Posto de Trabalho maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_posto_de_trabalho<=0);
    for( i=0; i<maxFICHA_DE_POSTO_DE_TRABALHO; i++)
    {
        if(n_ficha_de_posto_de_trabalho==ficha_de_posto_de_trabalho[i].id)
        {
            mostrar_ficha_de_posto_de_trabalho(i);
        }

        if(numeroFICHA_DE_POSTO_DE_TRABALHO<n_ficha_de_posto_de_trabalho)
        {
            system("cls");
            printf("\n\n O numero da Ficha de Componentes que indicou nao existe\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    system("cls");
}

void mostrar_ficha_de_posto_de_trabalho(int i)
{
    printf("     +--------------------Ficha de Posto de Trabalho(N:%d)-----------------+\n\n",ficha_de_posto_de_trabalho[i].id);
    printf("                     Identificacao:%d\n",ficha_de_posto_de_trabalho[i].id);
    printf("                      Nome:%s\n",ficha_de_posto_de_trabalho[i].nome);
    printf("                       Local:%s\n",ficha_de_posto_de_trabalho[i].local);
    printf("                        Seccao:%s\n",ficha_de_posto_de_trabalho[i].seccao);
    printf("                         Descricao:%s\n",ficha_de_posto_de_trabalho[i].descricao);
    printf("                          Identificao do Funcionario:%d",ficha_de_posto_de_trabalho[i].id_funcionario);
    printf("                                                                            \n");
    printf("     +--------------------Ficha de Posto de Trabalho(N:%d)-----------------+\n\n",ficha_de_posto_de_trabalho[i].id);
    system("pause");

}

/***************************************************************************************************/

void menu_ficha_de_funcionarios()
{

    int opcao;

    do
    {

        printf ("+---------------------------Menu Ficha de Funcionario-------------------------+");
        printf ("\n|                                                                             |");
        printf ("\n|                1 - Criar Ficha de Funcionarios                              |");
        printf ("\n|                 2 - Apagar Ficha de Funcionarios                            |");
        printf ("\n|                  3 - Listar Ficha de Funcionarios                           |");
        printf ("\n|                   4 - Alterar Ficha de Funcionarios                         |");
        printf ("\n|                    5 - Pesquisar Ficha de Funcionarios                      |");
        printf ("\n|                     6 - Sair                                                |");
        printf ("\n|                                                                             |");
        printf ("\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            criar_ficha_de_funcionario();
            break;
        case 2:
            system("cls");
            apagar_ficha_de_funcionario();
            break;
        case 3:
            system("cls");
            listar_ficha_de_funcionarios();
            break;
        case 4:
            system("cls");
            alterar_ficha_de_funcionario();
            break;
        case 5:
            system("cls");
            pesquisar_ficha_de_funcionario();
            break;

        case 6:
            system("cls");
            break;
        default:
        {
            printf("\n Opcao nao existente\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }
    }
    while(opcao !=6);

}

void criar_ficha_de_funcionario()
{

    int i;
    i=numeroFICHA_DE_FUNCIONARIO;
    ficha_de_funcionario[i].id=numeroFICHA_DE_FUNCIONARIO;

    system("cls");
    printf("Preencher dados da Ficha de Funcionario\n-------------------------\n");
    rewind(stdin);
    printf("\n Adicionar Nome: ");
    rewind(stdin);
    scanf("%s",ficha_de_funcionario[i].nome);
    printf("\n Adicionar Funcao: ");
    rewind(stdin);
    scanf("%s",ficha_de_funcionario[i].funcao);
    printf("\n Adicionar Descricao: ");
    scanf("%s",ficha_de_funcionario[i].descricao);

    mostrar_ficha_de_funcionario(i);

    FICHA_DE_FUNCIONARIO ficha_funcionario;

    ficha_funcionario=ficha_de_funcionario[i];


    numeroFICHA_DE_FUNCIONARIO++;



    system("cls");
}

void apagar_ficha_de_funcionario()
{
    int numero;
    printf("Numero da Ficha de Funcionario a Apagar: ");
    scanf("%d",&numero);
    int i;
    for(i=0; i<maxFICHA_DE_FUNCIONARIO; i++)
    {
        if(numero==ficha_de_funcionario[i].id)
        {
            int j;

            for(j=i+1; j<maxFICHA_DE_FUNCIONARIO; j++)
            {
                ficha_de_funcionario[j-1]=ficha_de_funcionario[j];
            }

            numeroFICHA_DE_FUNCIONARIO--;
            system("pause");
            system("cls");
        }

    }

}

void listar_ficha_de_funcionarios()
{

    system("cls");
    if(numeroFICHA_DE_FUNCIONARIO==0)
    {

        printf("\n\n Nao existem Fichas de Funcionarios registados na base de dados\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        for(i=1; i<numeroFICHA_DE_FUNCIONARIO; i++)
        {
            mostrar_ficha_de_funcionario(i);
        }

    }

    system("cls");

}

void alterar_ficha_de_funcionario()
{

    system("cls");
    int n_ficha_de_funcionarios;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Funcionario: ");
        scanf("%d",&n_ficha_de_funcionarios);
        if(n_ficha_de_funcionarios<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Funcionario maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_funcionarios<=0);
    for( i=0; i<maxFICHA_DE_FUNCIONARIO; i++)
    {
        if(n_ficha_de_funcionarios==ficha_de_funcionario[i].id)
        {
            system("cls");


            int opcao;
            do
            {


                printf ("+------------------------Menu Alterar Ficha de Funcionario--------------------+");;
                printf ("\n|                                                                             |");
                printf ("\n|                1 - Nome                                                     |");
                printf ("\n|                 2 - Funcao                                                  |");
                printf ("\n|                  3 - Descricao                                              |");
                printf ("\n|                   4 - Sair                                                  |");
                printf ("\n|                                                                             |");
                printf ("\n+.............................................................................+");

                printf ("\n Introduza a opcao: ");

                scanf ("%d",&opcao);
                switch (opcao)
                {
                case 1:
                    system("cls");
                    printf("\n Introduza novo nome:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_funcionario[i].nome);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduza nova funcao:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_funcionario[i].funcao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n Insira nova descricao:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_funcionario[i].descricao);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    break;
                default:
                {
                    printf("\n Opcao nao existente\n ");
                    printf("\n Tente novamente \n ");
                }
                system("pause");
                system("cls");
                break;

                }
            }
            while(opcao !=4);

        }

    }

    if(numeroFICHA_DE_FUNCIONARIO<n_ficha_de_funcionarios)
    {
        system("cls");
        printf("\n\n O numero da Ficha de Funcionario que indicou nao existe\n\n");
        system("pause");
        system("cls");
    }


    system("cls");

}

void pesquisar_ficha_de_funcionario()
{
    system("cls");
    int n_ficha_de_funcionario;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Funcionarios: ");
        scanf("%d",&n_ficha_de_funcionario);
        if(n_ficha_de_funcionario<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Funcionario maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_funcionario<=0);
    for( i=0; i<maxFICHA_DE_FUNCIONARIO; i++)
    {
        if(n_ficha_de_funcionario==ficha_de_funcionario[i].id)
        {
            mostrar_ficha_de_funcionario(i);
        }

        if(numeroFICHA_DE_FUNCIONARIO<n_ficha_de_funcionario)
        {
            system("cls");
            printf("\n\n O numero da Ficha de Funcionario que indicou nao existe\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    system("cls");
}

void mostrar_ficha_de_funcionario(int i)
{

    printf("     +-------------------------Ficha de Funcionario(N:%d)----------------------+\n\n",ficha_de_funcionario[i].id);
    printf("                     Identificacao:%d\n",ficha_de_funcionario[i].id);
    printf("                      Nome:%s\n",ficha_de_funcionario[i].nome);
    printf("                       Funcao:%s\n",ficha_de_funcionario[i].funcao);
    printf("                        Descricao:%s\n",ficha_de_funcionario[i].descricao);
    printf("                                                                            \n");
    printf("     +-------------------------Ficha de Funcionario(N:%d)----------------------+\n\n",ficha_de_funcionario[i].id);
    system("pause");

}

/***************************************************************************************************/

void menu_ficha_de_operacoes()
{

    int opcao;

    do
    {

        printf ("+----------------------------Menu Ficha de Operacoes--------------------------+");
        printf ("\n|                                                                             |");
        printf ("\n|                1 - Criar Ficha de Operacoes                                 |");
        printf ("\n|                 2 - Apagar Ficha de Operacoes                               |");
        printf ("\n|                  3 - Listar Ficha de Operacoes                              |");
        printf ("\n|                   4 - Alterar Ficha de Operacoes                            |");
        printf ("\n|                    5 - Pesquisar Ficha de Operacoes                         |");
        printf ("\n|                     6 - Sair                                                |");
        printf ("\n|                                                                             |");
        printf ("\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            criar_ficha_de_operacoes();
            break;
        case 2:
            system("cls");
            apagar_ficha_de_operacoes();
            break;
        case 3:
            system("cls");
            listar_ficha_de_operacoes();
            break;
        case 4:
            system("cls");
            alterar_ficha_de_operacoes();
            break;
        case 5:
            system("cls");
            pesquisar_ficha_de_operacoes();
            break;

        case 6:
            system("cls");
            break;
        default:
        {
            printf("\n Opcao nao existente\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }
    }
    while(opcao !=6);

}

void criar_ficha_de_operacoes()
{

    int i;
    i=numeroFICHA_DE_OPERACOES;
    ficha_de_operacoes[i].id=numeroFICHA_DE_OPERACOES;

    system("cls");
    printf("Preencher dados da Ficha de Operacoes\n-------------------------\n");
    rewind(stdin);
    printf("\n Adicionar Numero do Documento Interno: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_doc_int);
    printf("\n Adicionar Numero do Documento Externo: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_doc_ext);
    printf("\n Adicionar Identificao do Posto de Trabalho: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_posto_trabalho);
    printf("\n Adicionar Identificao do Componente: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_componente);
    printf("\n Adicionar Identificacao da Empresa: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_empresa);
    printf("\n Adicionar Tipo de Operacao: ");
    rewind(stdin);
    scanf("%s",ficha_de_operacoes[i].tipo_op);
    printf("\n Adicionar Data de Saida: ");
    rewind(stdin);
    ficha_de_operacoes[i].saida=ler_data();
    printf("\n Adicionar Data de Chegada: ");
    rewind(stdin);
    ficha_de_operacoes[i].chegada=ler_data();
    printf("\n Adicionar Data Prevista de Chegada: ");
    rewind(stdin);
    ficha_de_operacoes[i].ETA=ler_data();
    printf("\n Adicionar Identificao do Funcionario: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].id_funcionario);
    printf("\n Adicionar Data da Operacao: ");
    rewind(stdin);
    ficha_de_operacoes[i].operacao=ler_data();
    printf("\n Adicionar Montante: ");
    rewind(stdin);
    scanf("%d",&ficha_de_operacoes[i].montante);
    printf("\n Adicionar Observacoes: ");
    rewind(stdin);
    scanf("%s",ficha_de_operacoes[i].obs);

    mostrar_ficha_de_operacoes(i);

    FICHA_DE_OPERACOES ficha_operacoes;

    ficha_operacoes=ficha_de_operacoes[i];
    numeroFICHA_DE_OPERACOES++;


    system("cls");
}

void apagar_ficha_de_operacoes()
{
    int numero;
    printf("Numero da Ficha de Operacao a Apagar: ");
    scanf("%d",&numero);
    int i;
    for(i=0; i<maxFICHA_DE_OPERACOES; i++)
    {
        if(numero==ficha_de_operacoes[i].id)
        {
            int j;

            for(j=i+1; j<maxFICHA_DE_OPERACOES; j++)
            {
                ficha_de_operacoes[j-1]=ficha_de_operacoes[j];
            }

            numeroFICHA_DE_OPERACOES--;
            system("pause");
            system("cls");
        }

    }

}

void listar_ficha_de_operacoes()
{

    system("cls");
    if(numeroFICHA_DE_OPERACOES==0)
    {

        printf("\n\n Nao existem Fichas de Operacoes registados na base de dados\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        for(i=1; i<numeroFICHA_DE_OPERACOES; i++)
        {
            mostrar_ficha_de_operacoes(i);
        }

    }

    system("cls");

}

void alterar_ficha_de_operacoes()
{

    system("cls");
    int n_ficha_de_operacoes;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Operacoes: ");
        scanf("%d",&n_ficha_de_operacoes);
        if(n_ficha_de_operacoes<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Operacoes maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_operacoes<=0);
    for( i=0; i<maxFICHA_DE_OPERACOES; i++)
    {
        if(n_ficha_de_operacoes==ficha_de_operacoes[i].id)
        {
            system("cls");


            int opcao;
            do
            {


                printf ("+-------------------------Menu Alterar Ficha de Operacoes---------------------+");;
                printf ("\n|                                                                             |");
                printf ("\n|                1 - Numero do Documento Interno                              |");
                printf ("\n|                 2 - Numero do Documento Externo                             |");
                printf ("\n|                  3 - Identificao do Posto de Trabalho                       |");
                printf ("\n|                   4 - Identificao do Componente                             |");
                printf ("\n|                    5 - Identificacao da Empresa                             |");
                printf ("\n|                     6 - Tipo de Operacao                                    |");
                printf ("\n|                      7 - Data de Saida                                      |");
                printf ("\n|                       8 - Data de Chegada                                   |");
                printf ("\n|                        9 - Data Prevista de Chegada                         |");
                printf ("\n|                         10 - Identificao do Funcionario                     |");
                printf ("\n|                          11 - Data da Operacao                              |");
                printf ("\n|                           12 - Montante                                     |");
                printf ("\n|                            13 - Observacoes                                 |");
                printf ("\n|                             14 - Sair                                       |");
                printf ("\n|                                                                             |");
                printf ("\n+.............................................................................+");

                printf ("\n Introduza a opcao: ");

                scanf ("%d",&opcao);
                switch (opcao)
                {
                case 1:
                    system("cls");
                    printf("\n Introduza novo numero do documento interno:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_doc_int);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduza novo numero do documento externo:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_doc_ext);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n Insira nova identificao do posto de trabalho:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_posto_trabalho);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    printf("\n Insira nova identificao do componente:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_componente);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    printf("\n Insira nova identificao da empresa:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_empresa);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    system("cls");
                    printf("\n Insira novo tipo de operacao:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_operacoes[i].tipo_op);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    system("cls");
                    printf("\n Insira nova data de saida:\n");
                    rewind(stdin);
                    ficha_de_operacoes[i].saida=ler_data();
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    system("cls");
                    printf("\n Insira nova data de chegada:\n");
                    rewind(stdin);
                    ficha_de_operacoes[i].chegada=ler_data();
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 9:
                    system("cls");
                    printf("\n Insira nova data prevista de chegada:\n");
                    rewind(stdin);
                    ficha_de_operacoes[i].ETA=ler_data();
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 10:
                    system("cls");
                    printf("\n Insira nova identificao do funcionario:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].id_funcionario);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 11:
                    system("cls");
                    printf("\n Insira nova data da operacao:\n");
                    rewind(stdin);
                    ficha_de_operacoes[i].operacao=ler_data();
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 12:
                    system("cls");
                    printf("\n Insira novo montante:\n");
                    rewind(stdin);
                    scanf("%d",&ficha_de_operacoes[i].montante);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 13:
                    system("cls");
                    printf("\n Insira novas observacoes:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_componentes[i].obs);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 14:
                    system("cls");
                    break;
                default:
                {
                    printf("\n Opcao nao existente\n ");
                    printf("\n Tente novamente \n ");
                }
                system("pause");
                system("cls");
                break;

                }
            }
            while(opcao !=14);

        }

    }

    if(numeroFICHA_DE_OPERACOES<n_ficha_de_operacoes)
    {
        system("cls");
        printf("\n\n O numero da Ficha de Operacoes que indicou nao existe\n\n");
        system("pause");
        system("cls");
    }


    system("cls");

}

void pesquisar_ficha_de_operacoes()
{
    system("cls");
    int n_ficha_de_operacoes;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Operacoes: ");
        scanf("%d",&n_ficha_de_operacoes);
        if(n_ficha_de_operacoes<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Operacoes maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_operacoes<=0);
    for( i=0; i<maxFICHA_DE_OPERACOES; i++)
    {
        if(n_ficha_de_operacoes==ficha_de_operacoes[i].id)
        {
            mostrar_ficha_de_operacoes(i);
        }

        if(numeroFICHA_DE_OPERACOES<n_ficha_de_operacoes)
        {
            system("cls");
            printf("\n\n O numero da Ficha de Operacoes que indicou nao existe\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    system("cls");
}

void mostrar_ficha_de_operacoes(int i)
{

    printf("     +-------------------------Ficha de Operacoes(N:%d)----------------------+\n\n",ficha_de_operacoes[i].id);
    printf("                     Identificacao:%d\n",ficha_de_operacoes[i].id);
    printf("                      Numero do Documento Interno:%d\n",ficha_de_operacoes[i].id_doc_int);
    printf("                       Numero do Documento Externo:%d\n",ficha_de_operacoes[i].id_doc_ext);
    printf("                        Identificao do Posto de Trabalho:%d\n",ficha_de_operacoes[i].id_posto_trabalho);
    printf("                         Identificao do Componente:%d\n",ficha_de_operacoes[i].id_componente);
    printf("                          Identificacao da Empresa:%d\n",ficha_de_operacoes[i].id_empresa);
    printf("                           Tipo de Operacao:%s\n",ficha_de_operacoes[i].tipo_op);
    printf("                            Data de Saida:%d/%d/%d\n",ficha_de_operacoes[i].saida.dia,ficha_de_operacoes[i].saida.mes,ficha_de_operacoes[i].saida.ano);
    printf("                             Data de Chegada:%d/%d/%d\n",ficha_de_operacoes[i].chegada.dia,ficha_de_operacoes[i].chegada.mes,ficha_de_operacoes[i].chegada.ano);
    printf("                              Data Prevista de Chegada:%d/%d/%d\n",ficha_de_operacoes[i].ETA.dia,ficha_de_operacoes[i].ETA.mes,ficha_de_operacoes[i].ETA.ano);
    printf("                               Identificao do Funcionario:%d\n",ficha_de_operacoes[i].id_funcionario);
    printf("                                Data da Operacao:%d/%d/%d\n",ficha_de_operacoes[i].operacao.dia,ficha_de_operacoes[i].operacao.mes,ficha_de_operacoes[i].operacao.ano);
    printf("                                 Montante:%d\n",ficha_de_operacoes[i].montante);
    printf("                                  Observacoes:%s\n",ficha_de_operacoes[i].obs);
    printf("                                                                            \n");
    printf("     +-------------------------Ficha de Operacoes(N:%d)----------------------+\n\n",ficha_de_operacoes[i].id);
    system("pause");

}

/***************************************************************************************************/

void menu_ficha_de_empresa()
{

    int opcao;

    do
    {

        printf ("+-----------------------------Menu Ficha de Empresa---------------------------+");
        printf ("\n|                                                                             |");
        printf ("\n|                1 - Criar Ficha de Empresa                                   |");
        printf ("\n|                 2 - Apagar Ficha de Empresa                                 |");
        printf ("\n|                  3 - Listar Ficha de Empresa                                |");
        printf ("\n|                   4 - Alterar Ficha de Empresa                              |");
        printf ("\n|                    5 - Pesquisar Ficha de Empresa                           |");
        printf ("\n|                     6 - Sair                                                |");
        printf ("\n|                                                                             |");
        printf ("\n+.............................................................................+");

        printf ("\n Introduza a opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            criar_ficha_de_empresa();
            break;
        case 2:
            system("cls");
            apagar_ficha_de_empresa();
            break;
        case 3:
            system("cls");
            listar_ficha_de_empresa();
            break;
        case 4:
            system("cls");
            alterar_ficha_de_empresa();
            break;
        case 5:
            system("cls");
            pesquisar_ficha_de_empresa();
            break;

        case 6:
            system("cls");
            break;
        default:
        {
            printf("\n Opcao nao existente\n ");
            printf("\n Tente novamente \n ");
        }
        system("pause");
        system("cls");
        break;

        }
    }
    while(opcao !=6);

}

void criar_ficha_de_empresa()
{

    int i;
    i=numeroFICHA_DE_EMPRESA;
    ficha_de_empresa[i].id=numeroFICHA_DE_EMPRESA;

    system("cls");
    printf("Preencher dados da Ficha de Empresa\n-----------------------------------\n");
    rewind(stdin);
    printf("\n Adicionar Nome: ");
    rewind(stdin);
    scanf("%s",ficha_de_empresa[i].nome);
    printf("\n Adicionar Tipo: ");
    rewind(stdin);
    scanf("%s",ficha_de_empresa[i].tipo);
    printf("\n Adicionar Contacto: ");
    scanf("%s", ficha_de_empresa[i].contacto);

    mostrar_ficha_de_empresa(i);

    FICHA_DE_EMPRESA ficha_empresa;

    ficha_empresa=ficha_de_empresa[i];

    numeroFICHA_DE_EMPRESA++;


    system("cls");
}

void apagar_ficha_de_empresa()
{
    int numero;
    printf("Numero da Ficha de Empresa a Apagar: ");
    scanf("%d",&numero);
    int i;

    for(i=0; i<maxFICHA_DE_EMPRESA; i++)
    {
        if(numero==ficha_de_empresa[i].id)
        {
            int j;

            for(j=i+1; j<maxFICHA_DE_EMPRESA; j++)

            {
                ficha_de_empresa[j-1]=ficha_de_empresa[j];
            }

            numeroFICHA_DE_EMPRESA--;
            system("pause");
            system("cls");
        }
    }
}

void listar_ficha_de_empresa()
{

    system("cls");
    if(numeroFICHA_DE_EMPRESA==0)
    {

        printf("\n\n Nao existem Fichas de Empresas registadas na base de dados\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        for(i=1; i<numeroFICHA_DE_EMPRESA; i++)
        {
            mostrar_ficha_de_empresa(i);
        }

    }

    system("cls");

}

void alterar_ficha_de_empresa()
{

    system("cls");
    int n_ficha_de_empresa;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Empresa: ");
        scanf("%d",&n_ficha_de_empresa);
        if(n_ficha_de_empresa<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Empresa maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_empresa<=0);
    for( i=0; i<maxFICHA_DE_EMPRESA; i++)
    {
        if(n_ficha_de_empresa==ficha_de_empresa[i].id)
        {
            system("cls");


            int opcao;
            do
            {


                printf ("+-------------------------Menu Alterar Ficha de Empresa-----------------------+");
                printf ("\n|                                                                             |");
                printf ("\n|                1 - Nome                                                     |");
                printf ("\n|                 2 - Tipo                                                    |");
                printf ("\n|                  3 - Contacto                                               |");
                printf ("\n|                   4 - Sair                                                  |");
                printf ("\n|                                                                             |");
                printf ("\n+.............................................................................+");

                printf ("\n Introduza a opcao: ");

                scanf ("%d",&opcao);
                switch (opcao)
                {
                case 1:
                    system("cls");
                    printf("\n Introduza novo nome:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_empresa[i].nome);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduza novo tipo:\n");
                    rewind(stdin);
                    scanf("%s", ficha_de_empresa[i].tipo);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n Introduza novo contacto:\n");
                    rewind(stdin);
                    scanf("%s",ficha_de_empresa[i].contacto);
                    printf("\n\n\t Os seus dados foram alterados com sucesso\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    break;
                default:
                {
                    printf("\n Opcao nao existente\n ");
                    printf("\n Tente novamente \n ");
                }
                system("pause");
                system("cls");
                break;

                }
            }
            while(opcao !=4);

        }

    }

    if(numeroFICHA_DE_EMPRESA<n_ficha_de_empresa)
    {
        system("cls");
        printf("\n\n O numero da Ficha de Empresa que indicou nao existe\n\n");
        system("pause");
        system("cls");
    }


    system("cls");

}

void pesquisar_ficha_de_empresa()
{
    system("cls");
    int n_ficha_de_empresa;
    int i;

    do
    {
        printf("\nIntroduza o numero da Ficha de Empresa: ");
        scanf("%d",&n_ficha_de_empresa);
        if(n_ficha_de_empresa<=0)
        {
            system("cls");
            printf("\n\n Introduza o numero da Ficha de Empresa maior que 0\n\n ");
            system("pause");
            system("cls");
        }
    }
    while(n_ficha_de_empresa<=0);
    for( i=0; i<maxFICHA_DE_EMPRESA; i++)
    {
        if(n_ficha_de_empresa==ficha_de_empresa[i].id)
        {
            mostrar_ficha_de_empresa(i);
        }

        if(numeroFICHA_DE_EMPRESA<n_ficha_de_empresa)
        {
            system("cls");
            printf("\n\n O numero da Ficha de Empresa que indicou nao existe\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    system("cls");
}

void mostrar_ficha_de_empresa(int i)
{

    printf("     +-------------------------Ficha de Empresa(N:%d)----------------------+\n\n",ficha_de_empresa[i].id);
    printf("                     Identificacao:%d\n",ficha_de_empresa[i].id);
    printf("                      Nome:%s\n",ficha_de_empresa[i].nome);
    printf("                       Tipo:%s\n",ficha_de_empresa[i].tipo);
    printf("                        Contacto:%s\n",ficha_de_empresa[i].contacto);
    printf("                                                                            \n");
    printf("     +-------------------------Ficha de Empresa(N:%d)----------------------+\n\n",ficha_de_empresa[i].id);
    system("pause");

}

/***************************************************************************************************/
