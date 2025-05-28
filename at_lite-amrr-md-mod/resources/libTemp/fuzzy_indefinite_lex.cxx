#encoding "utf-8"

/*Num -> AnyWord<wff=/([0-9]?[0-9]?[0-9])/>;

Indistinct -> Word<kwset="нечеткость"> ;

Inaccurate -> Word<kwset = "неточность"> | Noun<kwtype=noun1> Num;
*/

Indefinite_00_10 -> Adv<kwtype=adv00> | "никогда" ;

Indefinite_05_20 -> Adv<kwtype=adv20> ;//| "маловероятно";

Indefinite_25_40 -> Adv<kwtype=adv2540> | /*Adv<kwtype=advdop> Adv<kwtype=adv75> */ Adv<kwset="крайне"> Adv<kwtype=adv2540>;

// ----- ок ------

Indefinite_40_60 -> Adv<kwtype=adv50>; // | "не исключено";

// ----- ок ------

Indefinite_50_75 -> AnyWord<kwtype=fuzzy> | (Adv<kwset=["теоретически"]>) Adv<kwtype=adv75> | Verb Noun<kwtype=noun100>; // | "кажется";

// ----- ок ------

Indefinite_80_90 -> Adv<kwtype=adv8090> ("всего") | "похоже" | "зачастую";

// ----- ок ------

Indefinite_75_100 -> Adv<kwtype=adv75100> | "вполне" Adv<kwtype=adv75> | "где-то" | "когда-то"| Word<kwtype=adj100>;

// ----- ок ------

Indefinite_90_100 -> Adv<kwtype=adv100> ;

// ----- ок ------



FuzIndefLex -> Indefinite_00_10 interp(FuzzyIndefiniteLexeme.Indefinite_00_10)
| Indefinite_05_20 interp(FuzzyIndefiniteLexeme.Indefinite_05_20)
| Indefinite_25_40 interp(FuzzyIndefiniteLexeme.Indefinite_25_40)
| Indefinite_40_60 interp(FuzzyIndefiniteLexeme.Indefinite_40_60)
| Indefinite_50_75 interp(FuzzyIndefiniteLexeme.Indefinite_50_75)
| Indefinite_80_90 interp(FuzzyIndefiniteLexeme.Indefinite_80_90)
| Indefinite_75_100 interp(FuzzyIndefiniteLexeme.Indefinite_75_100)
| Indefinite_90_100 interp(FuzzyIndefiniteLexeme.Indefinite_90_100);
