#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdexcept>

template <class T>
class Lista{
    public:
        Lista(int);
        virtual ~Lista();
        void adicionarNoFim(const T&);
        void adicionarNoInicio(const T&);
        void adicionarNaPosicao(const T&,int);
        T retirarDoFim();
        T retirarDoInicio();
        T retirarDaPosicao(int);
        T retirarEspecifico(const T&);
        bool cheia();
        bool vazia();
        int posicao(const T&);
        bool contem(const T&);
        int tamanho();
        T elementoDaPosicao(int);
        void destroiLista();

    private:
        T* elementos;
        int topo;
        int tamanhoMax;
        void deslocarParaDireita(int);
        void deslocarParaEsquerda(int);
};


template <class T>
Lista<T>::Lista(int max) : topo(-1), tamanhoMax(max){
   elementos = new T[tamanhoMax];
}

template <class T>
Lista<T>::~Lista(){
    delete[] elementos;
}

template <class T>
void Lista<T>::adicionarNoFim(const T& adicionado){
    this->elementos[++topo] = adicionado;
}

template <class T>
T Lista<T>::retirarDoFim(){
    return this->elementos[topo--];
}

template <class T>
void Lista<T>::adicionarNoInicio(const T& adicionado){
    this->adicionarNaPosicao(adicionado,0);
}

template <class T>
T Lista<T>::retirarDoInicio(){
    return this->retirarDaPosicao(0);
}

template <class T>
void Lista<T>::adicionarNaPosicao(const T& adicionado,int posicao){
    if(this->cheia()){
        throw std::out_of_range(" ");
    }
    if(posicao>this->tamanho())
        throw std::out_of_range("Erro: fila cheia.");
    this->deslocarParaDireita(posicao);
    elementos[posicao] = adicionado;
    topo++;
    
}

template <class T>
T Lista<T>::retirarDaPosicao(int posicao){
    if(this->vazia()){
        throw std::out_of_range("Erro: fila cheia.");
    }
    if(posicao<0){
        throw std::out_of_range("Erro: fila cheia.");
    }
    T variavel = elementos[posicao];
    this->deslocarParaEsquerda(posicao);
    --topo;
    return variavel;
}

template <class T>
bool Lista<T>::cheia(){
    return (tamanho() == tamanhoMax);
}

template <class T>
bool Lista<T>::vazia(){
    return (tamanho() == 0);
}

template <class T>
int Lista<T>::tamanho(){
    return (topo+1);
}
template <class T>
int Lista<T>::posicao(const T& elemento){
    for(int i = 0; i<=topo; ++i){
        if(elementos[i] == elemento){
            return i;
        }
    }
    throw std::out_of_range("Erro: fila cheia.");
}
template <class T>
bool Lista<T>::contem(const T& elemento){
    for(int i = 0; i<=topo; ++i){
        if(elementos[i] == elemento){
            return true;
        }
    }
    return false;
}
template <class T>
void Lista<T>::deslocarParaDireita(int posicao){
    for(int i = topo; i >= posicao; --i){
        elementos[i+1] = elementos[i];
    }
}

template <class T>
void Lista<T>::deslocarParaEsquerda(int posicao){
    while(posicao < topo){
        elementos[posicao] = elementos[++posicao];
    }
}

template <class T>
T Lista<T>::elementoDaPosicao(int posicao){
    if(posicao > topo){
        throw std::out_of_range("Erro: fila cheia.");
    }
    if(posicao < (-1)){
        throw std::out_of_range("Erro: fila cheia.");
    }
    return this->elementos[posicao];
}
template <class T>
void Lista<T>::destroiLista(){
    topo = -1;
}

#endif