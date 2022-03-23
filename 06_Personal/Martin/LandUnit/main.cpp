#include "LandUnit.hpp"

int main()
{
	string indexhtml = "/var/www/html/index.html";
	string datatxt   = "data.txt";

  	LandUnit landUnitObj(indexhtml, datatxt);	

	landUnitObj.updateTUI();
	return 0;
}
