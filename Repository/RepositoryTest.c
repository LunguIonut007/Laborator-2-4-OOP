//
// Created by ionut on 12.03.2018.
//

#include <assert.h>
#include <string.h>
#include "RepositoryTest.h"
#include "MedicineRepository/MedicineRepository.h"

void medicineRepositoryTests() {
    char name[] = "Adrian";
    Medicine* medicine = createMedicine(1, name, 57, 3);

    char name1[] = "Ionut";
    Medicine* medicine1 = createMedicine(2, name1, 2, 10);

    // Create tests
    MedicineRepository* medicineRepository = createMedicineRepository();
    assert(getMedicineRepositorySize(medicineRepository) == 0);

    // Add tests
    addMedicineRepository(medicineRepository, medicine);
    assert(getMedicineRepositorySize(medicineRepository) == 1);

    addMedicineRepository(medicineRepository, medicine1);
    assert(getMedicineRepositorySize(medicineRepository) == 2);

    // Update tests
    assert(getMedicineConcentration(medicine) == 57);
    assert(strcmp(getMedicineName(medicine), name) == 0);

    updateMedicineRepository(medicine, "Alt nume", 8);

    assert(getMedicineConcentration(medicine) == 8);
    assert(strcmp(getMedicineName(medicine), "Alt nume") == 0);

    // Find tests
    assert(findMedicineRepository(medicineRepository, 1) == medicine);
    assert(findMedicineRepository(medicineRepository, 3) == NULL);

    List* medicineList = getAllMedicineRepository(medicineRepository);
    assert(getListSize(medicineList) == getMedicineRepositorySize(medicineRepository));
    destroyList(medicineList);
    destroyMedicineRepository(medicineRepository);
}
