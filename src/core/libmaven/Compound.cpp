#include "Compound.h"
#include "mzMassCalculator.h"

Compound::Compound(string id, string name, string formula, int charge ) {
    this->id = id;
    this->name = name;
    this->formula = formula;
    this->charge = charge;
    /**
    *@brief  -   calculate mass of compound by its formula and assign it to mass
    *@see  - double MassCalculator::computeNeutralMass(string formula) in mzMassCalculator.cpp
    */
    this->mass =  MassCalculator::computeNeutralMass(formula);
    this->expectedRt = -1;

    precursorMz=0;
    productMz=0;
    collisionEnergy=0;
    _groupUnlinked=false;
}

float Compound::adjustedMass(int charge) { 
     /**   
    *@return    -    total mass by formula minus loss of electrons' mass 
    *@see  -  double MassCalculator::computeMass(string formula, int charge) in mzMassCalculator.cpp
    */
    return MassCalculator::computeMass(formula,charge); 
}
