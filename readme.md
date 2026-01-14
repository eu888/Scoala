# 2.1 Cantitatea de informaţie
`Informaţie` - ştire, comunicare verbală, scrisă sau transmisă prin alte metode despre anumite fapte, evenimente, activităţi etc. care se concretizează	într-un	compartiment al	matematicii, denumit `teoria informaţiei`. 

`Sursa de informatie` poate fi notata cu variabila `S` si poate avea valori a unei multimi finite cu forma `{s₁, s₂,⋯,s`<small>`n`</small>`}`, care se considera ca valorile lui ei nu se cunosc, dar se cunosc numai multimea `{s₁, s₂,⋯,s`<small>`n`</small>`}`, denumita `mulţimea mesajelor posibile`.
### Exemplu:
Un semafor poate avea culoarea rosie, galbena si verde, drept urmare mulţimea mesajelor posibile ar fi egal cu `{rosu, galben, verde}`.
Un alt exemplu poate fi tastele de la un telegram sau tastatura `{A, B, C,⋯,Z, 1, 2,⋯, 9}`
***
## Calea mesajului
Mesagele se transmit de la sursa pritrun mediu fizic numit `canal de transmisie`, care poate fi un fir electric sau unde radio etc.
`Perturbatiile` (zgomotele) din mediu fizic pot altera mesaju. Valoarea `S` devine cunoscuta odata cu ajungerea la `Destinatar`.

```
         Mesaj
⌜‾‾‾‾⌝    |    ⌜‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾⌝         ⌜‾‾‾‾‾‾‾‾⌝
|Sursa| —————→ |canal de transmisie| —————→ |Destinatar|
⌞____⌟         ⌞__________________⌟         ⌞________⌟
                        |
                    Perturbatii

```
## Cantitatea de informatie
`Cantitatea	de	informaţie` notata prin	`I` ce	este	conţinută	într-un	mesaj	emis	de	sursă	se	
determină	din	relaţia: `I = log`<small>`a`</small>`n`.
> Un bit este cantitatea de informaţie din mesajul unei surse cu numai 
două mesaje posibile

Prin	urmare,	ca	şi	în	cazul	altor	mărimi	(lungimea,	masa,	temperatura	etc.),	
cantitatea	de	informaţie	se	măsoară	prin	compararea	cu	`etalonul`.	Întrucât	pentru	
sursa-etalon	`n = 2`,	din	ecuaţia: `log`<small>`a`</small>`2`		(bit) 

***
Obţinem	`a = 2`.	În	consecinţă,	cantitatea	de	informaţie	`I`,	măsurată	în	biţi,	se	de
termină	din	relaţia: `I = log₂n` (bit)
***
## Exerciti
1. Cum	se	defineşte	o	sursă	de	informaţie?	Daţi	câteva	exemple.
2.	Care	este	destinaţia	canalului	de	transmisie?
3.	Cum	se	determină	cantitatea	de	informaţie	dintr-un	mesaj?	Dar	din	`N`	mesaje?
4.	Care	este	unitatea	de	măsură	a	informaţiei	şi	ce	semnificaţie	are	ea?
5.	Determinaţi	cantitatea	de	informaţie	într-un	mesaj	al	surselor	cu	următoarele	mesaje	posibile:
    1. literele	mari	şi	mici	ale	alfabetului	latin;
    	literele	mari	şi	mici	ale	alfabetului	grec;
    2.	literele	mari	şi	mici	ale	alfabetului	român;
    3.	cifrele	zecimale	`0,	1,	2,	...,	9`;
    4.	cifrele	`0,	1,	2,	...,	9`,	semnele	`+,	–,	×,	/`	şi	parantezele	`()`;
    5. indicaţiile	numerice	de	forma	hh:mm (hh	–	ora,	mm	–	minutele)	ale	unui	ceas	
    electronic;
    6. indicaţiile	numerice	de	forma	`hh:mm:ss` (ss	–	secundele)	ale	unui	ceas	electronic;
    7. indicaţiile	numerice	de	forma	`zz.ll.aa` (zz	–	ziua,	ll	–	luna,	aa	–	anul)	ale	unui	
    calendar	electronic.
6. Pentru	fiecare	dintre	sursele	indicate	în	`exerciţiul	5`	determinaţi	cantitatea	de	
informaţie	ce	este	conţinută	în	`1	000	de	mesaje`	emise	de	sursă.
7.	Elaboraţi	un	program	care	calculează	cantitatea	de	informaţie	din	`N`	mesaje	
emise	de	o	sursă	cu	`n`	mesaje	posibile.
## Exemplu

```c
#include <stdio.h>
#include <math.h>

int main(){
    double I;
    int n, N;
    printf("Introduce n: ");
    scanf("%d", &n);
    printf("Introduce N: ");
    scanf("%d", &N);
    I = N * log2((double)n);
    printf("Cantitatea de informatie este: %.2f",I);
    return 0;
}
```
