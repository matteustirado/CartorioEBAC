#include <stdio.h> // biblioteca de comunicação do  usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registrar() // função responsável por cadastrar usuários no sistema
{
    // início da criação das variáveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da criação das variáveis
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
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
    
    // início da criação das variáveis
    char cpf[40];
    char conteudo[200];
    // fim da criação das variáveis
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" significa ler
    
    if (file == NULL)
    {
        printf("\nNão foi possível abrir o arquivo, usuário não localizado.\n\n");
        system("pause");
        return 0;
    }

    printf("\nEssas são as informações do usuário:\n\n");
    
    while (fgets(conteudo, 200, file) != NULL)
    {
        // início da criação das variáveis
        char *campo;
        int contador = 1;
        char nome_completo[80]; // criei uma variável para unir os nomes + sobrenome
        // fim da criação das variáveis
        
        campo = strtok(conteudo, ","); // Menu de separação para consulta "," identifica o ponto de nova informação
        
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
        printf("Arquivo não encontrado ou não existe!\n");
        system("pause");
        return 0;
    }

    // Pergunta ao usuário se tem certeza de que deseja excluir
    char resposta;
    printf("Tem certeza que deseja excluir o arquivo com CPF: %s?\n\n\t[S] [N]\n", cpf);
    
    getchar(); 
    scanf("%c", &resposta);

    if (resposta == 's' || resposta == 'S')
    {
        fclose(file);

        if (remove(cpf) == 0)
        {
            printf("\nArquivo %s excluído com sucesso!\n\n", cpf);
            system("pause");
        }
        else
        {
            // Caso não consiga excluir, imprime o erro
            perror("\nErro ao excluir o arquivo\n\n");
            system("pause");
        fclose(file);
        
        }
    }
    else if (resposta == 'n' || resposta == 'N')
    {
    	fclose(file);
    	
        // Se o usuário escolher 'N', apenas cancela a operação e permite nova tentativa
        printf("\nExclusão cancelada.\n\n");
        system("pause");
	fclose(file);
		 
	}
    else
    {
        // Caso o usuário forneça um caractere inválido
        printf("\nResposta inválida. Exclusão cancelada.\n\n");
        system("pause");
    fclose(file);
    
    }

    return 0;
}

int main ()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;
    
    while (1) 
    {
        system("cls"); // responsável por limpar a tela
    
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
        printf("\t---------------\n"); // Início do menu
        printf("\tCARTORIO EBAC\n");
        printf("\t---------------\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Opção:"); // Fim do Menu
    
        scanf("%d", &opcao); // Armazenando a escolha do user
    
        system("cls");
        
        switch(opcao) // Início da seleção
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
                printf("Esta opção não está disponível!\n");
                system("pause");
                break;    
        } // Fim da seleção
    }
}

// Código criado e gerenciado por Matteus Tirado
