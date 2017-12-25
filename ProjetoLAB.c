//INICIO DA PARTE DE ALINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


//PONTEIROS PARA OS ARQUIVOS
FILE *fp, *fs;

typedef struct
{
    char nomeLivro[31], nomeAutor[31], area[31];
    int codLivro, qtda, numero;
} LIVROS;

typedef struct
{
    char nomeAluno[31], matricula[15], cpf[19];
} ALUNOS;

typedef struct
{
    char aluno[31], livro[31], mat[15], dataAtual[15], dataDevolucao[15];
    int cod;
} EMPRESTIMOS;

COORD coord = {0, 0};
COORD max_res,cursor_size;

void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//INICIO DO CODIGO PARA OS MENUS
//INICIO DA PARTE DE VINICIUS
//FEITO POR VINICIUS E EDITADO POR ALINE
void linhaSuperior()
{
    int i;
    gotoxy(34,4);
    printf("%c", 201);
    for(i=35; i<85; i++)
    {
        gotoxy(i,4);
        printf("%c", 205);
    }
    gotoxy(85,4);
    printf("%c", 187);
}

void linhaInferior()
{
    int i;
    gotoxy(34,19);
    printf("%c", 200);
    for(i=35; i<85; i++)
    {
        gotoxy(i,19);
        printf("%c", 205);
    }
    gotoxy(85,19);
    printf("%c", 188);
}

void linhaMeio()
{
    int i;
    for(i=35; i<85; i++)
    {
        gotoxy(i,6);
        printf("%c", 205);
    }
}

void linhaLateral()
{
    int i;
    for(i=5; i<20; i++)
    {
        gotoxy(34,i);
        printf("%c", 186);
        gotoxy(85,i);
        printf("%c\n", 186);
    }
}//FIM DO CODIGO DOS MENUS

//TELA DE CARREGAMENTO
void inicio()
{
    int i;
    gotoxy(45,3);
    printf("CARREGANDO POR FAVOR AGUARDE...");
    for(i=0; i<104; i++)
    {
        Sleep(1);
        gotoxy(i,4);
        printf("%c", 219);
    }
}//FIM DA PARTE DE VINICIUS
//TELA DE CARREGAMENTO DO FIM
void fim()
{
    int i;
    gotoxy(45,3);
    printf("ENCERRANDO...");
    for(i=0; i<104; i++)
    {
        Sleep(1);
        gotoxy(i,4);
        printf("%c", 219);
    }
}

/*  Trecho adaptado do código de Paulo Marcos Trentin
    Disponível em <https://www.vivaolinux.com.br/script/Funcao-em-C-retorna-a-data-do-sistema-ja-formatada>
    acessado em 24/12/2017*/

char *formatacao(int num)
{
    char *retorno, ret[30];
    int i;

    if (num < 10)
    {
        sprintf(ret,"0%d",num);
        retorno = ret;
        return retorno;
    }
    else
    {
        sprintf(ret,"%d",num);
        retorno = ret;
        return retorno;
    }
}

char *data(void)
{

    int dia,mes,ano;
    char num1[6], num2[6], num3[6], num4[15], *dataEmp;

    struct tm *local;

    time_t t;

    t = time(NULL);
    local = localtime(&t);
    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    ano = local -> tm_year + 1900;

    sprintf(num1,"%s",formatacao(dia));
    sprintf(num2,"%s",formatacao(mes));
    sprintf(num3,"%s",formatacao(ano));


    sprintf(num4,"%s/%s/%s",num1,num2,num3);

    dataEmp = num4;
    return dataEmp;
} //FIM DO TRECHO ADAPTADO

//FUNCAO QUE CONFIGURA A DATA DE DEVOLUCAO DOS EMPRESTIMOS
char *dataDevolucao(void)
{

    int dia,mes,ano;
    char num1[6], num2[6], num3[6], num4[15], *dataEmp;

    struct tm *local;

    time_t t;

    t = time(NULL);
    local = localtime(&t);

    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    ano = local -> tm_year + 1900;

    dia = dia + 10;

    if(mes == 2)
    {
        if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
        {
            if(dia>29)
            {

                dia = dia - 29;
                mes++;
            }
        }
        else
        {
            if(dia>28)
            {
                dia = dia - 28;
                mes++;
            }
        }
    }
    else if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia > 31)
    {
        dia = dia - 31;
        mes++;
    }
    else if(dia > 30)
    {
        dia = dia - 30;
        mes++;
    }

    if (mes > 12)
    {
        mes = mes - 12;
        ano++;
    }

    sprintf(num1,"%s",formatacao(dia));
    sprintf(num2,"%s",formatacao(mes));
    sprintf(num3,"%s",formatacao(ano));

    sprintf(num4,"%s/%s/%s",num1,num2,num3);

    dataEmp = num4;
    return dataEmp;
}
//FUNCAO DOS MENUS
void menuPrincipal ()
{
    system("cls");
    linhaSuperior();
    gotoxy(52,5);
    printf("MENU PRINCIPAL");
    linhaMeio();
    linhaLateral();
    gotoxy(36,9);
    printf("1. ACERVO");
    gotoxy(36,11);
    printf("2. ALUNOS");
    gotoxy(36,13);
    printf("3. EMPRESTIMOS");
    gotoxy(36,15);
    printf("4. SAIR");
    linhaInferior();
    gotoxy(34,20);
    printf("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,21);
}

void menuAcervo ()
{
    system("cls");
    linhaSuperior();
    gotoxy(52,5);
    printf("ACERVO");
    linhaMeio();
    linhaLateral();
    gotoxy(36,8);
    printf("1. CADASTRAR LIVRO");
    gotoxy(36,10);
    printf("2. EDITAR LIVRO");
    gotoxy(36,12);
    printf("3. REMOVER LIVRO");
    gotoxy(36,14);
    printf("4. LISTAR LIVROS CADASTRADOS");
    gotoxy(36,16);
    printf("5. VOLTAR PARA O MENU PRINCIPAL");
    linhaInferior();
    gotoxy(36,20);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,21);
}

void menuAluno ()
{
    system("cls");
    linhaSuperior();
    gotoxy(52,5);
    printf("ALUNOS");
    linhaMeio();
    linhaLateral();
    gotoxy(36,8);
    printf("1. CADASTRAR ALUNO");
    gotoxy(36,10);
    printf("2. EDITAR ALUNO");
    gotoxy(36,12);
    printf("3. REMOVER ALUNO");
    gotoxy(36,14);
    printf("4. LISTAR ALUNOS CADASTRADOS");
    gotoxy(36,16);
    printf("5. VOLTAR PARA O MENU PRINCIPAL");
    linhaInferior();
    gotoxy(34,20);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,21);
}

void menuEmprestimo ()
{
    system("cls");
    linhaSuperior();
    gotoxy(52,5);
    printf("EMPRESTIMOS");
    linhaMeio();
    linhaLateral();
    gotoxy(36,9);
    printf("1. NOVO EMPRESTIMO");
    gotoxy(36,11);
    printf("2. CONFIRMAR DEVOLUCAO");
    gotoxy(36,13);
    printf("3. LISTAR EMPRESTIMOS");
    gotoxy(36,15);
    printf("4. VOLTAR PARA O MENU PRINCIPAL");
    linhaInferior();
    gotoxy(34,20);
    printf("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,21);
}

void menuListaEmprestimo ()
{
    system("cls");
    linhaSuperior();
    linhaLateral();
    gotoxy(52,5);
    printf("LISTAR EMPRESTIMOS");
    linhaMeio();
    gotoxy(36,9);
    printf("1. LISTAR TODOS OS EMPRESTIMOS");
    gotoxy(36,11);
    printf("2. LISTAR POR LIVRO ESPECIFICO");
    gotoxy(36,13);
    printf("3. LISTAR POR ALUNO ESPECIFICO");
    gotoxy(36,15);
    printf("4. VOLTAR PARA O MENU PRINCIPAL");
    linhaInferior();
    gotoxy(34,20);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,21);
}//FIM DOS MENUS

//FUNCAO QUE REALIZA O CADASTRO DO LIVRO.
void cadastroLivro(LIVROS b)
{
    int o;
    char c;
    //ABRE O ARQUIVO DE LIVROS
    fp=fopen("Livros.dat", "ab+");
    system("cls");

    gotoxy(52,2);
    printf("CADASTRO DE LIVROS");
    setbuf(stdin, NULL);

    //GERA-SE O CODIGO, DEVE VIR ANTES DO CADASTRO.
    fseek (fp,ftell(fp)-sizeof(b),SEEK_END);

    if (fread(&b,sizeof(b),1,fp)!=1)
    {
        b.codLivro= 1000;
    }
    else
    {
        fscanf(fp,"%d",&b.codLivro);
        b.codLivro=b.codLivro+1;
    }

    //CADASTRO DO LIVRO.
    gotoxy(34,4);
    printf("DIGITE NOME DO LIVRO:");
    gets(b.nomeLivro);
    strupr(b.nomeLivro);
    setbuf(stdin, NULL);

    gotoxy(34,5);
    printf("DIGITE NOME DO AUTOR:");
    gets(b.nomeAutor);
    strupr(b.nomeAutor);
    setbuf(stdin, NULL);

    gotoxy(34,6);
    printf("DIGITE AREA DO LIVRO:");
    gets (b.area);
    strupr(b.area);
    setbuf(stdin, NULL);

    gotoxy(34,7);
    printf("DIGITE QUANTIDADE DO LIVRO:");
    scanf("%d", &b.qtda);
    setbuf(stdin, NULL);

    fseek(fp,0,SEEK_END);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    gotoxy(34,9);
    printf("O LIVRO FOI CADASTRADO CORRETAMENTE!");
    gotoxy(34,11);
    printf("CODIGO DO LIVRO: %d", b.codLivro);
    gotoxy(34,13);
    system("pause");
    system("cls");
    do
    {
        gotoxy(52,2);
        printf("CADASTRO DE LIVROS");
        gotoxy(34,4);
        printf ("CADASTRAR OUTRO? S-SIM OU N-NAO");
        gotoxy(49,6);
        c=getch();
        setbuf(stdin, NULL);
        c=toupper(c);
        if (c=='S')
        {
            cadastroLivro(b);
        }
    }
    while(c!='N');
}

//FUNCAO PARA EDITAR O LIVRO.
void editarLivro(LIVROS b, EMPRESTIMOS c)
{
    int d, i=0;
    char o;

    system("cls");

    gotoxy(52,2);
    printf("EDICAO DE LIVROS:");
    fp=fopen("Livros.dat", "rb");
    rewind(fp);
    //LER O ARQUIVO EM BUSCA DE LIVROS CADASTRADOS
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    fclose(fp);
    //SE NAO EXISTIR DADOS NO ARQUIVO
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!");
        gotoxy(34,4);
        system("pause");
    }
    //SE EXIXTIR DADOS NO ARQUIVO
    else
    {
        i=0;
        gotoxy(34,4);
        printf("DIGITE O CODIGO DO LIVRO PARA EDITAR:");
        scanf("%d", &d);

        fp=fopen("Emprestimos.dat", "rb");
        //LER O ARQUIVO DE EMPRESTIMOS EM BUSCA DO CODIGO DO LIVRO
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(c.cod==d)
            {
                i++;
            }
        }
        fclose(fp);
        //SE ENCONTRAR ALGUM...
        if(i>0)
        {
            system("cls");
            gotoxy(34,4);
            printf("EXEMPLAR EMPRESTADO, LIVRO NAO PODE SER EDITADO");
            gotoxy(34,6);
            system("pause");
        }
        else
        {
            //SE NAO ENCONTRAR NENHUM...
            if(i==0)
            {
                system("cls");
                gotoxy(34,4);
                printf("LIVRO NAO CADASTRADO!");
                gotoxy(34,6);
                system("pause");
            }
            else
            {
                fp=fopen("Livros.dat","rb+");
                //BUSCA O LIVRO NO ARUIVO DE ACORDO COM SEU CODIGO.
                while (fread(&b, sizeof(b),1,fp)==1)
                {
                    if(b.codLivro==d)
                    {
                        system("cls");
                        gotoxy(52,2);
                        printf("EDICAO DE LIVROS:");
                        gotoxy(34,5);
                        printf("NOME:%s", b.nomeLivro);
                        gotoxy(34,6);
                        printf("AUTOR:%s", b.nomeAutor);
                        gotoxy(34,7);
                        printf("QUANTIDADE:%d", b.qtda);
                        gotoxy(34,8);
                        printf("AREA:%s", b.area);
                        gotoxy(34,10);
                        printf ("EDITAR LIVRO? S-SIM OU N-NAO");
                        gotoxy(49,12);
                        o=getch();
                        o=toupper(o);

                        if (o=='S')
                        {
                            system("cls");
                            gotoxy(52,2);
                            printf("EDICAO DE LIVROS:");
                            gotoxy(34,4);
                            printf("NOVO NOME:");
                            setbuf(stdin,NULL);
                            gets(b.nomeLivro);
                            strupr(b.nomeLivro);
                            setbuf(stdin,NULL);

                            gotoxy(34,6);
                            printf("NOME DO AUTOR:");
                            setbuf(stdin, NULL);
                            gets(b.nomeAutor);
                            strupr(b.nomeAutor);
                            setbuf(stdin, NULL);

                            gotoxy(34,8);
                            printf("AREA DO LIVRO:");
                            setbuf(stdin, NULL);
                            gets(b.area);
                            strupr(b.area);
                            setbuf(stdin, NULL);

                            gotoxy(34,10);
                            printf("QUANTIDADE:");
                            scanf("%d", &b.qtda);

                            gotoxy(34,12);
                            printf("LIVRO EDITADO!");

                            fseek(fp,ftell(fp)-sizeof(b),0);
                            fwrite(&b,sizeof(b),1,fp);
                            fclose(fp);
                            gotoxy(34,14);
                            system("pause");
                        }
                    }
                }
            }
        }
    }
    system("cls");
    do
    {
        gotoxy(52,2);
        printf("EDICAO DE LIVROS:");
        gotoxy(34,4);
        printf ("EDITAR OUTRO? S-SIM OU N-NAO");
        gotoxy(49,6);
        o=getch();
        o=toupper(o);

        if (o=='S')
        {
            editarLivro(b,c);
        }
    }
    while(o!='N');
}

//FUNCAO QUE REMOVE O LIVRO.
void removerLivro(LIVROS b, EMPRESTIMOS c)
{
    int d, i=0;
    char o;

    system("cls");
    gotoxy(52,2);
    printf("REMOVER LIVRO:");

    fp=fopen("Livros.dat", "rb");
    rewind(fp);
    //LER O ARQUIVO DE LIVROS EM BUSCA DE CADASTROS
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    fclose(fp);
    //SE NAO EXISTIR NENHUM...
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!");
        gotoxy(34,4);
    }
    //SE EXISTIR ALGUM...
    else
    {
        i=0;
        gotoxy(34,4);
        printf("DIGITE CODIGO DO LIVRO PARA REMOVER:");
        scanf("%d", &d);

        fp=fopen("Emprestimos.dat", "rb");
        //LER O ARQUIVO DOS EMPRESTIMOS EM BUSCA DO CODIGO DO LIVRO
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(c.cod==d)
            {
                i++;
            }
        }
        fclose(fp);
        //SE ENCONTRAR ALGUM...
        if(i>0)
        {
            system("cls");
            gotoxy(34,4);
            printf("EXEMPLAR EMPRESTADO, LIVRO NAO PODE SER REMOVIDO");
            gotoxy(34,6);
            system("pause");
        }
        //SE NAO ENCONTRAR NENHUM...
        else
        {
            if(i==0)
            {
                system("cls");
                gotoxy(34,4);
                printf("LIVRO NAO CADASTRADO!");
                gotoxy(34,6);
                system("pause");
            }
            else
            {
                fp=fopen("Livros.dat","ab+");
                //BUSCA O LIVRO DE ACORDO COM O CODIGO.
                while(fread(&b,sizeof(b),1,fp)==1)
                {
                    if (d==b.codLivro)
                    {
                        gotoxy(34,6);
                        printf("NOME: %s", b.nomeLivro);
                        gotoxy(34,7);
                        printf("CODIGO: %d", b.codLivro);
                        gotoxy(34,8);
                        printf("AUTOR:%s", b.nomeAutor);
                        gotoxy(34,9);
                        printf("AREA: %s", b.area);
                        gotoxy(34,10);
                        printf("QUANTIDADE: %d", b.qtda);
                        gotoxy(34,12);
                        printf("DELETAR? S-SIM OU N-NAO");
                        gotoxy(49,14);
                        o=getch();
                        o=toupper(o);
                    }

                    if (o=='S')
                    {
                        rewind(fp);
                        fs=fopen("remove.dat", "wb");

                        while(fread(&b,sizeof(b),1,fp)==1)
                        {
                            if(b.codLivro!=d)
                            {
                                fwrite(&b,sizeof(b),1,fs);
                                setbuf(stdin, NULL);
                            }
                        }
                        fclose(fs);
                        fclose(fp);
                        remove("Livros.dat");
                        rename("remove.dat","Livros.dat");
                        gotoxy(34,14);
                        printf("LIVRO REMOVIDO!");
                        gotoxy(34,16);
                        system("pause");
                    }
                }
            }
        }
    }
    system("cls");
    do
    {
        gotoxy(52,2);
        printf("REMOVER LIVRO:");
        gotoxy(34,5);
        printf ("REMOVER OUTRO? S-SIM OU N-NAO");
        gotoxy(49,7);
        o=getch();
        o=toupper(o);

        if (o=='S')
        {
            removerLivro(b,c);
        }
    }
    while(o!='N');
}

//FUNCAO QUE LISTA TODOS OS LIVROS CADASTRADOS.
void listarLivro(LIVROS b)
{
    int i=0,j=5;

    fp=fopen("Livros.dat","rb");
    system("cls");
    //LER O ARQUIVO DOS LIVROS EM BUSCA DE CADASTROS
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    //SE NAO EXISTIR NENHUM...
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!");
        gotoxy(34,4);
    }
    //SE EXISTIR ALGUM...
    else
    {
        rewind(fp);
        i=0;
        gotoxy(52,2);
        printf("LIVROS CADASTRADOS");
        gotoxy(1,4);
        printf("NOME:");
        gotoxy(31,4);
        printf("CODIGO:");
        gotoxy(42,4);
        printf("AUTOR:");
        gotoxy(71,4);
        printf("QUANTIDADE:");
        gotoxy(90,4);
        printf("AREA:");
        while(fread(&b,sizeof(b),1,fp)==1)
        {
            gotoxy(1,j);
            printf("%s", b.nomeLivro);
            gotoxy(31,j);
            printf("%d", b.codLivro);
            gotoxy(42,j);
            printf("%s", b.nomeAutor);
            gotoxy(71,j);
            printf("%d", b.qtda);
            gotoxy(90,j);
            printf("%s", b.area);
            j++;
            i=i+b.qtda;
        }
        gotoxy(1,j+2);
        printf("TOTAL DE LIVROS: %d", i);
        fclose(fp);
    }
    gotoxy(1,j+4);
    system("pause");
}

//REALIZA O CADASTRO DOS ALUNOS.
void cadastroAluno(ALUNOS a)
{
    int o;
    char c;

    fp=fopen("Alunos.dat", "ab+");
    system("cls");
    gotoxy(52,2);
    printf("CADASTRO DE ALUNOS");
    setbuf(stdin, NULL);
    gotoxy(34,4);
    printf("DIGITE NOME DO ALUNO:");
    gets(a.nomeAluno);
    strupr(a.nomeAluno);
    setbuf(stdin, NULL);
    gotoxy(34,5);
    printf("DIGITE MATRICULA DO ALUNO:");
    gets(a.matricula);
    setbuf(stdin, NULL);
    gotoxy(34,6);
    printf("DIGITE CPF DO ALUNO:");
    gets (a.cpf);
    setbuf(stdin, NULL);

    fseek(fp,0,SEEK_END);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    gotoxy(34,8);
    printf("O ALUNO FOI CADASTRADO CORRETAMENTE!");
    gotoxy(34,10);
    system("pause");
    system("cls");
    do
    {
        gotoxy(52,2);
        printf("CADASTRO DE ALUNOS");
        gotoxy(34,4);
        printf ("CADASTRAR OUTRO? S-SIM OU N-NAO.");
        gotoxy(49,19);
        c=getch();
        c=toupper(c);
        setbuf(stdin, NULL);

        if (c=='S')
        {
            cadastroAluno(a);
        }
    }
    while(c!='N');
}

//EDITA ALUNOS CADASTRADOS.
void editarAluno(ALUNOS a, EMPRESTIMOS c)
{
    char o, d[15];
    int i=0;

    system("cls");
    gotoxy(52,2);
    printf("EDICAO DE ALUNOS:");
    fp=fopen("Alunos.dat", "rb");
    rewind(fp);
    //BUSCA POR ALUNOS CADASTRADOS
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        i++;
    }
    fclose(fp);

    if(i==0)
    {
        system("cls");
        gotoxy(34,5);
        printf("NENHUM ALUNO MATRICULADO!");
        gotoxy(34,7);
        system("pause");
        gotoxy(49,9);
    }
    else
    {
        i=0;
        gotoxy(34,4);
        printf("DIGITE MATRICULA DO ALUNO QUE DESEJA EDITAR:");
        setbuf(stdin, NULL);
        gets(d);
        setbuf(stdin, NULL);

        fp=fopen("Emprestimos.dat", "rb");
        //BUSCA POR DEBITOS DE EMPRESTIMOS DO ALUNO
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(strcmp(d,c.mat)==0)
            {
                i++;
            }
        }
        fclose(fp);

        if(i>0)
        {
            system("cls");
            gotoxy(34,4);
            printf("EMPRESTIMO PENDENTE, ALUNO NAO PODE SER EDITADO");
            gotoxy(34,6);
            system("pause");
        }
        else
        {
            i=0;
            fp=fopen("Alunos.dat","rb+");
            rewind(fp);
            //BUSCA O ALUNO NO ARQUIVO DE ACORDO COM A MATTRICULA.
            while (fread(&a, sizeof(a),1,fp)==1)
            {
                if(strcmp(d,a.matricula)==0)
                {
                    i++;
                    gotoxy(34,6);
                    printf("NOME:%s", a.nomeAluno);
                    gotoxy(34,7);
                    printf("CPF:%s", a.cpf);
                    gotoxy(34,9);
                    printf ("EDITAR ALUNO? S-SIM OU N-NAO");
                    o=getch();
                    o=toupper(o);

                    if (o=='S')
                    {
                        system("cls");
                        gotoxy(52,2);
                        printf("EDICAO DE ALUNOS:");
                        setbuf(stdin, NULL);
                        gotoxy(34,5);
                        printf("NOVO NOME:");
                        setbuf(stdin,NULL);
                        gets(a.nomeAluno);
                        strupr(a.nomeAluno);
                        setbuf(stdin,NULL);
                        gotoxy(34,6);
                        printf("MATRICULA:");
                        setbuf(stdin,NULL);
                        gets(a.matricula);
                        setbuf(stdin, NULL);
                        gotoxy(34,7);
                        printf("CPF:");
                        setbuf(stdin,NULL);
                        gets(a.cpf);
                        setbuf(stdin, NULL);

                        fseek(fp,ftell(fp)-sizeof(a),0);
                        fwrite(&a,sizeof(a),1,fp);
                        fclose(fp);
                        gotoxy(34,9);
                        printf("CADASTRO DO ALUNO FOI EDITADO COM SUCESSO!");
                        gotoxy(34,11);
                        system("pause");
                        gotoxy(49,19);
                    }
                }
            }
            if(i==0)
            {
                system("cls");
                gotoxy(34,5);
                printf("ALUNO NAO CADASTRADO!");
                gotoxy(34,7);
                system("pause");
                gotoxy(49,9);
            }
        }
    }

    system("cls");
    do
    {
        gotoxy(52,2);
        printf("EDICAO DE ALUNOS:");
        gotoxy(34,4);
        printf ("EDITAR OUTRO? S-SIM OU N-NAO.");
        gotoxy(49,6);
        o=getch();
        o=toupper(o);

        if (o=='S')
        {
            editarAluno(a,c);
        }
    }
    while(o!='N');
}

//FUNCAO QUE REMOVE O ALUNO CADASTRADO.
void removerAluno(ALUNOS a, EMPRESTIMOS c)
{
    char o, d[15];
    int i=0;

    system("cls");
    gotoxy(52,2);
    printf("REMOVER ALUNO");

    fp=fopen("Alunos.dat", "rb");
    rewind(fp);
    //PROCURA POR ALUNOS CADASTRADOS
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        i++;
    }
    fclose(fp);

    if(i==0)
    {
        system("cls");
        gotoxy(34,5);
        printf("NENHUM ALUNO MATRICULADO!");
    }
    else
    {
        i=0;
        gotoxy(34,4);
        printf("DIGITE MATRICULA DO ALUNO QUE DESEJA REMOVER:");
        gets(d);
        setbuf(stdin, NULL);

        fp=fopen("Emprestimos.dat", "rb");
        //BUSCA POR DEBITOS DE EMPRESTIMOS DO ALUNO
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(strcmp(d,c.mat)==0)
            {
                i++;
            }
        }
        fclose(fp);

        if(i>0)
        {
            system("cls");
            gotoxy(34,4);
            printf("EMPRESTIMO PEDENTE, ALUNO NAO PODE SER REMOVIDO");
            gotoxy(34,6);
            system("pause");
        }
        else
        {
            fp=fopen("Alunos.dat","ab+");
            //BUSCA O ALUNO PELA MATRICULA.
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if (strcmp(d,a.matricula)==0)
                {
                    gotoxy(34,6);
                    printf("NOME: %s", a.nomeAluno);
                    gotoxy(34,7);
                    printf("MATRICULA: %s", a.matricula);
                    gotoxy(34,8);
                    printf("CPF:%s", a.cpf);
                    gotoxy(34,10);
                    printf("DELETAR? S-SIM OU N-NAO.");
                    gotoxy(49,12);
                    o=getch();
                    o=toupper(o);
                }

                if (o=='S')
                {
                    fs=fopen("remove.dat", "wb+");
                    rewind(fp);
                    while(fread(&a,sizeof(a),1,fp)==1)
                    {
                        if(strcmp(d,a.matricula)!=0)
                        {
                            fseek(fs,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,fs);
                        }
                    }
                    fclose(fs);
                    fclose(fp);
                    remove("Alunos.dat");
                    rename("remove.dat","Alunos.dat");
                    gotoxy(34,12);
                    printf("CADASTRO DE ALUNO REMOVIDO!");
                    gotoxy(34,14);
                    system("pause");
                }
            }
            if(i==0)
            {
                system("cls");
                gotoxy(34,5);
                printf("ALUNO NAO CADASTRADO!");
                gotoxy(34,7);
                system("pause");
                gotoxy(49,9);
            }
        }
    }
    system("cls");
    do
    {
        gotoxy(52,2);
        printf("REMOVER ALUNO");
        gotoxy(34,4);
        printf ("REMOVER OUTRO? S-SIM N-NAO.");
        gotoxy(49,6);
        o=getch();
        o=toupper(o);

        if (o=='S')
        {
            removerAluno(a,c);
        }
    }
    while(o!='N');
}

//LISTA TODOS OS ALUNOS CADASTRADOS.
void listarAluno(ALUNOS a)
{
    int i=0, j=5;

    fp=fopen("Alunos.dat","rb");
    system("cls");
    //BUSCA CADASTROS DOS ALUNOS
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        i++;
    }

    if(i==0)
    {
        system("cls");
        gotoxy(34,4);
        printf("NENHUM ALUNO CADASTRADO!\n");
        gotoxy(34,6);
    }
    else
    {
        rewind(fp);
        gotoxy(45,2);
        printf("ALUNOS MATRICULADOS");
        gotoxy(25,4);
        printf("NOME:");
        gotoxy(55,4);
        printf("MATRICULA:");
        gotoxy(80,4);
        printf("CPF:");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            gotoxy(25,j);
            printf("%s", a.nomeAluno);
            gotoxy(55,j);
            printf("%s", a.matricula);
            gotoxy(80,j);
            printf("%s", a.cpf);
            gotoxy(25,j+2);
            j++;
        }
        fclose(fp);
    }
    system("pause");
}

//FUNCAO QUE REALIZA NOVO EMPRESTIMO.
void novoEmprestimo(LIVROS b, ALUNOS a, EMPRESTIMOS c)
{
    int l, i=0, n;
    char m[15], o, al[31];

    system("cls");

    gotoxy(52,2);
    printf("NOVO EMPRESTIMO");

    gotoxy(34,4);
    printf("DIGITE MATRICULA DO ALUNO:");
    setbuf(stdin, NULL);
    gets(m);
    setbuf(stdin,NULL);

    fp=fopen("Alunos.dat", "rb");
    //BUSCA O ALUNO PELA MATRICULA.
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if (strcmp(m,a.matricula)==0)
        {
            i++;
            gotoxy(34,6);
            printf("NOME: %s", a.nomeAluno);
            gotoxy(34,7);
            printf("MATRICULA:%s", a.matricula);
            gotoxy(34,8);
            printf("CPF: %s", a.cpf);
            gotoxy(34,10);
            strcpy(al,a.nomeAluno);
            system("pause");
        }
    }
    fclose(fp);
    //PROCURA SE O ALUNO ESTA CADASTRADO
    if(i==0)
    {
        gotoxy(34,6);
        printf("ALUNO NAO CADASTRADO!");
        gotoxy(34,8);
    }
    else
    {
        i=0;
        fp=fopen("Emprestimos.dat","rb");
        //PROCURA SE O ALUNO EXCEDEU O LIMITE DE EMPRESTIMOS
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(strcmp(m,c.mat)==0)
            {
                i++;
            }
        }
        fclose(fp);
        if(i==2)
        {
            system("cls");
            gotoxy(34,4);
            printf("QUANTIDADE DE EMPRESTIMOS EXCEDIDA!");
            gotoxy(34,6);
        }
        else
        {
            i=0;
            system("cls");
            gotoxy(34,4);
            printf("DIGITE CODIGO DO LIVRO:");
            scanf("%d", &l);

            fp=fopen("Livros.dat","rb+");
            //BUSCA O LIVRO PELO CODIGO.
            while(fread(&b,sizeof(b),1,fp)==1)
            {
                if(l==b.codLivro)
                {
                    i++;
                    gotoxy(34,6);
                    printf("NOME: %s", b.nomeLivro);
                    gotoxy(34,7);
                    printf("AUTOR: %s", b.nomeAutor);
                    gotoxy(34,8);
                    printf("AREA: %s", b.area);
                    gotoxy(34,9);
                    n=b.qtda;
                    gotoxy(34,11);
                    system("pause");
                }
            }
            fclose(fp);

            if(i==0)
            {
                system("cls");
                gotoxy(34,4);
                printf("LIVRO NAO CADASTRADO.");
                gotoxy(34,6);
            }
            else
            {
                if(n==0)
                {
                    system("cls");
                    gotoxy(34,4);
                    printf("NENHUM EXEMPLAR DISPONIVEL!");
                    gotoxy(34,6);
                }
                else
                {
                    i=0;
                    fp=fopen("Emprestimos.dat", "rb");
                    //BUSCA PELA MATRICULA DO ALUNO SE ELE JA TEM ESSE EXEMPLAR DO LIVRO
                    while(fread(&c, sizeof(c), 1, fp)==1)
                    {
                        if(l==c.cod && strcmp(m,c.mat)==0)
                        {
                            i++;
                        }
                    }
                    fclose(fp);

                    if(i==1)
                    {
                        system("cls");
                        gotoxy(34,4);
                        printf("ALUNO COM ESSE EXEMPLAR EMPRESTADO!");
                        gotoxy(34,6);
                    }
                    else
                    {
                        system("cls");
                        gotoxy(34,4);
                        printf("REALIZAR EMPRESTIMO? S-SIM OU N-NAO.");
                        gotoxy(49,6);
                        o=getch();
                        o=toupper(o);

                        if(o=='S')
                        {
                            fp=fopen("Livros.dat","rb+");
                            while(fread(&b,sizeof(b),1,fp)==1)
                            {
                                if(l==b.codLivro)
                                {
                                    //A QUATIDADE DO LIVRO E DECREMENTADA EM 1
                                    b.qtda=b.qtda-1;
                                    strcpy(c.livro,b.nomeLivro);
                                    fseek(fp,ftell(fp)-sizeof(b),0);
                                    fwrite (&b,sizeof(b),1,fp);
                                    fseek(fp,0,SEEK_END);

                                }
                            }
                            fclose(fp);

                            fp=fopen("Emprestimos.dat","ab+");
                            strcpy(c.mat,m);
                            strcpy(c.aluno, al);
                            c.cod=l;
                            //PEGA A DATA DO SISTEMA E CALCULA A DATA DE DEVOLUCAO
                            sprintf(c.dataAtual,"%s",data());
                            sprintf(c.dataDevolucao,"%s",dataDevolucao());
                            //ESCREVE TODAS AS INFORMACOES NO ARQUIVO
                            fwrite(&c,sizeof(c),1,fp);
                            fclose(fp);
                            gotoxy(34,6);
                            printf("EMPRESTIMO REALIZADO!");
                            gotoxy(34,8);
                            printf("DATA: %s",c.dataAtual);
                            gotoxy(34,10);
                            printf("DEVOLUCAO: %s",c.dataDevolucao);
                            gotoxy(34,12);
                        }
                    }
                }
            }
        }
    }
    system("pause");
}

//FUNCAO DE DEVOLUCAO DE LIVROS EMPRESTADOS.
void devolucaoEmprestimo(EMPRESTIMOS c, LIVROS b)
{
    char o, m[15];
    int d, i=0;

    system("cls");
    gotoxy(52,2);
    printf("DEVOLUCAO");

    fp=fopen("Emprestimos.dat", "rb");
    rewind(fp);
    //LER O ARQUIVO DE EMPRESTIMOS
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    fclose(fp);

    if(i==0)
    {
        gotoxy(34,4);
        printf("NENHUM EMPRESTIMO CADASTRADO!");
        gotoxy(34,6);
    }
    else
    {
        //REALIZA OS EMPRESTIMOS PELO CODIGO DO LIVRO E MATRICULA DO ALUNO
        i=0;
        gotoxy(34,4);
        printf("DIGITE CODIGO DO LIVRO: ");
        scanf("%d", &d);
        gotoxy(34,5);
        printf("DIGITE MATRICULA DO ALUNO: ");
        setbuf(stdin, NULL);
        gets(m);
        setbuf(stdin, NULL);

        fp=fopen("Emprestimos.dat", "rb+");

        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if (d==c.cod && strcmp(m,c.mat)==0)
            {
                i++;
                gotoxy(34,7);
                printf("NOME DO ALUNO: %s", c.aluno);
                gotoxy(34,8);
                printf("MATRICULA: %s", c.mat);
                gotoxy(34,9);
                printf("NOME DO LIVRO: %s", c.livro);
                gotoxy(34,10);
                printf("CODIGO: %d", c.cod);
            }
        }
        fclose(fp);
        if(i==0)
        {
            system("cls");
            gotoxy(34,4);
            printf("DADOS DE EMPRESTIMO NAO ENCONTRADOS");
            gotoxy(34,6);
        }
        else
        {
            gotoxy(34,12);
            printf("CONFIRMAR DEVOLUCAO? S-SIM OU N-NAO.");
            gotoxy(49,14);
            o=getch();
            o=toupper(o);

            if (o=='S')
            {
                fp=fopen("Emprestimos.dat", "rb+");
                fs=fopen("remove.dat", "wb+");
                rewind(fp);
                while(fread(&c,sizeof(c),1,fp)==1)
                {
                    if(d!=c.cod || strcmp(m,c.mat)!=0)
                    {
                        fwrite(&c,sizeof(c),1,fs);
                        setbuf(stdin, NULL);
                    }
                }
                fclose(fs);
                fclose(fp);
                remove("Emprestimos.dat");
                rename("remove.dat","Emprestimos.dat");
                gotoxy(34,14);
                printf("DEVOLUCAO CONFIRMADA!");
                gotoxy(34,16);
                //APOS A DEVOLUCAO A QUANTIDADE DO LIVRO E CREMENTADA EM 1
                fp=fopen("Livros.dat","rb+");
                while(fread(&b,sizeof(b),1,fp)==1)
                {
                    if(d==b.codLivro)
                    {
                        b.qtda=b.qtda+1;
                        fseek(fp,ftell(fp)-sizeof(b),0);
                        fwrite (&b,sizeof(b),1,fp);
                        fseek(fp,0,SEEK_END);
                    }
                }
                fclose(fp);
            }
        }
        system("pause");
    }
}

//LISTA TODOS OS EMPRESTIMOS.
void listarTodosEmprestimo(EMPRESTIMOS c)
{
    int i=0, j=5;

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    fclose(fp);

    if(i==0)
    {
        gotoxy(34,4);
        printf("NENHUM EMPRESTIMO CADASTRADO!");
        gotoxy(34,6);
    }
    else
    {
        fp=fopen("Emprestimos.dat","rb");
        gotoxy(45,2);
        printf("EMPRESTIMOS CADASTRADOS");
        gotoxy(1,4);
        printf("NOME ALUNO:");
        gotoxy(25,4);
        printf("MATRICULA:");
        gotoxy(40,4);
        printf("NOME LIVRO:");
        gotoxy(60,4);
        printf("CODIGO LIVRO:");
        gotoxy(80,4);
        printf("DATA EMPRESTIMO:");
        gotoxy(100,4);
        printf("DATA DEVOLUCAO:");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            gotoxy(1,j);
            printf("%s", c.aluno);
            gotoxy(25,j);
            printf("%s", c.mat);
            gotoxy(40,j);
            printf("%s", c.livro);
            gotoxy(60,j);
            printf("%d", c.cod);
            gotoxy(80,j);
            printf("%s", c.dataAtual);
            gotoxy(100,j);
            printf("%s", c.dataDevolucao);
            gotoxy(1,j+2);
            j++;
        }
        fclose(fp);
    }
    system("pause");
}
//LISTA OS EMPRESTIMOS DO MESMO LIVRO.
void listarEmprestimoLivro(EMPRESTIMOS c)
{
    int i=0, d, j=5;

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }

    if(i==0)
    {
        gotoxy(34,4);
        printf("NENHUM EMPRESTIMO CADASTRADO!");
        gotoxy(34,6);
    }
    else
    {
        gotoxy(34,4);
        printf("DIGITE CODIGO DO LIVRO:");
        scanf("%d", &d);
        rewind(fp);

        system("cls");
        gotoxy(45,2);
        printf("EMPRESTIMOS CADASTRADOS");
        gotoxy(1,4);
        printf("NOME ALUNO:");
        gotoxy(25,4);
        printf("MATRICULA:");
        gotoxy(40,4);
        printf("NOME LIVRO:");
        gotoxy(60,4);
        printf("CODIGO LIVRO:");
        gotoxy(80,4);
        printf("DATA EMPRESTIMO:");
        gotoxy(100,4);
        printf("DATA DEVOLUCAO:");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(d==c.cod)
            {
                gotoxy(1,j);
                printf("%s", c.aluno);
                gotoxy(25,j);
                printf("%s", c.mat);
                gotoxy(40,j);
                printf("%s", c.livro);
                gotoxy(60,j);
                printf("%d", c.cod);
                gotoxy(80,j);
                printf("%s", c.dataAtual);
                gotoxy(100,j);
                printf("%s", c.dataDevolucao);
                j++;
                gotoxy(1,j+2);
            }
        }
        fclose(fp);
    }
    system("pause");
}
//LISTA OS EMPRESTIMOS DO MESMO ALUNO.
void listarEmprestimoAluno(EMPRESTIMOS c)
{
    int i=0, j=5;
    char m[15];

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        gotoxy(34,4);
        printf("NENHUM EMPRESTIMO CADASTRADO!");
        gotoxy(34,6);
    }
    else
    {
        rewind(fp);
        gotoxy(34,4);
        printf("DIGITE MATRICULA DO ALUNO:");
        setbuf(stdin, NULL);
        gets(m);
        setbuf(stdin, NULL);

        system("cls");
        gotoxy(45,2);
        printf("EMPRESTIMOS CADASTRADOS");
        gotoxy(1,4);
        printf("NOME ALUNO:");
        gotoxy(25,4);
        printf("MATRICULA:");
        gotoxy(40,4);
        printf("NOME LIVRO:");
        gotoxy(60,4);
        printf("CODIGO LIVRO:");
        gotoxy(80,4);
        printf("DATA EMPRESTIMO:");
        gotoxy(100,4);
        printf("DATA DEVOLUCAO:");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(strcmp(c.mat,m)==0)
            {
                gotoxy(1,j);
                printf("%s", c.aluno);
                gotoxy(25,j);
                printf("%s", c.mat);
                gotoxy(40,j);
                printf("%s", c.livro);
                gotoxy(60,j);
                printf("%d", c.cod);
                gotoxy(80,j);
                printf("%s", c.dataAtual);
                gotoxy(100,j);
                printf("%s", c.dataDevolucao);
                j++;
                gotoxy(1,j+2);
            }
        }
        fclose(fp);
    }
    system("pause");
}

main()
{
    system("color 70");
    ALUNOS a;
    LIVROS b;
    EMPRESTIMOS c;
    char mopt, opt;
    inicio();
    do
    {
        menuPrincipal();
        mopt=getch();
        switch (mopt)
        {
        case '1':
            do
            {
                menuAcervo();
                opt=getch();
                switch (opt)
                {
                case '1':
                    cadastroLivro(b);
                    break;
                case '2':
                    editarLivro(b,c);
                    break;
                case '3':
                    removerLivro(b,c);
                    break;
                case '4':
                    listarLivro(b);
                    break;
                case '5':
                    system("cls");
                    break;
                }
            }
            while(opt!='5');
            break;
        case '2':
            do
            {
                menuAluno();
                opt=getch();
                switch (opt)
                {
                case '1':
                    cadastroAluno(a);
                    break;
                case '2':
                    editarAluno(a,c);
                    break;
                case '3':
                    removerAluno(a,c);
                    break;
                case '4':
                    listarAluno(a);
                    break;
                }
            }
            while(opt!='5');
            break;

        case '3':
            do
            {
                menuEmprestimo();
                opt=getch();
                switch(opt)
                {
                case '1':
                    novoEmprestimo(b,a,c);
                    break;
                case '2':
                    devolucaoEmprestimo(c,b);
                    break;
                case '3':
                    do
                    {
                        menuListaEmprestimo();
                        opt=getch();
                        switch(opt)
                        {
                        case '1':
                            listarTodosEmprestimo(c);
                            break;
                        case '2':
                            listarEmprestimoLivro(c);
                            break;
                        case '3':
                            listarEmprestimoAluno(c);
                            break;
                        }
                    }
                    while(opt!='4');
                    break;
                }
            }
            while(opt!='4');
            break;
        }
    }
    while (mopt!='4');
    system("cls");
    fim();
}
//FIM DA PARTE DE ALINE
