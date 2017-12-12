#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#define TAM 35

FILE *fp, *ft, *fs;

typedef struct {
    char nomeLivro[41], nomeAutor[41], area[41];
    int codLivro, qtda, numero;
}LIVROS;

typedef struct {
    char nomeAluno[41], matricula[15], cpf[19];
    int codAluno;
}ALUNOS;

void menuPrincipal (){
    linhasup();
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

void menuAcervo (){
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
}

void menuAluno (){
    linhasup();
    linhalat("ALUNOS");
    linhamed();
    linhalat("1. Cadastrar aluno");
    linhalat("2. Editar aluno");
    linhalat("3. Remover aluno");
    linhalat("4. Listar alunos cadastrados");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf ("\t\t\t\tPor Favor escolha uma das opcos acima...");
}

void menuEmprestimo (){
    linhasup();
    linhalat("EMPRESTIMOS");
    linhamed();
    linhalat("1. Novo emprestimo");
    linhalat("2. Confirmar devolucao");
    linhalat("3. Cancelar emprestimo");
    linhalat("4. Listar emprestimos");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf("\t\t\t\tPor Favor escolha uma das opcoes acima...");
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
    setbuf(stdin, NULL);
    printf("DIGITE NOME DO AUTOR:");
    gets(b.nomeAutor);
    setbuf(stdin, NULL);
    printf("DIGITE AREA DO LIVRO:");
    gets (b.area);
    setbuf(stdin, NULL);
    printf("DIGITE QUANTIDADE DO LIVRO:");
    scanf("%d", &b.qtda);
    setbuf(stdin, NULL);
    b.codLivro=(b.numero)+1*1000+(b.numero);
    (b.numero)++;
    fseek(fp,0,SEEK_END);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("O LIVRO FOI CADASTRADO CORRETAMENTE!\n");
    printf ("CADASTRAR OUTRO? (S) PARA SIM OU (N) PARA NÃO\n");
    scanf("%c", &c);
    toupper(c);
    setbuf(stdin, NULL);
    if (c=='S'){
        system("cls");
        cadastroLivro(b);
    }
    else {
        menuAcervo();
        system("cls");
        fflush(stdin);
    }
    system("pause");
}

void editarLivro(LIVROS *b){
    int d;
    char c;
    printf("EDIÇÃO DE LIVROS:\n");
    printf("DIGITE O CÓDIGO DO LIVRO PARA EDITAR:");
    scanf("%d", &d);
    fp=fopen("Livros.dat", "rb+");
    rewind(fp);
    while (fread(&b, sizeof(b),1,fp)==1){
        if(b->codLivro==d){
            printf("NOME:\n", b->nomeLivro);
            printf("AUTOR:\n", b->nomeAutor);
            printf("DIGITE NOVO NOME:");
            gets(b->nomeLivro);
            setbuf(stdin, NULL);
            printf("DIGITE NOME DO AUTOR:");
            gets(b->nomeAutor);
            setbuf(stdin, NULL);
            printf("DIGITE QUANTIDADE:");
            scanf("%d", &b->qtda);
            fseek(fp,ftell(fp)-sizeof(b),0);
            fwrite(&b,sizeof(b),1,fp);
            fclose(fp);
        }
            printf ("EDITAR OUTRO? (S) par sim e (N) para não");
            scanf ("%c", &c);
            toupper(c);
            if (c=='S'){
                system("cls");
                editarLivro(b);
                fflush(stdin);
            }
            else{
                    menuAcervo();
                    fflush(stdin);
                }
        }
}


void removerLivro(LIVROS *b){
    int d;
    char c;
    printf("REMOVER LIVRO\n");
    printf("DIGITE CÓDIGO DO LIVRO PARA REMOVER:\n");
    scanf("%d", &d);
    fp=fopen("Livros.dat", "rb+");
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1){
        if (d==b->codLivro){
            printf("NOME: %s\n", b->nomeLivro);
            printf("CÓDIGO: %d\n", b->codLivro);
            printf("AUTOR:%s\n", b->nomeAutor);
            printf("ÁREA: %s\n", b->area);
            printf("QUANTIDADE: %d\n", b->qtda);
        }
        printf("DELETAR? (S) PARA SIM OU (N) PARA NÃO");
        scanf("%c", &c);
        toupper(c);
        if (c=='S'){
            ft=fopen("remove.dat", "wb+");
            rewind(fp);
            while(fread(&b,sizeof(b),1,fp)==1){
		    if(b->codLivro!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&b,sizeof(b),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("Livros.dat");
		rename("remover.dat","Livros.dat");
		}
    }
}

void listarLivro(LIVROS b){
    int i=0;
    fp=fopen("Livros.dat","rb");
    while(fread(&b,sizeof(b),1,fp)==1){
        printf("NOME:\t\t\tCÓDIGO:\t\t\tAUTOR:\t\t\tQUANTIDADE:\t\t\tÁREA:\n");
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

main(){
    setlocale(LC_ALL, "");
    ALUNOS a;
    LIVROS b;
    int opt, x=0;
    inicio();
    do {
        setbuf(stdin,NULL);
        system("cls");
        menuPrincipal();
        scanf ("%d", &opt);
        switch (opt){
            case 1:
                system("cls");
                menuAcervo();
                scanf ("%d", &opt);
                    switch (opt){
                        case 1:
                            system("cls");
                            cadastroLivro(b);
                            break;
                        case 2:
                            system("cls");
                            editarLivro(&b);
                            break;
                        case 3:
                            system("cls");
                            removerLivro(&b);
                            break;
                        case 4:
                            system("cls");
                            listarLivro(b);
                            break;
			case 5:
			    system("cls");
			    menuPrincipal();
                    }
                break;

            case 2:
                system("cls");
                menuAluno();
                scanf ("%d", &opt);
                    switch (opt){
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        case 4:

                            break;
                    }
                    break;

            case 3:
                system("cls");
                menuEmprestimo();
                scanf ("%d", &opt);
                break;

            case 4:

                break;
        }
    }
    while (opt!=5);
}
