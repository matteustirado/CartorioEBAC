#include <stdio.h> // biblioteca de comunica��o do  usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registrar() // fun��o respons�vel por cadastrar usu�rios no sistema
{
    // in�cio da cria��o das vari�veis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da cria��o das vari�veis
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // "w" significa escrever
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a"); // "a" significa atualizar
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    printf("\n\n");
    
    system("pause");
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese");
    
    // in�cio da cria��o das vari�veis
    char cpf[40];
    char conteudo[200];
    // fim da cria��o das vari�veis
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" significa ler
    
    if (file == NULL)
    {
        printf("\nN�o foi poss�vel abrir o arquivo, usu�rio n�o localizado.\n\n");
        system("pause");
        return 0;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n\n");
    
    while (fgets(conteudo, 200, file) != NULL)
    {
        // in�cio da cria��o das vari�veis
        char *campo;
        int contador = 1;
        char nome_completo[80]; // criei uma vari�vel para unir os nomes + sobrenome
        // fim da cria��o das vari�veis
        
        campo = strtok(conteudo, ","); // Menu de separa��o para consulta "," identifica o ponto de nova informa��o
        
        while (campo != NULL)
        {
            switch (contador)
            {
                case 1:
                    printf("CPF: %s\n", campo);
                    break;
                
                case 2:
                    strcpy(nome_completo, campo);
                    break;
                    
                case 3:
                    strcat(nome_completo, " ");
                    strcat(nome_completo, campo);
                    printf("Nome: %s\n", nome_completo);
                    break;
                                    
                case 4:
                    printf("Cargo: %s\n\n", campo);
                    break;
                
                default:
                    break;
            }
            
            campo = strtok(NULL, ",");
            contador++;
        }
    }
    
    fclose(file);
    system("pause");
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do cadastro que deseja deletar: ");
    scanf("%s", cpf);

    printf("\n");

    FILE *file = fopen(cpf, "r"); 
    
    if (file == NULL)
    {
    	fclose(file);
        printf("Arquivo n�o encontrado ou n�o existe!\n");
        system("pause");
        return 0;
    }

    // Pergunta ao usu�rio se tem certeza de que deseja excluir
    char resposta;
    printf("Tem certeza que deseja excluir o arquivo com CPF: %s?\n\n\t[S] [N]\n", cpf);
    
    getchar(); 
    scanf("%c", &resposta);

    if (resposta == 's' || resposta == 'S')
    {
        fclose(file);

        if (remove(cpf) == 0)
        {
            printf("\nArquivo %s exclu�do com sucesso!\n\n", cpf);
            system("pause");
        }
        else
        {
            // Caso n�o consiga excluir, imprime o erro
            perror("\nErro ao excluir o arquivo\n\n");
            system("pause");
        fclose(file);
        
        }
    }
    else if (resposta == 'n' || resposta == 'N')
    {
    	fclose(file);
    	
        // Se o usu�rio escolher 'N', apenas cancela a opera��o e permite nova tentativa
        printf("\nExclus�o cancelada.\n\n");
        system("pause");
	fclose(file);
		 
	}
    else
    {
        // Caso o usu�rio forne�a um caractere inv�lido
        printf("\nResposta inv�lida. Exclus�o cancelada.\n\n");
        system("pause");
    fclose(file);
    
    }

    return 0;
}

int main ()
{
    int opcao = 0; // Definindo vari�veis
    int laco = 1;
    
    while (1) 
    {
        system("cls"); // respons�vel por limpar a tela
    
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
        printf("\t---------------\n"); // In�cio do menu
        printf("\tCARTORIO EBAC\n");
        printf("\t---------------\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Op��o:"); // Fim do Menu
    
        scanf("%d", &opcao); // Armazenando a escolha do user
    
        system("cls");
        
        switch(opcao) // In�cio da sele��o
        {
            case 1:
                registrar();
                break;
            
            case 2:
                consultar();
                break;
            
            case 3:
                deletar();
                break;
                
            case 4:
            	printf("Obrigado por utilizar o sistema\n\n");
            	return 0;
            	break;
            
            default:
                printf("Esta op��o n�o est� dispon�vel!\n");
                system("pause");
                break;    
        } // Fim da sele��o
    }
}

// C�digo criado e gerenciado por Matteus Tirado
