#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>  
#include <crtdbg.h>  
#include "UtilsTest.h"
#include "Domain/DomainTest.h"
#include "Repository/RepositoryTest.h"
#include "Service/MedicineServiceTests.h"
#include "UI/UI.h"
#include "ListTest.h"

int main() {
	runListTests();	
	runUtilsTest();
    runDomainTests();
    medicineRepositoryTests();
    runMedicineServiceTests();

     //UI* ui = createUI(createMedicineService(createMedicineRepository()));
     //runUI(ui);
     //destroyUI(ui);

	_CrtDumpMemoryLeaks();
    return 0;
}