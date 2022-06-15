#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

//         CORES

#define gray   "\e[30;10m" // normal
#define grayn  "\e[30;1m" // negrito
#define grayf  "\e[30;2m" // fraco
#define grayi  "\e[30;3m" // itálico
#define grays  "\e[30;4m" // sublinhado
#define grayp  "\e[30;5m" // piscando
#define grayb  "\e[30;7m" // background
#define grayc  "\e[30;9m" // cancelado

#define red   "\e[31;10m" // normal
#define redn  "\e[31;1m" // negrito
#define redf  "\e[31;2m" // fraco
#define redi  "\e[31;3m" // itálico
#define reds  "\e[31;4m" // sublinhado
#define redp  "\e[31;5m" // piscando
#define redb  "\e[31;7m" // background
#define redc  "\e[31;9m" // cancelado

#define green   "\e[32;10m" // normal
#define greenn  "\e[32;1m" // negrito
#define greenf  "\e[32;2m" // fraco
#define greeni  "\e[32;3m" // itálico
#define greens  "\e[32;4m" // sublinhado
#define greenp  "\e[32;5m" // piscando
#define greenb  "\e[32;7m" // background
#define greenc  "\e[32;9m" // cancelado

#define yellow   "\e[33;10m" // normal
#define yellown  "\e[33;1m" // negrito
#define yellowf  "\e[33;2m" // fraco
#define yellowi  "\e[33;3m" // itálico
#define yellows  "\e[33;4m" // sublinhado
#define yellowp  "\e[33;5m" // piscando
#define yellowb  "\e[33;7m" // background
#define yellowc  "\e[33;9m" // cancelado

#define blue   "\e[34;10m" // normal
#define bluen  "\e[34;1m" // negrito
#define bluef  "\e[34;2m" // fraco
#define bluei  "\e[34;3m" // itálico
#define blues  "\e[34;4m" // sublinhado
#define bluep  "\e[34;5m" // piscando
#define blueb  "\e[34;7m" // background
#define bluec  "\e[34;9m" // cancelado

#define purple   "\e[35;10m" // normal
#define purplen  "\e[35;1m" // negrito
#define purplef  "\e[35;2m" // fraco
#define purplei  "\e[35;3m" // itálico
#define purples  "\e[35;4m" // sublinhado
#define purplep  "\e[35;5m" // piscando
#define purpleb  "\e[35;7m" // background
#define purplec  "\e[35;9m" // cancelado

#define cyan   "\e[36;10m" // normal
#define cyann  "\e[36;1m" // negrito
#define cyanf  "\e[36;2m" // fraco
#define cyani  "\e[36;3m" // itálico
#define cyans  "\e[36;4m" // sublinhado
#define cyanp  "\e[36;5m" // piscando
#define cyanb  "\e[36;7m" // background
#define cyanc  "\e[36;9m" // cancelado

#define white   "\e[38;10m" // normal
#define whiten  "\e[38;1m" // negrito
#define whitef  "\e[38;2m" // fraco
#define whitei  "\e[38;3m"// itálico
#define whites  "\e[38;4m" // sublinhado
#define whitep  "\e[38;5m" // piscando
#define whiteb  "\e[38;7m" // background
#define whitec  "\e[38;9m" // cancelado

#define off  "\e[m" // desliga



int main(void)
{
	struct agendamed
	{
		char nome[50];
		float cpf;
		char sexo[2];
		float idade;
		char email[50];
		float telefone;
		float cep;
		char bairro[50];
		char cidade[50];
		char estado[2];	
		char cadastro_login[50];
		char cadastro_senha[50];		
	}cadmed;

	
	// VARIÁVEIS:
	
	char agenda_exames[9][5];
	char agenda_consulta[9][5];
	int l, col;
	char acesso_login[50], acesso_senha[50];
	char c;
	char dia_consulta[10];
	char dia_exame[10];
	int a=0,b=1,d=3;// d controlará a quantidade de erros ao logar no sistema
	int i, j,k=0, n_cont;
	int opcaomenu;
	int opcaologin;
	int dia, hora;
	int diaE, horaE;
	int horario_consulta;
	int horario_exame;
	int *consulta_dia = &dia;
	int *consulta_horario = &hora; 
	int *exame_dia = &diaE;
	int *exame_horario = &horaE;
	int ler_consultas(int *rL,int *rC,int *rB);
	int get_size_consultas(const char* file_name);
	int gravar_consultas(int linha,int coluna);
	int ler_exames(int *rL,int *rC,int *rB);
	int get_size_exames(const char* file_name);
	int gravar_exames(int linha,int coluna);
	int colunasP[45];
	int linhasP[45];
	int pause;
	int colunasPE[45];
	int linhasPE[45];
	int pauseE;
	int tratamento_cpf();
	int tratamento_idade();
	int tratamento_cep();
	int tratamento_telefone();
	int tratamento_horario_consulta();
	int tratamento_horario_exames();
	
	// PONTEIROS:
	FILE *cadastro;
	
	void Movexy(int x, int y);
	void carregamento();
	void Retangulo(int ho, int vo, int larg, int alt);
	
	system("mode con:cols=77 lines=47");
	system("color 00");
	
    carregamento();
    
    do 
	{
		i = 0;
	    Retangulo(1,1,72,44);
	    Retangulo(21,2,34,2);
	    
	    Movexy(23,3); printf(whiten"[!]SEJA BEM VINDO AO SISTEMA[!]"off);
	    Movexy(4,6); printf("Escolha a opcao em que voce se enquadra: ");
	    Movexy(4,8); printf("(1)-LOGIN");
	    Movexy(4,10); printf("(2)-CADASTRAR-SE");
	    
			Movexy(4,12); printf("Selecione:\t");
		    scanf("%d", &opcaologin);
		    	
		    system("cls");
		    switch(opcaologin)
			{
					
					
					case 1:
						do
						{ 
							if ((cadastro = fopen("Agenda_Medicos.txt", "rb")) == NULL)
			            	{
			                	printf("HOUVE UM ERRO AO ABRIR O ARQUIVO. O PROGRAMA SERA FECHADO.\n\n");
								printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR.\n");
								getch();
								exit(1);
							}
						
							fread(&cadmed, sizeof(struct agendamed), 1, cadastro);
							int erro=0;
							
							Retangulo(1,1,72,44);
			    			Retangulo(31,2,14,2);
			    			Movexy(33,3); printf(whiten"[!]LOGIN[!]"off);
			    			Movexy(4,6); printf(whiten">Entre com o login: "off);
			           		fflush(stdin);      //Limpando o buffer do teclado
			           		gets(acesso_login);
			          		Movexy(4,8); printf(whiten">Entre com a senha: "off);
			           		a=0;
			               	do
						   	{
			                	c=getch();
			                	if(isprint(c))
								{      //Verifica o valor de c, se será imprimível.
			                   		acesso_senha[a]=c;
			                   		a++;
			                   		printf("*");      //Mostrando ao visor, onde se digita, mostrando apenas o asterisco *
			                   	}
			                   	else if(c==8&&a)
								{
			                   		acesso_senha[a]='\0';
			                   		a--;
			                   		printf("\b \b");     //Apagando os caracteres digitados
			                   	}
			               	}while(c!=13);           //13 é o valor de ENTER na tabela ASCII
			               	acesso_senha[a]='\0';
			               	fflush(stdin);
			               	     	
			               	if((strcmp(acesso_login, cadmed.cadastro_login)) == 0 && (strcmp(acesso_senha, cadmed.cadastro_senha)) == 0)
							{
							
								fclose (cadastro);
								k=1;
								break;
							}
							else
						    {
			               		d--;          //Quando a variavel D for igual a 0, sistema irá bloquear o sistema, logo finalizando o mesmo.
			               		if (d) Movexy(10,10);printf(redn"\t\a\tSENHA INVALIDA - TENTE NOVAMENTE..."off);
			               		getch();
								system("cls");
			                }
			       			}while(b&&d);   //Enquanto as variaveis b e d serem diferente de ==zero==.
							                      
			       			if(k==1)
			       			{
			       				break;
							}
							
			       			else if(!d) Movexy(4,15);printf(redn"\t\aCONTA BLOQUEADA - VOCE ERROU 3 VEZES CONSECUTIVAS..."off); //Contagem de erros até 3 vezes, se errar as 3, sistema encerra. A variavel !d é o mesmo que d==0
			       			{
			       				Retangulo(1,1,72,44);
			       				getch();
			       				exit(1);
							}
							if ((cadastro = fopen("Agenda_Medicos.txt", "rb")) == NULL)
			            	{
			                	printf("HOUVE UM ERRO AO ABRIR O ARQUIVO. O PROGRAMA SERA FECHADO.\n\n");
								printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR.\n");
								getch();
								exit(1);
							}
				
					break;
				
					case 2:
						
					if ((cadastro = fopen("Agenda_Medicos.txt", "wb")) == NULL)
					{
						printf("HOUVE UM ERRO AO ABRIR O ARQUIVO. O PROGRAMA SERA FECHADO.\n\n");
						printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR.\n");
						getch();
						exit(1);
					}
										
			        system("cls");
			        Retangulo(1,1,72,44);
			        Retangulo(24,2,26,2);
			        
			        Movexy(25,3); printf(purplen"[!]CADASTRO DE USUARIO[!]"off);
			        
					fflush(stdin);
			        Movexy(4,6); printf(whiten">Cadastrar Login:"off);
			        gets(cadmed.cadastro_login);
			        
			        fflush(stdin);
			        Movexy(4,8); printf(whiten">Cadastrar Senha:"off);
			        do
					{
			    		c=getch();
			        	if(isprint(c))
						{       //Analisa se o valor da variável c é imprimivel
			           		cadmed.cadastro_senha[a]=c;  //Se for, armazena o dado inserido
			           		a++;
			           		printf("*");          //imprime o * Anterisco
			        	}
			        	else if(c==8&&a)
						{     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
			           		cadmed.cadastro_senha[a]='\0';
			           		a--;
			           		printf("\b \b");       //Limpa os campos digitados
			        	}
					}while(c!=13);             //13 é o valor de ENTER na tabela ASCII
						cadmed.cadastro_senha[a]='\0';
					
			       		Movexy(20,10); printf(greenn"[!]Cadastro efetuado com sucesso..."off);
			       		Movexy(15,12); printf(whiten"[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR..."off);
			       		getch();
			       		system("cls");
					
					Retangulo(1,1,72,44);
			        Retangulo(24,2,27,2);
			        
			        int tratamento_cpf();
			        int tratamento_idade();
			        int tratamento_cep();
			        int tratamento_telefone();
			        
			        Movexy(25,3); printf(purplen"[!]CADASTRO DE PACIENTE[!]"off);
					
			        fflush(stdin);
			        Movexy(4,6); printf(">Digite seu Nome Completo:");
			        char nome;
					int cont = 0;
					
					do
					{
						cadmed.nome[cont] = '\0';
						nome = getch();
						nome = toupper(nome);
						
						if (isalpha(nome)  || nome == 32)
						{
							cadmed.nome[cont] = nome;
							cont++;
							printf("%c", nome);
						}
						else if (nome == 8 && cont)
						{
							cadmed.nome[cont] = '\0';
							cont--;
							printf("\b \b");
						}
		
					}
					while(nome != 13 || !strlen(cadmed.nome) || cadmed.nome[cont-1] == 32);
					cadmed.nome[cont]='\0';
					
					cont = 0;
					
			        fflush(stdin);
			        Movexy(4,8); printf(">Digite seu CPF:");
			        cadmed.cpf = tratamento_cpf();
			        
			        fflush(stdin);
			        Movexy(4,10); printf(">Digite seu Sexo:");
			        char sexo;
					
					do
					{
						cadmed.sexo[cont] = '\0';
						sexo = getch();
						sexo = toupper(sexo);
						
						if (isalpha(sexo) || sexo == 32)
						{
							cadmed.sexo[cont] = sexo;
							cont++;
							printf("%c", sexo);
						}
						else if (sexo == 8 && cont)
						{
							cadmed.sexo[cont] = '\0';
							cont--;
							printf("\b \b");
						}
							
					}
					while(sexo != 13 || !strlen(cadmed.sexo) || cadmed.sexo[cont-1] == 32);
					cadmed.sexo[cont]='\0';
			
					cont = 0;
			
			        fflush(stdin);
			        Movexy(4,12); printf(">Digite sua Idade:");
			        cadmed.idade = tratamento_idade();
			                			
			        fflush(stdin);
			        Movexy(4,14); printf(">Digite o Email (OPCIONAL):");
			    	gets(cadmed.email);
			    	
			        fflush(stdin);
			        Movexy(4,16); printf(">Digite o Telefone:");
			        cadmed.telefone = tratamento_telefone();
			    
			        fflush(stdin);
			        Movexy(4,18); printf(">Digite seu CEP:");
			        cadmed.cep = tratamento_cep();
			    
			        fflush(stdin);
			        Movexy(4,20); printf(">Digite o Bairro:");
			        char bairro;
					
					do
					{
						cadmed.bairro[cont] = '\0';
						bairro = getch();
						bairro = toupper(bairro);
						
						if (isalpha(bairro) || bairro == 32)
						{
							cadmed.bairro[cont] = bairro;
							cont++;
							printf("%c", bairro);
						}
						else if (bairro == 8 && cont)
						{
							cadmed.bairro[cont] = '\0';
							cont--;
							printf("\b \b");
						}	
						
					}
					while(bairro != 13 || !strlen(cadmed.bairro) || cadmed.bairro[cont-1] == 32);
					cadmed.bairro[cont]='\0';
			
					cont = 0;
			
			        fflush(stdin);
			        Movexy(4,22); printf(">Digite o Cidade:");
			        char cidade;
					
					do
					{
						cadmed.cidade[cont] = '\0';
						cidade = getch();
						cidade = toupper(cidade);
						
						if (isalpha(cidade) || cidade == 32)
						{
							cadmed.cidade[cont] = cidade;
							cont++;
							printf("%c", cidade);
						}
						else if (cidade == 8 && cont)
						{
							cadmed.cidade[cont] = '\0';
							cont--;
							printf("\b \b");
						}
								
					}
					while(cidade != 13 || !strlen(cadmed.cidade) || cadmed.cidade[cont-1] == 32);
					cadmed.cidade[cont]='\0';
			    	
			    	cont = 0;
			    	
			        fflush(stdin);
			        Movexy(4,24); printf(">Digite o Estado:");
			        char estado;
					
					do
					{
						cadmed.estado[cont] = '\0';
						estado = getch();
						estado = toupper(estado);
						
						if (isalpha(estado) || estado == 32)
						{
							cadmed.estado[cont] = estado;
							cont++;
							printf("%c", estado);
						}
						else if (estado == 8 && cont)
						{
							cadmed.estado[cont] = '\0';
							cont--;
							printf("\b \b");
						}	
						
					}
					while(estado != 13 || !strlen(cadmed.estado) || cadmed.estado[cont-1] == 32);
					cadmed.estado[cont]='\0';
					
			   	
			        if (fwrite(&cadmed, sizeof(struct agendamed), 1, cadastro)==1)
			        {
			            Movexy(14,27); printf(greenn"[!]Cadastro Concluido com Sucesso!..."off);
						Movexy(10,29); printf(whiten"[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR..."off);
			            getch();
			            system("cls");
					}
					
					fclose (cadastro);
			    	
			        break;
			        
			        default:
			        	
			        	Retangulo(1,1,72,44);
					    Retangulo(21,2,34,2);
					    
					    Movexy(23,3); printf(whiten"[!]SEJA BEM VINDO AO SISTEMA[!]"off);
					    Movexy(4,6); printf("Escolha a opcao em que voce se enquadra: ");
					    Movexy(4,8); printf("(1)-LOGIN");
					    Movexy(4,10); printf("(2)-CADASTRAR-SE");
					    
						Movexy(4,12); printf("Selecione:\t");
						
			        	Movexy(26,14); printf(redn"[!]OPCAO INVALIDA[!]."off);
			        	Movexy(15,16); printf(whiten"[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR..."off);
			        	i = 1;
						getch();
						system("cls");
						
					break;
	        	    	
			}
			
	} while (i == 1);
	
					Retangulo(1,1,72,44);
	
               		Movexy(24,10); printf(greenn"[!]LOGADO COM SUCESSO..."off);
               		Movexy(14,12); printf(whiten"[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR..."off);
               		getch();
               	do
				{
					system("cls");
					
					Retangulo(1,1,72,44);
    				Retangulo(23,2,34,2);
    				
                	Movexy(25,3); printf(purplen">SISTEMA PRINCIPAL DO HOSPITAL<"off);
                	Movexy(4,8);  printf(whiten"Escolha a opcao que deseja: "off);
                	Movexy(4,10); printf(whiten"(1)-Agendamento de Consultas."off);
                	Movexy(4,11); printf(whiten"(2)-Suas Consultas Agendadas."off);
                	Movexy(4,12); printf(whiten"(3)-Agendamento de Exames ."off);
                	Movexy(4,13); printf(whiten"(4)-Seus Exames Agendados."off);
                	Movexy(4,14); printf(whiten"(5)-Sair do Sistema."off);
                	Movexy(4,16); printf(whiten"Selecione:\t"off);
                	fflush(stdin);
                	
                	scanf("%d", &opcaomenu);
                	switch(opcaomenu)
					{
						
						case 1:
						
						system("cls");
						system("color 00");
									
						n_cont = 0;
						i = 0;
                		
                		for(l=0;l<9;l++)
		    			for(col=0;col<5;col++)
		        		agenda_consulta[l][col] = 0;
		        		ler_consultas(linhasP,colunasP,&pause);
						if(pause!=0)
						{
							while(i<pause)
							{
								dia=linhasP[i];
								hora=colunasP[i];
								agenda_consulta[dia][hora] = 1;
								i++;
							}
						}
			
						do
						{
							Retangulo(1,1,72,44);
    						Retangulo(20,2,32,2);
    						Retangulo(10,8,50,11);
							
							Movexy(23,3); printf(purplen">AGENDAMENTO DE CONSULTAS<"off);
							
	                		Movexy(4,6); printf("Digite o dia da semana que voce deseja agendar:");
	                		Movexy(14,9); printf(blue"Medicos"off);
	                		Movexy(26,9); printf("Seg");
	                		Movexy(33,9); printf("Ter");
	                		Movexy(40,9); printf("Qua");
	                		Movexy(47,9); printf("Qui");
	                		Movexy(54,9); printf("Sex");
	                		
	                		Movexy(13,10); printf(cyan"Dra. Anna"off);
	                		Movexy(13,11); printf(cyan"Dra. Lais"off);
	                		Movexy(13,12); printf(cyan"Dra. Edna"off);
	                		Movexy(13,13); printf(cyan"Dr. Paulo"off);
	                		Movexy(13,14); printf(cyan"Dr. Saulo"off);
	                		Movexy(13,15); printf(cyan"Dr. Lucas"off);
	                		Movexy(13,16); printf(cyan"Dr. Andre"off);
	                		Movexy(13,17); printf(cyan"Dr. Kaleb"off);
	                		Movexy(13,18); printf(cyan"Dr. Bruno"off);

	                			for (l=8;l<17;l++)
	                			{
									Movexy(25,l+2);	
		                			for (col=0;col<5;col++)
		                			{
										if (agenda_consulta[l-8][col] == 0)
										{								
		                					if (l < 10)
		                					{
			                					printf(white"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(white"%d:00  "off,l);
			                				}
			                			}
			                			else if (agenda_consulta[l-8][col] == 1)
			                			{
		                					if (l < 10)
		                					{
			                					printf(red"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(red"%d:00  "off,l);
			                				}
										}
		                			}
		                			printf("\n");
								}
	
								i = 1;
								
									Movexy(4,21); printf("Digite qual dia da que voce deseja marcar sua consulta: ");
									
									int cont = 0;
									char diaC;
									
									do
									{
										dia_consulta[cont] = '\0';
										diaC = getch();
										diaC = toupper(diaC);
										
										if (isalpha(diaC)  || diaC == 32)
										{
											dia_consulta[cont] = diaC;
											cont++;
											printf("%c", diaC);
										}
										else if (diaC == 8 && cont)
										{
											dia_consulta[cont] = '\0';
											cont--;
											printf("\b \b");
										}
						
									}
									while(diaC != 13 || !strlen(dia_consulta) || dia_consulta[cont-1] == 32);
									dia_consulta[cont]='\0';
									
									if ((strcmp(dia_consulta,"SEGUNDA") == 0) || (strcmp(dia_consulta,"SEG") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
			                			{
			                				Movexy(53,23);
											horario_consulta = tratamento_horario_consulta();
											if (horario_consulta < 8 || horario_consulta > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][0] == 1)
											break;
										}
										while(horario_consulta < 8 || horario_consulta > 16);
										
										if (agenda_consulta[horario_consulta-8][0] == 0)
										{
				                			gravar_consultas(horario_consulta-8,0);
				                			agenda_consulta[horario_consulta-8][0] = 1;
				                			break;
			                			}
									}
									if ((strcmp(dia_consulta,"TERCA") == 0) || (strcmp(dia_consulta,"TER") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
			                			{
			                				Movexy(53,23);
											horario_consulta = tratamento_horario_consulta();
											if (horario_consulta < 8 || horario_consulta > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][1] == 1)
											break;
										}
										while(horario_consulta < 8 || horario_consulta > 16);
										
										if (agenda_consulta[horario_consulta-8][1] == 0)
										{
				                			gravar_consultas(horario_consulta-8,1);
				                			agenda_consulta[horario_consulta-8][1] = 1;
				                			break;
			                			}
									}
									if ((strcmp(dia_consulta,"QUARTA") == 0) || (strcmp(dia_consulta,"QUA") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
			                			{
			                				Movexy(53,23);
											horario_consulta = tratamento_horario_consulta();
											if (horario_consulta < 8 || horario_consulta > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][2] == 1)
											break;
										}
										while(horario_consulta < 8 || horario_consulta > 16);
										
										if (agenda_consulta[horario_consulta-8][2] == 0)
										{
				                			gravar_consultas(horario_consulta-8,2);
				                			agenda_consulta[horario_consulta-8][2] = 1;
				                			break;
			                			}
									}
									if ((strcmp(dia_consulta,"QUINTA") == 0) || (strcmp(dia_consulta,"QUI") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
			                			{
			                				Movexy(53,23);
											horario_consulta = tratamento_horario_consulta();
											if (horario_consulta < 8 || horario_consulta > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][3] == 1)
											break;
										}
										while(horario_consulta < 8 || horario_consulta > 16);
										
										if (agenda_consulta[horario_consulta-8][3] == 0)
										{
				                			gravar_consultas(horario_consulta-8,3);
				                			agenda_consulta[horario_consulta-8][3] = 1;
				                			break;
			                			}
									}
									if ((strcmp(dia_consulta,"SEXTA") == 0) || (strcmp(dia_consulta,"SEX") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
			                			{
			                				Movexy(53,23);
			                				horario_consulta = tratamento_horario_consulta();
											if (horario_consulta < 8 || horario_consulta > 16)
											{
												horario_consulta = 0;
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][4] == 1)
											break;
										}
										while(horario_consulta < 8 || horario_consulta > 16);
										
										if (agenda_consulta[horario_consulta-8][4] == 0)
										{
				                			gravar_consultas(horario_consulta-8,4);
				                			agenda_consulta[horario_consulta-8][4] = 1;
				                			break;
			                			}
									}
									
									Movexy(10,25); printf(red"DIA/HORARIO INVALIDO, POR FAVOR DIGITE NOVAMENTE."off);
									
									Movexy(10,27); printf(whiten"[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR..."off);
									printf("\a");
			               			getch();
									system("cls");
								
							}
							while(1);
							
							Retangulo(1,1,72,44);
    						Retangulo(20,2,32,2);
    						Retangulo(10,8,50,11);
							
							Movexy(23,3); printf(purplen">AGENDAMENTO DE CONSULTAS<"off);
							
							n_cont = 0;
							
	                		Movexy(4,6); printf("Selecione o dia e o medico disponivel:");
	                		Movexy(14,9); printf(blue"Medicos"off);
	                		Movexy(26,9); printf("Seg");
	                		Movexy(33,9); printf("Ter");
	                		Movexy(40,9); printf("Qua");
	                		Movexy(47,9); printf("Qui");
	                		Movexy(54,9); printf("Sex");
	                		
	                		Movexy(13,10); printf(cyan"Dra. Anna"off);
	                		Movexy(13,11); printf(cyan"Dra. Lais"off);
	                		Movexy(13,12); printf(cyan"Dra. Edna"off);
	                		Movexy(13,13); printf(cyan"Dr. Paulo"off);
	                		Movexy(13,14); printf(cyan"Dr. Saulo"off);
	                		Movexy(13,15); printf(cyan"Dr. Lucas"off);
	                		Movexy(13,16); printf(cyan"Dr. Andre"off);
	                		Movexy(13,17); printf(cyan"Dr. Kaleb"off);
	                		Movexy(13,18); printf(cyan"Dr. Bruno"off);

	                			for (l=8;l<17;l++)
	                			{
									Movexy(25,l+2);	
		                			for (col=0;col<5;col++)
		                			{
										if (agenda_consulta[l-8][col] == 0)
										{								
		                					if (l < 10)
		                					{
			                					printf(white"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(white"%d:00  "off,l);
			                				}
			                			}
			                			else if (agenda_consulta[l-8][col] == 1)
			                			{
		                					if (l < 10)
		                					{
			                					printf(red"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(red"%d:00  "off,l);
			                				}
										}
		                			}
		                			printf("\n");
								}
	                			printf("\n");
							
                			getch();
                			
                		break;
						
                     	case 2:
                     		
                     		system("color 00");
                     		system("cls");
                     		
                     		i = 0;
                     		
                     		for(l=0;l<9;l++)
			    			for(col=0;col<5;col++)
			        		agenda_consulta[l][col] = 0;
			        		ler_consultas(linhasP,colunasP,&pause);
							if(pause!=0)
							{
								while(i<pause)
								{
									dia=linhasP[i];
									hora=colunasP[i];
									agenda_consulta[dia][hora] = 1;
									i++;
								}
							}
                     			
							Retangulo(1,1,72,44);
    						Retangulo(26,2,22,2);
    						Retangulo(10,8,50,11);
							
							Movexy(27,3); printf(purplen">AGENDA DE CONSULTAS<"off);
							
							n_cont = 0;
							
	                		Movexy(14,9); printf(blue"Medicos"off);
	                		Movexy(26,9); printf("Seg");
	                		Movexy(33,9); printf("Ter");
	                		Movexy(40,9); printf("Qua");
	                		Movexy(47,9); printf("Qui");
	                		Movexy(54,9); printf("Sex");
	                		
	                		Movexy(13,10); printf(cyan"Dra. Anna"off);
	                		Movexy(13,11); printf(cyan"Dra. Lais"off);
	                		Movexy(13,12); printf(cyan"Dra. Edna"off);
	                		Movexy(13,13); printf(cyan"Dr. Paulo"off);
	                		Movexy(13,14); printf(cyan"Dr. Saulo"off);
	                		Movexy(13,15); printf(cyan"Dr. Lucas"off);
	                		Movexy(13,16); printf(cyan"Dr. Andre"off);
	                		Movexy(13,17); printf(cyan"Dr. Kaleb"off);
	                		Movexy(13,18); printf(cyan"Dr. Bruno"off);

	                			for (l=8;l<17;l++)
	                			{
									Movexy(25,l+2);	
		                			for (col=0;col<5;col++)
		                			{
										if (agenda_consulta[l-8][col] == 0)
										{								
		                					if (l < 10)
		                					{
			                					printf(white"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(white"%d:00  "off,l);
			                				}
			                			}
			                			else if (agenda_consulta[l-8][col] == 1)
			                			{
		                					if (l < 10)
		                					{
			                					printf(red"0%d:00  "off,l);
			                	    		}
			                	    		else
			                	    		{
			                					printf(red"%d:00  "off,l);
			                				}
										}
		                			}
		                			printf("\n");
								}
	                			printf("\n");
								
                			Movexy(11,23); printf("[!]PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU...");
                			
							getch();
							
							
							
						break;
						
						case 3:
							
							system("color 00");
							system("cls");		
									
							n_cont = 0;
	                		i = 0;
	                		
	                		for(l=0;l<9;l++)
			    			for(col=0;col<5;col++)
			        		agenda_exames[l][col] = 0;
			        		ler_exames(linhasPE,colunasPE,&pauseE);
							if(pauseE!=0)
							{
								while(i<pauseE)
								{
									diaE=linhasPE[i];
									horaE=colunasPE[i];
									agenda_exames[diaE][horaE] = 1;
									i++;
								}
							}
											
							do
							{
								
								Retangulo(1,1,72,44);
	    						Retangulo(26,2,24,2);
	    						Retangulo(10,8,50,11);
								
								Movexy(27,3); printf(purplen">AGENDAMENTO DE EXAMES<"off);
								
		                		Movexy(4,6);  printf("Selecione o dia e o exame disponivel:");
		                		Movexy(14,9); printf(blue"Exames"off);
		                		Movexy(26,9); printf("Seg");
		                		Movexy(33,9); printf("Ter");
		                		Movexy(40,9); printf("Qua");
		                		Movexy(47,9); printf("Qui");
		                		Movexy(54,9); printf("Sex");
		                		
		                		Movexy(13,10); printf(cyan"Hemograma"off);
		                		Movexy(13,11); printf(cyan"Raio-X   "off);
		                		Movexy(13,12); printf(cyan"Check-UP "off);
		                		Movexy(13,13); printf(cyan"COVID-19 "off);
		                		Movexy(13,14); printf(cyan"Urina    "off);
		                		Movexy(13,15); printf(cyan"Fezes    "off);
		                		Movexy(13,16); printf(cyan"Glicemia "off);
		                		Movexy(13,17); printf(cyan"Tireoide "off);
		                		Movexy(13,18); printf(cyan"Prostata "off);
	
		                			for (l=8;l<17;l++)
		                			{
										Movexy(25,l+2);	
			                			for (col=0;col<5;col++)
			                			{
											if (agenda_exames[l-8][col] == 0)
											{								
			                					if (l < 10)
			                					{
				                					printf(white"0%d:00  "off,l);
				                	    		}
				                	    		else
				                	    		{
				                					printf(white"%d:00  "off,l);
				                				}
				                			}
				                			else if (agenda_exames[l-8][col] == 1)
				                			{
			                					if (l < 10)
			                					{
				                					printf(red"0%d:00  "off,l);
				                	    		}
				                	    		else
				                	    		{
				                					printf(red"%d:00  "off,l);
				                				}
											}
			                			}
			                			printf("\n");
									}
		
								
									i = 1;
									
									Movexy(4,21); printf("Digite qual dia da semana que voce deseja marcar seu exame: ");
									
									int cont = 0;
									char diaE;
									
									do
									{
										dia_exame[cont] = '\0';
										diaE = getch();
										diaE = toupper(diaE);
										
										if (isalpha(diaE)  || diaE == 32)
										{
											dia_exame[cont] = diaE;
											cont++;
											printf("%c", diaE);
										}
										else if (diaE == 8 && cont)
										{
											dia_exame[cont] = '\0';
											cont--;
											printf("\b \b");
										}
						
									}
									while(diaE != 13 || !strlen(dia_exame) || dia_exame[cont-1] == 32);
									dia_exame[cont]='\0';
									if ((strcmp(dia_exame,"SEGUNDA") == 0) || (strcmp(dia_exame,"SEG") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
		                				{
			                				Movexy(53,23);
											horario_exame = tratamento_horario_exames();
											if (horario_exame < 8 || horario_exame > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][0] == 1)
											break;
										}
										while(horario_exame < 8 || horario_exame > 16);
										
										if (agenda_exames[horario_exame-8][0] == 0)
										{
											gravar_exames(horario_exame-8,0);
				                			agenda_exames[horario_exame-8][0] = 1;
				                			break;
				                		}
									}
									if ((strcmp(dia_exame,"TERCA") == 0) || (strcmp(dia_exame,"TER") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
		                				{
			                				Movexy(53,23);
											horario_exame = tratamento_horario_exames();
											if (horario_exame < 8 || horario_exame > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][1] == 1)
											break;
										}
										while(horario_exame < 8 || horario_exame > 16);
										
										if (agenda_exames[horario_exame-8][1] == 0)
										{
				                			gravar_exames(horario_exame-8,1);
				                			agenda_exames[horario_exame-8][1] = 1;
				                			break;
				                		}
									}
									if ((strcmp(dia_exame,"QUARTA") == 0) || (strcmp(dia_exame,"QUA") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
		                				{
			                				Movexy(53,23);
											horario_exame = tratamento_horario_exames();
											if (horario_exame < 8 || horario_exame > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][2] == 1)
											break;
										}
										while(horario_exame < 8 || horario_exame > 16);
										
										if (agenda_exames[horario_exame-8][2] == 0)
										{
			                			gravar_exames(horario_exame-8,2);
			                			agenda_exames[horario_exame-8][2] = 1;
			                			break;
			                			}
									}
									if ((strcmp(dia_exame,"QUINTA") == 0) || (strcmp(dia_exame,"QUI") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
		                				{
			                				Movexy(53,23);
											horario_exame = tratamento_horario_exames();
											if (horario_exame < 8 || horario_exame > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][3] == 1)
											break;
										}
										while(horario_exame < 8 || horario_exame > 16);
										
										if (agenda_exames[horario_exame-8][3] == 0)
										{
			                			gravar_exames(horario_exame-8,3);
			                			agenda_exames[horario_exame-8][3] = 1;
			                			break;
			                			}
									}
									if ((strcmp(dia_exame,"SEXTA") == 0) || (strcmp(dia_exame,"SEX") == 0))
			                		{
			                			Movexy(4,23); printf("Digite o horario que deseja marcar sua consulta: ");
			                			do
		                				{
			                				Movexy(53,23);
											horario_exame = tratamento_horario_exames();
											if (horario_exame < 8 || horario_exame > 16)
											{
												Movexy(53,23); printf(redn"HORARIO INVALIDO."off);
												Sleep(1000);
												Movexy(53,23); printf("\b                  \b");
											}
											
											if (agenda_consulta[horario_consulta-8][4] == 1)
											break;
										}
										while(horario_exame < 8 || horario_exame > 16);
										
										if (agenda_exames[horario_exame-8][4] == 0)
										{
			                			gravar_exames(horario_exame-8,4);
			                			agenda_exames[horario_exame-8][4] = 1;
			                			break;
			                			}
									}
								
								Movexy(10,25); printf(red"DIA/HORARIO INVALIDO, POR FAVOR DIGITE NOVAMENTE."off);
								
								Movexy(10,27); printf("[!]PRESSIONE QUALQUER TECLA PARA CONTINUAR...");
								printf("\a");
			               		getch();
								system("cls");
								
							}
								while(1);
								
								Retangulo(1,1,72,44);
	    						Retangulo(26,2,24,2);
	    						Retangulo(10,8,50,11);
								
								Movexy(27,3); printf(purplen">AGENDAMENTO DE EXAMES<"off);
								
								n_cont = 0;
								
		                		Movexy(4,6); printf("Selecione o dia e o exame disponivel:");
		                		Movexy(14,9); printf(blue"Exames"off);
		                		Movexy(26,9); printf("Seg");
		                		Movexy(33,9); printf("Ter");
		                		Movexy(40,9); printf("Qua");
		                		Movexy(47,9); printf("Qui");
		                		Movexy(54,9); printf("Sex");
		                		
		                		Movexy(13,10); printf(cyan"Hemograma"off);
		                		Movexy(13,11); printf(cyan"Raio-X   "off);
		                		Movexy(13,12); printf(cyan"Check-UP "off);
		                		Movexy(13,13); printf(cyan"COVID-19 "off);
		                		Movexy(13,14); printf(cyan"Urina    "off);
		                		Movexy(13,15); printf(cyan"Fezes    "off);
		                		Movexy(13,16); printf(cyan"Glicemia "off);
		                		Movexy(13,17); printf(cyan"Tireoide "off);
		                		Movexy(13,18); printf(cyan"Prostata "off);
	
		                			for (l=8;l<17;l++)
		                			{
										Movexy(25,l+2);	
			                			for (col=0;col<5;col++)
			                			{
											if (agenda_exames[l-8][col] == 0)
											{								
			                					if (l < 10)
			                					{
				                					printf(white"0%d:00  "off,l);
				                	    		}
				                	    		else
				                	    		{
				                					printf(white"%d:00  "off,l);
				                				}
				                			}
				                			else if (agenda_exames[l-8][col] == 1)
				                			{
			                					if (l < 10)
			                					{
				                					printf(red"0%d:00  "off,l);
				                	    		}
				                	    		else
				                	    		{
				                					printf(red"%d:00  "off,l);
				                				}
											}
			                			}
			                			printf("\n");
									}
									                		
	                			getch();
                    		
                     	break;
                     	
                     	case 4:
                     		
                     		system("cls");
                     		system("color 00");
                     		
							 i = 0;
                     		
                     		for(l=0;l<9;l++)
			    			for(col=0;col<5;col++)
			        		agenda_exames[l][col] = 0;
			        		ler_exames(linhasPE,colunasPE,&pauseE);
							if(pauseE!=0)
							{
								while(i<pauseE)
								{
									diaE=linhasPE[i];
									horaE=colunasPE[i];
									agenda_exames[diaE][horaE] = 1;
									i++;
								}
							}
	                		
							Retangulo(1,1,72,44);
	    					Retangulo(26,2,19,2);
	    					Retangulo(10,8,50,11);
								
							Movexy(27,3); printf(purplen">AGENDA DE EXAMES<"off);
								
		                	n_cont = 0;
		                	
		                	Movexy(14,9); printf(blue"Exames"off);
		                	Movexy(26,9); printf("Seg");
		                	Movexy(33,9); printf("Ter");
		                	Movexy(40,9); printf("Qua");
		                	Movexy(47,9); printf("Qui");
		                	Movexy(54,9); printf("Sex");
		                		
		                	Movexy(13,10); printf(cyan"Hemograma"off);
		                	Movexy(13,11); printf(cyan"Raio-X   "off);
		                	Movexy(13,12); printf(cyan"Check-UP "off);
		                	Movexy(13,13); printf(cyan"COVID-19 "off);
		                	Movexy(13,14); printf(cyan"Urina    "off);
		                	Movexy(13,15); printf(cyan"Fezes    "off);
		                	Movexy(13,16); printf(cyan"Glicemia "off);
		                	Movexy(13,17); printf(cyan"Tireoide "off);
		                	Movexy(13,18); printf(cyan"Prostata "off);
	
		                	for (l=8;l<17;l++)
		                	{
								Movexy(25,l+2);	
			                	for (col=0;col<5;col++)
			                	{
									if (agenda_exames[l-8][col] == 0)
									{								
			                			if (l < 10)
			                			{
				                			printf(white"0%d:00  "off,l);
				                	   	}
				                	    else
				                	    {
				                			printf(white"%d:00  "off,l);
				                		}
				                	}
				                	else if (agenda_exames[l-8][col] == 1)
				                	{
			                			if (l < 10)
			                			{
				                			printf(red"0%d:00  "off,l);
				                	    }
				                	    else
				                	    {
				                			printf(red"%d:00  "off,l);
				                		}
									}
			                	}
			                	printf("\n");
							}
								
	                		Movexy(11,23); printf("[!]PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU...");
                			
							getch();
                			
						
						break;
						
						case 5:
							exit(1);
						break; 	
					}
				} while (1);
}

int ler_consultas(int *rL,int *rC,int *rB)
{
	int get_size_consultas(const char* file_name);
	
	FILE *consultas;
	int linhas;
	int colunas;
	int i=0,cont=0;
	consultas = fopen("arq_consultas","r+");
	
	if(consultas == NULL)
	{
		printf("Erro");
	}
	if(get_size_consultas("arq_consultas")==0)
	{
		*rB=0;
		return 0;
	}
	while(fscanf(consultas,"%d",&linhas)!= -1 && fscanf(consultas,"%d",&colunas)!= -1)
	{
		*rL=linhas;
		*rC=colunas;
		++rL;
		++rC;
		cont++;
		*rB=cont;
	}
	fclose(consultas);
	return 0;
}

int get_size_consultas(const char* file_name)
{
    FILE *file = fopen(file_name, "r+");

    if(file == NULL)
    return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int gravar_consultas(int linha,int coluna)
{
	FILE *consultas;
	int a,b;
	consultas = fopen("arq_consultas","a+");
	if(consultas == NULL)
	{
		printf("Erro ao abrir Arquivo");
		exit(1);
	}
	fprintf(consultas,"%d %d\n",linha,coluna);
	fclose(consultas);
}

int ler_exames(int *rL,int *rC,int *rB)
{
	int get_size_exames(const char* file_name);
	
	FILE *exames;
	int linhas;
	int colunas;
	int i=0,cont=0;
	exames = fopen("arq_exames","r+");
	
	if(exames == NULL)
	{
		printf("Erro");
	}
	if(get_size_exames("arq_exames")==0)
	{
		*rB=0;
		return 0;
	}
	while(fscanf(exames,"%d",&linhas)!= -1 && fscanf(exames,"%d",&colunas)!= -1)
	{
		*rL=linhas;
		*rC=colunas;
		++rL;
		++rC;
		cont++;
		*rB=cont;
	}
	fclose(exames);
	return 0;
}

int get_size_exames(const char* file_name)
{
    FILE *file = fopen(file_name, "r+");

    if(file == NULL)
    return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int gravar_exames(int linha,int coluna)
{
	FILE *exames;
	int a,b;
	exames = fopen("arq_exames","a+");
	if(exames == NULL)
	{
		printf("Erro ao abrir Arquivo");
		exit(1);
	}
	fprintf(exames,"%d %d\n",linha,coluna);
	fclose(exames);
}

void Movexy(int x, int y)//Função Recebe x e y
{
//Envia o parametro escolhido para o windows posicionando o Cursor nas respctivas cordenadas
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void Retangulo(int ho, int vo, int larg, int alt)
{
    int h, v;
    // Linhas horizontais
     for(h=ho; h < ho+larg; h++)//Laço de Repetição
	 {
        Movexy (h, vo); printf (purplen"%c", 205);//Imprime o Caracter Especial 206 da tabela ASCII
        Movexy(h, vo+alt); printf (purplen"%c", 205);//Imprime o Caracter Especial 206 da tabela ASCII
     }
     // Linhas verticais
     for(v=vo; v < vo+alt; v++)
	 {
        Movexy (ho, v);  printf (purplen"%c", 186);//Imprime o Caracter Especial 186 da tabela ASCII
        Movexy(ho+larg, v);  printf (purplen"%c", 186);//Imprime o Caracter Especial 186 da tabela ASCII
     }
     // Cantos
     Movexy (ho, vo);    printf (purplen"%c", 201);//Imprime o Caracter Especial 201 da tabela ASCII
     Movexy (ho, vo+alt);    printf (purplen"%c", 200);//Imprime o Caracter Especial 200 da tabela ASCII
     Movexy (ho+larg, vo);    printf (purplen"%c", 187);//Imprime o Caracter Especial 187 da tabela ASCII
     Movexy (ho+larg, vo+alt);    printf (purplen"%c", 188);//Imprime o Caracter Especial 188 da tabela ASCII
}

void carregamento()
{
	int i=0;//Varial i de Contagem
	system("color 00");//Limpar o Terminal
	Retangulo(1,1,72,44); // Retângulo principal.
	while(i<=60)
	{	
		Movexy(i+6,22); printf(purpleb" "purplen);//Imprime um Espaço Vermelho
		Movexy(35,24); printf(off"%d%%"purplen,i+40);//Imprime a Porcetagem do Carregamento
		Sleep(15);//Delay de 15ms
		i++;//incrementa +1 a i
	}
	system("cls");//Limpar o Terminal
}

int tratamento_cpf()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	return (atoi(numero));
	
}

int tratamento_idade()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	
	return (atoi(numero));	
}

int tratamento_telefone()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	return (atoi(numero));
	
}

int tratamento_cep()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	return (atoi(numero));
	
}	

int tratamento_horario_consulta()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	return (atoi(numero));
	
}

int tratamento_horario_exames()
{
	char num;
	char numero[15];
	int cont = 0;
	
	do
	{
		numero[cont] = '\0';
		num = getch();
		
		if (isdigit(num))
		{
			numero[cont] = num;
			cont++;
			printf("%c", num);
		}
		else if (num == 8 && cont)
		{
			numero[cont] = '\0';
			cont--;
			printf("\b \b");
		}	
	}
	while(num != 13 || !strlen(numero) || numero[cont-1] == 32);
	numero[cont]='\0';
	return (atoi(numero));
	
}