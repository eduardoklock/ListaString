#include "Lista.h"
#define Max 100
#include <string.h>

class ListaString : public Lista<char*>{
	public:
		ListaString();
		~ListaString();
		void adicionarEmOrdem(char*);
		char* retirarEspecifico(char*);
};