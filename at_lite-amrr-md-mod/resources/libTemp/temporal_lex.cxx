#encoding "utf-8"

DayOfWeek -> Noun<kwtype=dayOfWeek>; //дни недели

Day -> AnyWord<wff=/([1-2]?[0-9])|(3[0-1])/>; //дни числами

Date -> AnyWord<wff=/([0-2]\d|3[01])\.(0\d|1[012])\.(\d{4}|\d{2})/>;

Time -> AnyWord<wff=/(\d|[0-1]\d|2[0-3]):([0-5][0-9])/>;

Month -> Noun<kwtype=months>; 

Part -> Date (Time) | Time (Date) | Day Noun<kwtype=noun> (Day) (Noun<kwtype=noun>);

Period -> Adv<kwtype=adv5> | "каждый" (Day) Noun<kwtype=noun> | "раз" "в" (Day) Noun<kwtype=noun>;

Duration -> Adv<kwtype=adv4> | Prep<kwtype=prep4> (Day) Noun<kwtype=noun> | Prep<kwtype=prep4> Part;

Start -> Adv<kwtype=adv2> | Prep<kwtype=prep2> (Adj<kwtype=adj1>) Noun<kwtype=noun> (Noun<kwtype=noun>) | Prep<kwtype=prep2> (Adj<kwtype=adj1>) Part;
Start1 -> Prep<kwtype=prep2> Day;

End -> Adv<kwtype=adv3> | Prep<kwtype=prep3> (Adj<kwtype=adj1>) Noun<kwtype=noun> (Noun<kwtype=noun>) | Prep<kwtype=prep3> (Adj<kwtype=adj1>) Part;
End1 -> Prep<kwtype=prep3> Day;

Point -> DayOfWeek | Month | Day Noun<kwset=["месяцы", "день_недели"]> | (Prep<kwtype=prep1>) (Adj<kwtype=adj1>) (Noun<kwtype=noun>) Noun<kwtype=noun> | Prep<kwtype=prep1> (Adj<kwtype=adj1>) Part | Day Noun<kwtype=noun> "назад" | Day Noun<kwset=["месяцы", "день_недели"]> | Part | Adv<kwtype=adv1>;

Interval -> Start interp(TempLexeme.Start)  (End interp(TempLexeme.End)) (Duration interp(TempLexeme.Duration)) | End interp(TempLexeme.End) (Duration interp(TempLexeme.Duration)) | Duration interp(TempLexeme.Duration) | Start1 interp(TempLexeme.Start) End interp(TempLexeme.End) | Start1 interp(TempLexeme.Start) End1 interp(TempLexeme.End);

TempLex -> Interval interp(TempLexeme.Interval) | Point interp(TempLexeme.Point) | Period interp(TempLexeme.Period);
