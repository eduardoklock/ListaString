#include "ListaString.h"

ListaString::ListaString()
: Lista<char*>(Max){}

ListaString::~ListaString(){}

void ListaString::adicionarEmOrdem(char* adicionado){
	for(int i = 0; i < this->tamanho(); i++){
		if(strcmp(adicionado,this->elementoDaPosicao(i)) < 0){
			adicionarNaPosicao(adicionado,i);
			break;
		}
		if(i == (tamanho() -1)){
			adicionarNoFim(adicionado);
			break;
		}

	}
}
char* ListaString::retirarEspecifico(char* retirado){
	for(int i = 0; i < this->tamanho(); i++){
		if(strcmp(retirado,this->elementoDaPosicao(i)) == 0){
			return retirarDaPosicao(i);

		}
	}
}
