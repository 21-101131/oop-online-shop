#include<iostream>

#include "baseEntity.h"

using namespace std;

BaseEntity::BaseEntity(){}
BaseEntity::BaseEntity(int _id, string _filename, vector<string> _labels): id(_id), filename(_filename), labels(_labels){}

int BaseEntity::getId() const {
	return id;
}

void BaseEntity::setId(int id) {
	this->id = id;
}

