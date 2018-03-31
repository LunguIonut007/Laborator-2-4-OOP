
#include "MedicineRepository.h"
#include <stdlib.h>

MedicineRepository* createMedicineRepository() {
    MedicineRepository* medicineRepository = (MedicineRepository*) malloc(sizeof(MedicineRepository));
    medicineRepository->list = createList(destroyMedicine, getSizeOfMedicinePointer());

    return medicineRepository;
}

void addMedicineRepository(MedicineRepository* repository, Medicine* medicine) {
    addToList(repository->list, medicine);
}

void updateMedicineRepository(Medicine* medicine, char* name, int concentration) {
    setMedicineName(medicine, name);
    setMedicineConcentration(medicine, concentration);
}

Medicine* findMedicineRepository(MedicineRepository* repository, int id) {
	Medicine* medicine;
   for(int i = 0; i < getMedicineRepositorySize(repository); i++) {
		medicine = getAtListIndex(repository->list, i);
		if (id == medicine->id) {
			return getAtListIndex(repository->list, i);
		}
           
   }

    return NULL;
}

int getMedicineRepositorySize(MedicineRepository* medicineRepository) {
    return getListSize(medicineRepository->list);
}

void destroyMedicineRepository(MedicineRepository* medicineRepository) {
    destroyList(medicineRepository->list);
    free(medicineRepository);
}

List* getAllMedicineRepository(MedicineRepository* medicineRepository) {
	return deepCopyList(medicineRepository->list, deepCopyMedicine);
}