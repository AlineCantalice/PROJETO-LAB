#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    char bookName[41], authorName[41], course[41];
    int bookCod, number;
}CAD_BOOK;

typedef struct {
    char studentName[41], registration[15], cpf[15];
    int studentCod;
    CAD_BOOK *b;
}CAD_STUDENT;

void menuPrincipal();
void menuAcervo();
void menuAluno();
void menuEmprestimo();
void menuListaEmprestimo();
void cadastroLivro (CAD_BOOK *x, int *y);
void editarLivro (CAD_BOOK *x, int *y);
void removerLivro (CAD_BOOK *x, int *y);
void listarLivro (CAD_BOOK *x, int *y);
void cadastroAluno(CAD_STUDENT *s, int *c, int *y);
void editarAluno(CAD_STUDENT *s, int *c, int *y);
void removerAluno(CAD_STUDENT *s, int *c);
void listarAluno(CAD_STUDENT *s, int *c);

main (){
    setlocale (LC_ALL, "Portuguese");
    CAD_STUDENT *a;
    CAD_BOOK *b[1000];
    char atualDate[15], dataEmprestimo[15], dataDevolucao[15];
    int opt, *qtdaLivros=0, *qtdaEmprestimos=0;

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
                            cadastroLivro(*b, qtdaLivros);
                            break;
                        case 2:
                            system("cls");
                            editarLivro(*b, qtdaLivros);
                            break;
                        case 3:
                            system("cls");
                            removerLivro(*b, qtdaLivros);
                            break;
                        case 4:
                            system("cls");
                            listarLivro(*b, qtdaLivros);
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

                break;

            case 4:

                break;
        }
    }
    while (opt!=5);
}

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

void cadastroLivro (CAD_BOOK *x, int *y){
    int i;
    if (*y<1000){
    printf ("CADASTRO DO NOVO LIVRO\n");
    setbuf (stdin, NULL);
    printf ("Digite o nome do livro:");
    gets ((x+*y)->bookName);
    setbuf (stdin, NULL);
    printf ("Digite o nome do autor do livro:");
    gets ((x+*y)->authorName);
    setbuf (stdin, NULL);
    printf ("Digite a área de conhecimento do livro:");
    gets ((x+*y)->course);
    setbuf (stdin, NULL);
    printf ("Digite a quantidade de disponibilidade para empréstimos desse livro:");
    scanf ("%d", &(x+*y)->number);
    setbuf (stdin, NULL);
    for (i=0; i<(x+*y)->number; i++){
        (x+i)->bookCod=*y+1*1000+*y+1;
        }
    setbuf (stdin, NULL);
    *y+=1;
    }
    else {
        printf ("NÚMERO MÁXIMO DE LIVROS ATINGIDO\n");
    }
    system ("pause");

}

void editarLivro (CAD_BOOK *x, int *y){
    int i, cod;
    printf ("EDITAR LIVRO\n");
    printf ("Digite código do livro que deseja editar:");
    scanf ("%d", &cod);
    for (i=0; i<*y; i++){
        if (cod==(x+i)->bookCod){
            printf ("NOME DO LIVRO: %s\n", (x+i)->bookName);
            printf ("NOME DO AUTOR: %s\n", (x+i)->authorName);
            printf ("Digite novo nome para o livro:");
            gets ((x+i)->bookName);
            setbuf (stdin,NULL);
            printf ("Digite novo nome para o autor do livro:");
            gets ((x+i)->authorName);
            setbuf (stdin,NULL);
        }
    }
    system ("pause");

}

void removerLivro (CAD_BOOK *x, int *y){
    int i, cod;
    printf ("REMOVER LIVRO\n");
    printf ("Digite código do livro para remover do acervo:");
    scanf ("%d", &cod);
    for (i=0; i<*y; i++){
        if (cod==(x+i)->bookCod){
            (x+i)->bookName==NULL;
            (x+i)->authorName==NULL;
            (x+i)->bookCod==0;
            *y--;
        }
    }
    system ("pause");

}

void listarLivro (CAD_BOOK *x, int *y){
    int i;
    printf ("LISTA DE LIVROS CADASTRADOS\n");
    for (i=0; i<*y; i++){
    printf ("NOME DO LIVRO:\n");
    puts ((x+i)->bookName);
    printf ("NOME DO AUTOR:\n");
    puts ((x+i)->authorName);
    printf ("CÓDIGO DO LIVRO:\n");
    printf ("%d\n", (x+i)->bookCod);
    }
    system ("pause");

}
