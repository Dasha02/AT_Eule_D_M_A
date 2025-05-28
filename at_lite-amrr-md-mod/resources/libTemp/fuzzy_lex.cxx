#encoding "utf-8"

/*
Num -> AnyWord<wff=/([0-9]?[0-9]?[0-9])/>;

Indistinct -> Word<kwset="нечеткость"> ;

Inaccurate -> Word<kwset = "неточность"> | Noun<kwtype=noun1> Num;
*/
//Indefinite -> Word<kwset = "неопределенность"> | Word<kwset = "некоторый"> | Adv<kwtype=adv00>;


// Убрал "температура тела" так как был конфликт. Словосочетания не факт что работают
FuzzyT1 -> Adj<kwtype=adjFuzzyLengthT1> Noun<kwtype=nounFuzzyLength> |
               Adj<kwtype=adjFuzzyAreaT1> Noun<kwtype=nounFuzzyArea> |
               Adj<kwtype=adjFuzzyLeukocytesT1> Noun<kwtype=nounFuzzyLeukocytes> |
               Adj<kwtype=adjFuzzyVolumeT1> Noun<kwtype=nounFuzzyVolume> |
               Adj<kwtype=adjFuzzyMassT1> Noun<kwtype=nounFuzzyMass> |
               Adj<kwtype=adjFuzzyTimeT1> Noun<kwtype=nounFuzzyTime> |
               Adj<kwtype=adjFuzzyTemperatureT1> Noun<kwtype=nounFuzzyTemperature> |
               Adj<kwtype=adjFuzzyForceT1> Noun<kwtype=nounFuzzyForce> |
               Adj<kwtype=adjFuzzyAngleT1> Noun<kwtype=nounFuzzyAngle> |
               Adj<kwtype=adjFuzzyDensityT1> Noun<kwtype=nounFuzzyDensity> |
               Adj<kwtype=adjFuzzyFrequencyT1> Noun<kwtype=nounFuzzyFrequency> |
               Adj<kwtype=adjFuzzySpeedT1> Noun<kwtype=nounFuzzySpeed> |
               Adj<kwtype=adjFuzzyAccelerationT1> Noun<kwtype=nounFuzzyAcceleration> |
               Adj<kwtype=adjFuzzyPressureT1> Noun<kwtype=nounFuzzyPressure> |
               Adj<kwtype=adjFuzzyThroatPainT1> Noun<kwtype=nounadd1> |
               Adj<kwtype=adjFuzzyMucousColorT1> Noun<kwtype=nounadd4> |
               Adj<kwtype=adjFuzzyTonsilPlaqueColorT1> Noun<kwtype=nounadd5> |
               Adj<kwtype=adjFuzzySwallowingPainT1> Noun<kwtype=nounadd2> | 
               Adj<kwtype=adjFuzzyPulseT1> Noun<kwtype=nounFuzzyPulse> |
               Adj<kwtype=adjFuzzyNasalDischargeT1> Noun<kwtype=nounadd3> |
               Adj<kwtype=adjFuzzyPlaqueAreaT1> Noun<kwtype=nounadd6>;

FuzzyT2 -> Adj<kwtype=adjFuzzyLengthT2> Noun<kwtype=nounFuzzyLength> |
               Adj<kwtype=adjFuzzyAreaT2> Noun<kwtype=nounFuzzyArea> |
               Adj<kwtype=adjFuzzyLeukocytesT2> Noun<kwtype=nounFuzzyLeukocytes> |
               Adj<kwtype=adjFuzzyVolumeT2> Noun<kwtype=nounFuzzyVolume> |
               Adj<kwtype=adjFuzzyMassT2> Noun<kwtype=nounFuzzyMass> |
               Adj<kwtype=adjFuzzyTimeT2> Noun<kwtype=nounFuzzyTime> |
               Adj<kwtype=adjFuzzyTemperatureT2> Noun<kwtype=nounFuzzyTemperature> |
               Adj<kwtype=adjFuzzyForceT2> Noun<kwtype=nounFuzzyForce> |
               Adj<kwtype=adjFuzzyAngleT2> Noun<kwtype=nounFuzzyAngle> |
               Adj<kwtype=adjFuzzyDensityT2> Noun<kwtype=nounFuzzyDensity> |
               Adj<kwtype=adjFuzzyFrequencyT2> Noun<kwtype=nounFuzzyFrequency> |
               Adj<kwtype=adjFuzzySpeedT2> Noun<kwtype=nounFuzzySpeed> |
               Adj<kwtype=adjFuzzyAccelerationT2> Noun<kwtype=nounFuzzyAcceleration> |
               Adj<kwtype=adjFuzzyPressureT2> Noun<kwtype=nounFuzzyPressure> |
               Adj<kwtype=adjFuzzyThroatPainT2> Noun<kwtype=nounadd1> |
               Adj<kwtype=adjFuzzyMucousColorT2> Noun<kwtype=nounadd4> |   
               Adj<kwtype=adjFuzzyTonsilPlaqueColorT2> Noun<kwtype=nounadd5> |
               Adj<kwtype=adjFuzzySwallowingPainT2> Noun<kwtype=nounadd2> |
               Adj<kwtype=adjFuzzyPulseT2> Noun<kwtype=nounFuzzyPulse> |
               Adj<kwtype=adjFuzzyNasalDischargeT2> Noun<kwtype=nounadd3> |
               Adj<kwtype=adjFuzzyPlaqueAreaT2> Noun<kwtype=nounadd6>;

FuzzyT3 -> Adj<kwtype=adjFuzzyLengthT3> Noun<kwtype=nounFuzzyLength> |
               Adj<kwtype=adjFuzzyAreaT3> Noun<kwtype=nounFuzzyArea> |
               Adj<kwtype=adjFuzzyLeukocytesT3> Noun<kwtype=nounFuzzyLeukocytes> |
               Adj<kwtype=adjFuzzyVolumeT3> Noun<kwtype=nounFuzzyVolume> |
               Adj<kwtype=adjFuzzyMassT3> Noun<kwtype=nounFuzzyMass> |
               Adj<kwtype=adjFuzzyTimeT3> Noun<kwtype=nounFuzzyTime> |
               Adj<kwtype=adjFuzzyTemperatureT3> Noun<kwtype=nounFuzzyTemperature> |
               Adj<kwtype=adjFuzzyForceT3> Noun<kwtype=nounFuzzyForce> |
               Adj<kwtype=adjFuzzyAngleT3> Noun<kwtype=nounFuzzyAngle> |
               Adj<kwtype=adjFuzzyDensityT3> Noun<kwtype=nounFuzzyDensity> |
               Adj<kwtype=adjFuzzyFrequencyT3> Noun<kwtype=nounFuzzyFrequency> |
               Adj<kwtype=adjFuzzySpeedT3> Noun<kwtype=nounFuzzySpeed> |
               Adj<kwtype=adjFuzzyAccelerationT3> Noun<kwtype=nounFuzzyAcceleration> |
               Adj<kwtype=adjFuzzyPressureT3> Noun<kwtype=nounFuzzyPressure> |
               Adj<kwtype=adjFuzzyThroatPainT3> Noun<kwtype=nounadd1> |
               Adj<kwtype=adjFuzzyMucousColorT3> Noun<kwtype=nounadd4> |
               Adj<kwtype=adjFuzzyTonsilPlaqueColorT3> Noun<kwtype=nounadd5> |
               Adj<kwtype=adjFuzzySwallowingPainT3> Noun<kwtype=nounadd2> | 
               Adj<kwtype=adjFuzzyPulseT3> Noun<kwtype=nounFuzzyPulse> |
               Adj<kwtype=adjFuzzyNasalDischargeT3> Noun<kwtype=nounadd3> | 
               Adj<kwtype=adjFuzzyPlaqueAreaT3> Noun<kwtype=nounadd6>;

FuzzyT12 -> Adj<kwtype=adjFuzzyTemperatureT12> Noun<kwtype=nounFuzzyTemperature>; 

FuzzyT23 -> Adj<kwtype=adjFuzzyTemperatureT23> Noun<kwtype=nounFuzzyTemperature>;

// чтобы существовл такой тип переделал на просто температуру
FuzzyT30 -> Adj<kwtype=adjFuzzyBodyTemperatureT30> Noun<kwtype=nounFuzzyTemperature>; 


// как будто недоделан/ недодуман так что не стал пока добавлять
FuzzyT01 -> Adj<kwtype=adjFuzzySugarLevelT01> "Уровень сахара";



FuzLex -> FuzzyT1 interp(FuzzyLexeme.FuzzyT1) 
| FuzzyT2 interp(FuzzyLexeme.FuzzyT2) 
| FuzzyT3 interp(FuzzyLexeme.FuzzyT3) 
| FuzzyT12 interp(FuzzyLexeme.FuzzyT12) 
| FuzzyT23 interp(FuzzyLexeme.FuzzyT23) 
| FuzzyT30 interp(FuzzyLexeme.FuzzyT30) 
| FuzzyT01 interp(FuzzyLexeme.FuzzyT01);


