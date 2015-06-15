/*
 * Field.h
 *
 *  Created on: Jun 8, 2015
 *      Author: dor
 */

#ifndef OBJECTS_FIELD_H_
#define OBJECTS_FIELD_H_

#include "Superhero.h"
#include "../DataStructures/AVLRankTree.h"
#include "../DataStructures/HashTable.h"
#include "../DataStructures/PairID.h"
#include "../DataStructures/UnionFind.h"

class Field {
private:
	AVLRankTree<int,Superhero*> superheroesIdTree;
	AVLRankTree<PairID,Superhero*> superheroesPowerTree;
	HashTable<Superhero*> superheroesHashTable;
	UnionFind<Superhero*> groupsDepartments;
	int minID = 0;
	int maxID = 0;
	bool hasBeenInit = false;

public:
	Field(int n);
	virtual ~Field();
	void AddSuperhero(int superhero, int strength);
	void AssignSuperhero(int superheroID, int team);
	void JoinDepartments(int team1, int team2);
	int GetDepartment(int superheroID);
	void TeamUpgrade(int teamID, int factor);
	Superhero* GetStrongestSuperhero(int depID);
	int GetNumOfSuperherosInRange(int min, int max);
};


#endif /* OBJECTS_FIELD_H_ */