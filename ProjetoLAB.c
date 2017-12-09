#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>

FILE *fp, *ft, *fs;

typedef struct {
    char nomeLivro[41], nomeAutor[41], area[41];
    int codLivro, qtda;
}LIVROS;

typedef struct {
    char nomeAluno[41], matricula[15], cpf[19];
    int codAluno;
}ALUNOS;

void menuPrincipal (){
    printf ("MENU PRINCIPAL\n");
    printf ("1. Acervo\n");
    printf ("2. Alunos\n");
    printf ("3. Empréstimos\n");
    printf ("4. Débitos de devoluções\n");
    printf ("5. Sair\n");
    printf ("Por Favor escolha uma das opções acima...");
}

void menuAcervo (){
    printf ("ACERVO\n");
    printf ("1. Cadastrar livro\n");
    printf ("2. Editar livro\n");
    printf ("3. Remover livro\n");
    printf ("4. Listar livros cadastrados\n");
    printf ("5. Voltar para o menu principal\n");
    printf ("Por Favor escolha uma das opções acima...");
}

void menuAluno (){
    printf ("ALUNOS\n");
    printf ("1. Cadastrar aluno\n");
    printf ("2. Editar aluno\n");
    printf ("3. Remover aluno\n");
    printf ("4. Listar alunos cadastrados\n");
    printf ("5. Voltar para o menu principal\n");
    printf ("Por Favor escolha uma das opções acima...");
}

void menuEmprestimo (){
    printf ("EMPRÉSTIMOS\n");
    printf ("1. Novo empréstimo\n");
    printf ("2. Confirmar devolução\n");
    printf ("3. Cancelar empréstimo\n");
    printf ("4. Listar empréstimos\n");
    printf ("5. Voltar para o menu principal\n");
    printf ("Por Favor escolha uma das opções acima...");
}

void menuListaEmprestimo (){
    printf ("LISTAR EMPRÉSTIMOS\n");
    printf ("1. Listar todos os empréstimos\n");
    printf ("2. Listar por livro específico\n");
    printf ("3. Listar por aluno específico\n");
    printf ("4. Voltar para menu anterior\n");
    printf ("5. Voltar para o menu principal");
    printf ("Por Favor escolha uma das opções acima...");
}

void cadastroLivro(LIVROS b, int *x){
    int o;
    char c;
    do{
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
    b.codLivro=*x+1*1000+*x;
    (*x)++;
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
        cadastroLivro(b,x);
    }
    else {
        menuAcervo();
        system("cls");
        fflush(stdin);
    }
}
    while (o!=127);
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

main(){
    setlocale (LC_ALL, "Portuguese");
    ALUNOS a;
    LIVROS b;
    int opt, x=0;

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
                            cadastroLivro(b,&x);
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
