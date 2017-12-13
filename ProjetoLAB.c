#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

#define TAM 35

FILE *fp, *ft, *fs;

typedef struct{

}EMPRESTIMOS;

typedef struct {
    char nomeLivro[41], nomeAutor[41], area[41];
    int codLivro, qtda, numero;
}LIVROS;

typedef struct {
    char nomeAluno[41], matricula[15], cpf[19];
    int codAluno;
}ALUNOS;

COORD coord = {0, 0};
COORD max_res,cursor_size;

void gotoxy (int x, int y){
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int segundos)
{
    clock_t chegada = segundos + clock();
    while (chegada > clock());
}

void linhasup(){
    int i;
    printf("\t\t\t\t%c", 201);
    for(i=0;i<TAM;i++)
        printf("%c", 205);
    printf("%c\n", 187);
}

void linhainf(){
    int i;
    printf("\t\t\t\t%c", 200);
    for(i=0;i<TAM;i++)
        printf("%c", 205);
    printf("%c\n", 188);
}

void linhamed(){
    int i;
    printf("\t\t\t\t%c", 204);
    for(i=0;i<TAM;i++)
        printf("%c", 205);
    printf("%c\n", 185);
}

void linhalat(char st[]){
    int i, contlet = 0;
    for(i=0;i<TAM;i++){
        if(st[i]=='\0')
            break;
        else
            contlet++;
    }
    printf("\t\t\t\t%c", 186);
    printf("%s", st);
    while(contlet<TAM){
        printf("%c", 32);
        contlet++;
    }
    printf("%c\n", 186);
}

void inicio(){
    int i;
    linhasup();
    linhalat("CARREGANDO POR FAVOR AGUARDE...");
    linhainf();
    for(i=0;i<104;i++){
        Sleep(1);
        printf("%c", 219);
    }
}

void fim(){
    int i;
    linhasup();
    linhalat("ENCERRANDO...");
    linhainf();
    for(i=0;i<104;i++){
        Sleep(1);
        printf("%c", 219);
    }
}

void menuPrincipal (){
    linhasup();
    system("cls");
    linhalat("MENU PRINCIPAL");
    linhamed();
    linhalat("1. Acervo");
    linhalat("2. Alunos");
    linhalat("3. Emprestimos");
    linhalat("4. Debitos de devolucoes");
    linhalat("5. Sair");
    linhainf();
    printf("\t\t\t\tPor Favor escolha uma das opcoes acima...");
}

char menuAcervo (){
    char o;
    system("cls");
    linhasup();
    linhalat("ACERVO");
    linhamed();
    linhalat("1. Cadastrar livro");
    linhalat("2. Editar livro");
    linhalat("3. Remover livro");
    linhalat("4. Listar livros cadastrados");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf ("\t\t\t\tPor Favor escolha uma das opcoes acima...");
    o=getch();
    return o;
}

char menuAluno (){
    char o;
    system("cls");
    linhasup();
    linhalat("ALUNOS");
    linhamed();
    linhalat("1. Cadastrar aluno");
    linhalat("2. Editar aluno");
    linhalat("3. Remover aluno");
    linhalat("4. Listar alunos cadastrados");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf ("\t\t\t\tPor Favor escolha uma das opcoes acima...");
    o=getch();
    return o;
}

char menuEmprestimo (){
    char o;
    linhasup();
    system("cls");
    linhalat("EMPRESTIMOS");
    linhamed();
    linhalat("1. Novo emprestimo");
    linhalat("2. Confirmar devolucao");
    linhalat("3. Cancelar emprestimo");
    linhalat("4. Listar emprestimos");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf("\t\t\t\tPor Favor escolha uma das opcoes acima...");
    o=getch();
    return o;
}

void menuListaEmprestimo (){
    linhasup();
    printf ("LISTAR EMPRESTIMOS");
    linhamed();
    linhalat("1. Listar todos os emprestimos");
    linhalat("2. Listar por livro especifico");
    linhalat("3. Listar por aluno especifico");
    linhalat("4. Voltar para menu anterior");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf ("\t\t\t\tPor Favor escolha uma das opções acima...");
}

void cadastroLivro(LIVROS b){
    int o;
    char c;

    fp=fopen("Livros.dat", "ab+");

    printf("CADASTRO DE LIVROS\n");
    setbuf(stdin, NULL);

    printf("DIGITE NOME DO LIVRO:");
    gets(b.nomeLivro);
    strupr(b.nomeLivro);
    setbuf(stdin, NULL);

    printf("DIGITE NOME DO AUTOR:");
    gets(b.nomeAutor);
    strupr(b.nomeAutor);
    setbuf(stdin, NULL);

    printf("DIGITE AREA DO LIVRO:");
    gets (b.area);
    strupr(b.area);
    setbuf(stdin, NULL);

    printf("DIGITE QUANTIDADE DO LIVRO:");
    scanf("%d", &b.qtda);
    setbuf(stdin, NULL);

    fseek (fp,ftell(fp)-sizeof(b),SEEK_END);
    fscanf(fp,"%d",b.numero);

    if (fread(&b,sizeof(b),1,fp)!=1){
    	b.codLivro= 1000;
	}
	else {
		fseek(fp,sizeof(b),SEEK_END);
		fscanf(fp,"%d",&b.codLivro);
	}

    b.codLivro=b.codLivro+1;
    (b.numero)++;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("O LIVRO FOI CADASTRADO CORRETAMENTE!\n");
    printf ("CADASTRAR OUTRO? (S) PARA SIM OU (N) PARA NAO\n");
    scanf("%c", &c);
    setbuf(stdin, NULL);

    if (c=='S' || c=='s'){
        system("cls");
        cadastroLivro(b);
    }
    else {
        system("cls");
        menuAcervo();
    }
}

void editarLivro(LIVROS b){
    int d;
    char c;

    printf("EDICAO DE LIVROS:\n");

    printf("DIGITE O CODIGO DO LIVRO PARA EDITAR:");
    scanf("%d", &d);

    fp=fopen("Livros.dat", "rb+");
    rewind(fp);

    while (fread(&b, sizeof(b),1,fp)==1){
        if(b.codLivro==d){
            printf("NOME:%s\n", b.nomeLivro);
            printf("AUTOR:%s\n", b.nomeAutor);

            printf("DIGITE NOVO NOME:");
            setbuf(stdin,NULL);
            gets(b.nomeLivro);
            setbuf(stdin,NULL);

            printf("DIGITE NOME DO AUTOR:");
            gets(b.nomeAutor);
            setbuf(stdin, NULL);

            printf("DIGITE QUANTIDADE:");
            scanf("%d", &b.qtda);

            fseek(fp,ftell(fp)-sizeof(b),0);
            fwrite(&b,sizeof(b),1,fp);
            fclose(fp);
        }
            printf ("EDITAR OUTRO? (S) PARA SIM (N) PARA NAO");
            scanf ("%c", &c);

            if (c=='S' || c=='s'){
                system("cls");
                editarLivro(b);
                fflush(stdin);
            }
            else{
                    system("cls");
                    menuAcervo();
                }
        }
}


void removerLivro(LIVROS b){
    int d;
    char c;

    printf("REMOVER LIVRO\n");

    printf("DIGITE CODIGO DO LIVRO PARA REMOVER:\n");
    scanf("%d", &d);

    fp=fopen("Livros.dat", "rb+");
    rewind(fp);

    while(fread(&b,sizeof(b),1,fp)==1){
        if (d==b.codLivro){
            printf("NOME: %s\n", b.nomeLivro);
            printf("CODIGO: %d\n", b.codLivro);
            printf("AUTOR:%s\n", b.nomeAutor);
            printf("AREA: %s\n", b.area);
            printf("QUANTIDADE: %d\n", b.qtda);
        }

        printf("DELETAR? (S) PARA SIM OU (N) PARA NAO");
        scanf("%c", &c);

        if (c=='S' || c=='s'){
            ft=fopen("remove.dat", "wb+");
            rewind(fp);
            while(fread(&b,sizeof(b),1,fp)==1){
		    if(b.codLivro!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&b,sizeof(b),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("Livros.dat");
		rename("remove.dat","Livros.dat");
		}
    }
}

void listarLivro(LIVROS b){
    int i=0;

    fp=fopen("Livros.dat","rb");
printf("NOME:\t\t\tCODIGO:\t\t\tAUTOR:\t\t\tQUANTIDADE:\t\t\tAREA:\n");
    while(fread(&b,sizeof(b),1,fp)==1){
        printf("%s\t", b.nomeLivro);
        printf("%d\t", b.codLivro);
        printf("%s\t", b.nomeAutor);
        printf("%d\t", b.qtda);
        printf("%s\n", b.area);
        i=i+b.qtda;
    }

    printf("TOTAL DE LIVROS: %d\n", i);
    fclose(fp);

    if(i==0){
        printf("NENHUM LIVRO CADASTRADO!\n");
    }
    system("pause");
}

void cadastroAluno(ALUNOS a){
    int o;
    char c;

    fp=fopen("Alunos.dat", "ab+");

    printf("CADASTRO DE ALUNO\n");
    setbuf(stdin, NULL);

    printf("DIGITE NOME DO ALUNO:");
    gets(a.nomeAluno);
    strupr(a.nomeAluno);
    setbuf(stdin, NULL);

    printf("DIGITE MATRICULA DO ALUNO:");
    gets(a.matricula);
    setbuf(stdin, NULL);

    printf("DIGITE CPF DO ALUNO:");
    gets (a.cpf);
    strupr(a.cpf);
    setbuf(stdin, NULL);

    fseek(fp,0,SEEK_END);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("O ALUNO FOI CADASTRADO CORRETAMENTE!\n");
    printf ("CADASTRAR OUTRO? (S) PARA SIM OU (N) PARA NAO\n");
    scanf("%c", &c);
    setbuf(stdin, NULL);

    if (c=='S' || c=='s'){
        system("cls");
        cadastroAluno(a);
    }
    else {
        system("cls");
        menuAluno();
    }
}

void editarAluno(ALUNOS a){
    char c, d[15];

    printf("EDICAO DE ALUNOS:\n");

    printf("DIGITE MATRICULA DO ALUNO PARA EDITAR:");
    scanf("%d", &d);

    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    while (fread(&a, sizeof(a),1,fp)==1){
        if(strcmp(a.matricula,d)==0){
            printf("NOME:%s\n", a.nomeAluno);
            printf("CPF:%s\n", a.cpf);

            setbuf(stdin, NULL);
            printf("DIGITE NOVO NOME:");
            gets(a.nomeAluno);
            strupr(a.nomeAluno);
            setbuf(stdin,NULL);

            printf("DIGITE MATRICULA:");
            gets(a.matricula);
            setbuf(stdin, NULL);

            printf("DIGITE CPF:");
            gets(a.cpf);
            setbuf(stdin, NULL);

            fseek(fp,ftell(fp)-sizeof(a),0);
            fwrite(&a,sizeof(a),1,fp);
            fclose(fp);
        }
            printf ("EDITAR OUTRO? (S) PARA SIM (N) PARA NAO");
            scanf ("%c", &c);

            if (c=='S' || c=='s'){
                system("cls");
                editarAluno(a);
            }
                else{
                    system("cls");
                    menuAluno();
                }
        }
}

void removerAluno(ALUNOS a){
    char c, d[15];

    printf("REMOVER ALUNO\n");

    printf("DIGITE MATRICULA DO ALUNO PARA REMOVER:\n");
    gets(a.matricula);

    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1){
        if (strcmp(a.matricula,d)==0){
            printf("NOME: %s\n", a.nomeAluno);
            printf("MATRICULA: %d\n", a.matricula);
            printf("CPF:%s\n", a.cpf);
        }

        printf("DELETAR? (S) PARA SIM OU (N) PARA NAO");
        scanf("%c", &c);

        if (c=='S' || c=='s'){
            ft=fopen("remove.dat", "wb+");
            rewind(fp);
            while(fread(&a,sizeof(a),1,fp)==1){
		    if(strcmp(a.matricula,d)!=0)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("Alunos.dat");
		rename("remove.dat","Alunos.dat");
		}
    }
}

void listarAluno(ALUNOS a){
    int i=0;

    fp=fopen("Alunos.dat","rb");
printf("NOME:\t\t\tMATRICULA:\t\t\tCPF:\n");
    while(fread(&a,sizeof(a),1,fp)==1){
        printf("%s\t", a.nomeAluno);
        printf("%s\t", a.matricula);
        printf("%s\t", a.cpf);
    }
    fclose(fp);

    if(i==0){
        printf("NENHUM ALUNO CADASTRADO!\n");
    }
    system("pause");
}

main(){
    ALUNOS a;
    LIVROS b;
    char mopt, opt;
    inicio();
    do {
        setbuf(stdin,NULL);
        system("cls");
        menuPrincipal();
        mopt=getch();
        switch (mopt){
            case '1':
                opt=menuAcervo();
                    switch (opt){
                        case '1':
                            system("cls");
                            cadastroLivro(b);
                            break;
                        case '2':
                            system("cls");
                            editarLivro(b);
                            break;
                        case '3':
                            system("cls");
                            removerLivro(b);
                            break;
                        case '4':
                            system("cls");
                            listarLivro(b);
                            break;
                        case '5':
                        system("cls");
                        menuPrincipal();
                    }
                break;

            case '2':
                opt=menuAluno();
                    switch (opt){
                        case '1':
                            system("cls");
                            cadastroAluno(a);
                            break;
                        case '2':
                            system("cls");
                            editarAluno(a);
                            break;
                        case '3':
                            system("cls");
                            removerAluno(a);
                            break;
                        case '4':
                            system("cls");
                            listarAluno(a);
                            break;
                    }
                    break;

            case '3':
                opt=menuEmprestimo();
                break;

            case '4':

                break;
        }
    }
    while (mopt!='5');
    system("cls");
    fim();
}
