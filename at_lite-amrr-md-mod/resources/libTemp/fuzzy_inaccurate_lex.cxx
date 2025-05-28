#encoding "utf-8"

/*Num -> AnyWord<wff=/([0-9]?[0-9]?[0-9])/>;

Indistinct -> Word<kwset="нечеткость"> ;

Inaccurate -> Word<kwset = "неточность"> | Noun<kwtype=noun1> Num;

Digit -> '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9';
Digits -> Digit+;
RealNumber -> Digits '.' Digits;

Unit -> 'градусов' | 'метров' | 'килограмм';

Fact -> RealNumber Unit interp(Measurement.value) interp(Measurement.unit);

*/

/*AnyWord<wff=/([0-9]?[0-9]?[0-9]?[0-9])/>","AnyWord<wff=/([0-9]?[0-9]?[0-9]?[0-9])/> |*/

Num -> AnyWord<wff=/([0-9]?[0-9]?[0-9]?[0-9])/> | AnyWord<wff=/([0-9]?[0-9]?[0-9]?[0-9])?.?([0-9]?[0-9]?[0-9]?[0-9])/>;

rost_lemma -> Noun<kwtype=noun1> (Noun);
rost_unit -> "см";

weight_lemma -> Noun<kwtype=noun2> (Noun) ; // надо согласовать , или как-то пропустить???
weight_unit -> "кг";

temperature_lemma -> Noun<kwtype=noun3> (Noun); //| Noun<kwtype=noun3> "тело"<gram = "род">; проверить!!!!
temperature_unit -> Noun<kwtype=noun8> | "С" | "с" | "C" | "c";

pulse_lemma -> Noun<kwtype=noun4> (Noun);
pulse_unit -> Noun<kwtype=noun7> ; // не работает| "уд" "в" "мин" | "уд""/""мин";

saturation_lemma -> AnyWord<kwtype=noun5> ;
saturation_unit -> Percent ;

sugar_lemma -> Noun<kwtype=noun6> (Prep) (Noun);
sugar_unit -> "единиц" | "единицы" | "единица" | "ммоль" | "ммоль" "/" "л";

pressure_lemma -> AnyWord<kwtype=noun9> ;
pressure_unit -> "мм" "рт" "ст" ;


//N -> Num interp(FuzzyInaccurateLexeme.unit);

FuzInacLex -> (rost_lemma interp(FuzzyInaccurateLexeme.rost_lemma)) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (rost_unit interp(FuzzyInaccurateLexeme.rost_unit))
| weight_lemma interp(FuzzyInaccurateLexeme.weight_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (weight_unit interp(FuzzyInaccurateLexeme.weight_unit))
| temperature_lemma interp(FuzzyInaccurateLexeme.temperature_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (temperature_unit interp(FuzzyInaccurateLexeme.temperature_unit))
| pulse_lemma interp(FuzzyInaccurateLexeme.pulse_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (pulse_unit interp(FuzzyInaccurateLexeme.pulse_unit))
| saturation_lemma interp(FuzzyInaccurateLexeme.saturation_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (saturation_unit interp(FuzzyInaccurateLexeme.saturation_unit))
| sugar_lemma interp(FuzzyInaccurateLexeme.sugar_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (sugar_unit interp(FuzzyInaccurateLexeme.sugar_unit))
| pressure_lemma interp(FuzzyInaccurateLexeme.pressure_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) (Hyphen) (Num interp(FuzzyInaccurateLexeme.number2)) (pressure_unit interp(FuzzyInaccurateLexeme.pressure_unit))
| pressure_lemma interp(FuzzyInaccurateLexeme.pressure_lemma) (Verb) Num interp(FuzzyInaccurateLexeme.number1) 'на' (Num interp(FuzzyInaccurateLexeme.number2)) (pressure_unit interp(FuzzyInaccurateLexeme.pressure_unit));

