#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

#define TAM 35

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
    char aluno[31], livro[2531], mat[15];
    int dia, mes, ano, cod;
} EMPRESTIMOS;

COORD coord = {0, 0};
COORD max_res,cursor_size;

void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int segundos)
{
    clock_t chegada = segundos + clock();
    while (chegada > clock());
}

void linhasup()
{
    int i;
    printf("%c", 201);
    for(i=0; i<TAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);
}

void linhainf()
{
    int i;
    printf("%c", 200);
    for(i=0; i<TAM; i++)
        printf("%c", 205);
    printf("%c\n", 188);
}

void linhamed()
{
    int i;
    printf("%c", 204);
    for(i=0; i<TAM; i++)
        printf("%c", 205);
    printf("%c\n", 185);
}

void linhalat(char st[])
{
    int i, contlet = 0;
    for(i=0; i<TAM; i++)
    {
        if(st[i]=='\0')
            break;
        else
            contlet++;
    }
    printf("%c", 186);
    printf("%s", st);
    while(contlet<TAM)
    {
        printf("%c", 32);
        contlet++;
    }
    printf("%c\n", 186);
}

void inicio()
{
    int i;
    gotoxy(34,2);
    linhasup();
    gotoxy(34,3);
    linhalat("CARREGANDO POR FAVOR AGUARDE...");
    gotoxy(34,4);
    linhainf();
    gotoxy(0,5);
    for(i=0; i<104; i++)
    {
        Sleep(1);
        printf("%c", 219);
    }
}

void fim()
{
    int i;
    gotoxy(34,2);
    linhasup();
    gotoxy(34,3);
    linhalat("ENCERRANDO...");
    gotoxy(34,4);
    linhainf();
    gotoxy(0,5);
    for(i=0; i<104; i++)
    {
        Sleep(1);
        printf("%c", 219);
    }
}

char menuPrincipal ()
{
    char o;
    system("cls");
    gotoxy(34,7);
    linhasup();
    gotoxy(34,8);
    linhalat("MENU PRINCIPAL");
    gotoxy(34,9);
    linhamed();
    gotoxy(34,10);
    linhalat("1. Acervo");
    gotoxy(34,11);
    linhalat("2. Alunos");
    gotoxy(34,12);
    linhalat("3. Emprestimos");
    gotoxy(34,13);
    linhalat("4. Debitos de devolucoes");
    gotoxy(34,14);
    linhalat("5. Sair");
    gotoxy(34,15);
    linhainf();
    gotoxy(34,17);
    printf("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,19);
    o=getch();
    return o;
}

char menuAcervo ()
{
    char o;
    system("cls");
    gotoxy(34,7);
    linhasup();
    gotoxy(34,8);
    linhalat("ACERVO");
    gotoxy(34,9);
    linhamed();
    gotoxy(34,10);
    linhalat("1. Cadastrar livro");
    gotoxy(34,11);
    linhalat("2. Editar livro");
    gotoxy(34,12);
    linhalat("3. Remover livro");
    gotoxy(34,13);
    linhalat("4. Listar livros cadastrados");
    gotoxy(34,14);
    linhalat("5. Voltar para o menu principal");
    gotoxy(34,15);
    linhainf();
    gotoxy(34,17);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,19);
    o=getch();
    return o;
}

char menuAluno ()
{
    char o;
    system("cls");
    gotoxy(34,7);
    linhasup();
    gotoxy(34,8);
    linhalat("ALUNOS");
    gotoxy(34,9);
    linhamed();
    gotoxy(34,10);
    linhalat("1. Cadastrar aluno");
    gotoxy(34,11);
    linhalat("2. Editar aluno");
    gotoxy(34,12);
    linhalat("3. Remover aluno");
    gotoxy(34,13);
    linhalat("4. Listar alunos cadastrados");
    gotoxy(34,14);
    linhalat("5. Voltar para o menu principal");
    gotoxy(34,15);
    linhainf();
    gotoxy(34,17);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,19);
    o=getch();
    return o;
}

char menuEmprestimo ()
{
    char o;
    system("cls");
    gotoxy(34,7);
    linhasup();
    gotoxy(34,8);
    linhalat("EMPRESTIMOS");
    gotoxy(34,9);
    linhamed();
    gotoxy(34,10);
    linhalat("1. Novo emprestimo");
    gotoxy(34,11);
    linhalat("2. Confirmar devolucao");
    gotoxy(34,12);
    linhalat("3. Listar emprestimos");
    gotoxy(34,13);
    linhalat("4. Voltar para o menu principal");
    gotoxy(34,14);
    linhainf();
    gotoxy(34,16);
    printf("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,19);
    o=getch();
    return o;
}

char menuListaEmprestimo ()
{
    char o;
    system("cls");
    gotoxy(34,7);
    linhasup();
    gotoxy(34,8);
    linhalat("LISTAR EMPRESTIMOS");
    gotoxy(34,9);
    linhamed();
    gotoxy(34,10);
    linhalat("1. Listar todos os emprestimos");
    gotoxy(34,11);
    linhalat("2. Listar por livro especifico");
    gotoxy(34,12);
    linhalat("3. Listar por aluno especifico");
    gotoxy(34,13);
    linhalat("4. Voltar para o menu principal");
    gotoxy(34,14);
    linhainf();
    gotoxy(34,16);
    printf ("Por Favor escolha uma das opcoes acima...");
    gotoxy(49,19);
    o=getch();
    return o;
}

//FUNCAO QUE REALIZA O CADASTRO DO LIVRO.
void cadastroLivro(LIVROS b)
{
    int o;
    char c;

    fp=fopen("Livros.dat", "ab+");
    system("cls");

    gotoxy(34,2);
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
    printf ("CADASTRAR OUTRO? S-SIM OU N-NAO");
    gotoxy(49,15);
    c=getch();
    setbuf(stdin, NULL);
    c=toupper(c);
    if (c=='S')
    {
        cadastroLivro(b);
    }
}

//FUNCAO PARA EDITAR O LIVRO.
void editarLivro(LIVROS b)
{
    int d, i=0;
    char c;

    system("cls");

    gotoxy(34,2);
    printf("EDICAO DE LIVROS:");
    fp=fopen("Livros.dat", "rb+");
    rewind(fp);

    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!\n");
    }
    else
    {
        rewind(fp);

        gotoxy(34,4);
        printf("DIGITE O CODIGO DO LIVRO PARA EDITAR:");
        scanf("%d", &d);


        //BUSCA O LIVRO NO ARUIVO DE ACORDO COM SEU CODIGO.
        while (fread(&b, sizeof(b),1,fp)==1)
        {
            if(b.codLivro==d)
            {
                system("cls");
                gotoxy(34,5);
                printf("NOME:%s", b.nomeLivro);
                gotoxy(34,6);
                printf("AUTOR:%s", b.nomeAutor);
                gotoxy(34,8);
                printf ("EDITAR LIVRO? S-SIM OU N-NAO");
                c=getch();
                c=toupper(c);

                if (c=='S')
                {
                    system("cls");
                    gotoxy(34,5);
                    printf("NOVO NOME:");
                    setbuf(stdin,NULL);
                    gets(b.nomeLivro);
                    strupr(b.nomeLivro);
                    setbuf(stdin,NULL);

                    gotoxy(34,7);
                    printf("NOME DO AUTOR:");
                    gets(b.nomeAutor);
                    strupr(b.nomeAutor);
                    setbuf(stdin, NULL);

                    gotoxy(34,9);
                    printf("AREA DO LIVRO:");
                    gets(b.area);
                    strupr(b.area);
                    setbuf(stdin, NULL);

                    gotoxy(34,11);
                    printf("QUANTIDADE:");
                    scanf("%d", &b.qtda);

                    gotoxy(34,13);
                    printf("LIVRO EDITADO!");
                    fseek(fp,ftell(fp)-sizeof(b),0);
                    fwrite(&b,sizeof(b),1,fp);
                    fclose(fp);
                    gotoxy(34,15);
                    system("pause");
                }
            }
        }
    }
    system("cls");
    gotoxy(34,5);
    printf ("EDITAR OUTRO? S-SIM OU N-NAO");
    c=getch();
    c=toupper(c);

    if (c=='S')
    {
        editarLivro(b);
    }
}

//FUNCAO QUE REMOVE O LIVRO.
void removerLivro(LIVROS b)
{
    int d, i=0;
    char c;

    system("cls");
    gotoxy(34,2);
    printf("REMOVER LIVRO\n");

    fp=fopen("Livros.dat", "rb+");
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!\n");
    }
    else
    {
        rewind(fp);
        gotoxy(34,4);
        printf("DIGITE CODIGO DO LIVRO PARA REMOVER:\n");
        scanf("%d", &d);
        //BUSCA O LIVRO DE ACORDO COM O CODIGO.
        while(fread(&b,sizeof(b),1,fp)==1)
        {
            if (d==b.codLivro)
            {
                gotoxy(34,6);
                printf("NOME: %s\n", b.nomeLivro);
                gotoxy(34,7);
                printf("CODIGO: %d\n", b.codLivro);
                gotoxy(34,8);
                printf("AUTOR:%s\n", b.nomeAutor);
                gotoxy(34,9);
                printf("AREA: %s\n", b.area);
                gotoxy(34,10);
                printf("QUANTIDADE: %d\n", b.qtda);
                gotoxy(34,12);
                printf("DELETAR? S-SIM OU N-NAO");
                c=getch();
                c=toupper(c);
            }

            if (c=='S')
            {
                fs=fopen("remove.dat", "wb+");
                rewind(fp);
                while(fread(&b,sizeof(b),1,fp)==1)
                {
                    if(b.codLivro!=d)
                    {
                        fseek(fs,0,SEEK_CUR);
                        fwrite(&b,sizeof(b),1,fs);
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
    system("cls");
    gotoxy(34,5);
    printf ("REMOVER OUTRO? (S) PARA SIM (N) PARA NAO");
    c=getch();
    c=toupper(c);

    if (c=='S')
    {
        removerLivro(b);
    }
}

//FUNCAO QUE LISTA TODOS OS LIVROS CADASTRADOS.
void listarLivro(LIVROS b)
{
    int i=0,j=5;

    fp=fopen("Livros.dat","rb");
    system("cls");

    while(fread(&b,sizeof(b),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        system("cls");
        gotoxy(34,2);
        printf("NENHUM LIVRO CADASTRADO!");
        gotoxy(34,4);
        system("pause");
    }
    else
    {
        rewind(fp);
        i=0;
        gotoxy(34,2);
        printf("LIVROS DISPONIVEIS");
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
        printf("TOTAL DE LIVROS: %d\n", i);
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
    gotoxy(34,2);
    printf("CADASTRO DE ALUNOS\n");
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

//EDITA ALUNOS CADASTRADOS.
void editarAluno(ALUNOS a)
{
    char c, d[15];
    int i=0;

    system("cls");
    gotoxy(34,2);
    printf("EDICAO DE ALUNOS:\n");
    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        system("cls");
        gotoxy(34,5);
        printf("NENHUM ALUNO MATRICULADO!\n");
    }
    else
    {
        rewind(fp);
        gotoxy(34,4);
        printf("DIGITE MATRICULA DO ALUNO QUE DESEJA EDITAR:");
        gets(d);
        setbuf(stdin, NULL);

        //BUSCA O ALUNO NO ARQUIVO DE ACORDO COM A MATTRICULA.
        while (fread(&a, sizeof(a),1,fp)==1)
        {
            if(strcmp(d,a.matricula)==0)
            {
                gotoxy(34,6);
                printf("NOME:%s\n", a.nomeAluno);
                gotoxy(34,7);
                printf("CPF:%s\n", a.cpf);
                gotoxy(34,9);
                printf ("EDITAR ALUNO? S-SIM OU N-NAO");
                c=getch();
                c=toupper(c);

                if (c=='S')
                {
                    system("cls");
                    setbuf(stdin, NULL);
                    gotoxy(34,5);
                    printf("NOVO NOME:");
                    gets(a.nomeAluno);
                    strupr(a.nomeAluno);
                    setbuf(stdin,NULL);
                    gotoxy(34,6);
                    printf("MATRICULA:");
                    gets(a.matricula);
                    setbuf(stdin, NULL);
                    gotoxy(34,7);
                    printf("CPF:");
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
            if(strcmp(d,a.matricula)!=0)
            {
                system("cls");
                gotoxy(34,5);
                printf("ALUNO NAO CADASTRADO!");
            }
        }
    }
    system("cls");
    gotoxy(34,5);
    printf ("EDITAR OUTRO? S-SIM OU N-NAO.");
    c=getch();
    c=toupper(c);

    if (c=='S')
    {
        editarAluno(a);
    }
}

//FUNCAO QUE REMOVE O ALUNO CADASTRADO.
void removerAluno(ALUNOS a)
{
    char c, d[15];
    int i=0;

    system("cls");
    gotoxy(34,2);
    printf("REMOVER ALUNO\n");

    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        system("cls");
        gotoxy(34,5);
        printf("NENHUM ALUNO MATRICULADO!");
    }
    else
    {
        rewind(fp);
        gotoxy(34,4);
        printf("DIGITE MATRICULA DO ALUNO QUE DESEJA REMOVER:");
        gets(d);
        setbuf(stdin, NULL);
        //BUSCA O ALUNO PELA MATRICULA.
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if (strcmp(d,a.matricula)==0)
            {
                gotoxy(34,6);
                printf("NOME: %s\n", a.nomeAluno);
                gotoxy(34,7);
                printf("MATRICULA: %s\n", a.matricula);
                gotoxy(34,8);
                printf("CPF:%s\n", a.cpf);
                gotoxy(34,10);
                printf("DELETAR? S-SIM OU N-NAO.");
                gotoxy(49,19);
                c=getch();
                c=toupper(c);
            }

            if (c=='S')
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
    }
    system("cls");
    gotoxy(34,5);
    printf ("REMOVER OUTRO? S-SIM N-NAO.");
    c=getch();
    c=toupper(c);

    if (c=='S')
    {
        removerAluno(a);
    }
}

//LISTA TODOS OS ALUNOS CADASTRADOS.
void listarAluno(ALUNOS a)
{
    int i=0, j=5;

    fp=fopen("Alunos.dat","rb");
    system("cls");
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
        system("pause");
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
            i++;
        }
        fclose(fp);
    }
    system("pause");
}

//FUNCAO QUE REALIZA NOVO EMPRESTIMO.
void novoEmprestimo(LIVROS b, ALUNOS a, EMPRESTIMOS c)
{
    int l, i=0;
    char m[15], o;

    system("cls");

    printf("DIGITE MATRICULA DO ALUNO:\n");
    gets(m);
    setbuf(stdin,NULL);

    fp=fopen("Alunos.dat", "rb");
    //BUSCA O ALUNO PELA MATRICULA.
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if (strcmp(m,a.matricula)==0)
        {
            printf("NOME: %s\n", a.nomeAluno);
            printf("MATRICULA:%s\n", a.matricula);
            printf("CPF: %s\n", a.cpf);
            i++;
        }
    }
    fclose(fp);

    if(i==0)
    {
        printf("ALUNO NAO CADASTRADO!\n");
    }
    else
    {
        i=0;
        fp=fopen("Emprestimos.dat","ab+");
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
            printf("QUANTIDADE DE EMPRESTIMOS EXCEDIDA!\n");
        }
        else
        {
            i=0;
            printf("DIGITE CODIGO DO LIVRO:");
            scanf("%d", &c.cod);

            fp=fopen("Livros.dat","rb");
            //BUSCA O LIVRO PELO CODIGO.
            while(fread(&b,sizeof(b),1,fp)==1)
            {
                if(c.cod==b.codLivro)
                {
                    printf("NOME: %s\n", b.nomeLivro);
                    printf("AUTOR: %s\n", b.nomeAutor);
                    printf("AREA: %s\n", b.area);
                    printf("QUATIDADE: %d\n",b.qtda);
                    i++;
                    l=b.qtda;
                }
            }
            if(i==0)
            {
                printf("LIVRO NAO CADASTRADO\n");
            }
            else
            {
                if(l<=0)
                {
                    printf("NENHUM EXEMPLAR DISPONIVEL!\n");
                }
                else
                {
                    printf("REALIZAR EMPRESTIMO? (S) PARA SIM OU (N) PARA NAO.\n");
                    o=getch();
                    o=toupper(o);

                    if(o=='S')
                    {
                        rewind(fp);
                        while(fread(&b,sizeof(b),1,fp)==1)
                        {
                            if(c.cod==b.codLivro)
                            {
                                fscanf(fp,"%d", &b.qtda);
                                b.qtda=b.qtda-1;
                                fseek(fp,ftell(fs)-sizeof(b),0);
                                fwrite (&b,sizeof(b),1,fp);
                                fseek(fp,0,SEEK_END);

                            }
                        }
                        fs=fopen("Emprestimos.dat","ab+");
                        strcpy(c.mat,m);
                        strcpy(c.aluno,a.nomeAluno);
                        c.cod=b.codLivro;
                        strcpy(c.livro,b.nomeLivro);
                        fwrite(&c,sizeof(c),1,fs);
                        fclose(fs);
                    }
                }
            }
            fclose(fp);
            printf("EMPRESTIMO REALIZADO!\n");
        }
    }
    system("pause");
}

//FUNCAO DE DEVOLUCAO DE LIVROS EMPRESTADOS.
void devolucaoEmprestimo(EMPRESTIMOS c)
{
    char o;
    int d, i=0;

    system("cls");

    printf("DEVOLUCAO\n");

    fp=fopen("Emprestimos.dat", "rb+");
    rewind(fp);

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        printf("NENHUM EMPRESTIMO REALIZADO!\n");
    }
    else
    {
        rewind(fp);
        printf("DIGITE CODIGO DO LIVRO:\n");
        scanf("%d", &d);

        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if (d==c.cod)
            {
                printf("NOME DO ALUNO: %s\n", c.aluno);
                printf("MATRICULA: %s\n", c.mat);
                printf("NOME DO LIVRO:%s\n", c.livro);
                printf("CODIGO: %d", c.cod);

                printf("CONFIRMAR? (S) PARA SIM OU (N) PARA NAO");
                o=getch();
                o=toupper(o);
            }

            if (o=='S')
            {
                fs=fopen("remove.dat", "wb+");
                rewind(fp);
                while(fread(&c,sizeof(c),1,fp)==1)
                {
                    if(d==c.cod)
                    {
                        fseek(fs,0,SEEK_CUR);
                        fwrite(&c,sizeof(c),1,fs);
                    }
                }
                fclose(fs);
                fclose(fp);
                remove("Emprestimos.dat");
                rename("remove.dat","Emprestimos.dat");
                printf("DEVOLUCAO CONFIRMADA!\n");
            }
        }
    }
}

//LISTA TODOS OS EMPRESTIMOS.
void listarTodosEmprestimo(EMPRESTIMOS c)
{
    int i=0;

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        printf("NENHUM EMPRESTIMO CADASTRADO!\n");
    }
    else
    {
        rewind(fp);
        printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            printf("%s\t", c.aluno);
            printf("%s\t", c.mat);
            printf("%s\t", c.livro);
            printf("%d\n", c.cod);
            i++;
        }
        fclose(fp);
    }
    system("pause");
}
//LISTA OS EMPRESTIMOS DO MESMO LIVRO.
void listarEmprestimoLivro(EMPRESTIMOS c)
{
    int i=0, d;

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }

    if(i==0)
    {
        printf("\nNENHUM EMPRESTIMO CADASTRADO!\n");
    }
    else
    {
        printf("DIGITE CODIGO DO LIVRO:");
        scanf("%d", &d);
        rewind(fp);

        printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(d==c.cod)
            {
                printf("%s\t", c.aluno);
                printf("%s\t", c.mat);
                printf("%s\t", c.livro);
                printf("%d\n", c.cod);
                i++;
            }
        }
        fclose(fp);
    }
    system("pause");
}
//LISTA OS EMPRESTIMOS DO MESMO ALUNO.
void listarEmprestimoAluno(EMPRESTIMOS c)
{
    int i=0;
    char m[15];

    fp=fopen("Emprestimos.dat","rb");
    system("cls");

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        i++;
    }
    if(i==0)
    {
        printf("\nNENHUM EMPRESTIMO CADASTRADO!\n");
    }
    else
    {
        rewind(fp);
        printf("DIGITE MATRICULA DO ALUNO:");
        gets(m);
        setbuf(stdin, NULL);

        printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(strcmp(c.mat,m)==0)
            {
                printf("%s\t", c.aluno);
                printf("%s\t", c.mat);
                printf("%s\t", c.livro);
                printf("%d\n", c.cod);
                i++;
            }
        }
        fclose(fp);
    }
    system("pause");
}

void debitos()
{

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
        setbuf(stdin,NULL);
        mopt=menuPrincipal();
        switch (mopt)
        {
        case '1':
            opt=menuAcervo();
            switch (opt)
            {
            case '1':
                cadastroLivro(b);
                break;
            case '2':
                editarLivro(b);
                break;
            case '3':
                removerLivro(b);
                break;
            case '4':
                listarLivro(b);
                break;
            case '5':
                menuPrincipal();
            }
            break;
        case '2':
            opt=menuAluno();
            switch (opt)
            {
            case '1':
                cadastroAluno(a);
                break;
            case '2':
                editarAluno(a);
                break;
            case '3':
                removerAluno(a);
                break;
            case '4':
                listarAluno(a);
                break;
            case '5':
                menuPrincipal();
            }
            break;

        case '3':
            opt=menuEmprestimo();
            switch(opt)
            {
            case '1':
                novoEmprestimo(b,a,c);
                break;
            case '2':
                devolucaoEmprestimo(c);
                break;
            case '3':
                opt=menuListaEmprestimo();
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
                case '4':
                    menuPrincipal();
                    break;
                }
                break;
            case '4':
                menuPrincipal();
                break;
            }
            break;

        case '4':
            debitos();
            break;
        }
    }
    while (mopt!='5');
    system("cls");
    fim();
}
