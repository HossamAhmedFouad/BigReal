#include "BigReal.h"

BigReal :: BigReal(double realNumber) { //Initialize from double
    string realNumberString = to_string(realNumber);
    string rawNumber,fractionNumber;
    for(int i=0; i<realNumberString.size(); i++){
        if(realNumberString[i]=='.'){
            rawNumber = realNumberString.substr(0,i);
            BigDecimalInt rawNumberFormatted(rawNumber);
            number = rawNumberFormatted;
            fractionNumber = realNumberString.substr(i+1,realNumberString.size()-rawNumber.size()-1);
            BigDecimalInt fractionNumberFormatted(fractionNumber);
            fraction = fractionNumberFormatted;
            break;
        }
    }

}

BigReal :: BigReal(string realNumber) { // Initialize from string
    string rawNumber,fractionNumber;
    for(int i=0; i<realNumber.size(); i++){
        if(realNumber[i]=='.'){
            rawNumber = realNumber.substr(0,i);
            BigDecimalInt rawNumberFormatted(rawNumber);
            number = rawNumberFormatted;
            fractionNumber = realNumber.substr(i+1,realNumber.size()-rawNumber.size()-1);
            BigDecimalInt fractionNumberFormatted(fractionNumber);
            fraction = fractionNumberFormatted;
            break;
        }
    }
}

BigReal :: BigReal(BigDecimalInt bigInteger) { // Initialize from BigDecimalInt
    number = bigInteger;
    BigDecimalInt emptyFraction("0");
    fraction = emptyFraction;
}

BigReal :: BigReal(const BigReal& other) : number(other.number),fraction(other.fraction) {
} // Copy constructor - Deep Copy


BigReal ::BigReal(BigReal &&other){ // Move constructor
    number   = other.number;
    fraction = other.fraction;
}


BigReal& BigReal ::operator=(BigReal& other){ // Assignment operator
    number = other.number;
    fraction = other.fraction;
    return *this;
}

BigReal& BigReal ::operator=(BigReal&& other) { // Move assignment
    if(&other != this){
        number = other.number;
        fraction = other.fraction;
    }
    return *this;
}
