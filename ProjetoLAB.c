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

typedef struct {
    char nomeLivro[41], nomeAutor[41], area[41];
    int codLivro, qtda, numero;
}LIVROS;

typedef struct {
    char nomeAluno[41], matricula[15], cpf[19];
}ALUNOS;

typedef struct{
    char aluno[41], livro[41], mat[15];
    int qtdaEmprestimo, mm, dd, aa, cod;
}EMPRESTIMOS;

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

char menuListaEmprestimo (){
    char o;
    linhasup();
    linhalat("LISTAR EMPRESTIMOS");
    linhamed();
    linhalat("1. Listar todos os emprestimos");
    linhalat("2. Listar por livro especifico");
    linhalat("3. Listar por aluno especifico");
    linhalat("4. Voltar para menu anterior");
    linhalat("5. Voltar para o menu principal");
    linhainf();
    printf ("\t\t\t\tPor Favor escolha uma das opcoes acima...");
    o=getch();
    return o;
}

void cadastroLivro(LIVROS b){
    int o;
    char c;

    fp=fopen("Livros.dat", "ab+");

    printf("CADASTRO DE LIVROS\n");
    setbuf(stdin, NULL);

    //gera-se o codigo, precisa vim anres do cadastro.
    fseek (fp,ftell(fp)-sizeof(b),SEEK_END);

    if (fread(&b,sizeof(b),1,fp)!=1){
    	b.codLivro= 1000;
	}
	else {
		fscanf(fp,"%d",&b.codLivro);
		b.codLivro=b.codLivro+1;
	}

    //cadastro do livros.
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

    fseek(fp,0,SEEK_END);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("O LIVRO FOI CADASTRADO CORRETAMENTE!\n");
    printf ("CADASTRAR OUTRO? (S) PARA SIM OU (N) PARA NAO\n");
    c=getch();
    setbuf(stdin, NULL);
    c=toupper(c);
    if (c=='S'){
        system("cls");
        cadastroLivro(b);
    }
    else {
        system("cls");
        fflush(stdin);
        menuAcervo();
    }
}

void editarLivro(LIVROS b){
    int d;
    char c;

    printf("EDIÇÃO DE LIVROS:\n");

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
            strupr(b.nomeLivro);
            setbuf(stdin,NULL);

            printf("DIGITE NOME DO AUTOR:");
            gets(b.nomeAutor);
            strupr(b.nomeAutor);
            setbuf(stdin, NULL);

            printf("DIGITE AREA DO LIVRO:");
            gets(b.area);
            strupr(b.area);
            setbuf(stdin, NULL);

            printf("DIGITE QUANTIDADE:");
            scanf("%d", &b.qtda);

            fseek(fp,ftell(fp)-sizeof(b),0);
            fwrite(&b,sizeof(b),1,fp);
            fclose(fp);
        }
    }

            printf ("EDITAR OUTRO? (S) PARA SIM (N) PARA NAO");
            c=getch();
            c=toupper(c);

            if (c=='S'){
                system("cls");
                editarLivro(b);
            }
            else{
                    system("cls");
                    fflush(stdin);
                    menuAcervo();
                }
}


void removerLivro(LIVROS b){
    int d;
    char c;

    printf("REMOVER LIVRO\n");

    fp=fopen("Livros.dat", "rb+");
    rewind(fp);

    printf("DIGITE CODIGO DO LIVRO PARA REMOVER:\n");
    scanf("%d", &d);

    while(fread(&b,sizeof(b),1,fp)==1){
        if (d==b.codLivro){
            printf("NOME: %s\n", b.nomeLivro);
            printf("CODIGO: %d\n", b.codLivro);
            printf("AUTOR:%s\n", b.nomeAutor);
            printf("AREA: %s\n", b.area);
            printf("QUANTIDADE: %d\n", b.qtda);

        printf("DELETAR? (S) PARA SIM OU (N) PARA NAO");
        c=getch();
        c=toupper(c);
        }

        if (c=='S'){
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
    setbuf(stdin, NULL);

    fseek(fp,0,SEEK_END);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("O ALUNO FOI CADASTRADO CORRETAMENTE!\n");
    printf ("CADASTRAR OUTRO? (S) PARA SIM OU (N) PARA NAO\n");
    c=getch();
    c=toupper(c);
    setbuf(stdin, NULL);

    if (c=='S'){
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
    gets(d);
    setbuf(stdin, NULL);

    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    while (fread(&a, sizeof(a),1,fp)==1){
        if(strcmp(d,a.matricula)==0){
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
    }
    if(strcmp(d,a.matricula)!=0){
            printf("ALUNO NAO CADASTRADO!\n");
        }

            printf ("EDITAR OUTRO? (S) PARA SIM (N) PARA NAO");
            c=getch();
            c=toupper(c);

            if (c=='S'){
                system("cls");
                editarAluno(a);
            }
                else{
                    system("cls");
                    menuAluno();
                }
}

void removerAluno(ALUNOS a){
    char c, d[15];

    printf("REMOVER ALUNO\n");

    fp=fopen("Alunos.dat", "rb+");
    rewind(fp);

    printf("DIGITE MATRICULA DO ALUNO PARA REMOVER:\n");
    gets(d);
    setbuf(stdin, NULL);

    while(fread(&a,sizeof(a),1,fp)==1){
        if (strcmp(d,a.matricula)==0){
            printf("NOME: %s\n", a.nomeAluno);
            printf("MATRICULA: %s\n", a.matricula);
            printf("CPF:%s\n", a.cpf);

        printf("DELETAR? (S) PARA SIM OU (N) PARA NAO");
        c=getch();
        c=toupper(c);
        }

        if (c=='S'){
            ft=fopen("remove.dat", "wb+");
            rewind(fp);
            while(fread(&a,sizeof(a),1,fp)==1){
                if(strcmp(d,a.matricula)!=0){
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
        printf("%s\n", a.cpf);
        i++;
    }
    fclose(fp);

    if(i==0){
        printf("NENHUM ALUNO CADASTRADO!\n");
    }
    system("pause");
}

void novoEmprestimo(LIVROS b, ALUNOS a, EMPRESTIMOS c){
   
}

void devolucao(EMPRESTIMOS c){

}

void cancelarEmprestimo(EMPRESTIMOS c){
     char o;
     int d;

    printf("CANCELAR EMPRESTIMO\n");

    fp=fopen("Emprestimos.dat", "rb+");
    rewind(fp);

    printf("DIGITE CODIGO DO LIVRO:\n");
    scanf("%d", &d);

    while(fread(&c,sizeof(c),1,fp)==1){
        if (d==c.cod){
            printf("NOME DO ALUNO: %s\n", c.aluno);
            printf("MATRICULA: %s\n", c.mat);
            printf("NOME DO LIVRO:%s\n", c.livro);
            printf("CODIGO: %d", c.cod);

        printf("CANCELAR? (S) PARA SIM OU (N) PARA NAO");
        o=getch();
        o=toupper(o);
        }

        if (o=='S'){
            ft=fopen("remove.dat", "wb+");
            rewind(fp);
            while(fread(&c,sizeof(c),1,fp)==1){
                if(d==c.cod){
                fseek(ft,0,SEEK_CUR);
                fwrite(&c,sizeof(c),1,ft);
                }
            }
		fclose(ft);
		fclose(fp);
		remove("Emprestimos.dat");
		rename("remove.dat","Emprestimos.dat");
		}
    }
}

void listarTodosEmprestimo(EMPRESTIMOS c){
    int i=0;

    fp=fopen("Emprestimos.dat","rb");
    printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
    while(fread(&c,sizeof(c),1,fp)==1){
        printf("%s\t", c.aluno);
        printf("%s\t", c.mat);
        printf("%s\t", c.livro);
        printf("%d\n", c.cod);
        i++;
    }
    fclose(fp);

    if(i==0){
        printf("NENHUM EMPRESTIMO CADASTRADO!\n");
    }
    system("pause");
}

void listarEmprestimoLivro(EMPRESTIMOS c){
    int i=0, d;

    fp=fopen("Emprestimos.dat","rb");
    printf("DIGITE CODIGO DO LIVRO:");
    scanf("%d", &d);

    printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
    while(fread(&c,sizeof(c),1,fp)==1){
        if(d==c.cod){
            printf("%s\t", c.aluno);
            printf("%s\t", c.mat);
            printf("%s\t", c.livro);
            printf("%d\n", c.cod);
            i++;
        }
    }
    fclose(fp);

    if(i==0){
        printf("\nNENHUM EMPRESTIMO CADASTRADO!\n");
    }
    system("pause");
}

void listarEmprestimoAluno(EMPRESTIMOS c){
    int i=0;
    char m[15];

    fp=fopen("Emprestimos.dat","rb");
    printf("DIGITE MATRICULA DO ALUNO:");
    gets(m);
    setbuf(stdin, NULL);

    printf("NOME ALUNO:\t\t\tMATRICULA:\t\t\tNOME LIVRO:\t\t\tCODIGO LIVRO:\n");
    while(fread(&c,sizeof(c),1,fp)==1){
        if(strcmp(c.mat,m)==0){
            printf("%s\t", c.aluno);
            printf("%s\t", c.mat);
            printf("%s\t", c.livro);
            printf("%d\n", c.cod);
            i++;
        }
    }
    fclose(fp);

    if(i==0){
        printf("\nNENHUM EMPRESTIMO CADASTRADO!\n");
    }
    system("pause");
}

void debitos(){

}

main(){
    ALUNOS a;
    LIVROS b;
    EMPRESTIMOS c;
    char mopt, opt;
    inicio();
    do {
        setbuf(stdin,NULL);
        system("cls");
        menuPrincipal();
        mopt=getch();
        switch (mopt){
            case '1':
                    system("cls");
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
                        default:
                            printf("OPCAO INVALIDA!!\n");
                            break;
                    }
                break;
            case '2':
                system("cls");
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
                        case '5':
                            system("cls");
                            menuPrincipal();
                    }
                    break;

            case '3':
                system("cls");
                opt=menuEmprestimo();
                switch(opt){
                    case '1':
                        system("cls");
                        novoEmprestimo(b,a,c);
                        break;
                    case '2':
                        system("cls");
                        devolucao(c);
                        break;
                    case '3':
                        system("cls");
                        cancelarEmprestimo(c);
                        break;
                    case '4':
                        system("cls");
                        opt=menuListaEmprestimo();
                        switch(opt){
                            case '1':
                                system("cls");
                                listarTodosEmprestimo(c);
                                break;
                            case '2':
                                system("cls");
                                listarEmprestimoLivro(c);
                                break;
                            case '3':
                                system("cls");
                                listarEmprestimoAluno(c);
                                break;
                            case '4':
                                system("cls");
                                menuEmprestimo();
                                break;
                            case '5':
                                system("cls");
                                menuPrincipal();
                                break;
                        }
                        break;
                    case '5':
                        system("cls");
                        menuPrincipal();
                }
                break;

            case '4':
                system("cls");
                debitos();
                break;
        }
    }
    while (mopt!='5');
    system("cls");
    fim();
}
