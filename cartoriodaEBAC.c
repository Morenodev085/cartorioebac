#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espca em momoria 
#include <locale.h> //biblioteca de aloca�oes de texto por regiao
#include <string.h> //bliblioteca de string

int registro(){  // funcao de cadastramento 
		
		//cria��o das variavies 
		
		char arquivo[40];
		char cpf[40];
		char nome [40];
		char sobrenome[40];
		char cargo[40];
		
		// fim de variavesi 
		
		printf("Digite o CPFa ser cadastrado: "); // cleta de informa��o
		scanf("%s", cpf); //%s serve pra salvar string
		
		strcpy(arquivo, cpf); //reposnsavel por copiar ao valores das string
		
		FILE *file; // creia arquivo em banco de dados 
		file = fopen(arquivo, "w"); //cria o arquivo "W" dubcao escrever
		fprintf(file,cpf); // salva o valor 
		fclose(file); //fecha o arquivo **importante fechar**
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		printf("digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file= fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);	
		
		system("pause");
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que quer consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("n�o foi possivel localizar o aquivo \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar(){
	
	char cpf[40];
	
	printf("Digite o CPf a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL){
		printf("O usuario n�o foi encontado no sistema. \n");
		system("pause");
	}
	
	remove(cpf);
	
	
	if(file != NULL){
	
	printf("o usuario foi deletado com sucesso! \n");
	system("pause");
}
	
	
}

int main()
{
	
	int opcaodemenu = 0; // Definindo as variaveis 
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Comando para limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	
		printf("#### Cart�rio da EBAC #### \n\n "); // inicio do menu 
		printf("escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - sair do programa\n ");
		printf("Op��o: "); // fim do menu principal
	
	
	
	
		scanf("%d", &opcaodemenu); //mecanismo de armazenamento de responta 
	
	
		system("cls"); // linpando a tela 
		
		
		switch(opcaodemenu){
			
			case 1:
			registro();  
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Op��o invalida, use um dos numeros indicados no menu anterior");
			system("pause");
			break;
		}
	}
		
}
