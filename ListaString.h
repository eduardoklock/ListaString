#include "Lista.h"
#define Max 100

class ListaString : public Lista<char*>{
	public:
		ListaString();
		~ListaString();
		void adicionarEmOrdem();
}