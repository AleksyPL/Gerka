#include "NPCTransport.h"

void saveBarmanTemp(barman& bobby)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/barman_temp.txt");
	plik.open("./txt/mix/barman_temp.txt", ios::out);
	plik << bobby.repLevelInfo() << endl;
	plik << bobby.repPointsInfo() << endl;
	plik << bobby.repPointsToNextLevelInfo() << endl;
	plik << bobby.goldInfo() << endl;
	plik.close();
}

void loadBarmanTemp(barman& bobby)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/barman_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:bobby.repLevelSet(atoi(linia.c_str())); break;
		case 1:bobby.repPointsSet(atoi(linia.c_str())); break;
		case 2:bobby.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:bobby.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/barman_temp.txt");
}

void saveGeneralStoreSellerTemp(generalStoreSeller& handlarz)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/generalStoreSeller_temp.txt");
	plik.open("./txt/mix/generalStoreSeller_temp.txt", ios::out);
	plik << handlarz.repLevelInfo() << endl;
	plik << handlarz.repPointsInfo() << endl;
	plik << handlarz.repPointsToNextLevelInfo() << endl;
	plik << handlarz.goldInfo() << endl;
	plik.close();
}

void loadGeneralStoreSellerTemp(generalStoreSeller& handlarz)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/generalStoreSeller_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:handlarz.repLevelSet(atoi(linia.c_str())); break;
		case 1:handlarz.repPointsSet(atoi(linia.c_str())); break;
		case 2:handlarz.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:handlarz.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/generalStoreSeller_temp.txt");
}

void saveBlacksmithTemp(blacksmith& kowal)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/blacksmith_temp.txt");
	plik.open("./txt/mix/blacksmith_temp.txt", ios::out);
	plik << kowal.repLevelInfo() << endl;
	plik << kowal.repPointsInfo() << endl;
	plik << kowal.repPointsToNextLevelInfo() << endl;
	plik << kowal.goldInfo() << endl;
	plik.close();
}

void loadBlacksmithTemp(blacksmith& kowal)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/blacksmith_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:kowal.repLevelSet(atoi(linia.c_str())); break;
		case 1:kowal.repPointsSet(atoi(linia.c_str())); break;
		case 2:kowal.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:kowal.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/blacksmith_temp.txt");
}

void saveBladesmithTemp(bladesmith& miecznik)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/bladesmith_temp.txt");
	plik.open("./txt/mix/bladesmith_temp.txt", ios::out);
	plik << miecznik.repLevelInfo() << endl;
	plik << miecznik.repPointsInfo() << endl;
	plik << miecznik.repPointsToNextLevelInfo() << endl;
	plik << miecznik.goldInfo() << endl;
	plik.close();
}

void loadBladesmithTemp(bladesmith& miecznik)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/bladesmith_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:miecznik.repLevelSet(atoi(linia.c_str())); break;
		case 1:miecznik.repPointsSet(atoi(linia.c_str())); break;
		case 2:miecznik.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:miecznik.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/bladesmith_temp.txt");
}

void saveAlchemistTemp(alchemist& alchemik)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/alchemist_temp.txt");
	plik.open("./txt/mix/alchemist_temp.txt", ios::out);
	plik << alchemik.repLevelInfo() << endl;
	plik << alchemik.repPointsInfo() << endl;
	plik << alchemik.repPointsToNextLevelInfo() << endl;
	plik << alchemik.goldInfo() << endl;
	plik.close();
}

void loadAlchemistTemp(alchemist& alchemik)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/alchemist_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:alchemik.repLevelSet(atoi(linia.c_str())); break;
		case 1:alchemik.repPointsSet(atoi(linia.c_str())); break;
		case 2:alchemik.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:alchemik.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/alchemist_temp.txt");
}

void saveShamanTemp(shaman& szaman)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/shaman_temp.txt");
	plik.open("./txt/mix/shaman_temp.txt", ios::out);
	plik << szaman.repLevelInfo() << endl;
	plik << szaman.repPointsInfo() << endl;
	plik << szaman.repPointsToNextLevelInfo() << endl;
	plik << szaman.goldInfo() << endl;
	plik.close();
}

void loadShamanTemp(shaman& szaman)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/shaman_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:szaman.repLevelSet(atoi(linia.c_str())); break;
		case 1:szaman.repPointsSet(atoi(linia.c_str())); break;
		case 2:szaman.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:szaman.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/shaman_temp.txt");
}

void saveDoctorTemp(doctor& lekarz)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/doctor_temp.txt");
	plik.open("./txt/mix/doctor_temp.txt", ios::out);
	plik << lekarz.repLevelInfo() << endl;
	plik << lekarz.repPointsInfo() << endl;
	plik << lekarz.repPointsToNextLevelInfo() << endl;
	plik << lekarz.goldInfo() << endl;
	plik.close();
}

void loadDoctorTemp(doctor& lekarz)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/doctor_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:lekarz.repLevelSet(atoi(linia.c_str())); break;
		case 1:lekarz.repPointsSet(atoi(linia.c_str())); break;
		case 2:lekarz.repPointsToNextLevelSet(atoi(linia.c_str())); break;
		case 3:lekarz.goldSet(atoi(linia.c_str())); break;
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/doctor_temp.txt");
}

void saveChestTemp(chest& krzynka)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	remove("./txt/mix/chest_temp.txt");
	plik.open("./txt/mix/chest_temp.txt", ios::out);
	for (int i = 0; i < 60; i++)
	{
		plik << krzynka.menu[i] << endl << krzynka.menu_amount[i] << endl;
	}
	plik.close();
}

void loadChestTemp(chest& krzynka)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/chest_temp.txt", ios::in);
	while (getline(plik, linia))
	{
		if (nr_linii % 2 == 0)
		{
			krzynka.menu[nr_linii/2] = linia;
		}
		else
		{
			krzynka.menu_amount[nr_linii / 2] = atoi(linia.c_str());
		}
		nr_linii++;
	}
	plik.close();
	remove("./txt/mix/chest_temp.txt");
}
