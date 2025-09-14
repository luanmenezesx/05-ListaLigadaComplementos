#include <iostream>
using namespace std;

// definicao de tipo
struct NO
{
	int valor;
	NO *prox;
};

NO *primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO *posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7)
	{
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl
			 << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1:
			inicializar();
			break;
		case 2:
			exibirQuantidadeElementos();
			break;
		case 3:
			exibirElementos();
			break;
		case 4:
			buscarElemento();
			break;
		case 5:
			inserirElemento();
			break;
		case 6:
			excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista ja possuir elementos
	// libera a memoria ocupada
	NO *aux = primeiro;
	while (aux != NULL)
	{
		NO *paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos()
{

	int nElementos = 0;
	NO *aux = primeiro;
	while (aux != NULL)
	{
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}
	else
	{
		cout << "Elementos: \n";
		NO *aux = primeiro;
		while (aux != NULL)
		{
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO *atual = primeiro;
	NO *anterior = NULL;

	NO *novo = (NO *)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}
	cout << "Digite o numero: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (posicaoElemento(novo->valor) != NULL)
	{
		cout << "Este numero ja foi inserido" << endl;
		free(novo);
		return;
	}

	while (atual != NULL && atual->valor < novo->valor)
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (anterior == NULL)
	{
		primeiro = novo;
		primeiro->prox = atual;
	}
	else if (anterior != NULL)
	{
		anterior->prox = novo;
		novo->prox = atual;
	}
	else
	{
		novo->prox = atual;
	}
}

void excluirElemento()
{
	if (primeiro == NULL){
		cout <<"Lista vazia" << endl;
		return;
	}

	int numero;
	cout << "Digite o numero a ser excluido" << endl;
	cin >> numero;

	NO* atual = primeiro;
	NO* anterior = NULL;

	while(atual != NULL)
	{
		if(atual->valor == numero)
		{
			if(anterior ==NULL){
				primeiro = atual->prox;
			}
			else{
				anterior->prox = atual->prox;
			}

			free(atual);
			cout<< "Numero " << numero << " excluido com sucesso!" << endl;
			return;
		}
		else if (atual->valor > numero)
		{
			cout << "numero nao encontrado" << endl;
			return;
		}
		anterior = atual;
		atual = atual->prox;
	}
	cout <<"numero nao encontrado" << endl;
}

void buscarElemento()
{
	int buscar;
	cout << "Digite o numero a ser buscado: ";
	cin >> buscar;

	NO *aux = primeiro;

	while (aux != NULL)
	{
		if (aux->valor == buscar)
		{
			cout << "Numero encontrado" << endl;
			return;
		}
		else if (aux->valor > buscar)
		{
			cout << "Numero nao encontrado"<< endl;
			return;
		}
		aux = aux->prox;

	}
}

// Sem isso o código não funciona
NO *posicaoElemento(int numero)
{
	NO *aux = primeiro;
	while (aux != NULL)
	{
		if (aux->valor == numero)
		{
			return aux; // achou o elemento
		}
		aux = aux->prox;
	}
	return NULL; // não encontrou
}
