#include <stdio.h>
#include <stdlib.h>

// def funções
int categoria();
int comprar();
int montante();
int categorias();
int descricoes();

//def variáveis dos livros
int matdisp = 5, matvend = 5, matcod = 1;
int probdisp = 10, probvend = 0, probcod = 2;
int fisidisp = 8, fisivend = 2, fisicod = 3;
int quimidisp = 7, quimivend = 3, quimicod = 4;
int compdisp = 1, compvend = 9, compcod = 5;

float matval = 150.00, probval = 100.00, fisival = 160.00, quimival = 160.00, compval = 200.00, valor = 0;

#define VALORTOTAL (((matvend) * (matval)) + ((probvend) * (probval)) + ((fisivend) * (fisival)) + ((quimivend) * (quimival)) + ((compvend) * (compval)))
#define TOTALTOTAL (matvend + probvend + fisivend + quimivend + compvend)

// def inputs do usuário
int navegacao = 0, codlivro, quantlivro, carrinho = 0;

int main()

{
  do{
printf("\n°______________________________________________________________________°\n");
  printf("\nMenu:\n\n"
 
  "Digite um dos algarismos a seguir para navegar pelo menu:\n\n"
  "1 - Categorias\n"
  "2 - Descrições\n"
  "3 - Comprar Livros\n"
  "4 - Faturamento das Vendas\n"
  "5 - Quit\n");
printf("°______________________________________________________________________°\n");
//solicita input no menu principal
  
  scanf("%d", &navegacao);

  }while(navegacao != 5 && navegacao != 1 && navegacao != 2 && navegacao != 3 && navegacao != 4 && navegacao != 0);

  if(navegacao == 1)
  {
    system("clear");
    categorias();
  }
  if(navegacao == 2)
  {
    system("clear");
    descricoes();
  }
  if(navegacao == 3)
  {
    system("clear");
    comprar();
  }
  if(navegacao == 4)
  {
    system("clear");
    montante();
  }
  if(navegacao == 5)
  {
    system("clear");
    return 0;
  }
  else
  {
    printf("Escolha uma opção válida!");
  }
  
}

categorias()

{

//tabela de categorias
  
      printf("Livro        || Disponível || Vendido || Código || Valor\n\n");
      
      printf("Matemática   ||     %d     ||   %d    ||   %d   || R$ %.2f\n\n", matdisp, matvend, matcod, matval);
      
      printf("Prob. Estat. ||     %d    ||   %d    ||   %d   || R$ %.2f\n\n", probdisp, probvend, probcod, probval);
  
      printf("Física       ||     %d     ||   %d    ||   %d   || R$ %.2f\n\n", fisidisp, fisivend, fisicod, fisival);
  
      printf("Química      ||     %d     ||   %d    ||   %d   || R$ %.2f\n\n", quimidisp, quimivend, quimicod, quimival);
  
      printf("C.Computação ||     %d     ||   %d    ||   %d   || R$ %.2f\n\n", compdisp, compvend, compcod, compval);
  
      
      // solicita quit
      do{
        printf("\nPressione '0' para voltar ao Menu\n");
        scanf("%d", &navegacao);
        system("clear");
        
        } while (navegacao!=0);
  
  main();
}
        
descricoes()

{
    
  FILE *menu;
  char dados[1000]; 
    
      menu = fopen("descrições.txt", "r");
  
      while(fgets(dados, 1000, menu) !=NULL)
        {
        printf("%s", dados);
        }
      fclose(menu);
      
      //volta ao menu principal
      do{
        printf("\nPressione '0' para voltar ao Menu\n");
        scanf("%d", &navegacao);
        system("clear");
        
        } while (navegacao!=0);
  
      main();
      
    }
 
comprar()

{
    //solicita livro e quantidade
    
    printf("\nSelecione os livros que você deseja comprar, com base em seus códigos:\n");
    scanf("%d", &codlivro);

    if (codlivro == 1 || codlivro == 2 || codlivro == 3 || codlivro == 4 || codlivro == 5)
    {
      printf("\nSelecione a quantidade de livros de cada categoria que você deseja comprar:\n");
      scanf("%d", &quantlivro);
  
    switch(codlivro){
      
      //selecionando livro de matemática
      case 1:{
      
          if ((matdisp - quantlivro) >= 0)
            {
            matdisp -= quantlivro;
            matvend += quantlivro;
            carrinho += quantlivro;
            valor += (quantlivro * matval);
            
            printf("\nO livro foi adcionado ao seu carrinho.\n\n");
  
            }  
          else
            {
            printf("\nNão há livros suficientes dessa categoria para serem vendidos.\n");
              
              main();
            }
        //pergunta se quer finalizar a compra
        do
        {
    printf("Deseja comprar mais livros?\n""Tecle 3 para Sim ou 0 para retornar ao Menu e finalizar sua compra.\n");
    scanf("%d", &navegacao);
        } while (navegacao != 3 && navegacao != 0);
  
        if(navegacao == 3)
        {
          system("clear");
          comprar();
        }
        if(navegacao == 0)
        {
          system("clear");
          break;
        }
      }  
  
  
    //selecionando livro de Prob. Estat.
      case 2:{
      
          if ((probdisp - quantlivro) >= 0)
            {
            probdisp -= quantlivro;
            probvend += quantlivro;
            carrinho += quantlivro;
            valor += (quantlivro * probval);
            
            printf("\nO livro foi adcionado ao seu carrinho.\n\n");
  
            }  
          else
            {
            printf("\nNão há livros suficientes dessa categoria para serem vendidos.\n");
              
              main();
            }
        //pergunta se quer finalizar a compra
        do
        {
    printf("Deseja comprar mais livros?\n""Tecle 3 para Sim ou 0 para retornar ao Menu e finalizar sua compra.\n");
    scanf("%d", &navegacao);
        } while (navegacao != 3 && navegacao != 0);
  
        if(navegacao == 3)
        {
          comprar();
        }
        if(navegacao == 0)
        {
          break;
        }
      }
  
       // selecionando livro de física
        case 3:{
      
          if ((fisidisp - quantlivro) >= 0)
            {
            fisidisp -= quantlivro;
            fisivend += quantlivro;
            carrinho += quantlivro;
            valor += (quantlivro * fisival);
            
            printf("\nO livro foi adcionado ao seu carrinho.\n\n");
  
            }  
          else
            {
            printf("\nNão há livros suficientes dessa categoria para serem vendidos.\n");
              
              main();
            }
        //pergunta se quer finalizar a compra
        do
        {
    printf("Deseja comprar mais livros?\n""Tecle 3 para Sim ou 0 para retornar ao Menu e finalizar sua compra.\n");
    scanf("%d", &navegacao);
        } while (navegacao != 3 && navegacao != 0);
  
        if(navegacao == 3)
        {
          comprar();
        }
        if(navegacao == 0)
        {
          break;
        }
    
      }
      
      //selecionando livro de química
        case 4:{
      
          if ((quimidisp - quantlivro) >= 0)
            {
            quimidisp -= quantlivro;
            quimivend += quantlivro;
            carrinho += quantlivro;
            valor += (quantlivro * quimival);
            
            printf("\nO livro foi adcionado ao seu carrinho.\n\n");
  
            }  
          else
            {
            printf("\nNão há livros suficientes dessa categoria para serem vendidos.\n");
              
              main();
            }
        //pergunta se quer finalizar a compra
        do
        {
    printf("Deseja comprar mais livros?\n""Tecle 3 para Sim ou 0 para retornar ao Menu e finalizar sua compra.\n");
    scanf("%d", &navegacao);
        } while (navegacao != 3 && navegacao != 0);
  
        if(navegacao == 3)
        {
          comprar();
        }
        if(navegacao == 0)
        {
          break;
        }
        
      }
  
      //selecionando C.Comp
      case 5 :{
      
          if ((compdisp - quantlivro) >= 0)
            {
            compdisp -= quantlivro;
            compvend += quantlivro;
            carrinho += quantlivro;
            valor += (quantlivro * compval);
            
            printf("\nO livro foi adcionado ao seu carrinho.\n\n");
  
            }  
          else
            {
            printf("\nNão há livros suficientes dessa categoria para serem vendidos.\n");
              
              main();
            }
      }
      //pergunta se quer finalizar a compra
      do
      {
  printf("Deseja comprar mais livros?\n""Tecle 3 para Sim ou 0 para retornar ao Menu e finalizar sua compra.\n");
  scanf("%d", &navegacao);
      } while (navegacao != 3 && navegacao != 0);

      if(navegacao == 3)
      {
        comprar();
      }
      if(navegacao == 0)
      {
        break;
      }
      
    }
  }
    else
    {
      printf("\nEscolha uma opçao válida!\n");

        comprar();
    }
       //imprime o carrinho e valor da compra
    printf("\n====================================================================\n");
    printf("\nCARRINHO: %d livros\n", carrinho);
    printf("\nVALOR TOTAL: R$%.2f\n", valor);
    printf("\n====================================================================\n");
    
    main();   
  }

montante()

{
  printf("\n====================================================================\n");
  printf("\nSegue o valor caixa da biblioteca após as vendas:\n");
  printf("\n====================================================================\n");

  printf("Livro        || Disponível || Vendido || Código || Valor\n\n");
      
      printf("Matemática   ||     %d      ||   %d     ||   %d     || R$ %.2f\n\n", matdisp, matvend, matcod, matval);
      
      printf("Prob. Estat. ||     %d     ||   %d     ||   %d     || R$ %.2f\n\n", probdisp, probvend, probcod, probval);
  
      printf("Física       ||     %d      ||   %d     ||   %d     || R$ %.2f\n\n", fisidisp, fisivend, fisicod, fisival);
  
      printf("Química      ||     %d      ||   %d     ||   %d     || R$ %.2f\n\n", quimidisp, quimivend, quimicod, quimival);
  
      printf("C.Computação ||     %d      ||   %d     ||   %d     || R$ %.2f\n\n", compdisp, compvend, compcod, compval);

  printf("\n*******************VALOR VENDIDO: %.2f*******************\n", VALORTOTAL);

   printf("\n####################################################################\n");

  return main();
}
